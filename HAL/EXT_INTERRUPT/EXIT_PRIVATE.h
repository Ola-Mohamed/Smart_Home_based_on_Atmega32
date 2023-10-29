/*
 * EXIT_PROG.c
 *
 *  Created on: 26 Oct 2023
 *      Author: 20128
 */

#ifndef EXIT_PROG_C_
#define EXIT_PROG_C_


/************************************************************************************/
/* 								 SENSE CONTROL 										*/
/************************************************************************************/
#define RISING_EDGE 	3
#define FALLING_EDGE 	2
#define LOGIC_CHANGE 	1
#define LOW_LEVEL 		0


/************************************************************************************/
/* 						   ISRs PROTOTYPES - ATTRIBUTES 							*/
/************************************************************************************/
void __vector_1 (void) __attribute__ ((signal));
void __vector_2 (void) __attribute__ ((signal));
void __vector_3 (void) __attribute__ ((signal));
/************************************************************************************/


/************************************************************************************/
/* 						   EXTERNAL INTERRUPTS DEFINITIONS 							*/
/************************************************************************************/
#define EXTERNAL_INTERRUPT0				0
#define EXTERNAL_INTERRUPT1				1
#define EXTERNAL_INTERRUPT2				2
#define NUM_OF_EX_INTERRUPTS			3
/************************************************************************************/




#endif /* EXIT_PROG_C_ */
