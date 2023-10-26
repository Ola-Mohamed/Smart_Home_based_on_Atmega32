/*
 * TIM_interface.h
 *
 *  Created on: Oct 25, 2023
 *      Author: hp
 */

#ifndef TIM_INTERFACE_H_
#define TIM_INTERFACE_H_


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/***************************************************
 * Description : Initialize the Timer
 * Argument    : pointer to struct (TIMER_congif)
 * Returns     : None
 ***************************************************/
void Timer_init(const TIMER_config * Config_Ptr);

/***************************************************
 * Description : deinitialize the Timer
 * Argument    : channel of the timer -> timer 0,1,2
 * Returns     : None
 ***************************************************/

void Timer_deInit(Timer_channel channel);

/***************************************************
 * Description : Function to set the Call Back function address
 * Argument    : channel of the timer -> timer 0,1,2
 * 				 pointer to Call Back function
 * Returns     : None
 ***************************************************/

void Timer_setCallBack(Timer_channel channel,void(*a_ptr)(void));
#endif /* TIM_INTERFACE_H_ */
