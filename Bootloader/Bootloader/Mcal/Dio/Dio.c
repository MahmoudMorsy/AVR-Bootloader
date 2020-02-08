/*
 * Dio.c
 *
 * Created: 2/7/2020 8:22:23 PM
 *  Author: MahmoudMorsy
 */ 

#include "Dio.h"

void Dio_WritePin(uint8 portNumber, uint8 pinNumber, uint8 value)
{
	uint8* PORT_Ptr;
	uint8 pin = pinNumber % 8;
	
	switch (portNumber)
	{
		case 0:
			PORT_Ptr = PORTA;		
			break;
		case 1:
			PORT_Ptr = PORTB;
			break;
		case 2:
			PORT_Ptr = PORTC;
			break;		
		case 3:
			PORT_Ptr = PORTD;
			break;		
		default:
			break;
	}
	
	if(HIGH == value)
	{
		SET_BIT(PORT_Ptr,pin);
	}
	else
	{
		CLEAR_BIT(PORT_Ptr,pin);
	}
}

uint8 Dio_ReadPin(uint8 portNumber, uint8 pinNumber)
{
	uint8 * PIN_Ptr;
	uint8 pin = pinNumber % 8;
	uint8 returnValue = LOW;
	
	switch (portNumber)
	{
		case 0:
		PIN_Ptr = PINA;
		break;
		case 1:
		PIN_Ptr = PINB;
		break;
		case 2:
		PIN_Ptr = PINC;
		break;
		case 3:
		PIN_Ptr = PIND;
		break;
		default:
		break;
	}
	
	if (GET_BIT(PIN_Ptr,pin))
	{
		returnValue = HIGH;
	}
	else
	{
		returnValue = LOW;
	}
	
	return returnValue;
}

void Dio_WritePort(uint8 portNumber, uint8 value)
{
	uint8* PORT_Ptr;
		
	switch (portNumber)
	{
		case 0:
		PORT_Ptr = PORTA;
		break;
		case 1:
		PORT_Ptr = PORTB;
		break;
		case 2:
		PORT_Ptr = PORTC;
		break;
		case 3:
		PORT_Ptr = PORTD;
		break;
		default:
		break;
	}
	
	PORT_Ptr = value;
}

uint8 Dio_ReadPort(uint8 portNumber)
{
	uint8 * PIN_Ptr;
	uint8 returnValue = LOW;
	
	switch (portNumber)
	{
		case 0:
		PIN_Ptr = PINA;
		break;
		case 1:
		PIN_Ptr = PINB;
		break;
		case 2:
		PIN_Ptr = PINC;
		break;
		case 3:
		PIN_Ptr = PIND;
		break;
		default:
		break;
	}
	
	returnValue = PIN_Ptr;	
	return returnValue;
}

void Dio_SetPinDirection(uint8 portNumber, uint8 pinNumber, uint8 mode)
{
	uint8* DDR_Ptr;
	uint8 pin = pinNumber % 8;
	
	switch (portNumber)
	{
		case 0:
		DDR_Ptr = DDRA;
		break;
		case 1:
		DDR_Ptr = DDRB;
		break;
		case 2:
		DDR_Ptr = DDRC;
		break;
		case 3:
		DDR_Ptr = DDRD;
		break;
		default:
		break;
	}
	
	if(HIGH == mode)
	{
		SET_BIT(PORT_Ptr,pin);
	}
	else
	{
		CLEAR_BIT(PORT_Ptr,pin);
	}
}

void Dio_SetPortDirection(uint8 portNumber, uint8 mode)
{
	uint8* DDR_Ptr;
	
	switch (portNumber)
	{
		case 0:
		DDR_Ptr = DDRA;
		break;
		case 1:
		DDR_Ptr = DDRB;
		break;
		case 2:
		DDR_Ptr = DDRC;
		break;
		case 3:
		DDR_Ptr = DDRD;
		break;
		default:
		break;
	}
	
	DDR_Ptr = mode;
}