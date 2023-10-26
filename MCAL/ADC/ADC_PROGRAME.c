/*
 * ADC.c
 *
 *  Created on: Oct 25, 2023
 *      Author: ELAF
 */



#include "STD_TYPES.h"

#include "BIT_MATH.h"

#include "ADC_CONFIG.h"

#include "ADC.h"
#include "ADC_INTERFACE.h"


/*flag for the ADCState*/
static uint8 ADC_State= IDLE ;



void ADC_INIT (void)
{

	/*Select the voltage reference*/

	switch(ADC_VREF)
		{
			case AREF:
			CLR_BIT(ADMUX,REFS0);
			CLR_BIT(ADMUX,REFS1);
			break;
			case AVCC:
			SET_BIT(ADMUX,REFS0);
			CLR_BIT(ADMUX,REFS1);
			break;
			case INTERNAL_2_56:
			SET_BIT(ADMUX,REFS0);
			SET_BIT(ADMUX,REFS1);
			break;
		}
		switch (ADC_ADJUSTMENT)
		{
		case RIGHT_ADJUSTMENT:
			CLR_BIT(ADMUX , ADMUX_ADLAR) ;
			break;
		case LEFT_ADJUSTMENT:
			SET_BIT(ADMUX , ADMUX_ADLAR) ;
			break;

		}

		/*Set Prescaler Value*/

		ADCSRA &= ADC_PRE_MASK ;
		ADCSRA |= ADC_PRESCALLER ;

}


uint8 ADC_SETPRESCALER (uint8 Prescaler)
{
	uint8 Error =OK;

	if (Prescaler < 8)
	{
		/*Set Prescaler Value*/
		ADCSRA &= ADC_PRE_MASK ;
		ADCSRA |=Prescaler ;
		return Error;
	}
	else
	{
		Error=NOK;
		return Error;
	}


}


void ADC_Enable (void)
{
	/* ADC ENABLE*/
	SET_BIT(ADCSRA, ADSAR_ADEN) ;
}

void ADC_Disable (void)
{
	CLR_BIT(ADCSRA , ADSAR_ADEN) ;
}

void ADC_InterruptEnable (void)
{
	SET_BIT(ADCSRA , ADSAR_ADIE) ;
}


void ADC_InterruptDisable (void)
{
	CLR_BIT(ADCSRA, ADSAR_ADIE) ;
}



uint8 ADC_RESULT (uint8 C_Channel , uint16 * C_Result)
{
		uint8 Error= OK ;
		uint32 Timeout = 0 ;
		if (C_Result != NULL)
		{	if (ADC_State == IDLE)
		{
			/*Make ADC Busy*/

			ADC_State = BUSY ;

			/*Set required channel*/

			ADMUX &= ADC_CH_MASK ;
			ADMUX |= C_Channel ;

			/*Start Conversion*/

			SET_BIT(ADCSRA , ADSAR_ADSC) ;

			/*Waiting until the conversion is complete*/

			while (((GET_BIT(ADCSRA , ADSAR_ADSC)) == 1) && (Timeout < ADC_TIMEOUT))
			{
							Timeout++ ;
			}
			if (Timeout == ADC_TIMEOUT)
			{
							Error = TIMEOUT_STATE ;
			}
			else
						{
							/*Clear the interrupt flag*/
							SET_BIT(ADCSRA , ADSAR_ADIF) ;

							switch(ADC_ADJUSTMENT)
							{
							case RIGHT_ADJUSTMENT:
								*C_Result = (ADCL|(ADCH << 8))  ;
								break;
							case LEFT_ADJUSTMENT:
								*C_Result = ADCH ;
								break;
							}
						}
			/*ADC is IDLE*/

			ADC_State = IDLE ;

		}
		else
		{
			Error= BUSY_STATE ;
		}
		}

		else
			{
				Error = NULL_POINTER ;
			}

		return Error ;
}

























