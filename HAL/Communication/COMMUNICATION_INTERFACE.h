/*
 * COMMUNICATION_INTERFACE.h
 *
 * Created: 04/11/2023 12:51:03 م
 *  Author: JoBa
 */ 


#ifndef COMMUNICATION_INTERFACE_H_
#define COMMUNICATION_INTERFACE_H_

#include "uart.h"

uint8 COMMUNICATION_recieveChar(void);

void COMMUNICATION_receiveString(uint8 *Str);

void COMMUNICATION_sendString(const uint8 *Str);





#endif /* COMMUNICATION_INTERFACE_H_ */