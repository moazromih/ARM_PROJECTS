/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   21 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

typedef struct 
{   
    volatile u32 ISER[8];
    volatile u32 Reserved0[24];
    volatile u32 ICER[8];
    volatile u32 Reserved1[24];
    volatile u32 ISPR[8];
    volatile u32 Reserved2[24];
    volatile u32 ICPR[8];
    volatile u32 Reserved3[24];
    volatile u32 IABR[8];
    volatile u32 Reserved4[56];
    volatile u8 IPR[240];
    volatile u32 Reserved5[580];
    volatile u32 STIR;
}NVIC_t;


#define NVIC                    ((volatile NVIC_t *)0xE000E100)

#define SCB_AIRCR               *((volatile u32 *)0xE000ED0C)

#define VECTKEY                 0x05FA0000

#define SCB_AIRCR_PRIGROUP      8

#define GRP_0_SUB_4_BITS        0
#define GRP_1_SUB_3_BITS        4
#define GRP_2_SUB_2_BITS        5
#define GRP_3_SUB_1_BITS        6
#define GRP_0_SUB_4_BITS        7

#define FOUR_BITS               4
#define THIRTY_TWO_BITS         32


#endif