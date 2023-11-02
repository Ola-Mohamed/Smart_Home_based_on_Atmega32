/******************************************************************************
 *
 * Module: External Interrupt
 *
 * File Name: EXIT_CONFIG.c
 *
 * Author: Nti Team
 *
 * ******************************************************************************/

/*****************************************************************************/
/*  OPTIONS FOR EXTERNAL INTERRUPT INITIAL SENSE CONTROL:
/*  -LOGIC_CHANGE :EXIT0 ,EXIT1
 *  -RISING_EDGE  :EXIT0 ,EXIT1,EXIT2
 *  -FALLING_EDGE :EXIT0 ,EXIT1,EXIT2
 *  -LOW_LEVEL    : EXIT0 ,EXIT1
/*****************************************************************************/

#define EXIT0_SENSE_CONTROL 	RISING_EDGE

#define EXIT1_SENSE_CONTROL		RISING_EDGE

#define EXIT2_SENSE_CONTROL		FALLING_EDGE
/*****************************************************************************/
