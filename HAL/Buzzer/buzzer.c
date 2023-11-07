/******************************************************************************
 *
  Module: BUZZER
 *
 * File Name: buzzer.c
 *
 * Description: source file for buzzer module.
 *
 ******************************************************************************/
#include "buzzer.h"
/***********************************************************************************************/

void BUZZER_setOn()
{
	MCAL_DIO_Std_WRITE_PIN(&BUZZER, LOGIC_HIGH);    /* LED ON */
}

/*********************************************************************************************/
void BUZZER_setOff()
{
	MCAL_DIO_Std_WRITE_PIN(&BUZZER, LOGIC_LOW);  /* LED OFF */
}

