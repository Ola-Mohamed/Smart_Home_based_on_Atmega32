/*
* KEYPAD_CONFIG.h
*
* Created: 29/10/2023 09:22:35 م
*  Author: JoBa
*/


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "DIO_TYPES.h"


/******************************************************************KEYPAD COUNT ROWS AND COULMNS ************************************************************/
#define KEYPAD_ROW_COUNT       4
#define KEYPAD_COULMN_COUNT    4

/*************************************************************************KEYPAD PINS ROW ********************************************************************/
#define KEYPAD_ROW0         PIN0_ID
#define KEYPAD_ROW1         PIN1_ID
#define KEYPAD_ROW2		    PIN2_ID
#define KEYPAD_ROW3			PIN3_ID

/************************************************************************KEYPAD PINS COULMN *********************************************************************/
#define KEYPAD_COULMN0      PIN4_ID
#define KEYPAD_COULMN1      PIN5_ID
#define KEYPAD_COULMN2      PIN6_ID
#define KEYPAD_COULMN3      PIN7_ID

/****************************************************************************KEYPAD PORT *************************************************************************/
#define KEYPAD_PORT         PORTC_ID


/****************************************************************** BUTTONS OPERATIONS IN KEYPAD*******************************************************************/
#define KEYPAD_BUTTONS_OP0       {  '7'  ,   '8'   ,  '9'  ,  '/'  }
#define KEYPAD_BUTTONS_OP1	   	 {  '4'  ,   '5'   ,  '6'  ,  '*'  }
#define KEYPAD_BUTTONS_OP2		 {  '1'  ,   '2'   ,  '3'  ,  '-'  }
#define KEYPAD_BUTTONS_OP3		 {  'c'  ,   '0'   ,  '='  ,  '+'  }



/*********************************************************************** EXTERN CONFIG ARRAY **********************************************************************/
extern const uint8 KEYPAD_arrConfig[KEYPAD_ROW_COUNT][KEYPAD_COULMN_COUNT];


#endif /* KEYPAD_CONFIG_H_ */