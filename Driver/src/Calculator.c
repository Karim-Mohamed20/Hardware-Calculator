/*
 * Calculator.c
 *
 *  Created on: Aug 30, 2022
 *      Author: ahmad
 */

#ifndef SRC_CALCULATOR_C_
#define SRC_CALCULATOR_C_

#include "std_types.h"
#include "macros.h"
#include "Keypad.h"
#include "LCD.h"
#include "Calculator.h"

static u8 Calculator_GetRealNumber (Keypad_ButtonType button);
static s32 TwoDigitAfterDecimalPoint (f32 number);
static u8 CheckPressedButton (Keypad_ButtonType pressed_button);
static u8 CheckPressedButton2 (Keypad_ButtonType pressed_button);

static s32 TwoDigitAfterDecimalPoint (f32 number) {
    s32 value = (s32)(number * 100 + .5);
    return value%100;
}

static u8 CheckPressedButton (Keypad_ButtonType pressed_button) {
    if (pressed_button == CALCULATOR_BUTTON_PLUS || pressed_button == CALCULATOR_BUTTON_MINUS || pressed_button == CALCULATOR_BUTTON_MUL || pressed_button == CALCULATOR_BUTTON_DIV) {
        return 1;
    }
    else {
        return 0;
    }
}

static u8 CheckPressedButton2 (Keypad_ButtonType pressed_button) {
    if (pressed_button == CALCULATOR_BUTTON_EQUAL) {
        return 1;
    }
    else {
        return 0;
    }
}

void Calculator_Run(void) {
    s8 num1=0, num2=0, operation=0, result=0;
    u8 num1_flag=0, num2_flag=0, operation_flag=0, result_flag=0;
    Keypad_ButtonType pressed_button;
    while (1)
    {
        /* Wait for user input */
        do {
            pressed_button = Keypad_GetPressedButton();
        }
        while (pressed_button == KEYPAD_BUTTON_INVALID);

        if (pressed_button == CALCULATOR_BUTTON_CLR) {
            num1_flag = 0;
            num2_flag = 0;
            operation_flag = 0;
            result_flag = 0;
            LCD_Clear();
            continue;
        }
        if (num1_flag == 0) {
            num1_flag = 1;
            num1 = Calculator_GetRealNumber(pressed_button);
            LCD_DisplayNumber(num1);
        }
        else if (operation_flag == 0) {
            operation_flag = 1;
            switch (pressed_button)
            {
            case CALCULATOR_BUTTON_PLUS:
                operation = '+';
                break;
            case CALCULATOR_BUTTON_MINUS:
                operation = '-';
                break;
            case CALCULATOR_BUTTON_MUL:
                operation = '*';
                break;
            case CALCULATOR_BUTTON_DIV:
                operation = '/';
                break;
            default:
                break;
            }
            LCD_DisplayCharacter(operation);
        }
        else if (num2_flag == 0) {
            num2_flag = 1;
            num2 = Calculator_GetRealNumber(pressed_button);
            LCD_DisplayNumber(num2);
        }
        else if (result_flag == 0) {
            if (pressed_button == CALCULATOR_BUTTON_EQUAL) {
                result_flag = 1;
                switch (operation)
                {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
                default:
                    break;
                }
                LCD_DisplayCharacter('=');
                LCD_SetCursorPosition(1,0);
                LCD_DisplayString((u8*)"Result = ");
                LCD_DisplayNumber(result);
            }
        }
    }   
}

