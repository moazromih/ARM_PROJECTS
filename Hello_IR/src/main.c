#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"

void APP_GetFrame(void);
void APP_TakeAction(void);
void APP_voidPlay(void);

void main(void)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, GPIOA_ID);

	/*Set The A0 Pin To Be Input (EXTI0)*/
	MGPIO_voidSetPinMode(GPIOA, PIN0, INPUT);
	/*Set The A0 Pin To Be Pullup Up*/
	MGPIO_voidSetInputConnectionType(GPIOA, PIN0, PULLUP);

	/*Initialize STK*/
	MSTK_voidInit();

	/*Setup EXTI Line 0*/
	MEXTI_voidInit();
	MEXTI_voidSetTrigger(EXTI_LINE_ZERO, EXTI_FALLING_EDGE);
	MEXTI_voidSetCallBack(EXTI_LINE_ZERO, &APP_GetFrame);
	MEXTI_voidEnableEXTILineInterrupt(EXTI_LINE_ZERO);

	/*Initialize NVIC*/
	MNVIC_voidInit();
	/*Enable EXTI Peripheral In NVIC*/
	MNVIC_voidEnablePeripheralInterrput(MNIVC_EXTI0);
	while(1)
	{
		APP_voidPlay();
	}
}

u8  APP_u8StartEdgeFlag = 0;
u32 APP_u32ReceivedFrame[50] = {0};
u8  APP_u8EdgeCounter = 0;
void APP_GetFrame(void)
{
	if(APP_u8StartEdgeFlag == 0)
	{
		MSTK_voidSetSingleInterval(50000, &APP_TakeAction);
		APP_u8StartEdgeFlag = 1;
	}
	else
	{
		/*Get the counted time*/
		APP_u32ReceivedFrame[APP_u8EdgeCounter] = MSTK_u32GetElapsedTime();
		/*Reset The Timer, Set PreLoad Value*/
		MSTK_voidSetSingleInterval(50000, &APP_TakeAction);
		/*Increment Edge Counter*/
		APP_u8EdgeCounter++;
	}
}
u8 App_u8ButtonData = 0;
void APP_TakeAction(void)
{
	u8 Local_u8LoopCounter = 0;
	for(Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
	{
		if((APP_u32ReceivedFrame[17+Local_u8LoopCounter] >= 1000) &&
				(APP_u32ReceivedFrame[17+Local_u8LoopCounter] <= 1500))
		{
			CLR_BIT(App_u8ButtonData, Local_u8LoopCounter);
		}
		else
		{
			SET_BIT(App_u8ButtonData, Local_u8LoopCounter);
		}
	}
	APP_u8StartEdgeFlag = 0;
	APP_u8EdgeCounter = 0;
}

void APP_voidPlay(void)
{
	switch(App_u8ButtonData)
	{
	case 4:
		asm("NOP");
		break;
	case 5:
		asm("NOP");
		break;
	case 6:
		asm("NOP");
		break;
	}
}


