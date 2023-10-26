/*
 * buzzwr.c
 *
 *  Created on: Oct 27, 2022
 *      Author: hp
 */
#include "gpio.h"
#include "buzzer.h"
/*
 * Setup the direction for the buzzer pin as output pin through the
DIO driver.


 */
void Buzzer_init(void)
{
	MCAL_DIO_INIT(&buzzer_config->port_id,&buzzer_config->pin_id,&buzzer_config->pin_direction);

}
/* Description: Set the BUZZER state to ON */
void BUZZER_setOn(void);
{
	MCAL_DIO_Std_WRITE_PIN_DIRECTION(BUZZER_PORT,BUZZER_PIN,BUZZER_ON); //turn on buzzer
}


/* Description: Set the BUZZER state to OFF */
void BUZZER_setOff(void);
{
	MCAL_DIO_Std_WRITE_PIN_DIRECTION(BUZZER_PORT,BUZZER_PIN,BUZZER_OFF);  //turn off buzzer

}
