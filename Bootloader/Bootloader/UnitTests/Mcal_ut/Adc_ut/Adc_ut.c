/*
 * Adc_ut.c
 *
 * Created: 2/7/2020 8:26:41 PM
 *  Author: MahmoudMorsy
 */ 
/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              Adc_ut.c
* MODULE:            Adc Unit Test
* AUTHOR:            ShroukRashwan
* DESCRIPTION:       Unit test implementation for Adc Mcal driver
* CREATION DATE:     7/2/2020
* MODIFICATION DATE: 12/2/2020
**************************************************************************************************/
#include "Adc_ut.h"
#if UNIT_TESTING == STD_ON

static void ResetAllRegisters()
{
	Adc_ADMUX = 0;
	Adc_ADCSRA = 0;
	Adc_ADCH = 0;
	Adc_ADCL = 0;
	Adc_SFIOR = 0;
}


static void Test_Init_ValidInput()
{
	ResetAllRegisters();
	boolean Loc_Return = Adc_Init(0,3,6);
	UT_ASSERT_EQ("Init_ValidInput", "Adc", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	UT_ASSERT_EQ("Init_ValidInput", "Adc", Adc_ADMUX, 0b11000000,"Correct PORT data" ,"Wrong PORT data");
	UT_ASSERT_EQ("Init_ValidInput", "Adc", Adc_ADCSRA, 0b11011011,"Correct PORT data" ,"Wrong PORT data");
	
}

static void Test_Init_InValidInput()
{
	ResetAllRegisters();
	boolean Loc_Return = Adc_Init(1,2,9);
	UT_ASSERT_EQ("Init_InValidInput", "Adc", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
}

static void Test_ReadValue_ValidInput()
{
	ResetAllRegisters();
	Adc_Value = 1000;
	uint16 Loc_ReturnValue = 0;
	boolean Loc_Return = Adc_ReadValue(&Loc_ReturnValue);
	UT_ASSERT_EQ("ReadValue_ValidInput", "Adc", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	UT_ASSERT_EQ("ReadValue_ValidInput", "Adc", Loc_ReturnValue, 1000,"Correct Return data" ,"Wrong Return data");
}

static void Test_ReadValue_InValidInput()
{
	ResetAllRegisters();
	Adc_Value = 1000;
	boolean Loc_Return = Adc_ReadValue(NULL_PTR);
	UT_ASSERT_EQ("ReadValue_InValidInput", "Adc", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
}

void UT_Adc_RunAllTests()
{
	Test_Init_ValidInput();
	UT_SEPARATE_TESTCASES();
	Test_Init_InValidInput();
	UT_SEPARATE_TESTCASES();
	Test_ReadValue_ValidInput();
	UT_SEPARATE_TESTCASES();
	Test_ReadValue_InValidInput();
}

#endif