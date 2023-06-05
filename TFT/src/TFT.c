#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SPI_Interface.h"
#include "STK_interface.h"

#include "TFT_interface.h"

#include "elcc.h"

void main(void)
{
    MRCC_voidInit();
    MRCC_voidEnablePeripheralClock(RCC_AHB1,GPIOA_ID);
    MRCC_voidEnablePeripheralClock(RCC_APB2,SPI1_ID);
    MSTK_voidInit();
    MSPI1_voidInit();
    HTFT_voidInit();
    while (1)
    {
        HTFT_voidDisplayImage(image_data_download);
    }
    
}
