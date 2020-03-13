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
uint8 Adc_ADMUX                                                                                =0;
uint8 Adc_ADCSRA                                                                               =0;
uint8 Adc_ADCH                                                                                 =0;
uint8 Adc_ADCL                                                                                 =0;
uint8 Adc_SFIOR                                                                                =0;
uint16 Adc_DATA                                                                                =0;
#endif
                              
static uint16 Adc_Values[ADC_NUMBER_OF_CHANNELS+1] = {0,0,0,0,0,0,0,0};
static boolean Adc_Config_Channels[ADC_NUMBER_OF_CHANNELS+1] = {FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE};
static boolean Adc_Convert = FALSE;



/**************************************************************************************************
*                                     FUNCTIONS IMPLEMENTATION                                    *
**************************************************************************************************/
boolean Adc_Init(uint8 Param_ChannelNumber, uint8 Param_VolageReference, uint8 Param_PreScaler)
{
    boolean Loc_ReturnStatus = TRUE;
    if ((Param_ChannelNumber <=ADC_NUMBER_OF_CHANNELS) && (Param_VolageReference <=3) && (Param_PreScaler <= 7) )
    {
        /* No Gain !! */
        CLEAR_BIT(ADC_ADMUX,MUX4);
        CLEAR_BIT(ADC_ADMUX,MUX3);
        /* Choose channel according to user input */
        ADC_ADMUX = (ADC_ADMUX & 0xF8 ) | Param_ChannelNumber;
        /* Choose voltage reference according to user input */
        switch(Param_VolageReference)
        {
            case AREF:
            /* AREF, Internal Vref turned off */
            CLEAR_BIT(ADC_ADMUX,REFS1);
            CLEAR_BIT(ADC_ADMUX,REFS0);
            break;
            case AVCC:
            /* AVCC with external capacitor at AREF pin */
            CLEAR_BIT(ADC_ADMUX,REFS1);
            SET_BIT(ADC_ADMUX,REFS0);
            break;
            case INTERNAL_2V:
            /* Internal 2.56V Voltage Reference with external capacitor at AREF pin */
            SET_BIT(ADC_ADMUX,REFS1);
            SET_BIT(ADC_ADMUX,REFS0);
            break;
            default:
            /* AREF, Internal Vref turned off */
            CLEAR_BIT(ADC_ADMUX,REFS1);
            CLEAR_BIT(ADC_ADMUX,REFS0);
            break;
        }
        /* Choose pre-scaler according to user input */
        ADC_ADCSRA = (ADC_ADCSRA & 0xF8 ) | Param_PreScaler;
        
        /* Enable Adc */
        SET_BIT(ADC_ADCSRA,ADEN);
        
        /* Enable start conversion */
        SET_BIT(ADC_ADCSRA,ADSC);
        
        /* ADC Left Adjust Result */
        CLEAR_BIT(ADC_ADMUX,ADLAR);
        
        /* ADC Auto Trigger Enable */
       // SET_BIT(ADC_ADCSRA,ADATE);
        
        /* Enable Interrupt Flag */
        SET_BIT(ADC_ADCSRA,ADIF);
        
        /* Enable Interrupt */
        sei();
        SET_BIT(ADC_ADCSRA,ADIE);
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
    if ((Param_ReturnValue != NULL_PTR) && (Param_Channel <=ADC_NUMBER_OF_CHANNELS))
    {
        /* Add needed channel to array */
        Adc_Config_Channels[Param_Channel] = TRUE;
        /* Add Value to return to user */
        *Param_ReturnValue = Adc_Values[Param_Channel];
        /* Allow start conversion */
        Adc_Convert = TRUE;
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
    if(Adc_Convert)
    {
        /* Get Current Channel */
        uint8 currentChannel = ADC_ADMUX & 0x07;
        if(Adc_Config_Channels[currentChannel])
        {            
            /* Get Values from both registers */
            Adc_Values[currentChannel] = ADC_DATA;
    
            /* if reached last channel reset */
            if(currentChannel == ADC_NUMBER_OF_CHANNELS)
            {
                currentChannel = 255;
            }
            else
            {
                /* Do nothing */
            }
    
            /* Go to next Channel and Start Conversion */
            ADC_ADMUX = (ADC_ADMUX & 0xF8 ) | (currentChannel+1);
            /* Enable start conversion */
            SET_BIT(ADC_ADCSRA,ADSC);
            /* Disable Conversion */
            Adc_Convert = FALSE;
        }
        else
        {
            /* Do nothing */
        }        
    }
    else
    {
        /* Do nothing */
    }        
}