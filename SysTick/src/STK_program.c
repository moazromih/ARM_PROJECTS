#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

void STK_voidInit(void)
{
    STK->CTRL = 0;
    #if STK_INT_ENABLE == ENABLE
        SET_BIT(STK->CTRL,CTRL_TICKINT);
    #endif
    #if STK_CLK_SRC == AHB_DIVIDED_BY_8
        CLR_BIT(STK->CTRL,CTRL_CLKSOURCE);
    #elif STK_CLK_SRC == AHB
        SET_BIT(STK->CTRL,CTRL_CLKSOURCE);
    #else
        #error "55555555555555555"
    #endif
    #if STK_ENABLE == ENABLE
        SET_BIT(STK->CTRL,CTRL_ENABLE);
    #endif
}

void STK_voidSetBusyWaitus(u32 Copy_u32Delay)
{
    
    if (Copy_u32Delay <= MAX_VALUE)
    {
    STK->LOAD = Copy_u32Delay;
    while (GET_BIT(STK->CTRL,CTRL_COUNTFLAG) == 0);
    }
    else
    {
        u32 Local_u32Remainder = Copy_u32Delay % MAX_VALUE;
        u32 Local_u32Division = Copy_u32Delay / MAX_VALUE;
        STK->LOAD = Local_u32Remainder;
        while (GET_BIT(STK->CTRL,CTRL_COUNTFLAG) == 0);
        while (Local_u32Division-- > 0)
        {
            STK->LOAD = MAX_VALUE;
            while (GET_BIT(STK->CTRL,CTRL_COUNTFLAG) == 0);
        }
        
    }
    STK->VAL = 0;
}