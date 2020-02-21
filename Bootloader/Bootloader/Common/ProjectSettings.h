/*
 * ProjectSettings.h
 *
 * Created: 2/8/2020 9:21:39 PM
 *  Author: MahmoudMorsy
 */ 


#ifndef PROJECTSETTINGS_H_
#define PROJECTSETTINGS_H_

/* To enable or disable UNIT TESTING */
#define UNIT_TESTING            STD_OFF

/* Critical Section */
#if UNIT_TESTING == STD_OFF
    #include <avr/interrupt.h>
    #define Sys_StartCriticalSection() cli()
    #define Sys_StopCriticalSection() sei()
#else
    #define Sys_StartCriticalSection()
    #define Sys_StopCriticalSection()
#endif

/* Static Keyword */
#if UNIT_TESTING == STD_OFF
    #define STATIC static
#else
    #define STATIC
#endif

#endif /* PROJECTSETTINGS_H_ */