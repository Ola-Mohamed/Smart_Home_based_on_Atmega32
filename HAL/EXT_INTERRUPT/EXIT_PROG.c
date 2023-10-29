/*
 * EXIT_PROG.c
 *
 *  Created on: 26 Oct 2023
 *      Author: 20128
 */


#include "EXIT_INTERFACE.h"
#include "MemMap.h"


/* Array of Global Pointers to Functions for Calling Back */
void (*GLOB_VidINTPtrCallBack[NUM_OF_EX_INTERRUPTS])(void) = {NULL_PTR, NULL_PTR, NULL_PTR};

/************************************************************************************************/

uint8 EXIT_U8EXIT0Init(void)
{
	/* Configure Sense Control */
#if EXIT0_SENSE_CONTROL == LOW_LEVEL
	CLEAR_BIT(MCUCR, ISC00);
	CLEAR_BIT(MCUCR, ISC01);

#elif EXIT0_SENSE_CONTROL == LOGIC_CHANGE
	SET_BIT(MCUCR, ISC00);
	CLEAR_BIT(MCUCR, ISC01);

#elif EXIT0_SENSE_CONTROL == FALLING_EDGE
	CLEAR_BIT(MCUCR, ISC00);
	SET_BIT(MCUCR, ISC01);

#elif EXIT0_SENSE_CONTROL == RISING_EDGE
	SET_BIT(MCUCR, ISC00);
	SET_BIT(MCUCR, ISC01);
#else

	return E_NOT_OK;

#endif

	return E_OK;
}

uint8 EXIT_U8EXIT0SenseControl(const uint8 LOC_U8Source)
{
	if (LOC_U8Source == LOW_LEVEL)
	{
		CLEAR_BIT(MCUCR, ISC00);
		CLEAR_BIT(MCUCR, ISC01);
		return E_OK;
	}
	else if (LOC_U8Source == LOGIC_CHANGE)
	{
		SET_BIT(MCUCR, ISC00);
		CLEAR_BIT(MCUCR, ISC01);
		return E_OK;
	}
	else if (LOC_U8Source == FALLING_EDGE)
	{
		CLEAR_BIT(MCUCR, ISC00);
		SET_BIT(MCUCR, ISC01);
		return E_OK;
	}
	else if (LOC_U8Source == RISING_EDGE)
	{
		SET_BIT(MCUCR, ISC00);
		SET_BIT(MCUCR, ISC01);
		return E_OK;
	}
	else
	{
		return E_NOT_OK;
	}
}

uint8 EXIT_U8EXIT0Enable(void)
{
	/* Peripheral Interrupt Enable */
	SET_BIT(GICR, INT0);
	return E_OK;
}

uint8 EXIT_U8EXIT0Disable(void)
{
	/* Peripheral Interrupt Disable */
	CLEAR_BIT(GICR, INT0);
	return E_OK;
}

uint8 EXIT_U8EXIT0SetCallBack(void (*LOC_VidPtrToFun)(void))
{
	if ( LOC_VidPtrToFun != NULL_PTR)
	{
		/* Set the global pointer to point to the passed function */
		GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT0] = LOC_VidPtrToFun;
		return E_OK;
	}
	else
	{
		return E_NOT_OK;
	}
}


/*****************************************************************************************************************************/

uint8 EXIT_U8EXIT1Init(void)
{
	/* Configure Sense Control */
#if EXIT1_SENSE_CONTROL == LOW_LEVEL
	CLEAR_BIT(MCUCR, ISC11);
	CLEAR_BIT(MCUCR, ISC10);
#elif EXIT1_SENSE_CONTROL == LOGIC_CHANGE
	SET_BIT(MCUCR, ISC10);
	CLEAR_BIT(MCUCR, ISC11);
#elif EXIT1_SENSE_CONTROL == FALLING_EDGE
	CLEAR_BIT(MCUCR, ISC10);
	SET_BIT(MCUCR, ISC11);
#elif EXIT1_SENSE_CONTROL == RISING_EDGE
	SET_BIT(MCUCR, ISC11);
	SET_BIT(MCUCR, ISC10);
#else
	 return E_NOT_OK;
#endif
	return E_OK;
}

uint8 EXIT_U8EXIT1SenseControl(const uint8 LOC_U8Source)
{
	if (LOC_U8Source == LOW_LEVEL)
	{
		CLEAR_BIT(MCUCR, ISC11);
		CLEAR_BIT(MCUCR, ISC10);
		return E_OK;
	}
	else if (LOC_U8Source == LOGIC_CHANGE)
	{
		SET_BIT(MCUCR, ISC10);
		CLEAR_BIT(MCUCR, ISC11);
		return E_OK;
	}
	else if (LOC_U8Source == FALLING_EDGE)
	{
		CLEAR_BIT(MCUCR, ISC10);
		SET_BIT(MCUCR, ISC11);
		return E_OK;
	}
	else if (LOC_U8Source == RISING_EDGE)
	{
		SET_BIT(MCUCR, ISC11);
		SET_BIT(MCUCR, ISC10);
		return E_OK;
	}
	else
	{
		return E_NOT_OK;
	}
}

