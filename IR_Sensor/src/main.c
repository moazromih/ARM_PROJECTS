#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"

u8 APP_u8StartEdgeFlag = 0;
u32 APP_u32ReceivedFrame[50] = {0};
u8 APP_u8EdgeCounter = 0;

void APP_GetFrame(void);

void APP_TakeAction(void);

void main(void)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1,GPIOA_ID);

	MSTK_voidInit();

	MGPIO_voidSetPinMode(GPIOA,PIN0,INPUT);
	MGPIO_voidSetInputConnectionType(GPIOA,PIN0,PULLUP);



	MNVIC_voidInit();
	MNVIC_voidEnablePeripheralInterrput(MNIVC_EXTI0);

	MEXTI_voidInit();
	MEXTI_voidSetTrigger(EXTI_LINE_ZERO,EXTI_FALLING_EDGE);
	MEXTI_voidSetCallBack(EXTI_LINE_ZERO,&APP_GetFrame);
	MEXTI_voidEnableEXTILineInterrupt(EXTI_LINE_ZERO);
	while(1);
}


void APP_GetFrame(void)
{
	if(APP_u8StartEdgeFlag == 0)
	{
		MSTK_voidSetSingleInterval(1000000,&APP_TakeAction);
		APP_u8StartEdgeFlag = 1;
	}
	else
	{
		/* Get the counted time & increment the counter */
		APP_u32ReceivedFrame[APP_u8EdgeCounter++] = MSTK_u32GetElapsedTime();
		/* Reset The Timer */
		MSTK_voidResetSysTick();
		/* Set PreLoad Value */
		MSTK_voidSetPreloadValue(1000000);

	}
}

void APP_TakeAction(void)
{

}