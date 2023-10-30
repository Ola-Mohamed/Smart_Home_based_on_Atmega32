/*
 * TIM_prog.c
 *
 *  Created on: Oct 25, 2023
 *      Author: hp
 */
#include <avr/interrupt.h> /* For TIMER ISR */
#include "common_macros.h" /* For GET_BIT Macro */
#include "STD_TYPES.h"
#include "TIM0_interface.h"
#include "TIM0_types.h"



/******************************************************************
 *                        Global Variables                        *
 ******************************************************************/

static void(*g_callBackPtr0)(void)=NULL_PTR;      /* Call back function of timer 0 */



/*******************************************************************
 *                                  ISR                            *
 *******************************************************************/
//For timer 0 -> overflow (normal) mode
ISR(TIMER0_OVF_vect){
	if(g_callBackPtr0 != NULL_PTR)
	{
		(*g_callBackPtr0)();  /* Call call back function */
	}
}

ISR(TIMER0_COMP_vect){
	if(g_callBackPtr0 != NULL_PTR)
	{
		(*g_callBackPtr0)();  /* Call call back function */
	}
}


/*******************************************************************************
 *                      Functions declaration                                   *
 *******************************************************************************/
/***************************************************
 * Description : Initialize the Timer
 * Argument    : pointer to struct (TIMER_congif)
 * Returns     : None
 ***************************************************/


void Timer0_init(TIMER_config * Config_Ptr){

#if(mode== normal)
	SET_BIT(TCCR0,FOC0);//for non PWM mode
	TCNT0=Config_Ptr->initial_value;      //set initial_value
	//enable interrupt for normal mode -> timer 0
	SET_BIT(TIMSK,TOIE0);
	//disconnect OC0
	CLEAR_BIT(TCCR0,COM00);
	CLEAR_BIT(TCCR0,COM01);
	TCNT0 =0; /* Clear counter register */
	TCCR0 =(Config_Ptr->prescaler)|((TCCR0>>3)|(Config_Ptr->mod));    //choose  mode & prescaler /* configure Pre-scaler */


#elif(mode == ctc)
	SET_BIT(TCCR0,FOC0);//for non PWM mode
	SET_BIT(TIMSK,OCIE0);
	//add the compare value
	OCR0=(uint8)(Config_Ptr->compare_value);

	TCNT0 =0; /* Clear counter register */
	TCCR0 =(Config_Ptr->prescaler);    //choose  mode & prescaler

#elif(mode == f_pwm )

	TCNT0 = 0; // Set Timer Initial Value to 0

	OCR0=(uint8)(Config_Ptr->compare_value);  // Set Compare Value

	DDRB  = DDRB | (1<<PB3); // Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 */
	if(Config_Ptr->invert_mode==non_invert){
		TCCR0 = (Config_Ptr->prescaler)|(1<<WGM00) | (1<<WGM01) | (1<<COM01) ;
	}
	else if(Config_Ptr->invert_mode==invert){
		TCCR0 = (Config_Ptr->prescaler)|(1<<WGM00) | (1<<WGM01) | (1<<COM01)|(1<<COM00) ;		 // Clear OC0 when match occurs ( inverted mode) COM00=1 & COM01=1

	}
	else{
		//nothing
	   }

#elif(mode == phas_pwm )

		TCNT0 = 0; // Set Timer Initial Value to 0

		OCR0=(uint8)(Config_Ptr->compare_value);  // Set Compare Value


		/* Configure timer control register
		 * 1. phase PWM mode FOC0=0
		 * 2. phase PWM Mode WGM01=1 & WGM00=1
		 * 3. Clear OC0 when match occurs (set compare mode) COM00=0 & COM01=1
		 */
		if(Config_Ptr->com_match==set){
		TCCR0 = (Config_Ptr->prescaler)|(1<<WGM00) | (1<<WGM01) | (1<<COM01) ;
	}
		else if(Config_Ptr->com_match==clear){
			TCCR0 = (Config_Ptr->prescaler)|(1<<WGM00) | (1<<WGM01) | (1<<COM01)|(1<<COM00) ;		 // Clear OC0 when match occurs ( clear compare mode) COM00=1 & COM01=1

		}
		else{
			//nothing
		}




#endif
}





/***************************************************
 * Description : deinitialize the Timer
 * Argument    : none
 * Returns     : None
 ***************************************************/

void Timer0_deInit(){

		TIMSK &= ~0X03; /* Disable All TIMER0 interrupt */
		TCNT0=0;        /* Disable timer0 */
		TCCR0=0;        /* Clear Counter*/
		OCR0=0;         /*Clear Compare Register*/

}


/***************************************************
 * Description : Function to set the Call Back function address
 * Argument    :pointer to Call Back function
 * Returns     : None
 ***************************************************/

void Timer_setCallBack(void(*a_ptr)(void))
{

		g_callBackPtr0=a_ptr;

}
