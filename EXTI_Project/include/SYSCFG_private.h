/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   22 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#ifndef SYSCFG_PRIVATE_H
#define SYSCFG_PRIVATE_H


typedef struct 
{
    u32 MEMRMP;
    u32 PMC;
    u32 EXTICR1;
    u32 EXTICR2;
    u32 EXTICR3;
    u32 EXTICR4;
    u32 CMPCR;
}SYSCFG_t;



#define SYSCFG          ((volatile SYSCFG_t *)0x40013800)
#define FOUR_BITS_MSK   0b1111
#define FOUT_BITS_SHIFT 4

#endif