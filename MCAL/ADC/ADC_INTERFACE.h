/*
 * ADC_INETFACE.h
 *
 *  Created on: Oct 25, 2023
 *      Author: ELAF
 */

#include "STD_TYPES.h"

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


#define ADC_DISABLE             0
#define ADC_ENABLE              1

#define INT_DISABLE             0
#define INT_ENABLE              1

#define AREF                    0
#define AVCC                    1
#define INTERNAL_2_56           3

#define ADC_CHANNEL0            0
#define ADC_CHANNEL1            1
#define ADC_CHANNEL2            2
#define ADC_CHANNEL3            3
#define ADC_CHANNEL4            4
#define ADC_CHANNEL5            5
#define ADC_CHANNEL6            6
#define ADC_CHANNEL7            7

#define ADC_SINGLE_CONVERSION   0
#define ADC_FREE_RUNNING        1

#define ADC_PRE_2               0
#define ADC_PRE_4               2
#define ADC_PRE_8               3
#define ADC_PRE_16              4
#define ADC_PRE_32              5
#define ADC_PRE_64              6
#define ADC_PRE_128             7

#define RIGHT_ADJUSTMENT        0
#define LEFT_ADJUSTMENT         1

/*******************FUNCTIONS*******************/

void  ADC_INIT ( void );
uint8 ADC_SETPRESCALER (uint8 Prescaler);
void ADC_Enable (void);
void ADC_Disable (void);
void ADC_InterruptEnable (void);
void ADC_InterruptDisable (void);
uint8 ADC_RESULT (uint8 C_Channel , uint16 * C_Result);







#endif /* ADC_INTERFACE_H_ */
