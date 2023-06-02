#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "SYSCFG_interface.h"

void Toggle_LED(void);

void main(void)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_APB2,SYSCFG_ID);
	MRCC_voidEnablePeripheralClock(RCC_AHB1,GPIOA_ID);

//	MSYSCFG_voidSelectInterruptPort(SYSCFG_LINE_ZERO,SYSCFG_PORTB);

	MGPIO_voidSetPinMode(GPIOA,PIN0,INPUT);
	MGPIO_voidSetInputConnectionType(GPIOA,PIN0,PULLUP);

	MGPIO_voidSetPinMode(GPIOA,PIN8,OUTPUT);
	MGPIO_voidSetOutputType(GPIOA,PIN8,PUSH_PULL);
	MGPIO_voidSetOutputSpeed(GPIOA,PIN8,LOW_SPEED);

	MNVIC_voidInit();
	MNVIC_voidEnablePeripheralInterrput(MNIVC_EXTI0);

	MEXTI_voidSetTrigger(EXTI_LINE_ZERO,EXTI_FALLING_EDGE);
	MEXTI_voidSetCallBack(EXTI_LINE_ZERO,&Toggle_LED);
	MEXTI_voidEnableEXTILineInterrupt(EXTI_LINE_ZERO);
	while(1)
	{

	}
}


void Toggle_LED(void)
{
	static u8 LedValue = 0;
	LedValue ^= 1;
	MGPIO_voidSetPinValue(GPIOA,PIN8,LedValue);
}
