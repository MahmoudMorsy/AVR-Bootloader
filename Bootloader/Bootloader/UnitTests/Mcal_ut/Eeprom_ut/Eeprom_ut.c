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

static void ResetAllRegisters()
{
    Eeprom_EEAR = 0;
    Eeprom_EECR = 0;
    Eeprom_EEDR = 0;
    Eeprom_SPMCR = 0;    
}

static void Test_WriteByte_ValidInput()
{
    ResetAllRegisters();
    boolean Loc_Return = Eeprom_WriteByte(5, 10);
    UT_ASSERT_EQ("WriteByte_ValidInput", "Eeprom", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
    UT_ASSERT_EQ("WriteByte_ValidInput", "Eeprom", Eeprom_EEAR, 5,"Correct EEAR data" ,"Wrong EEAR (Address register) data");
    UT_ASSERT_EQ("WriteByte_ValidInput", "Eeprom", Eeprom_EEDR, 10,"Correct EEDR data", "Wrong EEDR (Data register) data");
    UT_ASSERT_EQ("WriteByte_ValidInput", "Eeprom", Eeprom_EECR, 0b00000110,"Correct EECR data", "Wrong EECR (Control register) data");
}

static void Test_ReadByte_ValidInput()
{
    ResetAllRegisters();
    Eeprom_EEDR = 195;
    uint8 Loc_ReturnByte = 0;
    boolean Loc_Return = Eeprom_ReadByte(5, &Loc_ReturnByte);
    UT_ASSERT_EQ("ReadByte_ValidInput", "Eeprom", Loc_Return, 1,"Correct Return status" ,"Wrong Return status");
    UT_ASSERT_EQ("ReadByte_ValidInput", "Eeprom", Eeprom_EEAR, 5,"Correct EEAR data" ,"Wrong EEAR (Address register) data");
    UT_ASSERT_EQ("ReadByte_ValidInput", "Eeprom", Loc_ReturnByte, 195,"Correct EEDR data", "Wrong EEDR (Data register) data");
    UT_ASSERT_EQ("ReadByte_ValidInput", "Eeprom", Eeprom_EECR, 0b00000001,"Correct EECR data", "Wrong EECR (Control register) data");
}

static void Test_WriteByte_InValidInput()
{
    ResetAllRegisters();
    boolean Loc_Return = Eeprom_WriteByte(1500, 10);
    UT_ASSERT_EQ("WriteByte_InValidInput_WrongMemoryAddress", "Eeprom", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
}

static void Test_ReadByte_InValidInput()
{
    ResetAllRegisters();
    uint8 Loc_ReturnByte = 0;
    boolean Loc_Return = Eeprom_ReadByte(5000, &Loc_ReturnByte);
    UT_ASSERT_EQ("ReadByte_InValidInput_WrongMemoryAddress", "Eeprom", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
    
    Loc_Return = Eeprom_ReadByte(10, NULL_PTR);
    UT_ASSERT_EQ("ReadByte_InValidInput_NullPointer", "Eeprom", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
}

static void Test_ReadBuffer_InValidInput()
{
    ResetAllRegisters();
    uint8 Loc_Data[5];
    boolean Loc_Return = Eeprom_ReadBuffer(1024, Loc_Data, 10);
    UT_ASSERT_EQ("ReadBuffer_InValidInput_WrongMemoryAddress", "Eeprom", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
    
    Loc_Return = Eeprom_ReadBuffer(1020, Loc_Data, 10);
    UT_ASSERT_EQ("ReadBuffer_InValidInput_WrongNumberOfBytes", "Eeprom", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
    
    Loc_Return = Eeprom_ReadBuffer(1020, NULL_PTR, 1);
    UT_ASSERT_EQ("ReadBuffer_InValidInput_NullPointer", "Eeprom", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");    
}

static void Test_WriteBuffer_InValidInput()
{
    ResetAllRegisters();
    uint8 Loc_Data[5];
    boolean Loc_Return = Eeprom_WriteBuffer(1024, Loc_Data, 10);
    UT_ASSERT_EQ("WriteBuffer_InValidInput_WrongMemoryAddress", "Eeprom", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
    
    Loc_Return = Eeprom_WriteBuffer(1020, Loc_Data, 10);
    UT_ASSERT_EQ("WriteBuffer_InValidInput_WrongNumberOfBytes", "Eeprom", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
    
    Loc_Return = Eeprom_WriteBuffer(1020, NULL_PTR, 1);
    UT_ASSERT_EQ("WriteBuffer_InValidInput_NullPointer", "Eeprom", Loc_Return, 0,"Correct Return status" ,"Wrong Return status");
}

void UT_Eeprom_RunAllTests()
{
    Test_WriteByte_ValidInput();
    UT_SEPARATE_TESTCASES();
    Test_ReadByte_ValidInput();
    UT_SEPARATE_TESTCASES();
    Test_WriteByte_InValidInput();
    UT_SEPARATE_TESTCASES();
    Test_ReadByte_InValidInput();
    UT_SEPARATE_TESTCASES();
    Test_ReadBuffer_InValidInput();
    UT_SEPARATE_TESTCASES();
    Test_WriteBuffer_InValidInput();
    UT_SEPARATE_TESTCASES();
} 

#endif