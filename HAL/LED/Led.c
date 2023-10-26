/******************************************************************************
 *
  Module: Led
 *
 * File Name: Led.c
 *
 * Description: Source file for Led Module.
 ******************************************************************************/

#include "Led.h"




void HAL_LED_init(LED_config_t Led_config){

	MCAL_DIO_INIT(&Led_config->port_id,&Led_config->pin_id,&Led_config->pin_direction);

}

void HAL_LED_setOn(void)
{
	 MCAL_DIO_Std_WRITE_PIN_DIRECTION(LED_PORT,LED_PIN,LED_ON);  /* LED ON */
}

/*********************************************************************************************/
void HAL_LED_setOff(void)
{
	MCAL_DIO_Std_WRITE_PIN_DIRECTION(LED_PORT,LED_PIN,LED_OFF); /* LED OFF */
}

/*********************************************************************************************/
void HAL_LED_toggle(void)
{
     MCAL_DIO_Std_FLIP_PIN_DIRECTION(LED_PORT,LED_PIN);
}

/*********************************************************************************************/
