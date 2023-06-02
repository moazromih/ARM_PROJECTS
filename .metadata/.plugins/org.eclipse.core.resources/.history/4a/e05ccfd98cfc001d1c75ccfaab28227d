#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "EXTI_interface.h"

#include "IR_Sensor_interface.h"
#include "RGB_LED_interface.h"

void RPG_Control(u8 Copy_Button);

void main(void)
{
    HIR_SENSOR_voidSetActionFunction(&RPG_Control);
    HIR_SENSOR_voidInit();
    HRGB_voidInit();
    while(1)
    {

    }
}


void RPG_Control(u8 Copy_Button)
{
    switch (Copy_Button)
    {
    case BUTTON_0_VALUE:
        HRGB_voidSetColor(RGB_LED_OFF);
        break;
    case BUTTON_1_VALUE:
        HRGB_voidSetColor(RGB_LED_RED);
        break;
    case BUTTON_2_VALUE:
        HRGB_voidSetColor(RGB_LED_BLUE);
        break;
    case BUTTON_3_VALUE:
        HRGB_voidSetColor(RGB_LED_GREEN);
        break;
    case BUTTON_4_VALUE:
        HRGB_voidSetColor(RGB_LED_CYAN);
        break;
    case BUTTON_5_VALUE:
        HRGB_voidSetColor(RGB_LED_YELLOW);
        break;
    case BUTTON_6_VALUE:
        HRGB_voidSetColor(RGB_LED_PURPLE);
        break;
    case BUTTON_7_VALUE:
        HRGB_voidSetColor(RGB_LED_WHITE);
        break;
    default:
        break;
    }
}
