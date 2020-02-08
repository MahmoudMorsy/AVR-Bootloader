/*
 * Adc.h
 *
 * Created: 2/7/2020 8:22:07 PM
 *  Author: MahmoudMorsy
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "Common/Common_Macros.h"
#include "Common/Common_Types.h"

void Adc_Init(uint8 channel);
uint16 Adc_Read();


#endif /* ADC_H_ */