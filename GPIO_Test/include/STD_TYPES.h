/***********************************************
* Author :          Moaz Mohamed Mahmoud Romih
* Creation Date :   22/03/2023
* Version       :   v1.0
* Compiler      :   AVR GCC
************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char      	u8;
typedef unsigned short int 	u16;
typedef unsigned int       	u32;

typedef signed char        	s8;
typedef signed short int   	s16;
typedef signed int         	s32;

typedef float              	f32;
typedef double             	f64;

#define TRUE                1
#define FALSE               0

#define NULL                (void*)0
#endif
