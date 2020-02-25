/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              Adc.c
* MODULE:            Adc
* AUTHOR:            ShroukRashwan
* DESCRIPTION:       Adc driver functional implementation
* CREATION DATE:     7/2/2020
* MODIFICATION DATE: 12/2/2020
**************************************************************************************************/

/**************************************************************************************************
*                                       INCLUDES & LIBRARIES                                      *
**************************************************************************************************/
#include "Adc.h"
#include "Adc_Internal.h"

/**************************************************************************************************
*                                         GLOBAL VARIABLES                                        *
**************************************************************************************************/
#if UNIT_TESTING == STD_ON
	uint8 Adc_ADMUX																				=0;
	uint8 Adc_ADCSRA																			=0;
	uint8 Adc_ADCH																				=0;
	uint8 Adc_ADCL																				=0;
	uint8 Adc_SFIOR																				=0;
#endif

uint16 Adc_Value 																				=0;
uint16 Adc_Values[8] = {0,0,0,0,0,0,0,0};


/**************************************************************************************************
*                                     FUNCTIONS IMPLEMENTATION                                    *
**************************************************************************************************/
boolean Adc_Init(uint8 Param_ChannelNumber, uint8 Param_VolageReference, uint8 Param_PreScaler)
{
    boolean Loc_ReturnStatus = TRUE;
	if ((Param_ChannelNumber <=7) && (Param_VolageReference <=3) &&	(Param_PreScaler <= 7) )
	{
		/* No Gain !! */
		CLEAR_BIT(ADC_ADMUX,4);
		CLEAR_BIT(ADC_ADMUX,3);
		/* Choose channel according to user input */
		ADC_ADMUX = ADC_ADMUX | (0xFF & Param_ChannelNumber);
		/* Choose voltage reference according to user input */
		switch(Param_VolageReference)
		{
			case 0:
				/* AREF, Internal Vref turned off */
				CLEAR_BIT(ADC_ADMUX,7);
				CLEAR_BIT(ADC_ADMUX,6);
			break;			
			case 1:
				/* AVCC with external capacitor at AREF pin */
				CLEAR_BIT(ADC_ADMUX,7);
				SET_BIT(ADC_ADMUX,6);
			break;					
			case 3:
				/* Internal 2.56V Voltage Reference with external capacitor at AREF pin */
				SET_BIT(ADC_ADMUX,7);
				SET_BIT(ADC_ADMUX,6);
			break;
			default:
				/* AREF, Internal Vref turned off */
				CLEAR_BIT(ADC_ADMUX,7);
				CLEAR_BIT(ADC_ADMUX,6);
			break;
		}
		/* Choose pre-scaler according to user input */
		ADC_ADCSRA = ADC_ADCSRA | (0xFF & Param_PreScaler);
		
		/* Enable Adc */
		SET_BIT(ADC_ADCSRA,7);
		
		/* Enable start conversion */
		SET_BIT(ADC_ADCSRA,6);
		
		/* Enable start conversion */
		CLEAR_BIT(ADC_ADMUX,5);
		
		/* Enable Interrupt Flag */
		SET_BIT(ADC_ADCSRA,4);
		
		/* Enable Interrupt */
		sei();
		SET_BIT(ADC_ADCSRA,3);	
	}
	else
	{
		/*Error in parameters*/
		Loc_ReturnStatus = FALSE;
	}
    
    return Loc_ReturnStatus;
}

boolean Adc_ReadValue(uint16* Param_ReturnValue, uint8 Param_Channel)
{
    boolean Loc_ReturnStatus = TRUE;
	if ((Param_ReturnValue != NULL_PTR) && (Param_Channel <=7))
	{
		/* Add Value to return to user */
		*Param_ReturnValue = Adc_Values[Param_Channel];
	}
	else
	{
		/*Error in parameters*/
		Loc_ReturnStatus = FALSE;
	}
    
    return Loc_ReturnStatus;
}


ISR(ADC_vect)
{
    /* Get Current Channel */
    uint8 currentChannel = ADC_ADMUX & 0x0F;
	/* Get Values from both registers */
	Adc_Values[currentChannel] = ADC_ADCH << 7 || ADC_ADCL;
    
    /* if reached last channel reset */
    if(currentChannel == 7)
    {
       currentChannel = 255;
    }
    else
    {
        /* Do nothing */
    }
    
    /* Go to next Channel and Start Conversion */
    ADC_ADMUX = ADC_ADMUX | (0xFF & (currentChannel+1));
    /* Enable start conversion */
    SET_BIT(ADC_ADCSRA,6);
    
    
}