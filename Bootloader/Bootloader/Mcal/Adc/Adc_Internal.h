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

/* Stubbing for unit testing */
#if UNIT_TESTING == STD_ON
	/* Replacing Registers with Global Variables */
	#define ADC_ADMUX																	 Adc_ADMUX																				
	#define ADC_ADCSRA																	 Adc_ADCSRA		
	#define ADC_ADCH																	 Adc_ADCH			
	#define ADC_ADCL																	 Adc_ADCL																				
	#define ADC_SFIOR																	 Adc_SFIOR
	#define sei()
#else
	/* Putting actual register addresses */
	#define ADC_ADMUX																		ADMUX
	#define ADC_ADCSRA																		ADCSRA
	#define ADC_ADCH																		ADCH
	#define ADC_ADCL																		ADCL
	#define ADC_SFIOR																		SFIOR

#endif

#endif /* ADC_INTERNAL_H_ */