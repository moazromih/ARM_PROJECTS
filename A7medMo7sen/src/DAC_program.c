/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   02 June, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"

void HDAC_voidInit(void)
{
    u8 Local_u8LoopCounter;
    for(Local_u8LoopCounter = STARTING_PIN; Local_u8LoopCounter < STARTING_PIN + NUMBER_OF_PINS; Local_u8LoopCounter++)
    {
        MGPIO_voidSetPinMode(DAC_PORT,Local_u8LoopCounter,OUTPUT);
        MGPIO_voidSetOutputType(DAC_PORT,Local_u8LoopCounter,PUSH_PULL);
        MGPIO_voidSetOutputSpeed(DAC_PORT,Local_u8LoopCounter,LOW_SPEED);
    }
}

void HDAC_voidSendData(u32 Copy_u32Data)
{
    MGPIO_voidSetPortSpecificValue(DAC_PORT,STARTING_PIN,NUMBER_OF_PINS,Copy_u32Data);
}