/*
 * TIM_types.h
 *
 *  Created on: Oct 25, 2023
 *      Author: hp
 */

#ifndef TIM_TYPES_H_
#define TIM_TYPES_H_
#include "STD_TYPES.h"
extern volatile uint32 SECONDS_T1;
extern volatile uint32 SECONDS_T1_MC1;
extern volatile uint32 SECONDS_T1_MC2;
/*******************************************************************************
                               Types Declaration
 *******************************************************************************/

typedef enum{
	timer0,timer1,timer2
}Timer_channel;

typedef enum {
	t_noClock,t_prescaler_1,t_prescaler_8,t_prescaler_64,t_prescaler_256,t_prescaler_1024,external_falling,external_rising,
	t2_noclock=0,t2_prescaler_1,t2_prescaler_8,t2_prescaler_32,t2_prescaler_64,t2_prescaler_128,t2_prescaler_256,t2_prescaler_1024
}Timer_clock;

typedef enum{
	normal,pwm,ctc,fast_pwm
}Timer_mode;

typedef struct{
	Timer_channel channel;
	 uint16 initial_value;
	Timer_clock clock;
	Timer_mode mode;
	Timer_clock prescaler;
	uint16 compare_value;    // it will be used in compare mode only.
}TIMER_config;

#endif /* TIM_TYPES_H_ */
