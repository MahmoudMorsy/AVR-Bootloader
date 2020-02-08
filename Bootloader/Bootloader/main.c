/*
 * Bootloader.c
 *
 * Created: 2/7/2020 7:49:01 PM
 * Author : MahmoudMorsy
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Common/Common_Macros.h"
#include "Common/Common_Types.h"
#include "Mcal/Eeprom/Eeprom.h"
uint8 Data1,Data2,Data3,Data4,Data5;
int main(void)
{
    /* Replace with your application code */
	uint8 Data[] = {1,2,3,4,5,6,7,8,9,10};
	Eeprom_WriteBuffer(20,Data,10);
	Eeprom_ReadBuffer(15, Data, 10);
	Eeprom_WriteBuffer(20,Data,10);
	//
	//Eeprom_ReadByte(0, &Data1);
	//Eeprom_WriteByte(0, 1);
	//Eeprom_ReadByte(0, &Data1);
	//Eeprom_WriteByte(1, 9);
	//Eeprom_ReadByte(2, &Data2);
	//Eeprom_WriteByte(2, 1);
	//Eeprom_ReadByte(2, &Data2);
	//Eeprom_WriteByte(3, 9);
	//Eeprom_WriteByte(4, 9);
	//Eeprom_WriteByte(5, 5);
	//
	//Eeprom_ReadByte(10, &Data3);
	//
	//Eeprom_WriteByte(1018, 1);
	//Eeprom_WriteByte(1019, 9);
	//Eeprom_WriteByte(1020, 1);
	//Eeprom_ReadByte(1021, &Data4);
	//Eeprom_WriteByte(1021, 9);
	//Eeprom_ReadByte(1021, &Data4);
	//Eeprom_WriteByte(1022, 9);
	//Eeprom_WriteByte(1023, 5);
	//Eeprom_ReadByte(1023, &Data5);
	DDRA = 0xFF;
    while (1) 
    {
		SET_BIT(PORTA, 5);
		_delay_ms(1000);
		CLEAR_BIT(PORTA, 5);
		_delay_ms(1000);
    }
}

