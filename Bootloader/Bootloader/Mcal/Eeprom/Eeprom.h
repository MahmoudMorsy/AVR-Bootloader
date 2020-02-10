/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              Eeprom.h
* MODULE:            Eeprom
* AUTHOR:            MahmoudMorsy
* DESCRIPTION:       Header file for Eeprom Mcal driver
* CREATION DATE:     7/2/2020
* MODIFICATION DATE: 9/2/2020
**************************************************************************************************/
#ifndef EEPROM_H_
#define EEPROM_H_

/**************************************************************************************************
*                                       INCLUDES & LIBRARIES                                      *
**************************************************************************************************/
#include "Common.h"

/**************************************************************************************************
*                                       FUNCTION PROTOTYPES                                       *
**************************************************************************************************/
boolean Eeprom_WriteByte(uint16 Param_Address, uint8 Param_Data);
boolean Eeprom_ReadByte(uint16 Param_Address, uint8* Param_DataOutPtr);
boolean Eeprom_WriteBuffer(uint16 Param_StartAddress, uint8* Param_DataPtr, uint16 Param_NumberOfBytes);
boolean Eeprom_ReadBuffer(uint16 Param_StartAddress, uint8* Param_DataOutPtr, uint16 Param_NumberOfBytes);

#endif /* EEPROM_H_ */