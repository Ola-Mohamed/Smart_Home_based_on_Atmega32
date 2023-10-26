/*
 * EXIT_PROG.c
 *
 *  Created on: 26 Oct 2023
 *      Author: 20128
 */


#include "EXIT_INTERFACE.h"
#include "MemMap.h"


// external interrupt 0 initialization
void EXT_INT_0_init(EN_interrupt_sense_t SENSE)
{
	//1. Enable the global interrupt
	sei();
	//2. choose the interrupt sense on ext interrupt 0
	switch(SENSE)
	{
		case EXIT_LOW_LEVEL:
		CLEAR_BIT(MCUCR,ISC00);
		CLEAR_BIT(MCUCR,ISC01);  // low level interrupt
		break;
		case EXIT_LOGIC_CHANGE:
		SET_BIT(MCUCR,ISC00); //any logical change
		break;
		case EXIT_FALLING_EDGE:
		SET_BIT(MCUCR,ISC01);  // Falling edge trigger
		break;
		case EXIT_RISING_EDGE:

		SET_BIT(MCUCR,ISC01);
		SET_BIT(MCUCR,ISC00); // rising edge
		break;
		default:
		break;
	}
	//3. Enable the external interrupt 0
	SET_BIT(GICR,INT0);
}

void EXT_INT_1_init(EN_interrupt_sense_t SENSE)
{
	//1. Enable the global interrupt
	sei();
	//2. choose the interrupt sense on ext interrupt 1
	switch(SENSE)
	{
		case EXIT_LOW_LEVEL:
		CLEAR_BIT(MCUCR,ISC10);
		CLEAR_BIT(MCUCR,ISC11);  // low level interrupt
		break;
		case EXIT_LOGIC_CHANGE:
		SET_BIT(MCUCR,ISC10); //any logical change
		break;
		case EXIT_FALLING_EDGE:
		SET_BIT(MCUCR,ISC11);  // Falling edge trigger
		break;
		case EXIT_RISING_EDGE:

		SET_BIT(MCUCR,ISC11);
		SET_BIT(MCUCR,ISC10); // rising edge
		break;
		default:
		break;
	}
	//3. Enable the external interrupt 1
	SET_BIT(GICR,INT1);
}


// external interrupt 2 initialization
void EXT_INT_2_init(EN_interrupt_sense_t SENSE)
{
	//1. Enable the global interrupt
	sei();
	//2. choose the interrupt sense on ext interrupt 2
	switch(SENSE)
	{


		case EXIT_FALLING_EDGE:
		CLEAR_BIT(MCUCSR ,ISC2 ); // Falling edge trigger
		break;
		case EXIT_RISING_EDGE:
		SET_BIT(MCUCSR,ISC2); // rising edge
		break;
		default:
		break;
	}
	//3. Enable the external interrupt 2
	SET_BIT(GICR,INT2);

}
