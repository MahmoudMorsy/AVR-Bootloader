/*
 * Eeprom_ut.c
 *
 * Created: 2/7/2020 8:27:35 PM
 *  Author: MahmoudMorsy
 */ 
#include "Eeprom_ut.h"
#if UNIT_TESTING == STD_ON
static void Test_WriteByte()
{
	Eeprom_WriteByte(5, 10);
	UT_ASSERT_EQ("WriteByte", "Eeprom", Eeprom_EEAR, 5,"Correct EEAR data" ,"Wrong EEAR (Address register) data");
	UT_ASSERT_EQ("WriteByte", "Eeprom", Eeprom_EEDR, 7,"Correct EEDR data", "Wrong EEDR (Data register) data");
	UT_ASSERT_EQ("WriteByte", "Eeprom", Eeprom_EECR, 0b00000110,"Correct EECR data", "Wrong EECR (Control register) data");
}

void UT_Eeprom_RunAllTests()
{
	Test_WriteByte();
	
} 

#endif