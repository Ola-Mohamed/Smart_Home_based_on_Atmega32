/******************************************************************************
 *
 * Module: External Interrupt
 *
 * File Name: EXIT_PROG.c
 *
 * Author: Nti Team
 *
 * ******************************************************************************/


#include "EXIT_INTERFACE.h"
#include "MemMap.h"


/* Array of Global Pointers to Functions for Calling Back */
void (*GLOB_VidINTPtrCallBack[NUM_OF_EX_INTERRUPTS])(void) = {NULL_PTR, NULL_PTR, NULL_PTR};

/************************************************************************************************/

/************************************************************************************
* Service Name: EXIT_U8EXIT0Init
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: uint8
* Description: Function to Initialize the Interrupt0 module.
************************************************************************************/

uint8 EXIT_U8EXIT0Init(void)
{
	/* Configure Sense Control */
#if EXIT0_SENSE_CONTROL == LOW_LEVEL
	CLEAR_BIT(MCUCR, ISC00);   // Clear ISC00 bit in MCUCR register
	CLEAR_BIT(MCUCR, ISC01);   // Clear ISC01 bit in MCUCR register

#elif EXIT0_SENSE_CONTROL == LOGIC_CHANGE
	SET_BIT(MCUCR, ISC00);     // Set ISC00 bit in MCUCR register
	CLEAR_BIT(MCUCR, ISC01);   // Clear ISC01 bit in MCUCR register

#elif EXIT0_SENSE_CONTROL == FALLING_EDGE
	CLEAR_BIT(MCUCR, ISC00);   // Clear ISC00 bit in MCUCR register
	SET_BIT(MCUCR, ISC01);     // Set ISC01 bit in MCUCR register

#elif EXIT0_SENSE_CONTROL == RISING_EDGE
	SET_BIT(MCUCR, ISC00);     // Set ISC00 bit in MCUCR register
	SET_BIT(MCUCR, ISC01);     // Set ISC01 bit in MCUCR register

#else
	return E_NOT_OK;           // Return E_NOT_OK if an invalid EXIT0_SENSE_CONTROL value is defined

#endif

	return E_OK;                // Return E_OK to indicate successful initialization
}

/************************************************************************************
* Service Name: EXIT_U8EXIT0SenseControl
* Parameters (in):  LOC_U8Source
* Parameters (inout): None
* Parameters (out): None
* Return value: uint8
* Description: Function to Sense Control based on LOC_U8Source.
************************************************************************************/
uint8 EXIT_U8EXIT0SenseControl(const uint8 LOC_U8Source)
{
	/* Configure Sense Control based on LOC_U8Source */
	if (LOC_U8Source == LOW_LEVEL)
	{
		CLEAR_BIT(MCUCR, ISC00);   // Clear ISC00 bit in MCUCR register
		CLEAR_BIT(MCUCR, ISC01);   // Clear ISC01 bit in MCUCR register
		return E_OK;               // Return E_OK to indicate successful configuration
	}
	else if (LOC_U8Source == LOGIC_CHANGE)
	{
		SET_BIT(MCUCR, ISC00);     // Set ISC00 bit in MCUCR register
		CLEAR_BIT(MCUCR, ISC01);   // Clear ISC01 bit in MCUCR register
		return E_OK;               // Return E_OK to indicate successful configuration
	}
	else if (LOC_U8Source == FALLING_EDGE)
	{
		CLEAR_BIT(MCUCR, ISC00);   // Clear ISC00 bit in MCUCR register
		SET_BIT(MCUCR, ISC01);     // Set ISC01 bit in MCUCR register
		return E_OK;               // Return E_OK to indicate successful configuration
	}
	else if (LOC_U8Source == RISING_EDGE)
	{
		SET_BIT(MCUCR, ISC00);     // Set ISC00 bit in MCUCR register
		SET_BIT(MCUCR, ISC01);     // Set ISC01 bit in MCUCR register
		return E_OK;               // Return E_OK to indicate successful configuration
	}
	else
	{
		return E_NOT_OK;           // Return E_NOT_OK if an invalid LOC_U8Source value is provided
	}
}
/************************************************************************************
* Service Name: EXIT_U8EXIT0Enable
* Parameters (in):  None
* Parameters (inout): None
* Parameters (out): None
* Return value: uint8
* Description: Function to Enable External Interrupt 0.
************************************************************************************/
uint8 EXIT_U8EXIT0Enable(void)
{
	/* Enable External Interrupt 0 */
	SET_BIT(GICR, INT0);           // Set INT0 bit in GICR register
	return E_OK;                   // Return E_OK to indicate successful enablement
}
/************************************************************************************
* Service Name: EXIT_U8EXIT0Disable
* Parameters (in):  None
* Parameters (inout): None
* Parameters (out): None
* Return value: uint8
* Description: Function to Enable External Interrupt 0.
************************************************************************************/
uint8 EXIT_U8EXIT0Disable(void)
{
	/* Disable External Interrupt 0 */
	CLEAR_BIT(GICR, INT0);         // Clear INT0 bit in GICR register
	return E_OK;                   // Return E_OK to indicate successful disablement
}
/************************************************************************************
* Service Name: EXIT_U8EXIT0SetCallBack
* Parameters (in):  None
* Parameters (inout): None
* Parameters (out): None
* Return value: uint8
* Description: Function to Sets the callback function for external interrupt 0. .
************************************************************************************/
uint8 EXIT_U8EXIT0SetCallBack(void (*LOC_VidPtrToFun)(void))
{
	if (LOC_VidPtrToFun != NULL_PTR)
	{
		/* Set the global pointer to point to the passed function */
		GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT0] = LOC_VidPtrToFun;
		return E_OK;               // Return E_OK to indicate successful callback setting
	}
	else
	{
		return E_NOT_OK;           // Return E_NOT_OK if NULL pointer is provided
	}
}

