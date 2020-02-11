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
	boolean Loc_Return = Dio_SetPinDirection(0,2,0);
	UT_ASSERT_EQ("SetPinDirection_ValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	UT_ASSERT_EQ("SetPinDirection_ValidInput", "Dio", DDRA>>2, 0,"Correct DDRA_Pin2 data" ,"Wrong DDRA_Pin2 data");
}

static void Test_SetPinDirection_InValidInput()
{
	ResetAllRegisters();
	boolean Loc_Return = Dio_SetPinDirection(3,45,0);
	UT_ASSERT_EQ("SetPinDirection_InValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	boolean Loc_Return = Dio_SetPinDirection(9,4,0);
	UT_ASSERT_EQ("SetPinDirection_InValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
}

static void Test_SetPortDirection_ValidInput()
{
	ResetAllRegisters();
	boolean Loc_Return = Dio_SetPortDirection(1,1);
	UT_ASSERT_EQ("SetPortDirection_ValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	UT_ASSERT_EQ("SetPortDirection_ValidInput", "Dio", DDRB, 1,"Correct DDRB data" ,"Wrong DDRB data");
}

static void Test_SetPortDirection_InValidInput()
{
	ResetAllRegisters();
	boolean Loc_Return = Dio_SetPortDirection(9,0);
	UT_ASSERT_EQ("SetPinDirection_InValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
}

static void Test_WriteBit_ValidInput()
{
	ResetAllRegisters();
	boolean Loc_Return = Dio_WritePin(3,4,1)
	UT_ASSERT_EQ("WriteBit_ValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	UT_ASSERT_EQ("WriteBit_ValidInput", "Dio", PORTD>>4, 1,"Correct Pin data" ,"Wrong pin data");
}

static void Test_ReadBit_ValidInput()
{
	ResetAllRegisters();
	PORTC = 1000000;
	uint8 Loc_ReturnByte = 0;
	boolean Loc_Return = Dio_ReadPin(2,7, &Loc_ReturnByte);
	UT_ASSERT_EQ("ReadBit_ValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	UT_ASSERT_EQ("ReadBit_ValidInput", "Dio", Loc_ReturnByte, 1,"Correct PORTC_Pin7 data" ,"Wrong PORTC_Pin7 data");
} 

static void Test_WriteBit_InValidInput()
{
	ResetAllRegisters();
	boolean Loc_Return = Dio_WritePin(9,4,1)
	UT_ASSERT_EQ("WriteBit_InValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	boolean Loc_Return = Dio_WritePin(1,54,1)
	UT_ASSERT_EQ("WriteBit_InValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	
}

static void Test_ReadBit_InValidInput()
{
	ResetAllRegisters();
	PORTC = 1000000;
	uint8 Loc_ReturnByte = 0;
	boolean Loc_Return = Dio_ReadPin(2,8, &Loc_ReturnByte);
	UT_ASSERT_EQ("ReadBit_InValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	boolean Loc_Return = Dio_ReadPin(2,8, NULL_PTR);
	UT_ASSERT_EQ("ReadBit_InValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
}

static void Test_WritePort_ValidInput()
{
	ResetAllRegisters();
	boolean Loc_Return = Dio_WritePort(1,25)
	UT_ASSERT_EQ("WritePort_ValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	UT_ASSERT_EQ("WritePort_ValidInput", "Dio", PORTB, 25,"Correct Port data" ,"Wrong Port data");
	
}

static void Test_ReadPort_ValidInput()
{
	ResetAllRegisters();
	PORTC = 1010111;
	uint8 Loc_ReturnByte = 0;
	boolean Loc_Return = Dio_ReadPin(2,&Loc_ReturnByte);
	UT_ASSERT_EQ("ReadPort_ValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	UT_ASSERT_EQ("ReadPort_ValidInput", "Dio", Loc_ReturnByte, 1010111,"Correct PORT data" ,"Wrong PORT data");
}

static void Test_WritePort_InValidInput()
{
	ResetAllRegisters();
	boolean Loc_Return = Dio_WritePort(67,25)
	UT_ASSERT_EQ("WritePort_ValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
}

static void Test_ReadPort_InValidInput()
{
	ResetAllRegisters();
		PORTC = 1000000;
		uint8 Loc_ReturnByte = 0;
		boolean Loc_Return = Dio_ReadPin(12, &Loc_ReturnByte);
		UT_ASSERT_EQ("ReadBit_InValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
		boolean Loc_Return = Dio_ReadPin(2, NULL_PTR);
		UT_ASSERT_EQ("ReadBit_InValidInput", "Dio", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
	
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
	Test_WriteBit_ValidInput();
	UT_SEPARATE_TESTCASES();
	Test_ReadBit_ValidInput();
	UT_SEPARATE_TESTCASES();
	Test_WriteBit_InValidInput();
	UT_SEPARATE_TESTCASES();
	Test_ReadBit_InValidInput();
	UT_SEPARATE_TESTCASES();
	Test_WriteBit_ValidInput();
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