/*
 * LCD_cfg.h
 *
 *  Created on: Aug 29, 2022
 *      Author: ahmad
 */

#ifndef INC_LCD_CFG_H_
#define INC_LCD_CFG_H_

/* LCD Control Pins */
#define LCD_PIN_RS  DIO_PORTB,DIO_PIN2
#define LCD_PIN_RW  DIO_PORTB,DIO_PIN1
#define LCD_PIN_E   DIO_PORTB,DIO_PIN0

/* LCD Data Pins */
#define LCD_PIN_D0  DIO_PORTA,DIO_PIN7
#define LCD_PIN_D1  DIO_PORTA,DIO_PIN6
#define LCD_PIN_D2  DIO_PORTA,DIO_PIN5
#define LCD_PIN_D3  DIO_PORTA,DIO_PIN4
#define LCD_PIN_D4  DIO_PORTA,DIO_PIN3
#define LCD_PIN_D5  DIO_PORTA,DIO_PIN2
#define LCD_PIN_D6  DIO_PORTA,DIO_PIN1
#define LCD_PIN_D7  DIO_PORTA,DIO_PIN0

/* Options:
    LCD_ONE_LINE
    LCD_TWO_LINES
*/
#define LCD_MODE_LINES      LCD_TWO_LINES
/* Options:
    LCD_DOTS_5X7
    LCD_DOTS_5X10
*/
#define LCD_MODE_DOTS       LCD_DOTS_5X7
/* Options:
    LCD_DISPLAY_OFF,
    LCD_DISPLAY_ON
*/
#define LCD_MODE_DISPLAY    LCD_DISPLAY_ON
/* Options:
    LCD_CURSOR_OFF
    LCD_CURSOR_ON_BLINK
    LCD_CURSOR_ON_NO_BLINK
*/
#define LCD_MODE_CURSOR     LCD_CURSOR_OFF


#endif /* INC_LCD_CFG_H_ */
