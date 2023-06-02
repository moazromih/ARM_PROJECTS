/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   22 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSCFG_interface.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*MEXTI_pvoidInterruptFunction[16])(void) = {{NULL}};

void MEXTI_voidInit(void)
{
}

void MEXTI_voidEnableEXTILineInterrupt(u8 Copy_u8LineID)
{
    SET_BIT(EXTI->IMR,Copy_u8LineID);
}

void MEXTI_voidEnableEXTILineEvent(u8 Copy_u8LineID)
{
    SET_BIT(EXTI->EMR,Copy_u8LineID);
}

void MEXTI_voidDisableEXTILineEvent(u8 Copy_u8LineID)
{
    CLR_BIT(EXTI->EMR,Copy_u8LineID);
}

void MEXTI_voidSetTrigger(u8 Copy_u8LineID, u8 Copy_u8Trigger)
{
    switch (Copy_u8Trigger)
    {
    case EXTI_RISING_EDGE:
        CLR_BIT(EXTI->FTSR,Copy_u8LineID);
        SET_BIT(EXTI->RTSR,Copy_u8LineID); 
        break;
    case EXTI_FALLING_EDGE:
        CLR_BIT(EXTI->RTSR,Copy_u8LineID);
        SET_BIT(EXTI->FTSR,Copy_u8LineID);
        break;
    case EXTI_ON_CHANGE:
        SET_BIT(EXTI->FTSR,Copy_u8LineID);
        SET_BIT(EXTI->FTSR,Copy_u8LineID);
        break;
    default:
        /* ERROR */
        break;
    }
}

void MEXTI_voidSetSoftwareInterrupt(u8 Copy_u8LineID)
{
    SET_BIT(EXTI->SWIER,Copy_u8LineID);
}


u8 MEXTI_voidCheckPendingFlag(u8 Copy_u8LineID)
{
    u8 Local_u8ReturnedValue;
    Local_u8ReturnedValue = GET_BIT(EXTI->PR,Copy_u8LineID);
    return Local_u8ReturnedValue;
}


void MEXTI_voidClearPendingFlag(u8 Copy_u8LineID)
{
    SET_BIT(EXTI->PR,Copy_u8LineID);
}

void MEXTI_voidSetCallBack(u8 Copy_u8LineID, void (*pvoidNotificationFunction(void)))
{
    if(Copy_u8LineID < 16)
    {
    MEXTI_pvoidInterruptFunction[Copy_u8LineID] = pvoidNotificationFunction;
    }
    else
    {
        /* ERROR */
    }
}

void EXTI0_IRQHandler(void)
{
    if(MEXTI_pvoidInterruptFunction[EXTI_LINE_ZERO] != NULL)
    {
        MEXTI_pvoidInterruptFunction[EXTI_LINE_ZERO]();
    }
    else
    {
        /* ERROR */
    }
    MEXTI_voidClearPendingFlag(EXTI_LINE_ZERO);
}

void EXTI1_IRQHandler(void)
{
    if(MEXTI_pvoidInterruptFunction[EXTI_LINE_ONE] != NULL)
    {
        MEXTI_pvoidInterruptFunction[EXTI_LINE_ONE]();
    }
    else
    {
        /* ERROR */
    }
    MEXTI_voidClearPendingFlag(EXTI_LINE_ONE);
}

void EXTI2_IRQHandler(void)
{
    if(MEXTI_pvoidInterruptFunction[EXTI_LINE_TWO] != NULL)
    {
        MEXTI_pvoidInterruptFunction[EXTI_LINE_TWO]();
    }
    else
    {
        /* ERROR */
    }
    MEXTI_voidClearPendingFlag(EXTI_LINE_TWO);
}

void EXTI3_IRQHandler(void)
{
    if(MEXTI_pvoidInterruptFunction[EXTI_LINE_THREE] != NULL)
    {
        MEXTI_pvoidInterruptFunction[EXTI_LINE_THREE]();
    }
    else
    {
        /* ERROR */
    }
    MEXTI_voidClearPendingFlag(EXTI_LINE_THREE);
}

void EXTI4_IRQHandler(void)
{
    if(MEXTI_pvoidInterruptFunction[EXTI_LINE_FOUR] != NULL)
    {
        MEXTI_pvoidInterruptFunction[EXTI_LINE_FOUR]();
    }
    else
    {
        /* ERROR */
    }
    MEXTI_voidClearPendingFlag(EXTI_LINE_FOUR);
}

