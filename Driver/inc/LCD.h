/*
 * LCD.h
 *
 *  Created on: Aug 29, 2022
 *      Author: ahmad
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

enum {
    LCD_ONE_LINE,
    LCD_TWO_LINES
};
enum {
    LCD_DOTS_5X7,
    LCD_DOTS_5X10,    
};
enum {
    LCD_DISPLAY_OFF,
    LCD_DISPLAY_ON
};
enum {
    LCD_CURSOR_OFF,
    LCD_CURSOR_ON_BLINK,
    LCD_CURSOR_ON_NO_BLINK
};

/*Configuration*/


void LCD_Init(void);
void LCD_DisplayCharacter (u8 data);
void LCD_DisplayString (u8 *str);
void LCD_DisplayNumber (s32 number);
void LCD_SetCursorPosition(u8 row, u8 column);
void LCD_ShiftLeft (u8 counter);
void LCD_ShiftRight (u8 counter);
void LCD_Clear(void);
#endif /* INC_LCD_H_ */
