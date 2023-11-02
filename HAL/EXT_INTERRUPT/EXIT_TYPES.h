/******************************************************************************
 *
 * Module: External Interrupt
 *
 * File Name: EXIT_TYPES.c
 *
 * Author: Nti Team
 *
 * ******************************************************************************/

#ifndef EXIT_TYPES_H_
#define EXIT_TYPES_H_



/**************************************************************************************/
/*					     FUNCTIONS ARGUMENTS                                            */
/**************************************************************************************/
#define EXIT0_RISING_EDGE		3 // Configure external interrupt 0 to be triggered on the rising edge of the input signal
#define EXIT0_FALLING_EDGE		2 // Configure external interrupt 0 to be triggered on the falling edge of the input signal
#define EXIT0_LOGIC_CHANGE		1 // Configure external interrupt 0 to be triggered on any change in the input signal
#define EXIT0_LOW_LEVEL			0 // Configure external interrupt 0 to be triggered when the input signal is held at a low level

#define EXIT1_RISING_EDGE		3 // Configure external interrupt 1 to be triggered on the rising edge of the input signal
#define EXIT1_FALLING_EDGE		2 // Configure external interrupt 1 to be triggered on the falling edge of the input signal
#define EXIT1_LOGIC_CHANGE		1 // Configure external interrupt 1 to be triggered on any change in the input signal
#define EXIT1_LOW_LEVEL			0 // Configure external interrupt 1 to be triggered when the input signal is held at a low level

#define EXIT2_RISING_EDGE		3 // Configure external interrupt 2 to be triggered on the rising edge of the input signal
#define EXIT2_FALLING_EDGE		2 // Configure external interrupt 2 to be triggered on the falling edge of the input signal

/**************************************************************************************/
#endif /* EXIT_TYPES_H_ */
