/*
 * TIM_interface.h
 *
 *  Created on: Oct 25, 2023
 *      Author: hp
 */

#ifndef TIM1_INTERFACE_H_
#define TIM1_INTERFACE_H_

#include "TIM1_types.h"
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/***************************************************
 * Description : Initialize the Timer
 * Argument    : pointer to struct (TIMER_congif)
 * Returns     : None
 ***************************************************/
void Timer1_init(TIMER_config * Config_Ptr);
/***************************************************
 * Description : deinitialize the Timer
 * Returns     : None
 ***************************************************/

void Timer1_deInit();

/***************************************************
 * Description : Function to set the Call Back function address
 * 				 pointer to Call Back function
 * Returns     : None
 ***************************************************/
void TIMER1_OVF_setCallBack(void(*a_ptr)(void));

void TIMER1_CMPA_setCallBack(void(*a_ptr)(void));

void TIMER1_CMPB_setCallBack(void(*a_ptr)(void));
#endif /* TIM1_INTERFACE_H_ */
