/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              Dio.h
* MODULE:            Dio
* AUTHOR:            ShroukRashwan
* DESCRIPTION:       Header file for Dio Mcal driver
* CREATION DATE:     7/2/2020
* MODIFICATION DATE: 10/2/2020
**************************************************************************************************/
#ifndef DIO_H_
#define DIO_H_

/**************************************************************************************************
*                                       INCLUDES & LIBRARIES                                      *
**************************************************************************************************/
#include "Common/Common_Macros.h"
#include "Common/Common_Types.h"

/**************************************************************************************************
*                                       FUNCTION PROTOTYPES                                       *
**************************************************************************************************/
void Dio_WritePin(uint8 portNumber, uint8 pinNumber, uint8 value);
uint8 Dio_ReadPin(uint8 Param_PortNumber, uint8 Param_PinNumber)
void Dio_WritePort(uint8 Param_PortNumber, uint8 Param_value)
uint8 Dio_ReadPort(uint8 Param_PortNumber)
void Dio_SetPinDirection(uint8 Param_PortNumber, uint8 Param_PinNumber, uint8 Param_Mode);
void Dio_SetPortDirection(uint8 Param_PortNumber, uint8 Param_Mode)



#endif /* DIO_H_ */