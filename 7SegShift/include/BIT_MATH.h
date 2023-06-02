/***********************************************
* Author :          Moaz Mohamed Mahmoud Romih
* Creation Date :   16/03/2023
* Version       :   v1.0
* Compiler      :   GNU GCC
************************************************/
#ifndef BIT_MATH_H

/******************* Functions like macro to manipulate over specific bit/register. *******************/
#define BIT_MATH_H
#define SET_BIT(REG_NAME,BIT_NUM)   (REG_NAME |= (1<<BIT_NUM))
#define CLR_BIT(REG_NAME,BIT_NUM)   (REG_NAME &= (~(1<<BIT_NUM)))
#define GET_BIT(REG_NAME,BIT_NUM)   ((REG_NAME>>BIT_NUM)&1)
#define TOG_BIT(REG_NAME,BIT_NUM)   (REG_NAME ^= (1<<BIT_NUM))
#define SET_REG(REG_NAME,VALUE)     (REG_NAME = VALUE)
#define GET_REG(REG_NAME)           (REG_NAME)
#define CLR_REG(REG_NAME)           (REG_NAME = 0)


#endif
