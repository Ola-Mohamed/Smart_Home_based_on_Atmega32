/*
  MemMap.h
 *
 *  Created on: 26 Oct 2023
 *      Author: 20128
 */


/************************************************************************/
/* interrupt                                                                      */
/************************************************************************/



#include <avr/io.h>
#include <util/delay.h>



#define MCUCR     *((volatile uint8_t *)0x55)  // 8-bit register
#define MCUCSR    *((volatile uint8_t *)0x54)  // 8-bit register
#define GICR      *((volatile uint8_t *)0x5B)  // 8-bit register
#define GIFR     *((volatile uint8_t *)0x5A)  // 8-bit register
//External interrupt 0 sense bits
#define ISC00   0
#define ISC01   1
//External interrupt 1 sense bits
#define ISC10   2
#define ISC11   3
//External interrupt 2 sense bits
#define ISC2   6
//external interrupt enable bits
#define INT2    5
#define INT0    6
#define INT1    7
