/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   22 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


typedef struct 
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
}EXTI_t;


#define EXTI        ((volatile EXTI_t *)(0x40013C00))

#define SYSCFG_EXTICR1      (*(volatile u32 *)0x40013808)

#endif