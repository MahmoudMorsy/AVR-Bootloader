/*
 * UnitTest.c
 *
 * Created: 2/8/2020 10:01:11 PM
 *  Author: MahmoudMorsy
 */ 

#include "UnitTest.h"

/* List of Unit test modules to be included */
#include "Eeprom_ut.h"

/* Main function to run all the modules test cases */
#if UNIT_TESTING == STD_ON
void UT_RunAllTests()
{
	/* List of All unit tests main function to be called here */
	UT_Eeprom_RunAllTests();
}
#else
void UT_RunAllTests(){}
#endif