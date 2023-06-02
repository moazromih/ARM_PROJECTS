/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   26 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#ifndef IR_SENSOR_INTERFACE_H
#define IR_SENSOR_INTERFACE_H


#define BUTTON_0_VALUE          69
#define BUTTON_1_VALUE          12
#define BUTTON_2_VALUE          24
#define BUTTON_3_VALUE          94
#define BUTTON_4_VALUE          8
#define BUTTON_5_VALUE          28
#define BUTTON_6_VALUE          90
#define BUTTON_7_VALUE          66
#define BUTTON_8_VALUE          82
#define BUTTON_9_VALUE          74



void HIR_SENSOR_voidInit();
void HIR_SENSOR_voidSetActionFunction(void (*pvoidNotificationFunction(u8)));
void HIR_SENSOR_voidReceiveFrame(void);
void HIR_SENSOR_voidGetPressedKey(void);

#endif
