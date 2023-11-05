/*
 * COMMUNICATION_PROG.c
 *
 * Created: 04/11/2023 12:50:43 م
 *  Author: JoBa
 */ 

/*   */

#include "COMMUNICATION_INTERFACE.h"

uint8 COMMUNICATION_recieveChar(){
	uint8 dataByte ; 
	dataByte = UART_recieveByte();
	return dataByte;
}

void COMMUNICATION_receiveString(uint8 *Str){
	
	 UART_receiveString(Str);

}

void COMMUNICATION_sendString(const uint8 *Str){
	
	 UART_sendString(Str);

}


