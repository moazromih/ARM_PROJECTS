/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   21 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


#define MNVIC_WWDG                  0
#define MNVIC_EXTI16                1
#define MNVIC_PVD                   1
#define MNVIC_EXTI21                2
#define MNVIC_TAMP_STAMP            2
#define MNVIC_EXTI22                3
#define MNVIC_RTC_WKUP              3
#define MNVIC_FLASH                 4
#define MNVIC_RCC                   5
#define MNVIC_EXTI0                 6
#define MNVIC_EXTI1                 7
#define MNVIC_EXTI2                 8
#define MNVIC_EXTI3                 9
#define MNVIC_EXTI4                 10
#define MNVIC_DMA1_Stream0          11
#define MNVIC_DMA1_Stream1          12
#define MNVIC_DMA1_Stream2          13
#define MNVIC_DMA1_Stream3          14
#define MNVIC_DMA1_Stream3          15
#define MNVIC_DMA1_Stream5          16
#define MNVIC_DMA1_Stream6          17
#define MNVIC_ADC                   18
#define MNVIC_EXTI9                 19
#define MNVIC_EXTI8                 20
#define MNVIC_EXTI7                 21
#define MNVIC_EXTI6                 22
#define MNVIC_EXTI5                 23
#define MNVIC_TIM1_BRK_TIM9         24
#define MNVIC_TIM1_UP_TIM10         25
#define MNVIC_TIM1_TRG_COM_TIM11    26
#define MNVIC_TIM1_CC               27
#define MNVIC_TIM2                  28
#define MNVIC_TIM3                  29
#define MNVIC_TIM4                  30
#define MNVIC_I2C1_EV               31
#define MNVIC_I2C1_ER               32
#define MNVIC_I2C2_EV               33
#define MNVIC_I2C2_ER               34
#define MNVIC_SPI1                  35
#define MNVIC_SPI2                  36
#define MNVIC_USART1                37
#define MNVIC_USART2                38
#define MNVIC_EXTI15                39
#define MNVIC_EXTI14                40
#define MNVIC_



void MNVIC_voidInit(void);
void MNVIC_voidEnablePeripheralInterrput(u8 Copy_u8InterruptID);
void MNVIC_voidDisablePeripheralInterrput(u8 Copy_u8InterruptID);
void MNVIC_voidSetPendingFlag(u8 Copy_u8InterruptID);
void MNVIC_voidClearPendingFlag(u8 Copy_u8InterruptID);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptID);
void MNVIC_voidSetPeripheralPriority(u8 Copy_u8InterruptID, u8 Copy_u8Priority);


#endif