void EXTI5_IRQHandler(void)
{
    if(MEXTI_pvoidInterruptFunction[EXTI_LINE_FIVE] != NULL)
    {
        MEXTI_pvoidInterruptFunction[EXTI_LINE_FIVE]();
    }
    else
    {
        /* ERROR */
    }
    MEXTI_voidClearPendingFlag(EXTI_LINE_FIVE);
}

void EXTI6_IRQHandler(void)
{
    if(MEXTI_pvoidInterruptFunction[EXTI_LINE_SIX] != NULL)
    {
        MEXTI_pvoidInterruptFunction[EXTI_LINE_SIX]();
    }
    else
    {
        /* ERROR */
    }
    MEXTI_voidClearPendingFlag(EXTI_LINE_SIX);
}

void EXTI7_IRQHandler(void)
{
    if(MEXTI_pvoidInterruptFunction[EXTI_LINE_SEVEN] != NULL)
    {
        MEXTI_pvoidInterruptFunction[EXTI_LINE_SEVEN]();
    }
    else
    {
        /* ERROR */
    }
    MEXTI_voidClearPendingFlag(EXTI_LINE_SEVEN);
}

void EXTI8_IRQHandler(void)
{
    if(MEXTI_pvoidInterruptFunction[EXTI_LINE_EIGHT] != NULL)
    {
        MEXTI_pvoidInterruptFunction[EXTI_LINE_EIGHT]();
    }
    else
    {
        /* ERROR */
    }
    MEXTI_voidClearPendingFlag(EXTI_LINE_EIGHT);
}

void EXTI9_IRQHandler(void)
{
    if(MEXTI_pvoidInterruptFunction[EXTI_LINE_NINE] != NULL)
    {
        MEXTI_pvoidInterruptFunction[EXTI_LINE_NINE]();
    }
    else
    {
        /* ERROR */
    }
    MEXTI_voidClearPendingFlag(EXTI_LINE_NINE);
}

void EXTI10_IRQHandler(void)
{
    if(MEXTI_pvoidInterruptFunction[EXTI_LINE_TEN] != NULL)
    {
        MEXTI_pvoidInterruptFunction[EXTI_LINE_TEN]();
    }
    else
    {
        /* ERROR */
    }
    MEXTI_voidClearPendingFlag(EXTI_LINE_TEN);
}

void EXTI11_IRQHandler(void)
{
    if(MEXTI_pvoidInterruptFunction[EXTI_LINE_ELEVEN] != NULL)
    {
        MEXTI_pvoidInterruptFunction[EXTI_LINE_ELEVEN]();
    }
    else
    {
        /* ERROR */
    }
    MEXTI_voidClearPendingFlag(EXTI_LINE_ELEVEN);
}

void EXTI12_IRQHandler(void)
{
    if(MEXTI_pvoidInterruptFunction[EXTI_LINE_TWELVE] != NULL)
    {
        MEXTI_pvoidInterruptFunction[EXTI_LINE_TWELVE]();
    }
    else
    {
        /* ERROR */
    }
    MEXTI_voidClearPendingFlag(EXTI_LINE_TWELVE);
}

void EXTI13_IRQHandler(void)
{
    if(MEXTI_pvoidInterruptFunction[EXTI_LINE_THIRTEEN] != NULL)
    {
        MEXTI_pvoidInterruptFunction[EXTI_LINE_THIRTEEN]();
    }
    else
    {
        /* ERROR */
    }
    MEXTI_voidClearPendingFlag(EXTI_LINE_THIRTEEN);
}

void EXTI14_IRQHandler(void)
{
    if(MEXTI_pvoidInterruptFunction[EXTI_LINE_FOURTEEN] != NULL)
    {
        MEXTI_pvoidInterruptFunction[EXTI_LINE_FOURTEEN]();
    }
    else
    {
        /* ERROR */
    }
    MEXTI_voidClearPendingFlag(EXTI_LINE_FOURTEEN);
}

void EXTI15_IRQHandler(void)
{
    if(MEXTI_pvoidInterruptFunction[EXTI_LINE_FIFTEEN] != NULL)
    {
        MEXTI_pvoidInterruptFunction[EXTI_LINE_FIFTEEN]();
    }
    else
    {
        /* ERROR */
    }
    MEXTI_voidClearPendingFlag(EXTI_LINE_FIFTEEN);
}
