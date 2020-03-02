/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              Wdg_ut.c
* MODULE:            Wdg Unit Test
* AUTHOR:            MahmoudMorsy
* DESCRIPTION:       Unit test implementation for Wdg Mcal driver
* CREATION DATE:     21/2/2020
* MODIFICATION DATE: 21/2/2020
**************************************************************************************************/
#include "Wdg_ut.h"
#if UNIT_TESTING == STD_ON

static void ResetAllRegisters()
{
    Wdg_WDTCR = 0;
}

static void Test_AdjustPrescaler_ValidInputs()
{
    ResetAllRegisters();
    for (Wdg_OscCycles_en i = OSC_16; i<= OSC_2048; i++)
    {
        Wdg_AdjustPrescaler(i);
        UT_ASSERT_EQ("AdjustPrescaler_ValidInputs", "Wdg", Wdg_CurrentPrescaler, i,"Correct Prescaler" ,"Wrong Prescaler");        
    }
}

static void Test_EnableWdg()
{
    ResetAllRegisters();
    UT_ASSERT_EQ("Wdg_Enable", "Wdg", Wdg_CurrentState, DISABLED,"Correct State Value" ,"Wrong State Value");
    Wdg_AdjustPrescaler(OSC_2048);
    Wdg_Enable();
    UT_ASSERT_EQ("Wdg_Enable", "Wdg", Wdg_WDTCR, 0b00001111,"Correct WDTCR Value" ,"Wrong WDTCR Value");
    UT_ASSERT_EQ("Wdg_Enable", "Wdg", Wdg_CurrentState, RUNNING,"Correct State Value" ,"Wrong State Value");
}

static void Test_DisableWdg()
{
    UT_ASSERT_EQ("Wdg_Enable", "Wdg", Wdg_CurrentState, RUNNING,"Correct State Value" ,"Wrong State Value");
    Wdg_Disable();
    UT_ASSERT_EQ("Wdg_Disable", "Wdg", Wdg_WDTCR, 0,"Correct WDTCR Value" ,"Wrong WDTCR Value");
    UT_ASSERT_EQ("Wdg_Enable", "Wdg", Wdg_CurrentState, DISABLED,"Correct State Value" ,"Wrong State Value");
}

void UT_Wdg_RunAllTests()
{
    Test_AdjustPrescaler_ValidInputs();
    UT_SEPARATE_TESTCASES();
    Test_EnableWdg();
    UT_SEPARATE_TESTCASES();
    Test_DisableWdg();
    UT_SEPARATE_TESTCASES();
}

#endif