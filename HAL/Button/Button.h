/******************************************************************************
 *
  Module: Button
 *
 * File Name: Button.h
 *
 * Description: Header file for Button Module.
 *
 ******************************************************************************/
#ifndef BUTTON_H
#define BUTTON_H

#include "STD_TYPES.h"
#include "../DIO/DIO_INTERFACE.h"

/* Button State according to its configuration PULL UP/Down */
#define BUTTON_PRESSED  LOGIC_LOW
#define BUTTON_RELEASED LOGIC_HIGH
#define Button_PORT     DIO_PORT_ID
#define Button_PIN      DIO_PIN_ID


// Type definition for a button configuration.
typedef struct {
  DIO_PIN_ID pin_id;
  DIO_PORT_ID port_id;
  DIO_PIN_DIRECTION_TYPE pin_direction;

} BUTTON_config_t;

/*
 * Description: 1. Fill the button configurations structure
 *              2. Set the PIN direction which the button is connected as INPUT pin
 */
void HAL_BUTTON_init(BUTTON_config_t *button_config);

/* Description: Read the Button state Pressed/Released */
uint8 HAL_BUTTON_getState(Button_PORT,Button_PIN);


#endif /* BUTTON_H */
