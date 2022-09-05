/*
 * Keypad.c
 *
 *  Created on: Aug 30, 2022
 *      Author: ahmad
 */
#include "std_types.h"
#include "macros.h"
#include "DIO.h"
#include "Keypad.h"

void Keypad_Init(void) {
    /* Set all rows to input pullup */
    DIO_SetPinMode(KEYPAD_PIN_R0, DIO_INPUT_PULLUP);
    DIO_SetPinMode(KEYPAD_PIN_R1, DIO_INPUT_PULLUP);
    DIO_SetPinMode(KEYPAD_PIN_R2, DIO_INPUT_PULLUP);
    DIO_SetPinMode(KEYPAD_PIN_R3, DIO_INPUT_PULLUP);
    /* Set all columns to output */
    DIO_SetPinMode(KEYPAD_PIN_C0, DIO_OUTPUT);
    DIO_SetPinMode(KEYPAD_PIN_C1, DIO_OUTPUT);
    DIO_SetPinMode(KEYPAD_PIN_C2, DIO_OUTPUT);
    DIO_SetPinMode(KEYPAD_PIN_C3, DIO_OUTPUT);
}


/*
1. Set all columns to high
2. Set current column to low
3. Read current row 
	high -> Not Pressed
	low  -> Pressed

*/


Keypad_StateType Keypad_GetButtonState(Keypad_ButtonType button) {
    Keypad_StateType state = KEYPAD_STATE_NOT_PRESSED;
    u8 row = button / 4;
    u8 column = button % 4;
    DIO_SetPinLevel(KEYPAD_PIN_C0, DIO_HIGH);
    DIO_SetPinLevel(KEYPAD_PIN_C1, DIO_HIGH);
    DIO_SetPinLevel(KEYPAD_PIN_C2, DIO_HIGH);
    DIO_SetPinLevel(KEYPAD_PIN_C3, DIO_HIGH);
    switch (column)
    {
    case 0:
        DIO_SetPinLevel(KEYPAD_PIN_C0, DIO_LOW);
        break;
    case 1:
        DIO_SetPinLevel(KEYPAD_PIN_C1, DIO_LOW);
        break;
    case 2:
        DIO_SetPinLevel(KEYPAD_PIN_C2, DIO_LOW);
        break;
    case 3:
        DIO_SetPinLevel(KEYPAD_PIN_C3, DIO_LOW);
        break;
    default:
        break;
    }
    switch (row)
    {
    case 0:
        if (DIO_ReadPinLevel(KEYPAD_PIN_R0) == DIO_LOW) {
            state = KEYPAD_STATE_PRESSED;
        }
        break;
    case 1:
        if (DIO_ReadPinLevel(KEYPAD_PIN_R1) == DIO_LOW) {
            state = KEYPAD_STATE_PRESSED;
        }
        break;
    case 2:
        if (DIO_ReadPinLevel(KEYPAD_PIN_R2) == DIO_LOW) {
            state = KEYPAD_STATE_PRESSED;
        }
        break;
    case 3:
        if (DIO_ReadPinLevel(KEYPAD_PIN_R3) == DIO_LOW) {
            state = KEYPAD_STATE_PRESSED;
        }
        break;
    default:
        break;
    }
    return state;
}

Keypad_StateType Keypad_GetButtonStatePooling(Keypad_ButtonType button) {
    Keypad_StateType state = KEYPAD_STATE_NOT_PRESSED;
    u8 row = button / 4;
    u8 column = button % 4;
    DIO_SetPinLevel(KEYPAD_PIN_C0, DIO_HIGH);
    DIO_SetPinLevel(KEYPAD_PIN_C1, DIO_HIGH);
    DIO_SetPinLevel(KEYPAD_PIN_C2, DIO_HIGH);
    DIO_SetPinLevel(KEYPAD_PIN_C3, DIO_HIGH);
    switch (column)
    {
    case 0:
        DIO_SetPinLevel(KEYPAD_PIN_C0, DIO_LOW);
        break;
    case 1:
        DIO_SetPinLevel(KEYPAD_PIN_C1, DIO_LOW);
        break;
    case 2:
        DIO_SetPinLevel(KEYPAD_PIN_C2, DIO_LOW);
        break;
    case 3:
        DIO_SetPinLevel(KEYPAD_PIN_C3, DIO_LOW);
        break;
    default:
        break;
    }
    switch (row)
    {
    case 0:
        if (DIO_ReadPinLevel(KEYPAD_PIN_R0) == DIO_LOW) {
            state = KEYPAD_STATE_PRESSED;
            while (DIO_ReadPinLevel(KEYPAD_PIN_R0) == DIO_LOW);
        }
        break;
    case 1:
        if (DIO_ReadPinLevel(KEYPAD_PIN_R1) == DIO_LOW) {
            state = KEYPAD_STATE_PRESSED;
            while (DIO_ReadPinLevel(KEYPAD_PIN_R1) == DIO_LOW);
        }
        break;
    case 2:
        if (DIO_ReadPinLevel(KEYPAD_PIN_R2) == DIO_LOW) {
            state = KEYPAD_STATE_PRESSED;
            while (DIO_ReadPinLevel(KEYPAD_PIN_R2) == DIO_LOW);
        }
        break;
    case 3:
        if (DIO_ReadPinLevel(KEYPAD_PIN_R3) == DIO_LOW) {
            state = KEYPAD_STATE_PRESSED;
            while (DIO_ReadPinLevel(KEYPAD_PIN_R3) == DIO_LOW);
        }
        break;
    default:
        break;
    }
    return state;
}


Keypad_ButtonType Keypad_GetPressedButton(void) {
    u8 i=0;
    Keypad_ButtonType pressed_button = KEYPAD_BUTTON_INVALID;
    for (i=0; i<16; i++) {
        if (Keypad_GetButtonStatePooling(i) == KEYPAD_STATE_PRESSED) {
            pressed_button = i;
            break;
        }
    }
    return pressed_button;
}
