/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              Dio_ut.c
* MODULE:            Dio Unit Test
* AUTHOR:            ShroukRashwan
* DESCRIPTION:       Unit test implementation for Dio Mcal driver
* CREATION DATE:     7/2/2020
* MODIFICATION DATE: 11/2/2020
**************************************************************************************************/
#include "Dio_ut.h"
#if UNIT_TESTING == STD_ON

static void ResetAllRegisters()
{
	Dio_PINA = 0;
	Dio_PORTA = 0;
	Dio_DDRA = 0;

	Dio_PINB = 0;
	Dio_PORTB = 0;
	Dio_DDRB = 0;
	
	Dio_PINC = 0;
	Dio_PORTC	= 0;
	Dio_DDRC = 0;
	
	Dio_PIND = 0;
	Dio_PORTD	= 0;
	Dio_DDRD = 0;
}

static void Test_SetPinDirection_ValidInput()
{
	ResetAllRegisters();
	boolean Loc_Return = Dio_SetPinDirection(PORT_A,2,OUTPUT);
	UT_ASSERT_EQ("SetPinDirection_ValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	UT_ASSERT_EQ("SetPinDirection_ValidInput", "Dio", Dio_DDRA>>2, 0,"Correct DDRA_Pin2 data" ,"Wrong DDRA_Pin2 data");
}

static void Test_SetPinDirection_InValidInput()
{
	ResetAllRegisters();
	boolean Loc_Return = Dio_SetPinDirection(PORT_D,9,OUTPUT);
	UT_ASSERT_EQ("SetPinDirection_InValidInput", "Dio", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
	Loc_Return = Dio_SetPinDirection(9,4,0);
	UT_ASSERT_EQ("SetPinDirection_InValidInput", "Dio", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
}

static void Test_SetPortDirection_ValidInput()
{
	ResetAllRegisters();
	boolean Loc_Return = Dio_SetPortDirection(PORT_B,1);
	UT_ASSERT_EQ("SetPortDirection_ValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	UT_ASSERT_EQ("SetPortDirection_ValidInput", "Dio", Dio_DDRB, 1,"Correct DDRB data" ,"Wrong DDRB data");
}

static void Test_SetPortDirection_InValidInput()
{
	ResetAllRegisters();
	boolean Loc_Return = Dio_SetPortDirection(9,0);
	UT_ASSERT_EQ("SetPinDirection_InValidInput", "Dio", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
}

static void Test_WritePin_ValidInput()
{
	ResetAllRegisters();
	boolean Loc_Return = Dio_WritePin(PORT_D,4,1);
	UT_ASSERT_EQ("WritePin_ValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	UT_ASSERT_EQ("WritePin_ValidInput", "Dio", Dio_PORTD>>4, 1,"Correct Pin data" ,"Wrong pin data");
}

static void Test_ReadPin_ValidInput()
{
	ResetAllRegisters();
	Dio_PINC = 0b10000000;
	uint8 Loc_ReturnByte = 0;
	boolean Loc_Return = Dio_ReadPin(PORT_C,7, &Loc_ReturnByte);
	UT_ASSERT_EQ("ReadPin_ValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	UT_ASSERT_EQ("ReadPin_ValidInput", "Dio", Loc_ReturnByte, 1,"Correct PORTC_Pin7 data" ,"Wrong PORTC_Pin7 data");
} 

static void Test_WritePin_InValidInput()
{
	ResetAllRegisters();
	boolean Loc_Return = Dio_WritePin(9,4,1);
	UT_ASSERT_EQ("WritePin_InValidInput", "Dio", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
	Loc_Return = Dio_WritePin(1,9,1);
	UT_ASSERT_EQ("WritePin_InValidInput", "Dio", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
	
}

static void Test_ReadPin_InValidInput()
{
	ResetAllRegisters();
	
	Dio_PINC = 0b10000000;
	uint8 Loc_ReturnByte = 0;
	boolean Loc_Return = Dio_ReadPin(PORT_C,8, &Loc_ReturnByte);
	UT_ASSERT_EQ("ReadPin_InValidInput", "Dio", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
	Loc_Return = Dio_ReadPin(PORT_C,5, NULL_PTR);
	UT_ASSERT_EQ("ReadPin_InValidInput", "Dio", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
}

static void Test_WritePort_ValidInput()
{
	ResetAllRegisters();
	boolean Loc_Return = Dio_WritePort(PORT_B,25);
	UT_ASSERT_EQ("WritePort_ValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	UT_ASSERT_EQ("WritePort_ValidInput", "Dio", Dio_PORTB, 25,"Correct Port data" ,"Wrong Port data");
	
}

static void Test_ReadPort_ValidInput()
{
	ResetAllRegisters();
	Dio_PINA = 0b11111111;
	uint8 Loc_ReturnByte = 0;
	boolean Loc_Return = Dio_ReadPort(PORT_A,&Loc_ReturnByte);
	UT_ASSERT_EQ("ReadPort_ValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	UT_ASSERT_EQ("ReadPort_ValidInput", "Dio", Loc_ReturnByte, 0b11111111,"Correct PORT data" ,"Wrong PORT data");
}

static void Test_WritePort_InValidInput()
{
	ResetAllRegisters();
	boolean Loc_Return = Dio_WritePort(9,25);
	UT_ASSERT_EQ("WritePort_ValidInput", "Dio", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
}

static void Test_ReadPort_InValidInput()
{
	ResetAllRegisters();
	Dio_PORTC = 0b1000000;
	uint8 Loc_ReturnByte = 0;
	boolean Loc_Return = Dio_ReadPort(12, &Loc_ReturnByte);
	UT_ASSERT_EQ("ReadBit_InValidInput", "Dio", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
	Loc_Return = Dio_ReadPort(PORT_C, NULL_PTR);
	UT_ASSERT_EQ("ReadBit_InValidInput", "Dio", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
	
}

void UT_Dio_RunAllTests()
{
	Test_SetPinDirection_ValidInput();
	UT_SEPARATE_TESTCASES();
	Test_SetPinDirection_InValidInput();
	UT_SEPARATE_TESTCASES();
	Test_SetPortDirection_ValidInput();
	UT_SEPARATE_TESTCASES();
	Test_SetPortDirection_InValidInput();
	UT_SEPARATE_TESTCASES();
	Test_WritePin_ValidInput();
	UT_SEPARATE_TESTCASES();
	Test_ReadPin_ValidInput();
	UT_SEPARATE_TESTCASES();
	Test_WritePin_InValidInput();
	UT_SEPARATE_TESTCASES();
	Test_ReadPin_InValidInput();
	UT_SEPARATE_TESTCASES();
	Test_WritePin_ValidInput();
	UT_SEPARATE_TESTCASES();
	Test_WritePort_ValidInput();
	UT_SEPARATE_TESTCASES();
	Test_ReadPort_ValidInput();
	UT_SEPARATE_TESTCASES();
	Test_WritePort_InValidInput();
	UT_SEPARATE_TESTCASES();
	Test_ReadPort_InValidInput();

}

#endif