/******************************************************************************
 *
  Module: Led
 *
 * File Name: Led.c
 *
 * Description: Source file for Led Module.
 ******************************************************************************/

#include "Led.h"

void LED_init(){

	MCAL_DIO_INIT();

}

void LED_setOn(Dio_ConfigType  *LED)
{
	MCAL_DIO_Std_WRITE_PIN(&LED, LOGIC_HIGH);    /* LED ON */
}

/*********************************************************************************************/
void LED_setOff(Dio_ConfigType  *LED)
{
	MCAL_DIO_Std_WRITE_PIN(&LED, LOGIC_LOW);  /* LED OFF */
}

/*********************************************************************************************/
void LED_toggle(Dio_ConfigType  *LED)
{
	MCAL_DIO_Std_FLIP_PIN_DIRECTION(&LED);
}

/*********************************************************************************************/
