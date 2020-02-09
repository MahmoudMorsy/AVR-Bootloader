/*
 * Eeprom_ut.h
 *
 * Created: 2/7/2020 8:27:42 PM
 *  Author: MahmoudMorsy
 */ 


#ifndef EEPROM_UT_H_
#define EEPROM_UT_H_
#include "UnitTest.h"
#include "Eeprom.h"

#if UNIT_TESTING == STD_ON
	extern uint8 Eeprom_EECR;
	extern uint16 Eeprom_EEAR;
	extern uint8 Eeprom_EEDR;
	extern uint8 Eeprom_SPMCR;
	void UT_Eeprom_RunAllTests();
#endif

#endif /* EEPROM_UT_H_ */