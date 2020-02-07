/*
 * Bootloader.c
 *
 * Created: 2/7/2020 7:49:01 PM
 * Author : MahmoudMorsy
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRA = 0xFF;
    while (1) 
    {
		PORTA = 0xFF;
		_delay_ms(1000);
		PORTA = 0x00;
		_delay_ms(1000);
    }
}

