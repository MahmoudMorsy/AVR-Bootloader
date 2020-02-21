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
#include "Wdg.h"
#include "Eeprom.h"
/**************************************************************************************************
*                                     FUNCTIONS IMPLEMENTATION                                    *
**************************************************************************************************/
static uint8 counter = 0;
int main(void)
{
    Wdg_AdjustPrescaler(OSC_512);
    Wdg_Enable();
    Eeprom_ReadByte(0, &counter);
    counter++;
    Eeprom_WriteByte(0, counter);
	DDRA = 0xFF;
    SET_BIT(PORTA, 0);
    _delay_ms(500);
    CLEAR_BIT(PORTA, 0);
    Wdg_Feed();
    Wdg_Disable();
	while (1)
	{
            

		SET_BIT(PORTA, 5);
		_delay_ms(500);
        Wdg_Feed();
		CLEAR_BIT(PORTA, 5);
		_delay_ms(500);
                
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
