/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              Dio_ut.h
* MODULE:            Dio Unit Test
* AUTHOR:            ShroukRashwan
* DESCRIPTION:       Unit test header file for Dio Mcal driver
* CREATION DATE:     7/2/2020
* MODIFICATION DATE: 11/2/2020
**************************************************************************************************/
#ifndef DIO_UT_H_
#define DIO_UT_H_

/**************************************************************************************************
*                                       INCLUDES & LIBRARIES                                      *
**************************************************************************************************/
#include "UnitTest.h"
#include "Dio.h"

#if UNIT_TESTING == STD_ON
/**************************************************************************************************
*                                        EXTERNED VARIABLES                                       *
**************************************************************************************************/
extern uint8 Dio_PINA;
extern uint8 Dio_PORTA;
extern uint8 Dio_DDRA;

extern uint8 Dio_PINB;
extern uint8 Dio_PORTB;
extern uint8 Dio_DDRB;
	
extern uint8 Dio_PINC;
extern uint8 Dio_PORTC;
extern uint8 Dio_DDRC;
	
extern uint8 Dio_PIND;
extern uint8 Dio_PORTD;
extern uint8 Dio_DDRD;

/**************************************************************************************************
*                                       FUNCTION PROTOTYPES                                       *
**************************************************************************************************/
void UT_Dio_RunAllTests();

#endif



#endif /* DIO_UT_H_ */