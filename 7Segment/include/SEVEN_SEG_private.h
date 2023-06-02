/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   12 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#ifndef SEVEN_SEG_PRIVATE_H
#define SEVEN_SEG_PRIVATE_H



#define LOOPSTART       0
#define LOOPEND         7

#define MAX_NUM         99
#define MAX_NATURAL_NUM 9

#define NOTHING			256

#define SEG_PIN_A       0
#define SEG_PIN_B       1
#define SEG_PIN_C       2
#define SEG_PIN_D       3
#define SEG_PIN_E       4
#define SEG_PIN_F       5
#define SEG_PIN_G       6

static void SEVEN_SEG_voidprintNaturalNumber(u8 Copy_u8SegID,u8 Copy_u8Number);

#endif
