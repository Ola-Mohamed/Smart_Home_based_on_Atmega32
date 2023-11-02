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
#include"EXIT_PRIVATE.h"


/**************************************************************************************/
/* Description: Initialize sense control for external interrupt 0				   	  */
/* Input      : Nothing			                                                      */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
 uint8 EXIT_U8EXIT0Init(void);
/**************************************************************************************/

/**************************************************************************************/
/* Description: set sense control for external interrupt 0						   	  */
/* Input      : source for triggering                                                 */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
uint8 EXIT_U8EXIT0SenseControl(const uint8 LOC_U8Source);
/**************************************************************************************/

/**************************************************************************************/
/* Description: enable interrupt for external interrupt 0						   	  */
/* Input      : Nothing			                                                      */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
 uint8 EXIT_U8EXIT0Enable(void);
/**************************************************************************************/

/**************************************************************************************/
/* Description: disable interrupt for external interrupt 0						   	  */
/* Input      : Nothing			                                                      */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
uint8 EXIT_U8EXIT0Disable(void);
/**************************************************************************************/

/**************************************************************************************/
/* Description: takes a pointer to function that is to be executed on triggering	  */
/* external interrupt 0.									   						  */
/*	Inputs: pointer to a function that takes no arguments and returns no value	  	  */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
uint8 EXIT_U8EXIT0SetCallBack(void (*LOC_VidPtrToFun)(void));
/**************************************************************************************/

/**************************************************************************************/
/* Description: Initialize sense control for external interrupt 1				   	  */
/* Input      : Nothing			                                                      */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
uint8 EXIT_U8EXIT1Init(void);
/**************************************************************************************/

/**************************************************************************************/
/* Description: set sense control for external interrupt 1						   	  */
/* Input      : source for triggering                                                 */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
uint8 EXIT_U8EXIT1SenseControl(const uint8 LOC_U8Source);
/**************************************************************************************/

/**************************************************************************************/
/* Description: enable interrupt for external interrupt 1						   	  */
/* Input      : Nothing			                                                      */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
uint8 EXIT_U8EXIT1Enable(void);
/**************************************************************************************/

/**************************************************************************************/
/* Description: disable interrupt for external interrupt 1						   	  */
/* Input      : Nothing			                                                      */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
uint8 EXIT_U8EXIT1Disable(void);
/**************************************************************************************/

/**************************************************************************************/
/* Description: takes a pointer to function that is to be executed on triggering	  */
/* external interrupt 1.									   						  */
/*	Inputs: pointer to a function that takes no arguments and returns no value	  	  */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
uint8 EXIT_U8EXIT1SetCallBack(void (*LOC_VidPtrToFun)(void));
/**************************************************************************************/

/**************************************************************************************/
/* Description: Initialize sense control for external interrupt 2				   	  */
/* Input      : Nothing			                                                      */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
uint8 EXIT_U8EXIT2Init(void);
/**************************************************************************************/

/**************************************************************************************/
/* Description: set sense control for external interrupt 2						   	  */
/* Input      : source for triggering                                                 */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
uint8 EXIT_U8EXIT2SenseControl(const uint8 LOC_U8Source);
/**************************************************************************************/

/**************************************************************************************/
/* Description: enable interrupt for external interrupt 2						   	  */
/* Input      : Nothing			                                                      */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
uint8 EXIT_U8EXIT2Enable(void);
/**************************************************************************************/

/**************************************************************************************/
/* Description: disable interrupt for external interrupt 2						   	  */
/* Input      : Nothing			                                                      */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
uint8 EXIT_U8EXIT2Disable(void);
/**************************************************************************************/

/**************************************************************************************/
/* Description: takes a pointer to function that is to be executed on triggering	  */
/* external interrupt 2.									   						  */
/*	Inputs: pointer to a function that takes no arguments and returns no value	  	  */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
uint8 EXIT_U8EXIT2SetCallBack(void (*LOC_VidPtrToFun)(void));
/**************************************************************************************/


#endif /* EXIT_INTERFACE_H_ */
