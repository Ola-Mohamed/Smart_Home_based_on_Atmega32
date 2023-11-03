/*
 * ADC.h
 *
 *  Created on: Oct 25, 2023
 *      Author: ELAF
 */

#ifndef ADC_H_
#define ADC_H_
#include "STD_TYPES.h"

#define ADMUX	*((volatile uint8 *)0x27)					//ADC multiplexer
#define REFS1         7									//Reference selection bit1
#define REFS0         6									//Reference selection bit0
#define ADMUX_ADLAR         5							//ADC left adjust result




#define ADC_PRE_MASK				0b11111000
#define ADC_CH_MASK				    0b11100000

/* ADSAR Bits   */
#define ADCSRA				*((volatile uint8 *)0x26)		//ADC control and status register A

#define ADSAR_ADEN			7							//ADC enable
#define ADSAR_ADSC			6                           //Start conversion
#define ADSAR_ADATE		    5                           //Auto trigger enable
#define ADSAR_ADIF			4                           //Interrupt flag
#define ADSAR_ADIE			3                           //Interrupt enable
#define ADSAR_ADPS2		    2                           //Prescaler bit2
#define ADSAR_ADPS1		    1                           //Prescaler bit1
#define ADSAR_ADPS0		    0                           //Prescaler bit0

/* Data Reg  */
#define ADCH				*((volatile uint8*)0x25)		//ADC high register
#define ADCL				*((volatile uint8*)0x24)		//ADC Low register
#define ADC_DATA_RE 		*((volatile uint16*)0x24)		//ADC Low + High


#define SINGLE_CHANNEL_ASYNCH 0
#define CHAIN_CHANNEL_ASYNCH  1


#endif /* ADC_H_ */
