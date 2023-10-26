/*
 * ADC_CONFIG.h
 *
 *  Created on: Oct 25, 2023
 *      Author: ELAF
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define ADC_STATUS   ADC_ENABLE 			//ENABLE or DISABLE

#define INT_STATUS   INT_ENABLE				//ENABLE or DISABLE

#define ADC_VREF  AVCC						// AVCC or AREF or INTERNAL 2_56

#define ADC_CHANNEL  ADC_CHANNEL0			//CHANEL [0,1,2,3,4,5,6,7]

#define ADC_TRIGGERING_SOURCE   ADC_SINGLE_CONVERSION          //FREE_RUNNING

#define ADC_ADJUSTMENT RIGHT_ADJUSTMENT 						//RIGHT OT LEFT


#define  ADC_PRESCALLER   ADC_PRE_128        //PRESCALER[2,4,8,16,32,64,128]


#define ADC_TIMEOUT 50000
#endif /* ADC_CONFIG_H_ */