/*****************************************************************************************************************************/
/************************************************************************************
* Service Name: EXIT_U8EXIT1Init
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: uint8
* Description: Function to Initialize the Interrupt1 module.
************************************************************************************/
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
/************************************************************************************
* Service Name: EXIT_U8EXIT1SenseControl
* Parameters (in):  LOC_U8Source
* Parameters (inout): None
* Parameters (out): None
* Return value: uint8
* Description: Function to Sense Control based on LOC_U8Source.
************************************************************************************/
uint8 EXIT_U8EXIT1SenseControl(const uint8 LOC_U8Source)
{
	// Check the value of LOC_U8Source to determine the desired sense control mode
	if (LOC_U8Source == LOW_LEVEL)
	{
		// Configure sense control for low level
		CLEAR_BIT(MCUCR, ISC11);
		CLEAR_BIT(MCUCR, ISC10);
		return E_OK; // Return E_OK to indicate successful configuration
	}
	else if (LOC_U8Source == LOGIC_CHANGE)
	{
		// Configure sense control for logic change
		SET_BIT(MCUCR, ISC10);
		CLEAR_BIT(MCUCR, ISC11);
		return E_OK; // Return E_OK to indicate successful configuration
	}
	else if (LOC_U8Source == FALLING_EDGE)
	{
		// Configure sense control for falling edge
		CLEAR_BIT(MCUCR, ISC10);
		SET_BIT(MCUCR, ISC11);
		return E_OK; // Return E_OK to indicate successful configuration
	}
	else if (LOC_U8Source == RISING_EDGE)
	{
		// Configure sense control for rising edge
		SET_BIT(MCUCR, ISC11);
		SET_BIT(MCUCR, ISC10);
		return E_OK; // Return E_OK to indicate successful configuration
	}
	else
	{
		// Return E_NOT_OK if the provided sense control mode is not valid
		return E_NOT_OK;
	}
}
/************************************************************************************
* Service Name: EXIT_U8EXIT1Eable
* Parameters (in):  None
* Parameters (inout): None
* Parameters (out): None
* Return value: uint8
* Description: Function to Enable External Interrupt 1.
************************************************************************************/
uint8 EXIT_U8EXIT1Enable(void)
{
	/* Peripheral Interrupt Enable */
	SET_BIT(GICR, INT1);
	return E_OK;
}
/************************************************************************************
* Service Name: EXIT_U8EXIT1Disable
* Parameters (in):  None
* Parameters (inout): None
* Parameters (out): None
* Return value: uint8
* Description: Function to Enable External Interrupt 1.
************************************************************************************/
uint8 EXIT_U8EXIT1Disable(void)
{
	/* Peripheral Interrupt Disable */
	CLEAR_BIT(GICR, INT1);
	return E_OK;
}
/************************************************************************************
* Service Name: EXIT_U8EXIT1SetCallBack
* Parameters (in):  None
* Parameters (inout): None
* Parameters (out): None
* Return value: uint8
* Description: Function to Sets the callback function for external interrupt 1. .
************************************************************************************/
uint8 EXIT_U8EXIT1SetCallBack(void (*LOC_VidPtrToFun)(void))
{
	if (LOC_VidPtrToFun != NULL_PTR)
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
/************************************************************************************
* Service Name: EXIT_U8EXIT2Init
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: uint8
* Description: Function to Initialize the Interrupt2 module.
************************************************************************************/
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
/************************************************************************************
* Service Name: EXIT_U8EXIT2SenseControl
* Parameters (in):  LOC_U8Source
* Parameters (inout): None
* Parameters (out): None
* Return value: uint8
* Description: Function to Sense Control based on LOC_U8Source.
************************************************************************************/
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
/************************************************************************************
* Service Name: EXIT_U8EXIT2Eable
* Parameters (in):  None
* Parameters (inout): None
* Parameters (out): None
* Return value: uint8
* Description: Function to Enable External Interrupt 2.
************************************************************************************/

uint8 EXIT_U8EXIT2Enable(void)
{
	/* Peripheral Interrupt Enable */
	SET_BIT(GICR, INT2);
	return E_OK;
}

/************************************************************************************
* Service Name: EXIT_U8EXIT2Disable
* Parameters (in):  None
* Parameters (inout): None
* Parameters (out): None
* Return value: uint8
* Description: Function to Enable External Interrupt 2.
************************************************************************************/
uint8 EXIT_U8EXIT2Disable(void)
{
	/* Peripheral Interrupt Disable */
	CLEAR_BIT(GICR,INT2);
	return E_OK;
}
/************************************************************************************
* Service Name: EXIT_U8EXIT2SetCallBack
* Parameters (in):  None
* Parameters (inout): None
* Parameters (out): None
* Return value: uint8
* Description: Function to Sets the callback function for external interrupt 2. .
************************************************************************************/
uint8 EXIT_U8EXIT2SetCallBack(void (*LOC_VidPtrToFun)(void))
{
	if (LOC_VidPtrToFun != NULL_PTR)
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
