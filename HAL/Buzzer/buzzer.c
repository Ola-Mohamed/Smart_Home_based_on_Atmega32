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

void Buzzer_init(void)
{
	MCAL_DIO_INIT();

}
/***********************************************************************************************/

void BUZZER_setOn(Dio_ConfigType  *BUZZER)
{
	MCAL_DIO_Std_WRITE_PIN(&BUZZER, LOGIC_HIGH);    /* LED ON */
}

/*********************************************************************************************/
void BUZZER_setOff(Dio_ConfigType  *BUZZER)
{
	MCAL_DIO_Std_WRITE_PIN(&BUZZER, LOGIC_LOW);  /* LED OFF */
}

