#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

typedef struct 
{
    u32 CTRL;
    u32 LOAD;
    u32 VAL;
    u32 CALIB;
}STK_t;


#define STK                 ((volatile STK_t*)0xE000E010)

#define AHB_DIVIDED_BY_8    0
#define AHB                 1

#define CTRL_ENABLE              0
#define CTRL_TICKINT             1
#define CTRL_CLKSOURCE           2
#define CTRL_COUNTFLAG           16
#define MAX_VALUE                0xFFFFFF


#endif