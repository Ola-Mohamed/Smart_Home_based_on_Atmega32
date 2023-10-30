/*
 * TIM_prog.c
 *
 *  Created on: Oct 25, 2023
 *      Author: hp
 */
#include <avr/interrupt.h> /* For TIMER ISR */
#include "common_macros.h" /* For GET_BIT Macro */
#include "STD_TYPES.h"
#include "TIM1_interface.h"
#include "TIM1_types.h"



/******************************************************************
 *                        Global Variables                        *
 ******************************************************************/

static volatile void (*g_OVF_callBackPtr)(void) = NULL_PTR ;
static volatile void (*g_CMPA_callBackPtr)(void) = NULL_PTR;
static volatile void (*g_CMPB_callBackPtr)(void) = NULL_PTR;


/*******************************************************************
 *                                  ISR                            *
 *******************************************************************/
//For timer 1 -> overflow (normal) mode
ISR(TIMER1_OVF_vect){
	if(g_OVF_callBackPtr != NULL_PTR)
	{
		(*g_OVF_callBackPtr)();  /* Call call back function */
	}
}

ISR(TIMER1_COMPA_vect){
	if(g_CMPA_callBackPtr != NULL_PTR)
	{
		(*g_CMPA_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr_CMP(); */
	}
}
ISR(TIMER1_COMPB_vect){
	if(g_CMPB_callBackPtr != NULL_PTR)
	{
		(*g_CMPB_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr_CMP(); */
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

	TCNT1 = Config_Ptr -> init_value ;
	/* Configure the timer control register
		 * 1. Non PWM mode FOC1A=1 & FOC1A=1
		 * 2. Normal Mode WGM10=0 & WGM11=0 & WGM12=0 & WGM13=0
		 * 3. Normal Mode COM1A/B1=0 & COM1A/B0=0
		 */
	/* Non PWM Mode */
	TCCR1A = (1<<FOC1A) | (1<<FOC1B) ;

	/*clock insertion by the configurable structure */
	TIMSK |= (1<<TOIE1) ;

	TCCR1B =(Config_Ptr->prescaler);     /* configure Pre-scaler */


#elif(mode == compA)
	TCNT1 = Config_Ptr->initialValue;
	OCR1A = Config_Ptr->compareValueA;
	/* Configure timer0 control register
	 * 1. Non PWM mode FOC1A=1 & FOC1B=1
	 * 2. CTC Mode WGM10=0 & WGM11=0 & WGM12=1 & WGM13=0
	 * 3. No need for OC0 so COM00=0 & COM01=0 , "we'll do so using PWM mode"
			/* Non PWM Mode with*/
	TCCR1A = (1<<FOC1A) | (1<<FOC1B)  ;

	/*clock insertion by the configurable structure */
	TCCR1B =(Config_Ptr->prescaler)| (1<<WGM12) ;
	TIMSK |= (1<<OCIE1A) ; // Enable Timer1 Compare Interrupt

	TCCR0 =(Config_Ptr->prescaler);    //choose  prescaler

#elif(mode == compB )

	TCNT1 = Config_Ptr->initialValue;
	OCR1B = Config_Ptr->compareValueB;
	/* Configure timer0 control register
	 * 1. Non PWM mode FOC1A=1 & FOC1B=1
	 * 2. CTC Mode WGM10=0 & WGM11=0 & WGM12=1 & WGM13=0
	 * 3. No need for OC0 so COM00=0 & COM01=0 , "we'll do so using PWM mode"
			/* Non PWM Mode with*/
	TCCR1A = (1<<FOC1A) | (1<<FOC1B)  ;

	/*clock insertion by the configurable structure */
	TCCR1B = (Config_Ptr->prescaler) | (1<<WGM12) ;
	TIMSK |= (1<<OCIE1B) ; // Enable Timer1 Compare Interrupt


#elif(mode == f_pwm )

	TCNT1 = Config_Ptr->initialValue;
	OCR1A = Config_Ptr->dutyCycle;
	/* Configure timer control register
	 * 1. Fast PWM mode FOC1A=0 & FOC1B=0
	 * 2. Fast PWM Mode WGM10=1 & WGM11=0 & WGM12=1 & WGM13=1
	 */
	/* PWM Mode with channelA toggling at comparing*/
	TCCR1A = (1<<WGM10) | (WGM11);
	TCCR1A=(TCCR1A&0X3F)|(Config_Ptr -> oc1a_mode);    // Clear OC1A when match occurs mode(toggle/non invert/invert)

	/*clock insertion by the configurable structure with Fast PWM Mode */
	TCCR1B = (Config_Ptr->prescaler) | (1<<WGM12) | (1<<WGM13) ;

	DDRB  = DDRB | (1<<PB3); // Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC


#elif(mode == phas_pwm )

	TCNT1 = Config_Ptr->initialValue;
	OCR1A = Config_Ptr->dutyCycle;
	/* Configure timer control register
	 * 1. Fast PWM mode FOC1A=0 & FOC1B=0
	 * 2. Fast PWM Mode WGM10=1 & WGM11=0 & WGM12=1 & WGM13=1
	 */
	/* PWM Mode with channelA toggling at comparing*/
	TCCR1A = (1<<WGM10) | (WGM11);
	TCCR1A=(TCCR1A&0X3F)|(Config_Ptr -> oc1a_mode);	 // Clear OC1A when match occurs mode(toggle/non invert/invert)



	/*clock insertion by the configurable structure with Fast PWM Mode */
	TCCR1B = (Config_Ptr->prescaler)| (1<<WGM13) ;

	DDRB  = DDRB | (1<<PB3); // Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC



#endif
}





/***************************************************
 * Description : deinitialize the Timer
 * Argument    : none
 * Returns     : None
 ***************************************************/

void Timer1_deInit(){

	TCNT1=0;
	TCCR1A=0;
	TCCR1B=0;
	CLEAR_BIT(TIMSK,TOIE1);    // Disable Overflow INT
	CLEAR_BIT (TIMSK,OCIE1A);   // Disable Timer1 Compare Interrupt
	CLEAR_BIT (TIMSK,OCIE1B);   // Disable Timer1 Compare Interrupt
}


/***************************************************
 * Description : Function to set the Call Back function address for overflow
 * Argument    :pointer to Call Back function
 * Returns     : None
 ***************************************************/

void Timer1_OVF_setCallBack(void(*a_ptr)(void))
{

	g_OVF_callBackPtr=a_ptr;

}/***************************************************
 * Description : Function to set the Call Back function address for compare A
 * Argument    :pointer to Call Back function
 * Returns     : None
 ***************************************************/

void Timer1_CMPA_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_CMPA_callBackPtr = a_ptr;
}
/***************************************************
 * Description : Function to set the Call Back function address for compare B
 * Argument    :pointer to Call Back function
 * Returns     : None
 ***************************************************/

void Timer1_CMPB_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_CMPB_callBackPtr = a_ptr;
}
