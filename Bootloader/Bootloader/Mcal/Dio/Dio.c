/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              Dio.c
* MODULE:            Dio
* AUTHOR:            ShroukRashwan
* DESCRIPTION:       Dio driver functional implementation
* CREATION DATE:     7/2/2020
* MODIFICATION DATE: 10/2/2020
**************************************************************************************************/

#include "Dio.h"

/**************************************************************************************************
*                                     FUNCTIONS IMPLEMENTATION                                    *
**************************************************************************************************/


/*
*
*
*
*/
boolean Dio_WritePin(uint8 Param_PortNumber, uint8 Param_PinNumber, uint8 Param_value)
{
	
	uint8 Loc_Pin = Param_PinNumber % 8;
			
	/* Check if Port Number is right. (0-3) */
	/* Check if Pin Number is right. (0-7) */
	/* If passed the checks continue with code */
	if(Param_PortNumber >3 && Param_PortNumber =>0 && Loc_Pin =<7 && Loc_Pin >=0)
	{
		uint8* Loc_PortPtr;		
		/* Get the suitable PORT according to port number */
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
		/* Check value passed by user */
		if(HIGH == Param_value)
		{
			/* Set pin to high */
			SET_BIT(Loc_PortPtr,Loc_Pin);
		}
		else
		{
			/* Clear pin (LOW) */
			CLEAR_BIT(Loc_PortPtr,Loc_Pin);
		}
		
		return true;
	}
	else
	{
		/* Parameter Error */
		return false;
	}
}

boolean Dio_ReadPin(uint8 Param_PortNumber, uint8 Param_PinNumber, uint8* Param_ReturnValue)
{
	uint8 Loc_Pin = Param_PinNumber % 8;
	/* Check if Port Number is right. (0-3) */		
	/* Check if Pin Number is right. (0-7) */
	/* If passed the checks continue with code */
	if((Param_PortNumber =<3 && Param_PortNumber => 0 && Loc_Pin =<7 && Loc_Pin =>0)
	{
		uint8 * Loc_PinPtr;
		uint8 Loc_ReturnValue = LOW;	
		/* Get Suitable PIN register according to Port number */
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
		/* Get pin value and return it to the user*/	
		if (GET_BIT(Loc_PinPtr,Loc_Pin))
		{
			*Param_ReturnValue = HIGH;
		}
		else
		{
			*Param_ReturnValue = LOW;
		}	
		return true;
	}
	else
	{
		//error invalid param
		return false
	}
}

boolean Dio_WritePort(uint8 Param_PortNumber, uint8 Param_value)
{

	/* Check if Port Number is right. (0-3) */
	/* If passed the checks continue with code */
	if(Param_PortNumber =<3  && Param_PortNumber =>0)
	{
		uint8* Loc_PortPtr;
		/* Get suitable PORT register according to port number*/
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
		/* Set port with given value */
		Loc_PortPtr = value;
		return true;
	}
	else
	{
		//error in parameter
		return false
	}
}

boolean Dio_ReadPort(uint8 Param_PortNumber, uint8* Param_ReturnValue)
{
	/* Check if Port Number is right. (0-3) */
	/* If passed the checks continue with code */
	if(Param_PortNumber =<3 && Param_PortNumber =>0)
	{
		uint8 * Loc_PinPtr;
		/* Determine suitable PIN register according to given port number*/
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
	
		/* Return port value to user */
		*Param_ReturnValue = Loc_PinPtr;	
		return true;
	}
	else
	{
		//error
		return false
	}
}

boolean Dio_SetPinDirection(uint8 Param_PortNumber, uint8 Param_PinNumber, uint8 Param_Mode)
{
	uint8 Loc_Pin = Param_PinNumber % 8;
	/* Check if Port Number is right. (0-3) */
	/* Check if Pin Number is right. (0-7) */
	/* If passed the checks continue with code */
	if(Param_PortNumber =<3 && Param_PortNumber =>0 && Loc_Pin =<7 && Loc_Pin =>0 )
	{
		uint8* Loc_DdrPtr;
  		/* Get suitable DDR register according to given port number */
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
	
		/* Set pin with given value */
		if(HIGH == Param_Mode)
		{
			SET_BIT(Loc_DdrPtr,Loc_Pin);
		}
		else
		{
			CLEAR_BIT(Loc_DdrPtr,Loc_Pin);
		}
		return true;
	}
	else
	{
		//error
		return false;
	}
}

boolean Dio_SetPortDirection(uint8 Param_PortNumber, uint8 Param_Mode)
{
	/* Check if Port Number is right. (0-3) */
	/* If passed the checks continue with code */
	if(Param_PortNumber =<3 && Param_PortNumber =>0)
	{
		uint8* Loc_DdrPtr;
		/* Get suitable DDR register according to given port number */
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
	
		/* Set port with given value */
		Loc_DdrPtr = Param_Mode;
		
		return true;
	}
	else
	{
		//error
		return false;
	}
}
