

#ifndef INC_DIO_H_
#define INC_DIO_H_


/************ DIO Registers ************/
#define PORTA	*((volatile u8*)0x3B)
#define DDRA	*((volatile u8*)0x3A)
#define PINA	*((volatile u8*)0x39)

#define PORTB	*((volatile u8*)0x38)
#define DDRB	*((volatile u8*)0x37)
#define PINB	*((volatile u8*)0x36)

#define PORTC	*((volatile u8*)0x35)
#define DDRC	*((volatile u8*)0x34)
#define PINC	*((volatile u8*)0x33)

#define PORTD	*((volatile u8*)0x32)
#define DDRD	*((volatile u8*)0x31)
#define PIND	*((volatile u8*)0x30)

/************ DIO Types ************/
typedef enum {
    DIO_PORTA,
    DIO_PORTB,
    DIO_PORTC,
    DIO_PORTD
} DIO_PortType;


typedef enum {
    DIO_PIN0,
    DIO_PIN1,
    DIO_PIN2,
    DIO_PIN3,
    DIO_PIN4,
    DIO_PIN5,
    DIO_PIN6,
    DIO_PIN7,
} DIO_PinType;

typedef enum {
    DIO_INPUT_FLOATING,
    DIO_INPUT_PULLUP,
    DIO_OUTPUT
} DIO_ModeType;

typedef enum {
    DIO_LOW,
    DIO_HIGH
} DIO_LevelType;

/************ DIO Prototypes ************/
void DIO_SetPinMode             (DIO_PortType port, DIO_PinType pin, DIO_ModeType mode      );
void DIO_SetPortMode            (DIO_PortType port, DIO_ModeType mode                       );
void DIO_SetPinLevel            (DIO_PortType port, DIO_PinType pin, DIO_LevelType level    );
void DIO_SetPortLevel           (DIO_PortType port, DIO_LevelType level                     );
DIO_LevelType DIO_ReadPinLevel  (DIO_PortType port, DIO_PinType pin                         );
DIO_LevelType DIO_ReadPortLevel (DIO_PortType port                                          );

#endif /* INC_DIO_H_ */
