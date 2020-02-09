/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              Eeprom_Internal.h
* MODULE:            Eeprom
* AUTHOR:            MahmoudMorsy
* DESCRIPTION:       Header file for Internal parameter of Eeprom Mcal driver
* CREATION DATE:     9/2/2020
* MODIFICATION DATE: 9/2/2020
**************************************************************************************************/
#ifndef EEPROM_INTERNAL_H_
#define EEPROM_INTERNAL_H_

/**************************************************************************************************
*                                       INCLUDES & LIBRARIES                                      *
**************************************************************************************************/
#include "Eeprom.h"
#if UNIT_TESTING == STD_OFF
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif

/**************************************************************************************************
*                                        MACRO DEFINITIONS                                        *
**************************************************************************************************/
#define EEPROM_START_ADDRESS 0
#define EEPROM_LAST_ADDRESS 1023

/* Stubbing for unit testing */
#if UNIT_TESTING == STD_ON
	/* Replacing Registers with Global Variables */
	#define EEPROM_EECR                                                                 Eeprom_EECR
	#define EEPROM_EEAR                                                                 Eeprom_EEAR
	#define EEPROM_EEDR                                                                 Eeprom_EEDR
	#define EEPROM_SPMCR                                                               Eeprom_SPMCR
	#define SPMEN                                                                                 0
	#define EERIE                                                                                 3
	#define EEMWE                                                                                 2
	#define EEWE                                                                                  1
	#define EERE                                                                                  0
	#undef cli
	#undef sei
	#define cli()
	#define sei()

#else
	/* Putting actual register addresses */
	#define EEPROM_EECR                                                                        EECR
	#define EEPROM_EEAR                                                                        EEAR
	#define EEPROM_EEDR                                                                        EEDR
	#define EEPROM_SPMCR                                                                      SPMCR
#endif
/**************************************************************************************************
*                                       FUNCTION PROTOTYPES                                       *
**************************************************************************************************/
boolean Eeprom_WriteByte(uint16 Param_Address, uint8 Param_Data);
boolean Eeprom_ReadByte(uint16 Param_Address, uint8* Param_DataOutPtr);
boolean Eeprom_WriteBuffer(uint16 Param_StartAddress, uint8* Param_DataPtr, uint16 Param_NumberOfBytes);
boolean Eeprom_ReadBuffer(uint16 Param_StartAddress, uint8* Param_DataOutPtr, uint16 Param_NumberOfBytes);

#endif /* EEPROM_H_ */