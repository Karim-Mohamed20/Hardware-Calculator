


#include "std_types.h"
#include "macros.h"
#include "DIO.h"
#include "SSD.h"

	/*DDRD = 0xFF;
	PORTD = 0b00111111; // Print 0
	_delay_ms(500);
	PORTD = 0b00000110; // Print 1
	_delay_ms(500);
	PORTD = 0b01011011; // Print 2
	_delay_ms(500);
	PORTD = 0b01001111; // Print 3
	_delay_ms(500);
	PORTD = 0b01100110; // Print 4
	_delay_ms(500);
	PORTD = 0b01101101; // Print 5
	_delay_ms(500);
	PORTD = 0b01111101; // Print 6
	_delay_ms(500);
	PORTD = 0b00000111; // Print 7
	_delay_ms(500);
	PORTD = 0b01111111; // Print 8
	_delay_ms(500);
	PORTD = 0b01101111; // Print 9
	_delay_ms(500);
	PORTD = 0b00000000; // off*/

void SSD_Init(void) {
    DIO_SetPinMode(SSD_PIN_A, DIO_OUTPUT);
    DIO_SetPinMode(SSD_PIN_B, DIO_OUTPUT);
    DIO_SetPinMode(SSD_PIN_C, DIO_OUTPUT);
    DIO_SetPinMode(SSD_PIN_D, DIO_OUTPUT);
    DIO_SetPinMode(SSD_PIN_E, DIO_OUTPUT);
    DIO_SetPinMode(SSD_PIN_F, DIO_OUTPUT);
    DIO_SetPinMode(SSD_PIN_G, DIO_OUTPUT);

}
void SSD_Write (SSD_NumberType number) {
    switch (number)
    {

    case SSD_NUMBER_0: // 0b00111111
    #if SSD_TYPE == COMM_CATHODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
    #elif SSD_TYPE == COMM_ANODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
    #else 
        #error "Invalid SSD Type"
    #endif
        break;

    case SSD_NUMBER_1: // 0b00000110
    #if SSD_TYPE == COMM_CATHODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
    #elif SSD_TYPE == COMM_ANODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
    #else 
        #error "Invalid SSD Type"
    #endif
        break;

    case SSD_NUMBER_2: // 0b01011011
	#if SSD_TYPE == COMM_CATHODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
    #elif SSD_TYPE == COMM_ANODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
    #else
        #error "Invalid SSD Type"
    #endif
        break;

    case SSD_NUMBER_3: // 0b01001111
	#if SSD_TYPE == COMM_CATHODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
    #elif SSD_TYPE == COMM_ANODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
    #else
        #error "Invalid SSD Type"
    #endif
        break;

    case SSD_NUMBER_4: // 0b01100110
	#if SSD_TYPE == COMM_CATHODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
    #elif SSD_TYPE == COMM_ANODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
    #else
        #error "Invalid SSD Type"
    #endif
        break;

    case SSD_NUMBER_5: // 0b01101101
	#if SSD_TYPE == COMM_CATHODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
    #elif SSD_TYPE == COMM_ANODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
    #else
        #error "Invalid SSD Type"
    #endif
        break;

    case SSD_NUMBER_6: // 0b01111101
	#if SSD_TYPE == COMM_CATHODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
    #elif SSD_TYPE == COMM_ANODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
    #else
        #error "Invalid SSD Type"
    #endif
        break;

    case SSD_NUMBER_7: // 0b00000111
	#if SSD_TYPE == COMM_CATHODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
    #elif SSD_TYPE == COMM_ANODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
    #else
        #error "Invalid SSD Type"
    #endif
        break;

    case SSD_NUMBER_8: // 0b01111111
	#if SSD_TYPE == COMM_CATHODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
    #elif SSD_TYPE == COMM_ANODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
    #else
        #error "Invalid SSD Type"
    #endif
        break;

    case SSD_NUMBER_9: // 0b01101111
	#if SSD_TYPE == COMM_CATHODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
    #elif SSD_TYPE == COMM_ANODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
    #else
        #error "Invalid SSD Type"
    #endif
        break;

    case SSD_OFF:
    default:
    #if SSD_TYPE == COMM_CATHODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_B, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_C, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_D, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_E, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_F, DIO_LOW);
        DIO_SetPinLevel(SSD_PIN_G, DIO_LOW);
    #elif SSD_TYPE == COMM_ANODE
        DIO_SetPinLevel(SSD_PIN_A, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_B, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_C, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_D, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_E, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_F, DIO_HIGH);
        DIO_SetPinLevel(SSD_PIN_G, DIO_HIGH);
    #else 
        #error "Invalid SSD Type"
    #endif
        break;
    }
}



