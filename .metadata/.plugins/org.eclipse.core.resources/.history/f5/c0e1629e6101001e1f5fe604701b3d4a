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

void main(void)
{
    MRCC_voidInit();
    MRCC_voidEnablePeripheralClock(RCC_AHB1,GPIOA_ID);

    MSTK_voidInit();
    
    HDAC_voidInit();
    
    while (1)
    {
        HDAC_voidSendData(0b11110000);
        MSTK_voidSetBusyWaitus(500000);
        HDAC_voidSendData(0b00001111);
    }
}