/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              UnitTest.c
* MODULE:            Unit Test
* AUTHOR:            MahmoudMorsy
* DESCRIPTION:       Unit test running environment where developers should include their unit test
*                    files here and call their UT_ModuleName_RunAllTests() function in 
*                    "UT_RunAllTests()" function body.
* CREATION DATE:     8/2/2020
* MODIFICATION DATE: 9/2/2020
**************************************************************************************************/
#include "UnitTest.h"
#if UNIT_TESTING == STD_ON

/**************************************************************************************************
*                          LIST OF UNIT TEST HEADER FILES TO BE INCLUDED                          *
**************************************************************************************************/
#include "Eeprom_ut.h"
#include "Wdg_ut.h"

/**************************************************************************************************
*                                     FUNCTIONS IMPLEMENTATION                                    *
**************************************************************************************************/
/* Main function to run all the modules test cases */
void UT_RunAllTests()
{
    UT_PRINT_HEADER();
    
    /* USER-MODIFIED-SECTION : List of All unit tests main function to be called here */
    UT_Eeprom_RunAllTests();
    UT_SEPARATE_TESTMODULES();
    UT_Wdg_RunAllTests();
    UT_SEPARATE_TESTMODULES();
}
#else
/* Empty function */
void UT_RunAllTests(){}
#endif