void Assignment_Calculator_Run(void) {
    f32 num1=0, num2=0, result=0;
    s8 operation=0;
    u8 num1_flag=0, num2_flag=0, operation_flag=0, result_flag=0;
    Keypad_ButtonType pressed_button;
    while (1)
    {
        /* Wait for user input */
        do {
            pressed_button = Keypad_GetPressedButton();
        }
        while (pressed_button == KEYPAD_BUTTON_INVALID);

        if (pressed_button == CALCULATOR_BUTTON_CLR) {
            num1_flag = 0;
            num2_flag = 0;
            operation_flag = 0;
            result_flag = 0;
            num1=0;
            num2=0;
            result=0;
            LCD_Clear();
            continue;
        }
        if (num1_flag == 0) {
            if(CheckPressedButton(pressed_button) == 0) {
                f32 x = Calculator_GetRealNumber(pressed_button);
                num1=(num1*10)+x;
                LCD_DisplayNumber(x);
            }
            else if (CheckPressedButton(pressed_button) == 1){
                num1_flag=1;
                continue;
            }
        }
        else if (operation_flag == 0) {
            operation_flag = 1;
            switch (pressed_button)
            {
            case CALCULATOR_BUTTON_PLUS:
                operation = '+';
                break;
            case CALCULATOR_BUTTON_MINUS:
                operation = '-';
                break;
            case CALCULATOR_BUTTON_MUL:
                operation = '*';
                break;
            case CALCULATOR_BUTTON_DIV:
                operation = '/';
                break;
            default:
                break;
            }
            LCD_DisplayCharacter(operation);
        }
        else if (num2_flag == 0) {
            if(CheckPressedButton2(pressed_button) == 0) {
                f32 x = Calculator_GetRealNumber(pressed_button);
                num2=(num2*10)+x;
                LCD_DisplayNumber(x);
            }
            else if (CheckPressedButton2(pressed_button) == 1){
                num2_flag=1;
                continue;
            }
        }
        else if (result_flag == 0) {
            if (pressed_button == CALCULATOR_BUTTON_EQUAL) {
                result_flag = 1;
                switch (operation)
                {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    if (num2 == 0) {
                        LCD_SetCursorPosition(1,0);
                        LCD_DisplayString("Math Error");
                        continue;
                    }
                    result = num1 / num2;
                    s32 AfterDecimalPoint =TwoDigitAfterDecimalPoint(result);
                    LCD_DisplayCharacter('=');
                    LCD_SetCursorPosition(1,0);
                    LCD_DisplayString((u8*)"Result = ");
                    LCD_DisplayNumber(result);
                    LCD_DisplayCharacter('.');
                    LCD_DisplayNumber(AfterDecimalPoint);
                    continue;
                    break;
                default:
                    break;
                }
                LCD_DisplayCharacter('=');
                LCD_SetCursorPosition(1,0);
                LCD_DisplayString((u8*)"Result = ");
                LCD_DisplayNumber(result);
            }
        }
    }
}
static u8 Calculator_GetRealNumber (Keypad_ButtonType button) {
    u8 num = 0;
    switch (button)
    {
    case CALCULATOR_BUTTON_NUM0:
        num = 0;
        break;
    case CALCULATOR_BUTTON_NUM1:
        num = 1;
        break;
    case CALCULATOR_BUTTON_NUM2:
        num = 2;
        break;
    case CALCULATOR_BUTTON_NUM3:
        num = 3;
        break;
    case CALCULATOR_BUTTON_NUM4:
        num = 4;
        break;
    case CALCULATOR_BUTTON_NUM5:
        num = 5;
        break;
    case CALCULATOR_BUTTON_NUM6:
        num = 6;
        break;
    case CALCULATOR_BUTTON_NUM7:
        num = 7;
        break;
    case CALCULATOR_BUTTON_NUM8:
        num = 8;
        break;
    case CALCULATOR_BUTTON_NUM9:
        num = 9;
        break;
    default:
        break;
    }
    return num;
}

void Assignment_Calculator2_Run(void) {
    f32 num1=0, num2=0, result=0;
    s8 operation=0;
    u8 num1_flag=0, num2_flag=0, operation_flag=0, result_flag=0;
    Keypad_ButtonType pressed_button;
    while (1)
    {
        /* Wait for user input */
        do {
            pressed_button = Keypad_GetPressedButton();
        }
        while (pressed_button == KEYPAD_BUTTON_INVALID);

        if (pressed_button == CALCULATOR_BUTTON_CLR) {
        	num1_flag = 0;
			num2_flag = 0;
			operation_flag = 0;
			result_flag = 0;
			num1=0;
			num2=0;
			result=0;
			LCD_Clear();
			continue;
        }
        if (num1_flag == 0 && (CheckPressedButton(pressed_button) == 0)) {
            f32 x = Calculator_GetRealNumber(pressed_button);
            num1=(num1*10)+x;
            LCD_DisplayNumber(x);
        }
        else if (operation_flag == 0) {
            num1_flag=1;
            operation_flag = 1;
            switch (pressed_button)
            {
            case CALCULATOR_BUTTON_PLUS:
                operation = '+';
                break;
            case CALCULATOR_BUTTON_MINUS:
                operation = '-';
                break;
            case CALCULATOR_BUTTON_MUL:
                operation = '*';
                break;
            case CALCULATOR_BUTTON_DIV:
                operation = '/';
                break;
            default:
                break;
            }
            LCD_DisplayCharacter(operation);
        }
        else if (num2_flag == 0 && (CheckPressedButton2(pressed_button) == 0)) {
                f32 x = Calculator_GetRealNumber(pressed_button);
                num2=(num2*10)+x;
                LCD_DisplayNumber(x);
        }
        else if (result_flag == 0) {
            if (pressed_button == CALCULATOR_BUTTON_EQUAL) {
                num2_flag=1;
                result_flag = 1;
                switch (operation)
                {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    if (num2 == 0) {
                        LCD_SetCursorPosition(1,0);
                        LCD_DisplayString("Math Error");
                        continue;
                    }
                    result = num1 / num2;
                    s32 AfterDecimalPoint =TwoDigitAfterDecimalPoint(result);
                    LCD_DisplayCharacter('=');
                    LCD_SetCursorPosition(1,0);
                    LCD_DisplayString((u8*)"Result = ");
                    LCD_DisplayNumber(result);
                    LCD_DisplayCharacter('.');
                    LCD_DisplayNumber(AfterDecimalPoint);
                    continue;
                    break;
                default:
                    break;
                }
                LCD_DisplayCharacter('=');
                LCD_SetCursorPosition(1,0);
                LCD_DisplayString((u8*)"Result = ");
                LCD_DisplayNumber(result);
            }
        }
    }
}

#endif /* SRC_CALCULATOR_C_ */
