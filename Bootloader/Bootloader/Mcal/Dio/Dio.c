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
void Dio_WritePin(uint8 Param_PortNumber, uint8 Param_PinNumber, uint8 Param_value)
{
	/* Variable to determine if there is any error in function parameters */
	boolean Loc_Pass = TRUE;
	/* Check if Port Number is right. (0-3) */
	if (Param_PortNumber >3 || Param_PortNumber <0)
	{
		//error 
		Loc_Pass = FALSE;
	}
	else
	{
		//Nothing
	}
	
	uint8 Loc_Pin = Param_PinNumber % 8;		
	/* Check if Pin Number is right. (0-7) */
	if (Loc_Pin >7 || Loc_Pin <0)
	{		
		//error
		Loc_Pass = FALSE;
	}
	else
	{
		//Nothing
	}
	
	/* If passed the checks continue with code */
	if(Loc_Pass)
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
	}
	else
	{
		//error invalid param
	}
}

uint8 Dio_ReadPin(uint8 Param_PortNumber, uint8 Param_PinNumber)
{
	/* Variable to determine if there is any error in function parameters */
	boolean Loc_Pass = TRUE;
	/* Check if Port Number is right. (0-3) */
	if (Param_PortNumber >3 || Param_PortNumber <0)
	{
		//error
		Loc_Pass = FALSE;
	}
	else
	{
		//Nothing
	}
		
	uint8 Loc_Pin = Param_PinNumber % 8;		
	/* Check if Pin Number is right. (0-7) */
	if (Loc_Pin >7 || Loc_Pin <0)
	{
		//error
		Loc_Pass = FALSE;
	}
	else
	{
		//Nothing
	}
		
	/* If passed the checks continue with code */
	if(Loc_Pass)
	{
		uint8 * Loc_PinPtr;
		uint8 Loc_ReturnValue = LOW;	
		/* Get Suitable PIN regeistr according to Port number */
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
	/* Variable to determine if there is any error in function parameters */
	boolean Loc_Pass = TRUE;
	/* Check if Port Number is right. (0-3) */
	if (Param_PortNumber >3 || Param_PortNumber <0)
	{
		//error
		Loc_Pass = FALSE;
	}
	else
	{
		//Nothing
	}
		
	/* If passed the checks continue with code */
	if(Loc_Pass)
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
	}
	else
	{
		//error
	}
}

uint8 Dio_ReadPort(uint8 Param_PortNumber)
{
	/* Variable to determine if there is any error in function parameters */
	boolean Loc_Pass = TRUE;
	/* Check if Port Number is right. (0-3) */
	if (Param_PortNumber >3 || Param_PortNumber <0)
	{
		//error
		Loc_Pass = FALSE;
	}
	else
	{
		//Nothing
	}
			
	/* If passed the checks continue with code */
	if(Loc_Pass)
	{
		uint8 * Loc_PinPtr;
		uint8 Loc_ReturnValue = LOW;
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
		Loc_ReturnValue = Loc_PinPtr;	
		return Loc_ReturnValue;
	}
	else
	{
		//error
	}
}

void Dio_SetPinDirection(uint8 Param_PortNumber, uint8 Param_PinNumber, uint8 Param_Mode)
{
	/* Variable to determine if there is any error in function parameters */
	boolean Loc_Pass = TRUE;
	/* Check if Port Number is right. (0-3) */
	if (Param_PortNumber >3 || Param_PortNumber <0)
	{
		//error
		Loc_Pass = FALSE;
	}
	else
	{
		//Nothing
	}

	uint8 Loc_Pin = Param_PinNumber % 8;
	/* Check if Pin Number is right. (0-7) */
	if (Loc_Pin >7 || Loc_Pin <0)
	{
		//error
		Loc_Pass = FALSE;
	}
	else
	{
		//Nothing
	}

	/* If passed the checks continue with code */
	if(Loc_Pass)
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
	}
	else
	{
		//error
	}
}

void Dio_SetPortDirection(uint8 Param_PortNumber, uint8 Param_Mode)
{
	/* Variable to determine if there is any error in function parameters */
	boolean Loc_Pass = TRUE;
	/* Check if Port Number is right. (0-3) */
	if (Param_PortNumber >3 || Param_PortNumber <0)
	{
		//error
		Loc_Pass = FALSE;
	}
	else
	{
		//Nothing
	}

	/* If passed the checks continue with code */
	if(Loc_Pass)
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
	}
	else
	{
		//error
	}
}
