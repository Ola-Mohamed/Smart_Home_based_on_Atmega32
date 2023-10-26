/*
 * buzzer.h
 *
 *  Created on: Oct 27, 2022
 *      Author: hp
 */

#ifndef BUZZER_H_
#define BUZZER_H_
/* Set the BUZZER ON/OFF according to its configuration Positive logic or negative logic */
#define BUZZER_ON    LOGIC_HIGH
#define BUZZER_OFF    LOGIC_LOW
#define BUZZER_PORT      DIO_PORT_ID
#define BUZZER_PIN      DIO_PIN_ID



// Type definition for a BUZZWE configuration.
typedef struct {
  DIO_PIN_ID pin_id;
  DIO_PORT_ID port_id;
  DIO_PIN_DIRECTION_TYPE pin_direction;

} BUZZER_config_t;

/* Description: 1. Fill the BUZZER configurations structure
 *              2. Set the PIN direction which the BUZZER is connected as OUTPUT pin
 *		        3. Initialize the BUZZER ON/OFF according to the initial value
 */
void BUZZER_init(BUZZER_config_t *buzzer_config);
/* Description: Set the BUZZER state to ON */
void BUZZER_setOn(void);

/* Description: Set the BUZZER state to OFF */
void BUZZER_setOff(void);

#endif /* BUZZER_H_ */
