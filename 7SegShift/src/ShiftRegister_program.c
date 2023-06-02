/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   01 June, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "ShiftRegister_Interface.h"
#include "ShiftRegister_private.h"
#include "ShiftRegister_config.h"

void HShiftRegister_voidInit(void)
{
    /* Configure A PIN */
    MGPIO_voidSetPinMode(SR_A_PORT,SR_A_PIN,OUTPUT);
    MGPIO_voidSetOutputType(SR_A_PORT,SR_A_PIN,PUSH_PULL);
    MGPIO_voidSetOutputSpeed(SR_A_PORT,SR_A_PIN,LOW_SPEED);
    /* Configure Shift Clock CLK PIN */
    MGPIO_voidSetPinMode(SR_SHIFT_CLK_PORT,SR_SHIFT_CLK_PIN,OUTPUT);
    MGPIO_voidSetOutputType(SR_SHIFT_CLK_PORT,SR_SHIFT_CLK_PIN,PUSH_PULL);
    MGPIO_voidSetOutputSpeed(SR_SHIFT_CLK_PORT,SR_SHIFT_CLK_PIN,LOW_SPEED);
    /* Configure ShiftRegister1 Latch CLK PIN */
    MGPIO_voidSetPinMode(SR1_LATCH_CLK_PORT,SR1_LATCH_CLK_PIN,OUTPUT);
    MGPIO_voidSetOutputType(SR1_LATCH_CLK_PORT,SR1_LATCH_CLK_PIN,PUSH_PULL);
    MGPIO_voidSetOutputSpeed(SR1_LATCH_CLK_PORT,SR1_LATCH_CLK_PIN,LOW_SPEED);
    /* Configure ShiftRegister2 Latch CLK PIN */
    MGPIO_voidSetPinMode(SR2_LATCH_CLK_PORT,SR2_LATCH_CLK_PIN,OUTPUT);
    MGPIO_voidSetOutputType(SR2_LATCH_CLK_PORT,SR2_LATCH_CLK_PIN,PUSH_PULL);
    MGPIO_voidSetOutputSpeed(SR2_LATCH_CLK_PORT,SR2_LATCH_CLK_PIN,LOW_SPEED);

}


void HShiftRegister_voidSend1ByteDataLow(u8 Copy_u8Data)
{
    s8 Local_s8LoopCounter;
    for (Local_s8LoopCounter = ONE_BYTE; Local_s8LoopCounter >= ZERO; Local_s8LoopCounter--)
    {
        MGPIO_voidSetPinValue(SR_A_PORT,SR_A_PIN,GET_BIT(Copy_u8Data,Local_s8LoopCounter));
        MGPIO_voidSetPinValue(SR_SHIFT_CLK_PORT,SR_SHIFT_CLK_PIN,HIGH);
        MSTK_voidSetBusyWaitus(1);
        MGPIO_voidSetPinValue(SR_SHIFT_CLK_PORT,SR_SHIFT_CLK_PIN,LOW);
        MSTK_voidSetBusyWaitus(1);
    }
    MGPIO_voidSetPinValue(SR1_LATCH_CLK_PORT,SR1_LATCH_CLK_PIN,HIGH);
    MSTK_voidSetBusyWaitus(1);
    MGPIO_voidSetPinValue(SR1_LATCH_CLK_PORT,SR1_LATCH_CLK_PIN,LOW);
    MSTK_voidSetBusyWaitus(1);
}

void HShiftRegister_voidSend1ByteDataHigh(u8 Copy_u8Data)
{
    s8 Local_s8LoopCounter;
    for (Local_s8LoopCounter = ONE_BYTE; Local_s8LoopCounter >= ZERO; Local_s8LoopCounter--)
    {
        MGPIO_voidSetPinValue(SR_A_PORT,SR_A_PIN,GET_BIT(Copy_u8Data,Local_s8LoopCounter));
        MGPIO_voidSetPinValue(SR_SHIFT_CLK_PORT,SR_SHIFT_CLK_PIN,HIGH);
        MSTK_voidSetBusyWaitus(1);
        MGPIO_voidSetPinValue(SR_SHIFT_CLK_PORT,SR_SHIFT_CLK_PIN,LOW);
        MSTK_voidSetBusyWaitus(1);
    }
    for (Local_s8LoopCounter = ONE_BYTE; Local_s8LoopCounter >= ZERO; Local_s8LoopCounter--)
    {
        MGPIO_voidSetPinValue(SR_SHIFT_CLK_PORT,SR_SHIFT_CLK_PIN,HIGH);
        MSTK_voidSetBusyWaitus(1);
        MGPIO_voidSetPinValue(SR_SHIFT_CLK_PORT,SR_SHIFT_CLK_PIN,LOW);
        MSTK_voidSetBusyWaitus(1);
    }
    MGPIO_voidSetPinValue(SR2_LATCH_CLK_PORT,SR2_LATCH_CLK_PIN,HIGH);
    MSTK_voidSetBusyWaitus(1);
    MGPIO_voidSetPinValue(SR2_LATCH_CLK_PORT,SR2_LATCH_CLK_PIN,LOW);
    MSTK_voidSetBusyWaitus(1);
}


void HshiftRegister_voidSend2ByteData(u16 Copy_u16Data)
{
    s8 Local_s8LoopCounter;
    for (Local_s8LoopCounter = TWO_BYTES; Local_s8LoopCounter >= ZERO; Local_s8LoopCounter--)
    {
        MGPIO_voidSetPinValue(SR_A_PORT,SR_A_PIN,GET_BIT(Copy_u16Data,Local_s8LoopCounter));
        MGPIO_voidSetPinValue(SR_SHIFT_CLK_PORT,SR_SHIFT_CLK_PIN,HIGH);
        MSTK_voidSetBusyWaitus(1);
        MGPIO_voidSetPinValue(SR_SHIFT_CLK_PORT,SR_SHIFT_CLK_PIN,LOW);
        MSTK_voidSetBusyWaitus(1);
    }
    MGPIO_voidSetPinValue(SR1_LATCH_CLK_PORT,SR1_LATCH_CLK_PIN,HIGH);
    MGPIO_voidSetPinValue(SR2_LATCH_CLK_PORT,SR2_LATCH_CLK_PORT,HIGH);
    MSTK_voidSetBusyWaitus(1);
    MGPIO_voidSetPinValue(SR1_LATCH_CLK_PORT,SR1_LATCH_CLK_PIN,LOW);
    MGPIO_voidSetPinValue(SR2_LATCH_CLK_PORT,SR2_LATCH_CLK_PORT,LOW);
    MSTK_voidSetBusyWaitus(1);
}
