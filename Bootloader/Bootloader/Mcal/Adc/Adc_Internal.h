/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              Adc_Internal.h
* MODULE:            Adc
* AUTHOR:            ShroukRashwan
* DESCRIPTION:       Header file for Internal parameter of Adc Mcal driver
* CREATION DATE:     12/2/2020
* MODIFICATION DATE: 12/2/2020
**************************************************************************************************/
#ifndef ADC_INTERNAL_H_
#define ADC_INTERNAL_H_

/**************************************************************************************************
*                                       INCLUDES & LIBRARIES                                      *
**************************************************************************************************/
#include "Adc.h"
#if UNIT_TESTING == STD_OFF
#include <avr/io.h>
#include <avr/interrupt.h>
#endif

/**************************************************************************************************
*                                        MACRO DEFINITIONS                                        *
**************************************************************************************************/
#define ADC_NUMBER_OF_CHANNELS                                                                  7
/* Stubbing for unit testing */
#if UNIT_TESTING == STD_ON
/* Replacing Registers with Global Variables */
#define ADC_ADMUX                                                                        Adc_ADMUX
#define ADC_ADCSRA                                                                       Adc_ADCSRA
#define ADC_ADCH                                                                         Adc_ADCH
#define ADC_ADCL                                                                         Adc_ADCL
#define ADC_SFIOR                                                                        Adc_SFIOR
#define ADC_DATA                                                                         Adc_DATA
#define sei()
#define REFS1                                                                                   7
#define REFS0                                                                                   6
#define ADLAR                                                                                   5
#define MUX4                                                                                    4
#define MUX3                                                                                    3
#define ADEN                                                                                    7
#define ADSC                                                                                    6
#define ADATE                                                                                   5
#define ADIF                                                                                    4
#define ADIE                                                                                    3
#else
/* Putting actual register addresses */
#define ADC_ADMUX                                                                           ADMUX
#define ADC_ADCSRA                                                                          ADCSRA
#define ADC_ADCH                                                                            ADCH
#define ADC_ADCL                                                                            ADCL
#define ADC_SFIOR                                                                           SFIOR
#define ADC_DATA                                                                            ADC

#endif

enum 
{
    AREF,
    AVCC,
    INTERNAL_2V = 3
};
    
enum 
{
   CHANNAL0, 
   CHANNAL1, 
   CHANNAL2, 
   CHANNAL3, 
   CHANNAL4, 
   CHANNAL5, 
   CHANNAL6, 
   CHANNAL7
};

#endif /* ADC_INTERNAL_H_ */