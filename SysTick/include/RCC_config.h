/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   01 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


/* RCC Clock Source Select
    Options:
        HSI
        HSE
        PLL
*/
#define CPU_CLK_SRC         HSI

/* PLL Source Select
    Options:
        HSI
        HSE
*/
#define PLL_SRC             HSI

/* HSE Source Select
    Options:
        RC
        OSCI
*/
#define HSE_CLK_SRC         OSCI

/* PLL Division Factor Select
    Options
        PLL_DIV_2
        PLL_DIV_4
        PLL_DIV_6
        PLL_DIV_8
*/
#define PLL_DIV_FACTOR      PLL_DIV_2

/* PLL Multiplication Factor Select
    Options
    192 - 432 
*/
#define PLL_MULT_FACTOR     192    


/* AHB Prescaler
    Options :
        HPRE_NO_PRESCALER 
        HPRE_PRESCALER_2  
        HPRE_PRESCALER_4  
        HPRE_PRESCALER_8  
        HPRE_PRESCALER_16 
        HPRE_PRESCALER_64 
        HPRE_PRESCALER_128
        HPRE_PRESCALER_256
        HPRE_PRESCALER_512
*/
#define AHB_PRESCALER           HPRE_PRESCALER_2


/* APB1 Prescaler
    Options:
        #define PPRE_NO_PRESCALER  
        #define PPRE_PRESCALER_2   
        #define PPRE_PRESCALER_4   
        #define PPRE_PRESCALER_8   
        #define PPRE_PRESCALER_16  
*/
#define APB1_PRESCALER          PPRE_NO_PRESCALER


/* APB2 Prescaler
    Options:
        #define PPRE_NO_PRESCALER  
        #define PPRE_PRESCALER_2   
        #define PPRE_PRESCALER_4   
        #define PPRE_PRESCALER_8   
        #define PPRE_PRESCALER_16  
*/
#define APB2_PRESCALER          PPRE_NO_PRESCALER



#endif
