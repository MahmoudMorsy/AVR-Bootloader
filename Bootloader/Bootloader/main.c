/*
 * Bootloader.c
 *
 * Created: 2/7/2020 7:49:01 PM
 * Author : MahmoudMorsy
 */ 
#include "Common.h"

#if UNIT_TESTING == STD_OFF
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0xFF;
	while (1)
	{
		SET_BIT(PORTA, 5);
		_delay_ms(1000);
		CLEAR_BIT(PORTA, 5);
		_delay_ms(1000);
	}
	return 0;
}

#else
#include "UnitTest.h"
int main(void)
{
	UT_RunAllTests();
}
#endif
