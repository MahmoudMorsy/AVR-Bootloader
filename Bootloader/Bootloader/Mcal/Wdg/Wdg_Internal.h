/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              Wdg_Internal.h
* MODULE:            Wdg
* AUTHOR:            MahmoudMorsy
* DESCRIPTION:       Header file for Internal parameter of WDG Mcal driver
* CREATION DATE:     21/2/2020
* MODIFICATION DATE: 21/2/2020
**************************************************************************************************/
#ifndef WDG_INTERNAL_H_
#define WDG_INTERNAL_H_

/**************************************************************************************************
*                                       INCLUDES & LIBRARIES                                      *
**************************************************************************************************/
#include "Wdg.h"
#if UNIT_TESTING == STD_OFF
    #include <avr/io.h>
    #include <avr/interrupt.h>
#endif

/**************************************************************************************************
*                                        MACRO DEFINITIONS                                        *
**************************************************************************************************/
#define WDG_PRESCALER_MASK                                                                     0x07

/* Stubbing for unit testing */
#if UNIT_TESTING == STD_ON
    /* Replacing Registers with Global Variables */
    #define WDG_WDTCR                                                                     Wdg_WDTCR
    #define WDTOE                                                                                 4
    #define WDE                                                                                   3
    #define WDP2                                                                                  2
    #define WDP1                                                                                  1
    #define WDP0                                                                                  0

#else
    /* Putting actual register addresses */
    #define WDG_WDTCR                                                                         WDTCR
#endif

/**************************************************************************************************
*                                         MACRO FUNCTIONS                                         *
**************************************************************************************************/
#if UNIT_TESTING == STD_OFF
    #define Wdg_Reset()                                                                __asm("wdr")
#else
    #define Wdg_Reset()
#endif

#endif /* WDG_INTERNAL_H_ */