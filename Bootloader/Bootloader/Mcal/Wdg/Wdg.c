/*
 * Wdg.c
 *
 * Created: 2/7/2020 8:23:43 PM
 *  Author: MahmoudMorsy
 */ 
#include "Wdg.h"
#include <avr/io.h>

/* Global variable to store the current configured pre-scaler */
STATIC Wdg_OscCycles_en Wdg_CurrentPrescaler = OSC_16;
/* Global variable to store the current watch dog status */
STATIC Wdg_State_en Wdg_CurrentState = DISABLED;

void Wdg_Disable()
{
    /* Start Critical Section */
    Sys_StartCriticalSection();
    if (Wdg_CurrentState == RUNNING)
    {
        /* Reset Watch dog */
        Wdg_Reset();
        /* To disable WDG, Write 1 in WDTOE and WDE at the same time, then Write 0 in WDE within 4 clock cycles */
        WDTCR |= (1<<WDTOE) | (1<<WDE);
        WDTCR = 0;
        /* Set driver's current state as disabled */
        Wdg_CurrentState = DISABLED;        
    }
    else
    {
        /* Do Nothing */
    }
    /* Stop Critical Section */
    Sys_StopCriticalSection();
}

void Wdg_Enable()
{
    /* Start Critical Section */
    Sys_StartCriticalSection();
    if (Wdg_CurrentState == DISABLED)
    {
        /* To Enable WDG, Set bit WDE */
        SET_BIT(WDTCR, WDE);
        /* Within four cycles, set the pre-scaler bits */
        WDTCR |= (uint8)(Wdg_CurrentPrescaler & WDG_PRESCALER_MASK);
        /* Set driver's current state as enabled (running) */
        Wdg_CurrentState = RUNNING;
    }
    else
    {
        /* Do Nothing */
    }
    /* Stop Critical Section */
    Sys_StopCriticalSection();
}

void Wdg_AdjustPrescaler(Wdg_OscCycles_en OscCycles)
{
    Wdg_CurrentPrescaler = OscCycles;
}

void Wdg_Feed()
{
    if (Wdg_CurrentState == RUNNING)
    {
        Wdg_Reset();
    }
    else
    {
        /* Do Nothing */
    }
}