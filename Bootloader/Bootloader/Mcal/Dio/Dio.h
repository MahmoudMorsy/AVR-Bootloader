/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              Dio.h
* MODULE:            Dio
* AUTHOR:            ShroukRashwan
* DESCRIPTION:       Header file for Dio Mcal driver
* CREATION DATE:     7/2/2020
* MODIFICATION DATE: 11/2/2020
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
boolean Dio_WritePin(uint8 Param_PortNumber, uint8 Param_PinNumber, uint8 Param_value);
boolean Dio_ReadPin(uint8 Param_PortNumber, uint8 Param_PinNumber, uint8* Param_ReturnValue);
boolean Dio_WritePort(uint8 Param_PortNumber, uint8 Param_value);
boolean Dio_ReadPort(uint8 Param_PortNumber, uint8* Param_ReturnValue);
boolean Dio_SetPinDirection(uint8 Param_PortNumber, uint8 Param_PinNumber, uint8 Param_Mode);
boolean Dio_SetPortDirection(uint8 Param_PortNumber, uint8 Param_Mode);

#endif /* DIO_H_ */