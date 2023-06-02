/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   01 June, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#ifndef SHIFTREGISTER_INTERFACE_H
#define SHIFTREGISTER_INTERFACE_H


void HShiftRegister_voidInit(void);
void HShiftRegister_voidSend1ByteDataLow(u8 Copy_u8Data);
void HShiftRegister_voidSend1ByteDataHigh(u8 Copy_u8Data);
void HshiftRegister_voidSend2ByteData(u16 Copy_u16Data);

#endif