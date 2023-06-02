/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   22 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#ifndef SYSCFG_INTERFACE_H
#define SYSCFG_INTERFACE_H

#define SYSCFG_PORTA                0
#define SYSCFG_PORTB                1
#define SYSCFG_PORTC                2

#define SYSCFG_LINE_ZERO            0
#define SYSCFG_LINE_ONE             1
#define SYSCFG_LINE_TWO             2
#define SYSCFG_LINE_THREE           3
#define SYSCFG_LINE_FOUR            4
#define SYSCFG_LINE_FIVE            5
#define SYSCFG_LINE_SIX             6
#define SYSCFG_LINE_SEVEN           7
#define SYSCFG_LINE_EIGHT           8
#define SYSCFG_LINE_NINE            9
#define SYSCFG_LINE_TEN             10
#define SYSCFG_LINE_ELEVEN          11
#define SYSCFG_LINE_TWELVE          12
#define SYSCFG_LINE_THIRTEEN        13
#define SYSCFG_LINE_FOURTEEN        14
#define SYSCFG_LINE_FIFTEEN         15

void MSYSCFG_voidSelectInterruptPort(u8 Copy_u8LineID, u8 Copy_u8Port);


#endif