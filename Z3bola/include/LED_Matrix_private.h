/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   29 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#ifndef LED_MATRIX_PRIVATE_H
#define LED_MATRIX_PRIVATE_H



#define ROWS_PORTS          {ROW0_PORT,ROW1_PORT,ROW2_PORT,ROW3_PORT,ROW4_PORT,ROW5_PORT,ROW6_PORT,ROW7_PORT}
#define COLS_PORTS          {COL0_PORT,COL1_PORT,COL2_PORT,COL3_PORT,COL4_PORT,COL5_PORT,COL6_PORT,COL7_PORT}

#define ROWS_PINS           {ROW0_PIN,ROW1_PIN,ROW2_PIN,ROW3_PIN,ROW4_PIN,ROW5_PIN,ROW6_PIN,ROW7_PIN}
#define COLS_PINS           {COL0_PIN,COL1_PIN,COL2_PIN,COL3_PIN,COL4_PIN,COL5_PIN,COL6_PIN,COL7_PIN}

#define FOURxFOUR           4
#define EIGHTxEIGHT         8

#define EIGHT_STEPS_DELAY   2500
#define FOUR_STEPS_DELAY    5000


static void ResetColumns(void);


#endif
