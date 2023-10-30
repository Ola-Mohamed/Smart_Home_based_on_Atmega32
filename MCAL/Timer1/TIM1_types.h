/*
 * TIM_types.h
 *
 *  Created on: Oct 25, 2023
 *      Author: hp
 */

#ifndef TIM1_TYPES_H_
#define TIM1_TYPES_H_
#include "STD_TYPES.h"

/*******************************************************************************
                               Types Declaration
 *******************************************************************************/

#define normal 0
#define compA 1
#define compB 2
#define f_pwm 3
#define phas_pwm 4


#define mode normal

typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}TIMER1_Clock; //for choose precalar
typedef enum
{
	OCRA_DISCONNECTED=0,
	OCRA_TOGGLE,
	OCRA_NON_INVERTING,
	OCRA_INVERTING

}OC1A_Mode_type;



typedef struct{
	 uint16 init_value;
	TIMER1_Clock prescaler;
	uint8 compare_valueA;    // it will be used in compare mode only.
	uint8 compareValueB;    // it will be used in compare mode only.
	uint8 dutyCycle ;
	OC1A_Mode_type oc1a_mode
}TIMER_config;

#endif /* TIM1_TYPES_H_ */
