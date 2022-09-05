#include "std_types.h"
#include "macros.h"
#include "DIO.h"

void DIO_SetPinMode(DIO_PortType port, DIO_PinType pin, DIO_ModeType mode) {
    if (mode == DIO_INPUT_FLOATING) 
    {
        switch (port)
        {
        case DIO_PORTA:
            CLR_BIT(DDRA, pin);
            CLR_BIT(PORTA, pin);
            break;
        case DIO_PORTB:
            CLR_BIT(DDRB, pin);
            CLR_BIT(PORTB, pin);
            break;
        case DIO_PORTC:
            CLR_BIT(DDRC, pin);
            CLR_BIT(PORTC, pin);
            break;
        case DIO_PORTD:
            CLR_BIT(DDRD, pin);
            CLR_BIT(PORTD, pin);
            break;
        default:
            break;
        }
    }
    else if (mode == DIO_INPUT_PULLUP) 
    {
        switch (port)
        {
        case DIO_PORTA:
            CLR_BIT(DDRA, pin);
            SET_BIT(PORTA, pin);
            break;
        case DIO_PORTB:
            CLR_BIT(DDRB, pin);
            SET_BIT(PORTB, pin);
            break;
        case DIO_PORTC:
            CLR_BIT(DDRC, pin);
            SET_BIT(PORTC, pin);
            break;
        case DIO_PORTD:
            CLR_BIT(DDRD, pin);
            SET_BIT(PORTD, pin);
            break;
        default:
            break;
        }
    }
    else if (mode == DIO_OUTPUT) 
    {
        switch (port)
        {
        case DIO_PORTA:
            SET_BIT(DDRA, pin);
            break;
        case DIO_PORTB:
            SET_BIT(DDRB, pin);
            break;
        case DIO_PORTC:
            SET_BIT(DDRC, pin);
            break;
        case DIO_PORTD:
            SET_BIT(DDRD, pin);
            break;
        default:
            break;
        }

    }
}

void DIO_SetPortMode(DIO_PortType port, DIO_ModeType mode) {
    if (mode == DIO_INPUT_FLOATING) 
    {
        switch (port)
        {
        case DIO_PORTA:
            DDRA = 0x00;
            PORTA = 0x00;
            break;
        case DIO_PORTB:
            DDRB = 0x00;
            PORTB = 0x00;
            break;
        case DIO_PORTC:
            DDRC = 0x00;
            PORTC = 0x00;
            break;
        case DIO_PORTD:
            DDRD = 0x00;
            PORTD = 0x00;
            break;
        default:
            break;
        }
    }
    else if (mode == DIO_INPUT_PULLUP) 
    {
        switch (port)
        {
        case DIO_PORTA:
            DDRA = 0x00;
            PORTA = 0xFF;
            break;
        case DIO_PORTB:
            DDRB = 0x00;
            PORTB = 0xFF;
            break;
        case DIO_PORTC:
            DDRC = 0x00;
            PORTC = 0xFF;
            break;
        case DIO_PORTD:
            DDRD = 0x00;
            PORTD = 0xFF;
            break;
        default:
            break;
        }
    }
    else if (mode == DIO_OUTPUT) 
    {
        switch (port)
        {
        case DIO_PORTA:
            DDRA = 0xFF;
            break;
        case DIO_PORTB:
            DDRB = 0xFF;
            break;
        case DIO_PORTC:
            DDRC = 0xFF;
            break;
        case DIO_PORTD:
            DDRD = 0xFF;
            break;
        default:
            break;
        }

    }
    else
    {
        switch (port)
        {
        case DIO_PORTA:
            DDRA = mode;
            break;
        case DIO_PORTB:
            DDRB = mode;
            break;
        case DIO_PORTC:
            DDRC = mode;
            break;
        case DIO_PORTD:
            DDRD = mode;
            break;
        default:
            break;
        }

    }
}


