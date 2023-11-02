/*
 * uart_types.h
 *
 *  Created on: Oct 31, 2023
 *      Author: hp
 */

#ifndef UART_TYPES_H_
#define UART_TYPES_H_

/*______________________________________________________________________________
 |                       	   Types Definitions                   		     	|
 |______________________________________________________________________________|
 */
typedef enum {
	FIVE_BIT_MODE , SIX_BIT_MODE  = 2
	, SEVEN_BIT_MODE = 4, EIGHT_BIT_MODE = 6} UART_BitData;

typedef enum {
	DISABLED_PARITY , EVEN_PARITY = 32 , ODD_PARITY = 48 } UART_Parity;

typedef enum {
	ONE_STOP_BIT , TWO_STOP_BIT = 8} UART_StopBit;

typedef struct  {
	UART_BitData bit_data;
	UART_Parity parity;
	UART_StopBit stop_bit;
	uint32 baud_rate;
}UART_ConfigType;



#endif /* UART_TYPES_H_ */
