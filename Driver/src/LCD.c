/*
 * LCD.c
 *
 *  Created on: Aug 29, 2022
 *      Author: ahmad
 */

#include <util/delay.h>
#include "std_types.h"
#include "macros.h"
#include "DIO.h"
#include "LCD.h"
#include "LCD_cfg.h"
#undef  F_CPU
#define F_CPU 8000000


static void LCD_SendData(u8 data);
static void LCD_SendCommand(u8 command);
static void LCD_InitPinsMode(void);

void LCD_Init(void) {
    u8 command = 0;
    LCD_InitPinsMode();
    _delay_ms(30);

    /* Function Set:
        N: 1 (two lines)
        F: 0 (5x7)
    */
    command = 0b00110000;
    #if (LCD_MODE_LINES == LCD_TWO_LINES)
        SET_BIT(command, 3);
    #endif
    #if (LCD_MODE_DOTS == LCD_DOTS_5X10)
        SET_BIT(command, 2);
    #endif
    LCD_SendCommand(command);

    /* Display ON/OFF
        D: 1 (Display ON)
        C: 0 (Cursor off)
        B: 0 (Cursor not blink)
    */
    command = 0b00001000; 
    #if (LCD_MODE_DISPLAY == LCD_DISPLAY_ON)
        SET_BIT(command, 2);
    #endif
    #if (LCD_MODE_CURSOR == LCD_CURSOR_ON_BLINK)
        SET_BIT(command, 0);
        SET_BIT(command, 1);
    #endif
    #if (LCD_MODE_CURSOR == LCD_CURSOR_ON_NO_BLINK)
        SET_BIT(command, 1);
    #endif
    LCD_SendCommand(command);

    /* Display Clear */
    LCD_SendCommand(0b00000001);
}


void LCD_Clear (void) {
    LCD_SendCommand(0b00000001);
}

void LCD_DisplayCharacter (u8 data) {
    LCD_SendData(data);
}

void LCD_DisplayString (u8 *str) {
    u8 i=0;
    while(str[i] != '\0') {
        LCD_DisplayCharacter(str[i]);
        i++;
    }
}

void LCD_SetCursorPosition(u8 row, u8 column) {
    u8 address = column + row*0x40;
    SET_BIT(address, 7);
    LCD_SendCommand(address);
}

void LCD_DisplayNumber (s32 number) {
    u32 reversed_number = 0;
    u8 digits = 0;
    if (number < 0) {
        number = number*-1;
        LCD_DisplayCharacter('-');
    }
    else if (number == 0) {
        LCD_DisplayCharacter('0');
    }
    while (number != 0)
    {
        reversed_number = (reversed_number*10) + (number%10);
        number = number / 10;
        digits++;
    }
    while (reversed_number != 0)
    {
        u8 data = reversed_number % 10;
        data = data + '0';
        LCD_DisplayCharacter(data);
        reversed_number = reversed_number / 10;
        digits--;
    }
    while (digits != 0) {
        LCD_DisplayCharacter('0');
        digits--;
    }
    
}

void LCD_ShiftLeft (u8 counter) {
    u8 i;
    for (i=0; i<counter; i++) {
        LCD_SendCommand(0b00011000);
    }
}
void LCD_ShiftRight (u8 counter) {
    u8 i;
    for (i=0; i<counter; i++) {
        LCD_SendCommand(0b00011100);
    }
}

static void LCD_SendCommand(u8 command) {
    /* Set Control Pins:
        RS : 0 Command
        RW : 0 Write
    */
    DIO_SetPinLevel(LCD_PIN_RS, DIO_LOW);
    DIO_SetPinLevel(LCD_PIN_RW, DIO_LOW);
    
    /* Set Data Pins */
    DIO_SetPinLevel(LCD_PIN_D0, GET_BIT(command, 0));
    DIO_SetPinLevel(LCD_PIN_D1, GET_BIT(command, 1));
    DIO_SetPinLevel(LCD_PIN_D2, GET_BIT(command, 2));
    DIO_SetPinLevel(LCD_PIN_D3, GET_BIT(command, 3));
    DIO_SetPinLevel(LCD_PIN_D4, GET_BIT(command, 4));
    DIO_SetPinLevel(LCD_PIN_D5, GET_BIT(command, 5));
    DIO_SetPinLevel(LCD_PIN_D6, GET_BIT(command, 6));
    DIO_SetPinLevel(LCD_PIN_D7, GET_BIT(command, 7));

    DIO_SetPinLevel(LCD_PIN_E, DIO_HIGH);
    _delay_ms(2);
    DIO_SetPinLevel(LCD_PIN_E, DIO_LOW);
}

static void LCD_SendData(u8 data) {
    /* Set Control Pins:
        RS : 1 Data
        RW : 0 Write
    */
    DIO_SetPinLevel(LCD_PIN_RS, DIO_HIGH);
    DIO_SetPinLevel(LCD_PIN_RW, DIO_LOW);
    
    /* Set Data Pins */
    DIO_SetPinLevel(LCD_PIN_D0, GET_BIT(data, 0));
    DIO_SetPinLevel(LCD_PIN_D1, GET_BIT(data, 1));
    DIO_SetPinLevel(LCD_PIN_D2, GET_BIT(data, 2));
    DIO_SetPinLevel(LCD_PIN_D3, GET_BIT(data, 3));
    DIO_SetPinLevel(LCD_PIN_D4, GET_BIT(data, 4));
    DIO_SetPinLevel(LCD_PIN_D5, GET_BIT(data, 5));
    DIO_SetPinLevel(LCD_PIN_D6, GET_BIT(data, 6));
    DIO_SetPinLevel(LCD_PIN_D7, GET_BIT(data, 7));

    DIO_SetPinLevel(LCD_PIN_E, DIO_HIGH);
    _delay_ms(2);
    DIO_SetPinLevel(LCD_PIN_E, DIO_LOW);
}


static void LCD_InitPinsMode(void) {
    DIO_SetPinMode(LCD_PIN_RS, DIO_OUTPUT);
    DIO_SetPinMode(LCD_PIN_RW, DIO_OUTPUT);
    DIO_SetPinMode(LCD_PIN_E , DIO_OUTPUT);
    DIO_SetPinMode(LCD_PIN_D0, DIO_OUTPUT);
    DIO_SetPinMode(LCD_PIN_D1, DIO_OUTPUT);
    DIO_SetPinMode(LCD_PIN_D2, DIO_OUTPUT);
    DIO_SetPinMode(LCD_PIN_D3, DIO_OUTPUT);
    DIO_SetPinMode(LCD_PIN_D4, DIO_OUTPUT);
    DIO_SetPinMode(LCD_PIN_D5, DIO_OUTPUT);
    DIO_SetPinMode(LCD_PIN_D6, DIO_OUTPUT);
    DIO_SetPinMode(LCD_PIN_D7, DIO_OUTPUT);
}

