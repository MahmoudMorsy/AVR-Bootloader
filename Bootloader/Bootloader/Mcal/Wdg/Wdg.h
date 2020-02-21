/*
 * Wdg.h
 *
 * Created: 2/7/2020 8:23:35 PM
 *  Author: MahmoudMorsy
 */ 


#ifndef WDG_H_
#define WDG_H_
#include "Common.h"
typedef enum
{                 /* Number of WDT Oscillator Cycles | Typical Timeout at VCC 3.0 | Typical Timeout at VCC 5.0 */
    OSC_16,       /*          16K (16,384)           |          17.1 ms           |          16.3 ms           */
    OSC_32,       /*          32K (32,768)           |          34.3 ms           |          32.5 ms           */
    OSC_64,       /*          64K (65,536)           |          68.5 ms           |          65.0 ms           */
    OSC_128,      /*         128K (131,072)          |          0.14  s           |          0.13  s           */
    OSC_256,      /*         256K (262,144)          |          0.27  s           |          0.26  s           */
    OSC_512,      /*         512K (524,288)          |          0.55  s           |          0.52  s           */
    OSC_1024,     /*        1024K (1,048,576)        |          1.10  s           |          1.00  s           */
    OSC_2048      /*        2048K (2,097,152)        |          2.20  s           |          2.10  s           */
}Wdg_OscCycles_en;/* ***************************************************************************************** */
typedef enum
{
    DISABLED,
    RUNNING
}Wdg_State_en;

#define WDG_PRESCALER_MASK 0x07
#define Wdg_Reset() __asm("wdr")

void Wdg_Disable();
void Wdg_Enable();
void Wdg_AdjustPrescaler(Wdg_OscCycles_en OscCycles);
void Wdg_Feed();


#endif /* WDG_H_ */