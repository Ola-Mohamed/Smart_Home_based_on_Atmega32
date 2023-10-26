/*
 * EXIT_INTERFACE.h
 *
 *  Created on: 26 Oct 2023
 *      Author: 20128
 */

#ifndef EXIT_INTERFACE_H_
#define EXIT_INTERFACE_H_

#include "STD_TYPES.h"
#include"EXIT_TYPES.h"
#include"common_macros.h"





// external interrupt 0 initialization
void EXT_INT_0_init(EN_interrupt_sense_t SENSE);

// external interrupt 1 initialization
void EXT_INT_1_init(EN_interrupt_sense_t SENSE);

// external interrupt 2 initialization
void EXT_INT_2_init(EN_interrupt_sense_t SENSE);


#endif /* EXIT_INTERFACE_H_ */
