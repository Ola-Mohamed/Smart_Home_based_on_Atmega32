/*
 * TIM_prog.c
 *
 *  Created on: Oct 25, 2023
 *      Author: hp
 */
#include <avr/io.h> /* To use Timer1 Registers */
#include <avr/interrupt.h> /* For TIMER ISR */
#include "common_macros.h" /* For GET_BIT Macro */
#include "TIM_types.h"
#include "TIM_interface.h"
#include "STD_TYPES.h"



/******************************************************************
 *                        Global Variables                        *
 ******************************************************************/

static void(*g_callBackPtr0)(void)=NULL_PTR;      /* Call back function of timer 0 */
static void(*g_callBackPtr1)(void)=NULL_PTR;      /* Call back function of timer 1 */
static void(*g_callBackPtr2)(void)=NULL_PTR;      /* Call back function of timer 2 */


volatile uint32 SECONDS_T1=0;
volatile uint32 SECONDS_T1_MC1=0;
volatile uint32 SECONDS_T1_MC2=0;
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

//For timer 1 -> overflow (normal) mode
ISR(TIMER1_OVF_vect){
	if(g_callBackPtr1 != NULL_PTR)
	{
		(*g_callBackPtr1)();  /* Call call back function */
	}
}

ISR(TIMER1_COMPA_vect){
	if(g_callBackPtr1 != NULL_PTR)
	{
		(*g_callBackPtr1)();  /* Call call back function */
	}
}

//For timer 2 -> overflow (normal) mode
ISR(TIMER2_OVF_vect){
	if(g_callBackPtr2 != NULL_PTR)
	{
		(*g_callBackPtr2)();  /* Call call back function */
	}
}

ISR(TIMER2_COMP_vect){
	if(g_callBackPtr2 != NULL_PTR)
	{
		(*g_callBackPtr2)();  /* Call call back function */
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
void Timer_init(const TIMER_config * Config_Ptr){
	switch(Config_Ptr->channel){

	case timer0:
		SET_BIT(TCCR0,FOC0);//for non PWM mode
		TCNT0=Config_Ptr->initial_value;      //set initial_value
		if(Config_Ptr->mode==normal){
			//enable interrupt for normal mode -> timer 0
			SET_BIT(TIMSK,TOIE0);
			//disconnect OC0
			CLEAR_BIT(TCCR0,COM00);
			CLEAR_BIT(TCCR0,COM01);
		}
		else if(Config_Ptr->mode==ctc){
			//enable interrupt for CTC mode -> timer 0
			SET_BIT(TIMSK,OCIE0);
			//add the compare value
			OCR0=(uint8)Config_Ptr->compare_value;
		}
		TCNT0 =0; /* Clear counter register */
		TCCR0 =(Config_Ptr->prescaler)|((TCCR0>>3)|(Config_Ptr->mode));    //choose  mode & prescaler /* configure Pre-scaler */
		break;

	case timer1:
		TCNT1=Config_Ptr->initial_value;      //set initial_value
		TCCR1A=(1<<FOC1A)|(1<<FOC1B);   // The FOC1A/FOC1B bits are only active when the WGM13:0 bits specifies a non-PWM mode.
		if(Config_Ptr->mode==normal){
			//enable interrupt for normal mode -> timer 1
			SET_BIT(TIMSK,TOIE1);
			TCCR1B=0;
		}
		else if(Config_Ptr->mode==ctc){
			//enable interrupt for CTC mode -> timer 1
			SET_BIT(TIMSK,OCIE1A);
			OCR1A = Config_Ptr->compare_value; /* enter compare value */
		}
		TCNT1=0;    /* Clear Counter 1 */
		TCCR1B=(Config_Ptr->prescaler)|((TCCR1B>>3)|(Config_Ptr->mode));    //choose  mode & prescaler
		break;

	case timer2:
		//for non PWM mode
		SET_BIT(TCCR2,FOC2);
		TCNT2 = (uint8)(Config_Ptr->initial_value);	      //set initial_value

		if(Config_Ptr->mode==normal){
			SET_BIT(TIFR,TOV2);

			//enable interrupt for normal mode -> timer 2
			TIMSK = (1<<TOIE2);
		}
		else if(Config_Ptr->mode==ctc){
			//enable interrupt for CTC mode -> timer 2
			OCR2 =(uint8) Config_Ptr->compare_value; /* enter compare value*/
			TIMSK |= (1<<OCIE2);                      /*Enable timer interrupt*/
		}
		TCNT1=0;    /* Clear Counter 1 */
		TCCR2 =(Config_Ptr->prescaler)|((TCCR2>>3)|(Config_Ptr->mode)); /* configure Pre-scaler */

		break;
	}
}

/***************************************************
 * Description : deinitialize the Timer
 * Argument    : channel of the timer -> timer 0,1,2
 * Returns     : None
 ***************************************************/

void Timer_deInit(Timer_channel channel){
	switch (channel)
	{
	case timer0:
		TIMSK &= ~0X03; /* Disable All TIMER0 interrupt */
		TCNT0=0;        /* Disable timer0 */
		TCCR0=0;        /* Clear Counter*/
		OCR0=0;         /*Clear Compare Register*/
		break;
	case timer1:
		TIMSK &= ~0X1C; /*Disable All TIMER1 Interrupt */
		TCCR1A=0;       /* Disable Timer1 */
		TCCR1B=0;
		TCNT1=0;        /* Clear Counter*/
		OCR1A=0;        /*Clear Compare Register*/

		break;
	case timer2:
		TIMSK &= ~0XC0; /* Disable All TIMER2 interrupt */
		TCNT2=0;        /* Disable TIMER2 */
		TCCR2=0;        /* Clear Counter*/
		OCR0=0;         /*Clear Compare Register*/
		break;
	}
}


/***************************************************
 * Description : Function to set the Call Back function address
 * Argument    : channel of the timer -> timer 0,1,2
 * 				 pointer to Call Back function
 * Returns     : None
 ***************************************************/

void Timer_setCallBack(Timer_channel channel,void(*a_ptr)(void))
{
	switch(channel){
	case timer0:
		g_callBackPtr0=a_ptr;
		break;
	case timer1:
		g_callBackPtr1=a_ptr;
		break;
	case timer2:
		g_callBackPtr2=a_ptr;
		break;

	}
}