void DIO_SetPinLevel(DIO_PortType port, DIO_PinType pin, DIO_LevelType level) {
    if (level == DIO_HIGH) 
    {
        switch (port)
        {
        case DIO_PORTA:
            SET_BIT(PORTA, pin);
            break;
        case DIO_PORTB:
            SET_BIT(PORTB, pin);
            break;
        case DIO_PORTC:
            SET_BIT(PORTC, pin);
            break;
        case DIO_PORTD:
            SET_BIT(PORTD, pin);
            break;
        default:
            break;
        }
    }
    else if (level == DIO_LOW) 
    {
        switch (port)
        {
        case DIO_PORTA:
            CLR_BIT(PORTA, pin);
            break;
        case DIO_PORTB:
            CLR_BIT(PORTB, pin);
            break;
        case DIO_PORTC:
            CLR_BIT(PORTC, pin);
            break;
        case DIO_PORTD:
            CLR_BIT(PORTD, pin);
            break;
        default:
            break;
        }
    }
}

void DIO_SetPortLevel (DIO_PortType port, DIO_LevelType level) {
    if (level == DIO_HIGH) {
        switch (port)
        {
        case DIO_PORTA:
            PORTA = 0xFF;
            break;
        case DIO_PORTB:
            PORTB = 0xFF;
            break;
        case DIO_PORTC:
            PORTC = 0xFF;
            break;
        case DIO_PORTD:
            PORTD = 0xFF;
            break;
        default:
            break;
        }
    }
    else if (level == DIO_LOW) {
        switch (port)
        {
        case DIO_PORTA:
            PORTA = 0x00;
            break;
        case DIO_PORTB:
            PORTB = 0x00;
            break;
        case DIO_PORTC:
            PORTC = 0x00;
            break;
        case DIO_PORTD:
            PORTD = 0x00;
            break;
        default:
            break;
        }
    }
    else {
        switch (port)
        {
        case DIO_PORTA:
            PORTA = level;
            break;
        case DIO_PORTB:
            PORTB = level;
            break;
        case DIO_PORTC:
            PORTC = level;
            break;
        case DIO_PORTD:
            PORTD = level;
            break;
        default:
            break;
        }

    }
}



DIO_LevelType DIO_ReadPinLevel(DIO_PortType port, DIO_PinType pin) {
    DIO_LevelType result = DIO_LOW;
    switch (port)
    {
    case DIO_PORTA:
        result = GET_BIT(PINA, pin);
        break;
    case DIO_PORTB:
        result = GET_BIT(PINB, pin);
        break;
    case DIO_PORTC:
        result = GET_BIT(PINC, pin);
        break;
    case DIO_PORTD:
        result = GET_BIT(PIND, pin);
        break;
    default:
        break;
    }
    return result;
}

DIO_LevelType DIO_ReadPortLevel (DIO_PortType port) {
    u8 result = 0x00;
    switch (port)
    {
    case DIO_PORTA:
        if (PINA == 0xFF) {
            result = DIO_HIGH;
        }
        else if (PINA == 0x00) {
            result = DIO_LOW;
        }
        else {
            result = PINA;
        }
        break;
    case DIO_PORTB:
        if (PINB == 0xFF) {
            result = DIO_HIGH;
        }
        else if (PINB == 0x00) {
            result = DIO_LOW;
        }
        else {
            result = PINB;
        }
        break;
    case DIO_PORTC:
        if (PINC == 0xFF) {
            result = DIO_HIGH;
        }
        else if (PINC == 0x00) {
            result = DIO_LOW;
        }
        else {
            result = PINC;
        }
        break;
    case DIO_PORTD:
        if (PIND == 0xFF) {
            result = DIO_HIGH;
        }
        else if (PIND == 0x00) {
            result = DIO_LOW;
        }
        else {
            result = PIND;
        }
        break;
    default:
        break;
    }
    return result;
}
