/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              Dio_Internal.h
* MODULE:            Dio
* AUTHOR:            ShroukRashwan
* DESCRIPTION:       Header file for Internal parameter of Dio Mcal driver
* CREATION DATE:     11/2/2020
* MODIFICATION DATE: 11/2/2020
**************************************************************************************************/

#ifndef DIO_INTERNAL_H_
#define DIO_INTERNAL_H_

/**************************************************************************************************
*                                       INCLUDES & LIBRARIES                                      *
**************************************************************************************************/
#include "Dio.h"
#if UNIT_TESTING == STD_OFF
	#include <avr/io.h>
#endif

/**************************************************************************************************
*                                        MACRO DEFINITIONS                                        *
**************************************************************************************************/
#define DIO_NUMBER_OF_PORTS                                                                      3
#define DIO_NUMBER_OF_CHANNELS                                                                   7

/* Stubbing for unit testing */
#if UNIT_TESTING == STD_ON
	/* Replacing Registers with Global Variables */
	#define DIO_PINA																	 Dio_PINA
	#define DIO_PORTA																	 Dio_PORTA
	#define DIO_DDRA																	 Dio_DDRA
	
	#define DIO_PINB																	 Dio_PINB
	#define DIO_PORTB																	 Dio_PORTB
	#define DIO_DDRB																	 Dio_DDRB
	
	#define DIO_PINC																	 Dio_PINC
	#define DIO_PORTC																	 Dio_PORTC
	#define DIO_DDRC																	 Dio_DDRC
	
	#define DIO_PIND																	 Dio_PIND
	#define DIO_PORTD																	 Dio_PORTD
	#define DIO_DDRD																	 Dio_DDRD


#else
	/* Putting actual register addresses */
	#define DIO_PINA																		PINA
	#define DIO_PORTA																		PORTA
	#define DIO_DDRA																		DDRA
	
	#define DIO_PINB																		PINB
	#define DIO_PORTB																		PORTB
	#define DIO_DDRB																		DDRB
	
	#define DIO_PINC																		PINC
	#define DIO_PORTC																		PORTC
	#define DIO_DDRC																		DDRC
	
	#define DIO_PIND																		PIND
	#define DIO_PORTD																		PORTD
	#define DIO_DDRD																		DDRD
#endif

enum 
{
    PORT_A,
    PORT_B,
    PORT_C,
    PORT_D
};

enum
{
    OUTPUT,
    INPUT    
};



#endif /* DIO_INTERNAL_H_ */