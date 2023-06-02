/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   26 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "RGB_LED_interface.h"
#include "RGB_LED_private.h"
#include "RGB_LED_config.h"

void HRGB_voidInit(void)
{
    /* Configure REd PIN */
    MRCC_voidEnablePeripheralClock(RCC_AHB1,RGB_RED_PORT);
    MGPIO_voidSetPinMode(RGB_RED_PORT,RGB_RED_PIN,OUTPUT);
    MGPIO_voidSetOutputType(RGB_RED_PORT,RGB_RED_PIN,PUSH_PULL);
    MGPIO_voidSetOutputSpeed(RGB_RED_PORT,RGB_RED_PIN,LOW_SPEED);
    /* Configure Blue PIN*/
    MRCC_voidEnablePeripheralClock(RCC_AHB1,RGB_BLUE_PORT);
    MGPIO_voidSetPinMode(RGB_BLUE_PORT,RGB_BLUE_PIN,OUTPUT);
    MGPIO_voidSetOutputType(RGB_BLUE_PORT,RGB_BLUE_PIN,PUSH_PULL);
    MGPIO_voidSetOutputSpeed(RGB_BLUE_PORT,RGB_BLUE_PIN,LOW_SPEED);
    /* Configure Green PIN */
    MRCC_voidEnablePeripheralClock(RCC_AHB1,RGB_GREEN_PORT);
    MGPIO_voidSetPinMode(RGB_GREEN_PORT,RGB_GREEN_PIN,OUTPUT);
    MGPIO_voidSetOutputType(RGB_GREEN_PORT,RGB_GREEN_PIN,PUSH_PULL);
    MGPIO_voidSetOutputSpeed(RGB_GREEN_PORT,RGB_GREEN_PIN,LOW_SPEED);
}


void HRGB_voidSetColor(u8 Copy_u8Color)
{
    /* Reset All Colors */
    MGPIO_voidSetPinValue(RGB_RED_PORT,RGB_RED_PIN,LOW);
    MGPIO_voidSetPinValue(RGB_BLUE_PORT,RGB_BLUE_PIN,LOW);
    MGPIO_voidSetPinValue(RGB_GREEN_PORT,RGB_GREEN_PIN,LOW);
    /* Turn on the Colors for the intended color */
    switch (Copy_u8Color)
    {
    case RGB_LED_OFF:
        break;
    case RGB_LED_RED:
        MGPIO_voidSetPinValue(RGB_RED_PORT,RGB_RED_PIN,HIGH);
        break;
    case RGB_LED_BLUE:
        MGPIO_voidSetPinValue(RGB_BLUE_PORT,RGB_BLUE_PIN,HIGH);
        break;
    case RGB_LED_GREEN:
        MGPIO_voidSetPinValue(RGB_GREEN_PORT,RGB_GREEN_PIN,HIGH);
        break;
    case RGB_LED_CYAN:
        MGPIO_voidSetPinValue(RGB_BLUE_PORT,RGB_BLUE_PIN,HIGH);
        MGPIO_voidSetPinValue(RGB_GREEN_PORT,RGB_GREEN_PIN,HIGH);
        break;
    case RGB_LED_YELLOW:
        MGPIO_voidSetPinValue(RGB_RED_PORT,RGB_RED_PIN,HIGH);
        MGPIO_voidSetPinValue(RGB_GREEN_PORT,RGB_GREEN_PIN,HIGH);
        break;
    case RGB_LED_PURPLE:
        MGPIO_voidSetPinValue(RGB_RED_PORT,RGB_RED_PIN,HIGH);
        MGPIO_voidSetPinValue(RGB_BLUE_PORT,RGB_BLUE_PIN,HIGH);
        break;
    case RGB_LED_WHITE:
        MGPIO_voidSetPinValue(RGB_RED_PORT,RGB_RED_PIN,HIGH);
        MGPIO_voidSetPinValue(RGB_BLUE_PORT,RGB_BLUE_PIN,HIGH);
        MGPIO_voidSetPinValue(RGB_GREEN_PORT,RGB_GREEN_PIN,HIGH);
        break;
    default:
        /* ERROR */
        break;
    }
}
