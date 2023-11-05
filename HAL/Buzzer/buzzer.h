/******************************************************************************
 *
  Module: BUZZER
 *
 * File Name: buzzer.h
 *
 * Description: header file for buzzer module.
 *
 ******************************************************************************/

#ifndef BUZZER_H_
#define BUZZER_H_

#include"buzzer_config.h"

/* Description: 1. Fill the BUZZER configurations structure
 *              2. Set the PIN direction which the BUZZER is connected as OUTPUT pin
 *		        3. Initialize the BUZZER ON/OFF according to the initial value
 */

void Buzzer_init();
/* Description: Set the BUZZER state to ON */
void BUZZER_setOn(Dio_ConfigType  *BUZZER);

/* Description: Set the BUZZER state to OFF */
void BUZZER_setOff(Dio_ConfigType  *BUZZER);

#endif /* BUZZER_H_ */
