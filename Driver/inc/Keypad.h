/*
 * Keypad.h
 *
 *  Created on: Aug 30, 2022
 *      Author: ahmad
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

/***********************************************
*   B12   *   B13   *   B14   *   B15   *  ROW3*
*   B08   *   B09   *   B10   *   B11   *  ROW2*
*   B04   *   B05   *   B06   *   B07   *  ROW1*
*   B00   *   B01   *   B02   *   B03   *  ROW0*
* COLOMN0   COLUMN1   COLUMN2   COLUMN3 *      *
***********************************************/

#define KEYPAD_PIN_R0 DIO_PORTD,DIO_PIN0
#define KEYPAD_PIN_R1 DIO_PORTD,DIO_PIN1
#define KEYPAD_PIN_R2 DIO_PORTD,DIO_PIN2
#define KEYPAD_PIN_R3 DIO_PORTD,DIO_PIN3
#define KEYPAD_PIN_C0 DIO_PORTD,DIO_PIN4
#define KEYPAD_PIN_C1 DIO_PORTD,DIO_PIN5
#define KEYPAD_PIN_C2 DIO_PORTD,DIO_PIN6
#define KEYPAD_PIN_C3 DIO_PORTD,DIO_PIN7

typedef enum {
    KEYPAD_BUTTON00,
    KEYPAD_BUTTON01,
    KEYPAD_BUTTON02,
    KEYPAD_BUTTON03,
    KEYPAD_BUTTON04,
    KEYPAD_BUTTON05,
    KEYPAD_BUTTON06,
    KEYPAD_BUTTON07,
    KEYPAD_BUTTON08,
    KEYPAD_BUTTON09,
    KEYPAD_BUTTON10,
    KEYPAD_BUTTON11,
    KEYPAD_BUTTON12,
    KEYPAD_BUTTON13,
    KEYPAD_BUTTON14,
    KEYPAD_BUTTON15,
    KEYPAD_BUTTON_INVALID
} Keypad_ButtonType;

typedef enum {
    KEYPAD_STATE_PRESSED,
    KEYPAD_STATE_NOT_PRESSED
} Keypad_StateType;


void Keypad_Init(void);
Keypad_StateType Keypad_GetButtonState(Keypad_ButtonType button);
Keypad_StateType Keypad_GetButtonStatePooling(Keypad_ButtonType button);
Keypad_ButtonType Keypad_GetPressedButton(void);



#endif /* INC_KEYPAD_H_ */



