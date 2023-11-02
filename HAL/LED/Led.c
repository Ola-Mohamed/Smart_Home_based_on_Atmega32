/******************************************************************************
 *
  Module: Led
 *
 * File Name: Led.c
 *
 * Description: Source file for Led Module.
 ******************************************************************************/

#include "Led.h"

/************************************************************************************
* Service Name: HAL_LED_init
* Parameters (in): LED_config_t
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the LED module.
************************************************************************************/


void HAL_LED_init(LED_config_t Led_config){

	MCAL_DIO_INIT(&Led_config->port_id,&Led_config->pin_id,&Led_config->pin_direction);

}
/************************************************************************************
* Service Name: HAL_LED_setOn
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to SET the LED module ON.
************************************************************************************/
void HAL_LED_setOn(void)
{
	 MCAL_DIO_Std_WRITE_PIN_DIRECTION(LED_PORT,LED_PIN,LED_ON);  /* LED ON */
}

/************************************************************************************
* Service Name: HAL_LED_setOff
* Parameters (in):None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to SET the LED module Off.
************************************************************************************/
void HAL_LED_setOff(void)
{
	MCAL_DIO_Std_WRITE_PIN_DIRECTION(LED_PORT,LED_PIN,LED_OFF); /* LED OFF */
}

/************************************************************************************
* Service Name: HAL_LED_toggle
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Toggle LED.
************************************************************************************/
void HAL_LED_toggle(void)
{
     MCAL_DIO_Std_FLIP_PIN_DIRECTION(LED_PORT,LED_PIN);
}

/*********************************************************************************************/
