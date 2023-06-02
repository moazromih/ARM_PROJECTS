/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   09 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

typedef struct 
{
    u32 CTRL;
    u32 LOAD;
    u32 VAL;
    u32 CALIB;
}STK_t;


#define STK                     ((volatile STK_t*)0xE000E010)


#define STK_CTRL_ENABLE         0
#define STK_CTRL_TICKINT        1
#define STK_CTRL_CLKSOURCE      2
#define STK_CTRL_COUNTFLAG      16


#define STK_AHB                 1
#define STK_AHB_DIVIDED_BY_8    0

#define FULL_LOOP               0xFFFFFF

#define SINGLE_INTERVAL         0
#define PERIODIC_INTERVAL       1

#endif