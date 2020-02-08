/*
 * Eeprom.c
 *
 * Created: 2/7/2020 8:22:40 PM
 *  Author: MahmoudMorsy
 */ 
#include "Eeprom.h"
#include <avr/io.h>
#include <avr/interrupt.h>

/* Stubbing for unit testing */
#ifdef UNIT_TESTING
/* Replacing Registers with Global Variables */
uint8 Eeprom_EECR = 0;
uint16 Eeprom_EEAR = 0;
uint8 Eeprom_EEDR = 0;
uint8 Eeprom_SPMCR = 0;
#define EEPROM_EECR Eeprom_EECR
#define EEPROM_EEAR Eeprom_EEAR
#define EEPROM_EEDR Eeprom_EEDR
#define EEPROM_EEDR Eeprom_SPMCR
/* Putting actual register addresses */
#else
#define EEPROM_EECR EECR
#define EEPROM_EEAR EEAR
#define EEPROM_EEDR EEDR
#define EEPROM_SPMCR SPMCR
#endif

boolean Eeprom_WriteByte(uint16 Param_Address, uint8 Param_Data)
{
	/* Checking if the target address is valid */
	if ((Param_Address >= EEPROM_START_ADDRESS) || (Param_Address <= EEPROM_LAST_ADDRESS))
	{
		/* Disable Global Interrupts */
		cli();
		/* Poll until EEWE bit in EECR register is equal to 0 */
		while (BIT_IS_SET(EEPROM_EECR,EEWE));
		/* Poll until SPMEN bit in SPMCR register is equal to 0 */
		while (BIT_IS_SET(EEPROM_SPMCR,SPMEN));
		/* Write EEPROM target address to EEAR */
		EEPROM_EEAR = Param_Address;
		/* Write data into EEPROM buffer register EEDR */
		EEPROM_EEDR = Param_Data;
		/* Write logical one to EEMWE bit in EECR register */
		SET_BIT(EEPROM_EECR, EEMWE);
		/* Write logical one to EEWE bit in EECR to trigger the EEPROM write operation */
		SET_BIT(EEPROM_EECR, EEWE);
		/* Wait until EEWE bit is cleared (EEPROM write finished) */
		while (BIT_IS_SET(EEPROM_EECR,EEWE));
		/* Re-enable Global Interrupts */
		sei();
		return TRUE;
	}
	else
	{
		/* Return an error state */
		return FALSE;
	}
}

boolean Eeprom_ReadByte(uint16 Param_Address, uint8* Param_DataOutPtr)
{
	/* Checking if the target address is valid */
	if ((Param_Address >= EEPROM_START_ADDRESS) || (Param_Address <= EEPROM_LAST_ADDRESS))
	{
		/* Disable Global Interrupts */
		cli();
		/* Poll until EEWE bit in EECR register is equal to 0 */
		while (BIT_IS_SET(EEPROM_EECR,EEWE));
		/* Poll until SPMEN bit in SPMCR register is equal to 0 */
		while (BIT_IS_SET(EEPROM_SPMCR,SPMEN));
		/* Write EEPROM target address to EEAR */
		EEPROM_EEAR = Param_Address;
		/* Write logical one to EERE bit in EECR to trigger the EEPROM read operation */
		SET_BIT(EEPROM_EECR, EERE);
		/* Return the read data from EEPROM to user */
		*Param_DataOutPtr = EEPROM_EEDR;
		/* Re-enable Global Interrupts */
		sei();
		return TRUE;
	}
	else
	{
		/* Return an error state */
		return FALSE;
	}
}

boolean Eeprom_WriteBuffer(uint16 Param_StartAddress, uint8* Param_DataPtr, uint16 Param_NumberOfBytes)
{
	/* Return variable */
	boolean Loc_ReturnValue = TRUE;
	
	/* Checking if the target address and number of bytes are valid */
	if ( (Param_StartAddress >= EEPROM_START_ADDRESS) && (Param_NumberOfBytes > 0)
	   && ((Param_StartAddress + Param_NumberOfBytes) <= (EEPROM_LAST_ADDRESS+1)) )
	{
		for (uint16 Loc_CurrentAddress = Param_StartAddress; Loc_CurrentAddress<(Param_StartAddress+Param_NumberOfBytes); Loc_CurrentAddress++)
		{
			if (Eeprom_WriteByte(Loc_CurrentAddress, Param_DataPtr[Loc_CurrentAddress-Param_StartAddress]) == FALSE)
			{
				Loc_ReturnValue = FALSE;
				break;
			}
			else
			{
				/* Do Nothing, Continue Writing to EEPROM */
			}
		}
	}
	else
	{
		/* Return an error state */
		Loc_ReturnValue = FALSE;
	}
	return Loc_ReturnValue;
}
boolean Eeprom_ReadBuffer(uint16 Param_StartAddress, uint8* Param_DataOutPtr, uint16 Param_NumberOfBytes)
{
	/* Return variable */
	boolean Loc_ReturnValue = TRUE;
	
	/* Checking if the target address and number of bytes are valid */
	if ( (Param_StartAddress >= EEPROM_START_ADDRESS) && (Param_NumberOfBytes > 0)
	&& ((Param_StartAddress + Param_NumberOfBytes) <= (EEPROM_LAST_ADDRESS+1)) )
	{
		for (uint16 Loc_CurrentAddress = Param_StartAddress; Loc_CurrentAddress<(Param_StartAddress+Param_NumberOfBytes); Loc_CurrentAddress++)
		{
			if (Eeprom_ReadByte(Loc_CurrentAddress, &(Param_DataOutPtr[Loc_CurrentAddress-Param_StartAddress])) == FALSE)
			{
				Loc_ReturnValue = FALSE;
				break;
			}
			else
			{
				/* Do Nothing, Continue Reading EEPROM */
			}
		}
	}
	else
	{
		/* Return an error state */
		Loc_ReturnValue = FALSE;
	}
	return Loc_ReturnValue;
}
