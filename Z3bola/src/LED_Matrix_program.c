/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   29 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "STK_interface.h"
#include "GPIO_interface.h"

#include "LED_Matrix_interface.h"
#include "LED_Martix_config.h"
#include "LED_Matrix_private.h"


static u8 LED_MATRIX_pu8RowsPorts[MATRIX_RESOLUTION] = ROWS_PORTS;
static u8 LED_MATRIX_pu8ColsPorts[MATRIX_RESOLUTION] = COLS_PORTS;
static u8 LED_MATRIX_pu8RowsPins[MATRIX_RESOLUTION] = ROWS_PINS;
static u8 LED_MATRIX_pu8ColsPins[MATRIX_RESOLUTION] = COLS_PINS;

void HLED_MATRIX_voidInit(void)
{
    u8 Local_u8LoopCounter;
    
    for (Local_u8LoopCounter = ZERO; Local_u8LoopCounter < MATRIX_RESOLUTION; Local_u8LoopCounter++)
    {
        MGPIO_voidSetPinMode(LED_MATRIX_pu8RowsPorts[Local_u8LoopCounter],LED_MATRIX_pu8RowsPins[Local_u8LoopCounter],OUTPUT);
        MGPIO_voidSetPinMode(LED_MATRIX_pu8ColsPorts[Local_u8LoopCounter],LED_MATRIX_pu8ColsPins[Local_u8LoopCounter],OUTPUT);
        MGPIO_voidSetOutputSpeed(LED_MATRIX_pu8RowsPorts[Local_u8LoopCounter],LED_MATRIX_pu8RowsPins[Local_u8LoopCounter],LOW_SPEED);
        MGPIO_voidSetOutputType(LED_MATRIX_pu8RowsPorts[Local_u8LoopCounter],LED_MATRIX_pu8RowsPins[Local_u8LoopCounter],PUSH_PULL);
        MGPIO_voidSetOutputSpeed(LED_MATRIX_pu8ColsPorts[Local_u8LoopCounter],LED_MATRIX_pu8ColsPins[Local_u8LoopCounter],LOW_SPEED);
        MGPIO_voidSetOutputType(LED_MATRIX_pu8ColsPorts[Local_u8LoopCounter],LED_MATRIX_pu8ColsPins[Local_u8LoopCounter],PUSH_PULL);
    }
    ResetColumns();
}


void HLED_MATRIX_voidDisplay(u8* Copy_u8InputArray)
{
    u8 Local_u8ColsIterator;
    u8 Local_u8RowsIterator;
    for (Local_u8ColsIterator = ZERO; Local_u8ColsIterator < MATRIX_RESOLUTION; Local_u8ColsIterator++)
    {
        /* Enable a Column */
        for (Local_u8RowsIterator = ZERO; Local_u8RowsIterator < MATRIX_RESOLUTION; Local_u8RowsIterator++)
        {
            MGPIO_voidSetPinValue(LED_MATRIX_pu8RowsPorts[Local_u8RowsIterator],LED_MATRIX_pu8RowsPins[Local_u8RowsIterator],GET_BIT(Copy_u8InputArray[Local_u8ColsIterator],Local_u8RowsIterator));
        }
        MGPIO_voidSetPinValue(LED_MATRIX_pu8ColsPorts[Local_u8ColsIterator],LED_MATRIX_pu8ColsPins[Local_u8ColsIterator],LOW);
        MSTK_voidSetBusyWaitus(EIGHT_STEPS_DELAY);
        ResetColumns();
    }
}



static void ResetColumns(void)
{
    u8 Local_u8LoopCounter;
    for (Local_u8LoopCounter = ZERO; Local_u8LoopCounter < MATRIX_RESOLUTION; Local_u8LoopCounter++)
    {
        MGPIO_voidSetPinValue(LED_MATRIX_pu8ColsPorts[Local_u8LoopCounter],LED_MATRIX_pu8ColsPins[Local_u8LoopCounter],HIGH);
    }
    
}
