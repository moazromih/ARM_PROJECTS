/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   09 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void MSTK_voidInit(void);

void MSTK_voidEnableSTK(void);

void MSTK_voidDisableSTK(void);

void MSTK_voidEnableInterrupt(void);

void MSTK_voidDisableInterrupt(void);

u32 MSTK_u32GetElapsedTime(void);

u32 MSTK_u32GetRemainingTime(void);

void MSTK_voidSetBusyWaitus(u32 Copy_u32usec);

void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks, void (* pvNotificationFunction)());

void MSTK_voidSetPeriodicInterval(u32 Copy_u32Ticks, void (* pvNotificationFunction)());

void MSTK_voidResetSysTick(void);

void MSTK_voidSetPreloadValue(u32 Copy_u32PreloadValue);

#endif
