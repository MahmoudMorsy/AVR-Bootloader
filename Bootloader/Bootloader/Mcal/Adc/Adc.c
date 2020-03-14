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
                              
static volatile uint16 Adc_Values[ADC_NUMBER_OF_CHANNELS+1] = {0,0,0,0,0,0,0,0};
static boolean Adc_Async = FALSE;



/**************************************************************************************************
*                                     FUNCTIONS IMPLEMENTATION                                    *
**************************************************************************************************/
boolean Adc_Init(uint8 Param_VolageReference, uint8 Param_PreScaler, boolean Param_Async)
{
    boolean Loc_ReturnStatus = TRUE;
    if ((Param_VolageReference <=3) && (Param_PreScaler <= 7) )
    {
        /* No Gain !! */
        CLEAR_BIT(ADC_ADMUX,MUX4);
        CLEAR_BIT(ADC_ADMUX,MUX3);
        
        /* Choose if Sync or Async */
        Adc_Async = Param_Async;

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
        
        /* ADC Left Adjust Result */
        CLEAR_BIT(ADC_ADMUX,ADLAR);
        
        
        /* Enable Interrupt Flag */
        //SET_BIT(ADC_ADCSRA,ADIF);
        
        if(Adc_Async)
        {
            /* Enable Interrupt */
            sei();
            SET_BIT(ADC_ADCSRA,ADIE);
        }
        else
        {
            /* Do Nothing */
        }
        
    }
    else
    {
        /*Error in parameters*/
        Loc_ReturnStatus = FALSE;
    }
    
    return Loc_ReturnStatus;
}

boolean Adc_ReadValue(uint16* Param_ReturnValue, uint8 Param_ChannelNumber)
{
    boolean Loc_ReturnStatus = TRUE;
    if ((Param_ReturnValue != NULL_PTR) && (Param_ChannelNumber <=ADC_NUMBER_OF_CHANNELS))
    {
        /* Choose channel according to user input */
        ADC_ADMUX = (ADC_ADMUX & 0xF8 ) | Param_ChannelNumber;
        /* Enable start conversion */
        SET_BIT(ADC_ADCSRA,ADSC);
        
        if(Adc_Async)
        {
            /* Add Value to return to user */
            Param_ReturnValue = &Adc_Values[Param_ChannelNumber]; 
        }
        else
        {
            while(GET_BIT(ADC_ADCSRA,ADSC) == HIGH);
            /* Add Value to return to user */
            Param_ReturnValue = &Adc_Values[Param_ChannelNumber];
        }            
       
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
    uint8 currentChannel = ADC_ADMUX & 0x07;       
    /* Get Values from both registers */
    Adc_Values[currentChannel] = ADC_DATA;
 }