#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "SEVEN_SEG_interface.h"

void main(void)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1,GPIOA_ID);
	MRCC_voidEnablePeripheralClock(RCC_AHB1,GPIOB_ID);
	MSTK_voidInit();
	SEVEN_SEG_voidInit();
	while(1)
	{
		s8 Local_u8LoopCounter;
		for(Local_u8LoopCounter = 99; Local_u8LoopCounter >= 0; Local_u8LoopCounter--)
		{
			SEVEN_SEG_voidprintNumber(Local_u8LoopCounter);
			MSTK_voidSetBusyWaitus(200000);
		}
	}
}
