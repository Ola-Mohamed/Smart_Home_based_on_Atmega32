/******************************************************************************
 *
  *Module: Button
 *
 * File Name: Button.c
 *
 * Description: Source file for Button Module.
 *
 ******************************************************************************/


#include "Button.h"

/* Global variable to hold the button state */
static uint8 g_button_state = BUTTON_RELEASED;
/***********************************************************************************************************/

/************************************************************************************
* Service Name: HAL_BUTTON_init
* Parameters (in): BUTTON_config_t *button_config
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Button module.
************************************************************************************/
void HAL_BUTTON_init(BUTTON_config_t *button_config) {
	  // Check if the button configuration is valid.
	  if (button_config == NULL_PTR) {
	    return ;
	  }

	  else{

		  //do nothing
	  }
	  // Set the PIN direction which the button is connected as INPUT pin.
	 MCAL_DIO_INIT(button_config);
}

/***********************************************************************************************************/
/************************************************************************************
* Service Name: HAL_BUTTON_getState
* Parameters (in): Button_PORT,Button_PIN
* Parameters (inout): None
* Parameters (out): None
* Return value: g_button_state
* Description: Function to Initialize the Button module.
************************************************************************************/
uint8 HAL_BUTTON_getState(Button_PORT,Button_PIN)
{

    g_button_state =MCAL_DIO_Std_READ_PIN_DIRECTION(Button_PORT,Button_PIN);

    return g_button_state;
}
/************************************************************************************************************/
