
#include<util/delay.h>
#include "macros.h"
#include "std_types.h"
#include "DIO.h"
#include "LCD_cfg.h"
#include "LCD.h"
#include "Calculator.h"
#include "Keypad.h"
#undef  F_CPU
#define F_CPU 8000000

int main (void) {
    Keypad_Init();
    LCD_Init();
    //Calculator_Run();
    Assignment_Calculator2_Run();
}
