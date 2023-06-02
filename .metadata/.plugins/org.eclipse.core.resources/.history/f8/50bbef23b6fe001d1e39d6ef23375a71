/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   21 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidInit(void)
{
    SCB_AIRCR |= (VECTKEY) | (MNVIC_GROUP_SUB_DISTRIBUTION<<SCB_AIRCR_PRIGROUP);
}


void MNVIC_voidEnablePeripheralInterrput(u8 Copy_u8InterruptID)
{
    SET_BIT(NVIC->ISER[Copy_u8InterruptID/THIRTY_TWO_BITS],Copy_u8InterruptID%THIRTY_TWO_BITS);
}


void MNVIC_voidDisablePeripheralInterrput(u8 Copy_u8InterruptID)
{
    SET_BIT(NVIC->ICER[Copy_u8InterruptID/THIRTY_TWO_BITS],Copy_u8InterruptID%THIRTY_TWO_BITS);
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8InterruptID)
{
    SET_BIT(NVIC->ISPR[Copy_u8InterruptID/THIRTY_TWO_BITS],Copy_u8InterruptID%THIRTY_TWO_BITS);
}


void MNVIC_voidClearPendingFlag(u8 Copy_u8InterruptID)
{
    SET_BIT(NVIC->ICPR[Copy_u8InterruptID/THIRTY_TWO_BITS],Copy_u8InterruptID%THIRTY_TWO_BITS);
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptID)
{
    u8 Local_u8ReturnedValue =  GET_BIT(NVIC->IABR[Copy_u8InterruptID/THIRTY_TWO_BITS],Copy_u8InterruptID%THIRTY_TWO_BITS);
    return Local_u8ReturnedValue;
}



void MNVIC_voidSetPeripheralPriority(u8 Copy_u8InterruptID, u8 Copy_u8Priority)
{
    NVIC->IPR[Copy_u8InterruptID] = (Copy_u8Priority<<FOUR_BITS);
}

