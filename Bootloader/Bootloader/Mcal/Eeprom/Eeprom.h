/*
 * Eeprom.h
 *
 * Created: 2/7/2020 8:22:50 PM
 *  Author: MahmoudMorsy
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "Common.h"

#define EEPROM_START_ADDRESS 0
#define EEPROM_LAST_ADDRESS 1023

boolean Eeprom_WriteByte(uint16 Param_Address, uint8 Param_Data);
boolean Eeprom_ReadByte(uint16 Param_Address, uint8* Param_DataOutPtr);
boolean Eeprom_WriteBuffer(uint16 Param_StartAddress, uint8* Param_DataPtr, uint16 Param_NumberOfBytes);
boolean Eeprom_ReadBuffer(uint16 Param_StartAddress, uint8* Param_DataOutPtr, uint16 Param_NumberOfBytes);

#endif /* EEPROM_H_ */