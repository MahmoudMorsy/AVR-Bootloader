/*
 * Dio.h
 *
 * Created: 2/7/2020 8:22:16 PM
 *  Author: MahmoudMorsy
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "Common/Common_Macros.h"
#include "Common/Common_Types.h"

void Dio_WritePin(uint8 portNumber, uint8 pinNumber, uint8 value);
uint8 Dio_ReadPin(uint8 Param_PortNumber, uint8 Param_PinNumber)
void Dio_WritePort(uint8 Param_PortNumber, uint8 Param_value)
uint8 Dio_ReadPort(uint8 Param_PortNumber)
void Dio_SetPinDirection(uint8 Param_PortNumber, uint8 Param_PinNumber, uint8 mode);
void Dio_SetPortDirection(uint8 Param_PortNumber, uint8 mode)



#endif /* DIO_H_ */