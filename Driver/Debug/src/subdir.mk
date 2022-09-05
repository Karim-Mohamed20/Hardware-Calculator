################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Calculator.c \
../src/DIO.c \
../src/Keypad.c \
../src/LCD.c \
../src/SSD.c 

OBJS += \
./src/Calculator.o \
./src/DIO.o \
./src/Keypad.o \
./src/LCD.o \
./src/SSD.o 

C_DEPS += \
./src/Calculator.d \
./src/DIO.d \
./src/Keypad.d \
./src/LCD.d \
./src/SSD.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Embedded\Work_Space\DIO_Keypad\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


