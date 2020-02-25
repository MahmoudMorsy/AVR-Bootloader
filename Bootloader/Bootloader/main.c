/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              Main.c
* MODULE:            Main
* AUTHOR:            MahmoudMorsy
* DESCRIPTION:       Main application manager implementation to run the whole project.
* CREATION DATE:     7/2/2020
* MODIFICATION DATE: 9/2/2020
**************************************************************************************************/
#include "Common.h"
#if UNIT_TESTING == STD_OFF

/**************************************************************************************************
*                                        MACRO DEFINITIONS                                        *
**************************************************************************************************/
#define F_CPU                                                                             1000000UL

/**************************************************************************************************
*                                       INCLUDES & LIBRARIES                                      *
**************************************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
#include "Adc.h"


/**************************************************************************************************
*                                     FUNCTIONS IMPLEMENTATION                                    *
**************************************************************************************************/
int main(void)
{
    DDRA = 0xFF;
    Adc_Init(0,1,0);
    while (1)
    {
        uint16 value = 0;
        Adc_ReadValue(&value,0);
    }
    return 0;
}

/**************************************************************************************************
*                                        RUNNING UNITTESTS                                        *
**************************************************************************************************/
#else
#include "UnitTest.h"
int main(void)
{
	UT_RunAllTests();
}
#endif
