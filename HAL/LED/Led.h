/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led.h
 *
 * Description: Header file for Led Module.
 *
 ******************************************************************************/
#ifndef LED_H
#define LED_H


#include "STD_TYPES.h"
#include "../DIO/DIO_INTERFACE.h"

/* Set the led ON/OFF according to its configuration Positive logic or negative logic */
#define LED_ON    LOGIC_HIGH
#define LED_OFF    LOGIC_LOW
#define LED_PORT     DIO_PORT_ID
#define LED_PIN      DIO_PIN_ID



// Type definition for a LED configuration.
typedef struct {
  DIO_PIN_ID pin_id;
  DIO_PORT_ID port_id;
  DIO_PIN_DIRECTION_TYPE pin_direction;

} LED_config_t;

/* Description: 1. Fill the led configurations structure
 *              2. Set the PIN direction which the led is connected as OUTPUT pin
 *		        3. Initialize the led ON/OFF according to the initial value
 */
void HAL_LED_init(LED_config_t *Led_config);

/* Description: Set the LED state to ON */
void HAL_LED_setOn(void);

/* Description: Set the LED state to OFF */
void HAL_LED_setOff(void);

/*Description: Toggle the LED state */
void HAL_LED_toggle(void);

#endif /* LED_H */
