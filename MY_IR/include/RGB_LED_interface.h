/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   26 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#ifndef RGB_LED_INTERFACE_H
#define RGB_LED_INTERFACE_H


#define RGB_LED_OFF             0
#define RGB_LED_RED             1
#define RGB_LED_BLUE            2
#define RGB_LED_GREEN           3
#define RGB_LED_CYAN            4
#define RGB_LED_YELLOW          5
#define RGB_LED_PURPLE          6
#define RGB_LED_WHITE           7

void HRGB_voidInit(void);
void HRGB_voidSetColor(u8 Copy_u8Color);

#endif

