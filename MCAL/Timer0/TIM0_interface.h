/*
 * TIM_interface.h
 *
 *  Created on: Oct 25, 2023
 *      Author: hp
 */

#ifndef TIM0_INTERFACE_H_
#define TIM0_INTERFACE_H_

#include "TIM0_types.h"
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/***************************************************
 * Description : Initialize the Timer
 * Argument    : pointer to struct (TIMER_congif)
 * Returns     : None
 ***************************************************/
void Timer0_init(TIMER_config * Config_Ptr);
/***************************************************
 * Description : deinitialize the Timer
 * Returns     : None
 ***************************************************/

void Timer0_deInit();

/***************************************************
 * Description : Function to set the Call Back function address
 * 				 pointer to Call Back function
 * Returns     : None
 ***************************************************/

void Timer0_setCallBack(void(*a_ptr)(void));
#endif /* TIM0_INTERFACE_H_ */
