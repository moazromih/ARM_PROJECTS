/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   09 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


void MSTK_voidInit(void)
{
	/* Reset the CTRL Register */
	STK->CTRL = 0;
    /* Set the Prescaler */
    STK->CTRL |= (STK_CLK<<STK_CTRL_CLKSOURCE);

    /* Set the Load initial Value */
    STK->LOAD |= STK_INIT_LOAD_VALUE;

    /* Enable/Disable the Interrupt */
    STK->CTRL |= (STK_INT_MODE<<STK_CTRL_TICKINT);

    /* Enable the Timer */
    STK->CTRL |= (STK_ENABLE_DISABLE<<STK_CTRL_ENABLE);
}


void MSTK_voidEnableSTK(void)
{
    SET_BIT(STK->CTRL,STK_CTRL_ENABLE);
}


void MSTK_voidDisableSTK(void)
{
    CLR_BIT(STK->CTRL,STK_CTRL_ENABLE);
}


void MSTK_voidEnableInterrupt(void)
{
    SET_BIT(STK->CTRL,STK_CTRL_TICKINT);
}


void MSTK_voidDisableInterrupt(void)
{
    CLR_BIT(STK->CTRL,STK_CTRL_TICKINT);
}


u32 MSTK_u32GetElapsedTime(void)
{
    u32 Local_u32ElapsedTime;
    Local_u32ElapsedTime = STK->LOAD - STK->VAL;
    return Local_u32ElapsedTime;
}


u32 MSTK_u32GetRemainingTime(void)
{
    u32 Local_u32RemainingTime;
    Local_u32RemainingTime = STK->VAL;
    return Local_u32RemainingTime;
}

void MSTK_voidSetBusyWaitus(u32 Copy_u32usec)
{
    u32 Local_u32FullLoops = Copy_u32usec / FULL_LOOP;
    u32 Local_u32PartialLoop =  Copy_u32usec % FULL_LOOP;
    STK->LOAD = Local_u32PartialLoop;
    while (GET_BIT(STK->CTRL,STK_CTRL_COUNTFLAG) == 0);
    while (Local_u32FullLoops > 0)
    {
    	STK->LOAD = FULL_LOOP;
        while (GET_BIT(STK->CTRL,STK_CTRL_COUNTFLAG) == 0);
        Local_u32FullLoops--;
    }
    STK->VAL = 0;
}

void MSTK_voidSetLoadValue(u32 Copy_u32Value)
{
    STK -> LOAD = Copy_u32Value;
}



/**********************************************************************************************************/
/* Interrupt Functions */

void (*pvCallBackFunction)(void) = NULL;
static u8 u8IntervalFlag = SINGLE_INTERVAL;


void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks, void (*pvNotificationFunction)(void))
{
    MSTK_voidDisableSTK();
    STK -> VAL = RESET;
    STK -> LOAD = Copy_u32Ticks;
    pvCallBackFunction = pvNotificationFunction;
	u8IntervalFlag = SINGLE_INTERVAL;

    /*Enable STK Interrupt*/
    MSTK_voidEnableInterrupt();
	/*Enable STK*/
    MSTK_voidEnableSTK();
}

void MSTK_voidSetPeriodicInterval(u32 Copy_u32Ticks, void (*pvNotificationFunction)(void))
{
    STK -> VAL = RESET;
    STK -> LOAD = Copy_u32Ticks;
    pvCallBackFunction = pvNotificationFunction;
	u8IntervalFlag = PERIODIC_INTERVAL;

    /*Enable STK Interrupt*/
    MSTK_voidEnableInterrupt();
	/*Enable STK*/
    MSTK_voidEnableSTK();
}


void SysTick_Handler(void)
{
    u8 Local_u32ReadToReset;
    if (u8IntervalFlag == SINGLE_INTERVAL)
    {
        MSTK_voidDisableInterrupt();
    }
    if(pvCallBackFunction != NULL)
    {
        pvCallBackFunction();
    }
    Local_u32ReadToReset = GET_BIT(STK->CTRL,STK_CTRL_COUNTFLAG);
}


