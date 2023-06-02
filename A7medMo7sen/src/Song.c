/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   02 June, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "DAC_interface.h"

#include "Array.h"

void main(void)
{
    MRCC_voidInit();
    MRCC_voidEnablePeripheralClock(RCC_AHB1,GPIOA_ID);

    MSTK_voidInit();
    
    HDAC_voidInit();
    
    while (1)
    {
    	u32 Local_u32LoopCounter;
        for(Local_u32LoopCounter = 0; Local_u32LoopCounter < mo7sen_raw_len; Local_u32LoopCounter++)
        {
        	HDAC_voidSendData(mo7sen_raw[Local_u32LoopCounter]);
        	MSTK_voidSetBusyWaitus(125);
        }
    }
}
