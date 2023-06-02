#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LED_Matrix_interface.h"

const u8 Display1[8] = {0, 2, 132, 75, 63, 75, 132, 2};
const u8 Display2[8] = {0, 8, 136, 75, 63, 75, 136, 8};
const u8 Display3[8] = {0, 32, 144, 75, 63, 75, 144, 32};





void Display(void);

void main(void)
{
    MRCC_voidInit();
    MRCC_voidEnablePeripheralClock(RCC_AHB1,GPIOA_ID);
    MRCC_voidEnablePeripheralClock(RCC_AHB1,GPIOB_ID);
    MSTK_voidInit();
    HLED_MATRIX_voidInit();
    while(1)
    {
    	Display();
    }
}


void Display(void)
{
	u8 Local_LoopCounter;
	for(Local_LoopCounter = 0;Local_LoopCounter < 5;Local_LoopCounter++)
	{
		HLED_MATRIX_voidDisplay(Display1);
	}
	for(Local_LoopCounter = 0;Local_LoopCounter < 5;Local_LoopCounter++)
	{
		HLED_MATRIX_voidDisplay(Display2);
	}
	for(Local_LoopCounter = 0;Local_LoopCounter < 5;Local_LoopCounter++)
	{
		HLED_MATRIX_voidDisplay(Display3);
	}
	for(Local_LoopCounter = 0;Local_LoopCounter < 5;Local_LoopCounter++)
	{
		HLED_MATRIX_voidDisplay(Display2);
	}
}


