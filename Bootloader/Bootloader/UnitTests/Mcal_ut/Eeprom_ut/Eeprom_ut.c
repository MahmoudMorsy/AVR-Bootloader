/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              Eeprom_ut.c
* MODULE:            Eeprom Unit Test
* AUTHOR:            MahmoudMorsy
* DESCRIPTION:       Unit test implementation for Eeprom Mcal driver
* CREATION DATE:     7/2/2020
* MODIFICATION DATE: 9/2/2020
**************************************************************************************************/
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