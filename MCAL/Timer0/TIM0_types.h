/*
 * TIM_types.h
 *
 *  Created on: Oct 25, 2023
 *      Author: hp
 */

#ifndef TIM0_TYPES_H_
#define TIM0_TYPES_H_
#include "STD_TYPES.h"

/*******************************************************************************
                               Types Declaration
 *******************************************************************************/

#define normal 0
#define phas_pwm 1
#define f_pwm 3
#define ctc 2

#define mode normal
typedef enum {
	t_noClock,t_prescaler_1,t_prescaler_8,t_prescaler_64,t_prescaler_256,t_prescaler_1024,external_falling,external_rising,
}Timer_clock;

typedef enum{
	norm,ppwm,comp,fast_pwm
}Timer_mode;
typedef enum {
non_invert,invert
}PWM_MODE;
typedef enum {
set,clear
}phase_MODE;

typedef struct{
	 uint16 initial_value;
	Timer_mode mod;
	Timer_clock prescaler;
	uint16 compare_value;    // it will be used in compare mode only.
	PWM_MODE invert_mode;
	phase_MODE com_match;
}TIMER_config;

#endif /* TIM0_TYPES_H_ */