uint8 EXIT_U8EXIT1Enable(void)
{
	/* Peripheral Interrupt Enable */
	SET_BIT(GICR, INT1);
	return E_OK;
}

uint8 EXIT_U8EXIT1Disable(void)
{
	/* Peripheral Interrupt Disable */
	CLEAR_BIT(GICR, INT1);
	return E_OK;
}

uint8 EXIT_U8EXIT1SetCallBack(void (*LOC_VidPtrToFun)(void))
{
	if ( LOC_VidPtrToFun != NULL_PTR)
	{
		/* Set the global pointer to point to the passed function */
		GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT1] = LOC_VidPtrToFun;
		return E_OK;
	}
	else
	{
		return E_NOT_OK;
	}
}


/*****************************************************************************************************************************************/

uint8 EXIT_U8EXIT2Init(void)
{
	/* When Changing the ISC2 bit, an interrupt can occur. Therefore, it is recommended
	 * to first disable INT2 by clearing its interrupt Enable bit in GICR. Then, the
	 * ISC2 bit can be changed. Finally, the INT2 Interrupt Flag should be cleared by
	 * writing a logical one to its Interrupt Flag bit (INTF2) in GIFR before the
	 * interrupt is re-enabled
	 */
	CLEAR_BIT(GICR, INT2);
	/* Configure Sense Control */
#if EXIT2_SENSE_CONTROL == FALLING_EDGE
	CLEAR_BIT(MCUCSR, ISC2);
#elif EXIT2_SENSE_CONTROL == RISING_EDGE
	SET_BIT(MCUCSR, ISC2);
#else
         return E_NOT_OK;
#endif
	/* CLEAR INT2 Interrupt Flag */
	SET_BIT(GIFR, INTF2);
	return E_OK;
}

uint8 EXIT_U8EXIT2SenseControl(const uint8 LOC_U8Source)
{
	/* When Changing the ISC2 bit, an interrupt can occur. Therefore, it is recommended
	 * to first disable INT2 by clearing its interrupt Enable bit in GICR. Then, the
	 * ISC2 bit can be changed. Finally, the INT2 Interrupt Flag should be cleared by
	 * writing a logical one to its Interrupt Flag bit (INTF2) in GIFR before the
	 * interrupt is re-enabled
	 */
	CLEAR_BIT(GICR, INT2);
	if (LOC_U8Source == FALLING_EDGE)
	{
		CLEAR_BIT(MCUCSR, ISC2);
		/* CLEAR INT2 Interrupt Flag */
		SET_BIT(GIFR, INTF2);
		return E_OK;
	}
	else if (LOC_U8Source == RISING_EDGE)
	{
		SET_BIT(MCUCSR, ISC2);
		/* CLEAR INT2 Interrupt Flag */
		SET_BIT(GIFR, INTF2);
		return E_OK;
	}
	else
	{
		return E_NOT_OK;
	}
}

uint8 EXIT_U8EXIT2Enable(void)
{
	/* Peripheral Interrupt Enable */
	SET_BIT(GICR, INT2);
	return E_OK;
}

uint8 EXIT_U8EXIT2Disable(void)
{
	/* Peripheral Interrupt Disable */
	CLEAR_BIT(GICR, INT2);
	return E_OK;
}

uint8 EXIT_U8EXIT2SetCallBack(void (*LOC_VidPtrToFun)(void))
{
	if ( LOC_VidPtrToFun != NULL_PTR)
	{
		/* Set the global pointer to point to the passed function */
		GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT2] = LOC_VidPtrToFun;
		return E_OK;
	}
	else
	{
		return E_NOT_OK;
	}
}
/****************************************************************************************************************************/


/* Interrupt Service Routine (ISR) of external interrupt 0 */
void __vector_1 (void)
{
	if (GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT0] != NULL_PTR)
	{
		(*GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT0])();
	}
}

/* Interrupt Service Routine (ISR) of external interrupt 1 */
void __vector_2 (void)
{
	if (GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT1] != NULL_PTR)
	{
		(*GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT1])();
	}
}

/* Interrupt Service Routine (ISR) of external interrupt 2 */
void __vector_3 (void)
{
	if (GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT2] != NULL_PTR)
	{
		(*GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT2])();
	}
}

