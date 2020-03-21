/**************************************************************************************************
* FILE INFORMATION
* -------------------------------------------------------------------------------------------------
* NAME:              Adc.h
* MODULE:            Adc
* AUTHOR:            ShroukRashwan
* DESCRIPTION:       Header file for Adc Mcal driver
* CREATION DATE:     7/2/2020
* MODIFICATION DATE: 12/2/2020
**************************************************************************************************/
#ifndef ADC_H_
#define ADC_H_

/**************************************************************************************************
*                                       INCLUDES & LIBRARIES                                      *
**************************************************************************************************/
#include "Common.h"


/**************************************************************************************************
*                                       FUNCTION PROTOTYPES                                       *
**************************************************************************************************/
void Adc_Main();
boolean Adc_Init(uint8 Param_ChannelNumber, uint8 Param_VolageReference, uint8 Param_PreScaler);
boolean Adc_ReadValue(uint16* Param_ReturnValue, uint8 Param_Channel);

#endif /* ADC_H_ */