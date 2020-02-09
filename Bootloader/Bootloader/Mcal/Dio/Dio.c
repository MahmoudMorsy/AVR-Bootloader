/*
 * Dio.c
 *
 * Created: 2/7/2020 8:22:23 PM
 *  Author: MahmoudMorsy
 */ 

#include "Dio.h"

void Dio_WritePin(uint8 Param_PortNumber, uint8 Param_PinNumber, uint8 Param_value)
{
	boolean Loc_Pass = TRUE;
	if (Param_PortNumber >3 || Param_PortNumber <0)
	{
		//error 
		Loc_Pass = FALSE;
	}
	else
	{
		//Nothing
	}
	if (Param_PinNumber >7 || Param_PinNumber <0)
	{		
		//error
		Loc_Pass = FALSE;
	}
	else
	{
		//Nothing
	}
	if(Loc_Pass)
	{
		uint8* Loc_PortPtr;
		uint8 Loc_Pin = Param_PinNumber % 8;
	
		switch (Param_PortNumber)
		{
			case 0:
				Loc_PortPtr = PORTA;		
				break;
			case 1:
				Loc_PortPtr = PORTB;
				break;
			case 2:
				Loc_PortPtr = PORTC;
				break;		
			case 3:
				Loc_PortPtr = PORTD;
				break;		
			default:
				break;
		}
	
		if(HIGH == Param_value)
		{
			SET_BIT(Loc_PortPtr,Loc_Pin);
		}
		else
		{
			CLEAR_BIT(Loc_PortPtr,Loc_Pin);
		}
	}
	else
	{
		//error invalid param
	}
}

uint8 Dio_ReadPin(uint8 Param_PortNumber, uint8 Param_PinNumber)
{
	boolean Loc_Pass = TRUE;
	if (Param_PortNumber >3 || Param_PortNumber <0)
	{
		//error
		Loc_Pass = FALSE;
	}
	else
	{
		//Nothing
	}
	if (Param_PinNumber >7 || Param_PinNumber <0)
	{
		//error
		Loc_Pass = FALSE;
	}
	else
	{
		//Nothing
	}
	if(Loc_Pass)
	{
		uint8 * Loc_PinPtr;
		uint8 Loc_Pin = Param_PinNumber % 8;
		uint8 Loc_ReturnValue = LOW;
	
		switch (Param_PortNumber)
		{
			case 0:
			Loc_PinPtr = PINA;
			break;
			case 1:
			Loc_PinPtr = PINB;
			break;
			case 2:
			Loc_PinPtr = PINC;
			break;
			case 3:
			Loc_PinPtr = PIND;
			break;
			default:
			break;
		}
	
		if (GET_BIT(Loc_PinPtr,Loc_Pin))
		{
			Loc_ReturnValue = HIGH;
		}
		else
		{
			Loc_ReturnValue = LOW;
		}
	
		return Loc_ReturnValue;
	}
	else
	{
		//error invalid param
	}
}

void Dio_WritePort(uint8 Param_PortNumber, uint8 Param_value)
{
	boolean Loc_Pass = TRUE;
	if (Param_PortNumber >3 || Param_PortNumber <0)
	{
		//error
		Loc_Pass = FALSE;
	}
	else
	{
		//Nothing
	}
	if(Loc_Pass)
	{
		uint8* Loc_PortPtr;
		
		switch (Param_PortNumber)
		{
			case 0:
			Loc_PortPtr = PORTA;
			break;
			case 1:
			Loc_PortPtr = PORTB;
			break;
			case 2:
			Loc_PortPtr = PORTC;
			break;
			case 3:
			Loc_PortPtr = PORTD;
			break;
			default:
			break;
		}
	
		Loc_PortPtr = value;
	}
	else
	{
		//error
	}
}

uint8 Dio_ReadPort(uint8 Param_PortNumber)
{
	boolean Loc_Pass = TRUE;
	if (Param_PortNumber >3 || Param_PortNumber <0)
	{
		//error
		Loc_Pass = FALSE;
	}
	else
	{
		//Nothing
	}
	if(Loc_Pass)
	{
		uint8 * Loc_PinPtr;
		uint8 Loc_ReturnValue = LOW;
	
		switch (Param_PortNumber)
		{
			case 0:
			Loc_PinPtr = PINA;
			break;
			case 1:
			Loc_PinPtr = PINB;
			break;
			case 2:
			Loc_PinPtr = PINC;
			break;
			case 3:
			Loc_PinPtr = PIND;
			break;
			default:
			break;
		}
	
		Loc_ReturnValue = Loc_PinPtr;	
		return Loc_ReturnValue;
	}
	else
	{
		//error
	}
}

void Dio_SetPinDirection(uint8 Param_PortNumber, uint8 Param_PinNumber, uint8 mode)
{
	boolean Loc_Pass = TRUE;
	if (Param_PortNumber >3 || Param_PortNumber <0)
	{
		//error
		Loc_Pass = FALSE;
	}
	else
	{
		//Nothing
	}
	if (Param_PinNumber >7 || Param_PinNumber <0)
	{
		//error
		Loc_Pass = FALSE;
	}
	else
	{
		//Nothing
	}
	if(Loc_Pass)
	{
		uint8* Loc_DdrPtr;
		uint8 Loc_Pin = Param_PinNumber % 8;
	
		switch (Param_PortNumber)
		{
			case 0:
			Loc_DdrPtr = DDRA;
			break;
			case 1:
			Loc_DdrPtr = DDRB;
			break;
			case 2:
			Loc_DdrPtr = DDRC;
			break;
			case 3:
			Loc_DdrPtr = DDRD;
			break;
			default:
			break;
		}
	
		if(HIGH == mode)
		{
			SET_BIT(Loc_DdrPtr,Loc_Pin);
		}
		else
		{
			CLEAR_BIT(Loc_DdrPtr,Loc_Pin);
		}
	}
	else
	{
		//error
	}
}

void Dio_SetPortDirection(uint8 Param_PortNumber, uint8 mode)
{
	boolean Loc_Pass = TRUE;
	if (Param_PortNumber >3 || Param_PortNumber <0)
	{
		//error
		Loc_Pass = FALSE;
	}
	else
	{
		//Nothing
	}
	if(Loc_Pass)
	{
		uint8* Loc_DdrPtr;
	
		switch (Param_PortNumber)
		{
			case 0:
			Loc_DdrPtr = DDRA;
			break;
			case 1:
			Loc_DdrPtr = DDRB;
			break;
			case 2:
			Loc_DdrPtr = DDRC;
			break;
			case 3:
			Loc_DdrPtr = DDRD;
			break;
			default:
			break;
		}
	
		Loc_DdrPtr = mode;
	}
	else
	{
		//error
	}
}
