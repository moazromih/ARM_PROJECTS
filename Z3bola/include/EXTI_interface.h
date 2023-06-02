/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   22 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_LINE_ZERO              0
#define EXTI_LINE_ONE               1
#define EXTI_LINE_TWO               2
#define EXTI_LINE_THREE             3
#define EXTI_LINE_FOUR              4
#define EXTI_LINE_FIVE              5
#define EXTI_LINE_SIX               6
#define EXTI_LINE_SEVEN             7
#define EXTI_LINE_EIGHT             8
#define EXTI_LINE_NINE              9
#define EXTI_LINE_TEN               10
#define EXTI_LINE_ELEVEN            11
#define EXTI_LINE_TWELVE            12
#define EXTI_LINE_THIRTEEN          13
#define EXTI_LINE_FOURTEEN          14
#define EXTI_LINE_FIFTEEN           15

#define EXTI_RISING_EDGE            0
#define EXTI_FALLING_EDGE           1
#define EXTI_ON_CHANGE              2

void MEXTI_voidInit(void);
void MEXTI_voidEnableEXTILineInterrupt(u8 Copy_u8LineID);
void MEXTI_voidDisableEXTILineInterrupt(u8 Copy_u8LineID);

void MEXTI_voidEnableEXTILineEvent(u8 Copy_u8LineID);
void MEXTI_voidDisableEXTILineEvent(u8 Copy_u8LineID);

void MEXTI_voidSetTrigger(u8 Copy_u8LineID, u8 Copy_u8Trigger);

void MEXTI_voidSetSoftwareInterrupt(u8 Copy_u8LineID);
u8 MEXTI_voidCheckPendingFlag(u8 Copy_u8LineID);
void MEXTI_voidClearPendingFlag(u8 Copy_u8LineID);
void MEXTI_voidSetCallBack(u8 Copy_u8LineID, void (*pvoidNotificationFunction(void)));


#endif