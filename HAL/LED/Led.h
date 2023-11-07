/******************************************************************************
 *
  Module: Led
 *
 * File Name: Led.h
 *
 * Description: Header file for Led Module.
 *
 ******************************************************************************/
#ifndef LED_H
#define LED_H


#include "LED_Cfg.h"




typedef enum{
	RED,
	GREEN,
	YELLOW,
	BLUE

}LED_COLOR;

/* Description: 1. Fill the led configurations structure
 *              2. Set the PIN direction which the led is connected as OUTPUT pin
 *		        3. Initialize the led ON/OFF according to the initial value
 */
void LED_init();
/* Description: Set the LED state to ON */
void LED_setOn(LED_COLOR LED);
/* Description: Set the LED state to OFF */
void LED_setOff(LED_COLOR LED);
/*Description: Toggle the LED state */
void LED_toggle(LED_COLOR LED);

#endif /* LED_H */
