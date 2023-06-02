/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   26 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "STK_interface.h"
#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"

#include "IR_Sensor_interface.h"
#include "IR_Sensor_private.h"
#include "IR_Sensor_config.h"

static s8 IR_SENSOR_u8EdgeCounter = RESET;
static u32 IR_SENSOR_u32ReceivedFrame[FRAME_SIZE] = {RESET};
static void (* IR_SENSOR_pvActionFunction)(u8) = NULL;
static u8 IR_SENSOR_u8ButtonData = RESET;
static u8 IR_SENSOR_u8StartEdge = RESET;

/* Set the call back Function before Initialization */
void HIR_SENSOR_voidInit()
{
    MRCC_voidInit();
    MSTK_voidInit();
    MRCC_voidEnablePeripheralClock(RCC_AHB1,GPIOA_ID);
    MGPIO_voidSetPinMode(GPIOA,IR_SENSOR_LINE,INPUT);
    MGPIO_voidSetInputConnectionType(GPIOA,IR_SENSOR_LINE,PULLUP);
    MEXTI_voidInit();
    MEXTI_voidSetTrigger(IR_SENSOR_LINE,EXTI_FALLING_EDGE);
    MEXTI_voidSetCallBack(IR_SENSOR_LINE,&HIR_SENSOR_voidReceiveFrame);
    MEXTI_voidEnableEXTILineInterrupt(IR_SENSOR_LINE);
    MNVIC_voidInit();
    MNVIC_voidEnablePeripheralInterrput(MNIVC_EXTI0);
}



void HIR_SENSOR_voidSetActionFunction(void (*pvoidNotificationFunction(u8)))
{
    IR_SENSOR_pvActionFunction = pvoidNotificationFunction;
}

void HIR_SENSOR_voidReceiveFrame(void)
{
    if(IR_SENSOR_u8StartEdge == RESET)
    {
        MSTK_voidSetSingleInterval(READING_DELAY,&HIR_SENSOR_voidGetPressedKey);
        IR_SENSOR_u8StartEdge = SET;
    }
    else
    {
    /*Get the counted time & Increment the counter */
    IR_SENSOR_u32ReceivedFrame[IR_SENSOR_u8EdgeCounter] = MSTK_u32GetElapsedTime();
    IR_SENSOR_u8EdgeCounter++;
    /*Reset The Timer, Set PreLoad Value*/
    MSTK_voidSetSingleInterval(READING_DELAY,&HIR_SENSOR_voidGetPressedKey);
    }
}

void HIR_SENSOR_voidGetPressedKey(void)
{
	u8 Local_u8LoopCounter;
	for(Local_u8LoopCounter = LOOP_START; Local_u8LoopCounter < DATA_SIZE; Local_u8LoopCounter++)
	{
		if((IR_SENSOR_u32ReceivedFrame[DATA_INDEX+Local_u8LoopCounter] >= ZERO_MIN_TIME) && (IR_SENSOR_u32ReceivedFrame[DATA_INDEX+Local_u8LoopCounter] <= ZERO_MAX_TIME))
		{
			CLR_BIT(IR_SENSOR_u8ButtonData, Local_u8LoopCounter);
		}
		else
		{
			SET_BIT(IR_SENSOR_u8ButtonData, Local_u8LoopCounter);
		}
	}
	IR_SENSOR_u8EdgeCounter = RESET;
    IR_SENSOR_u8StartEdge = RESET;
    if(IR_SENSOR_pvActionFunction != NULL)
    {
        IR_SENSOR_pvActionFunction(IR_SENSOR_u8ButtonData);
    }
}
