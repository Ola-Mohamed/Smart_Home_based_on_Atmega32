/*
 * DIO_TYPES.h
 *
 *  Created on: 24 Oct 2023
 *      Author: 20128
 */

#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

// Type definition for a standard error code.
typedef enum {
  E_OK, // The operation was successful.
  E_NOT_OK, // The operation failed.
} STD_TYPE;


// Type definition for a DIO logic level.
typedef enum {
  LOGIC_LOW, // The signal is at a low voltage level.
  LOGIC_HIGH, // The signal is at a high voltage level.
} DIO_LEVEL_TYPE;

// Type definition for a DIO pin direction.
typedef enum {
  PIN_INPUT, // Pin is configured as an input.
  PIN_OUTPUT, // Pin is configured as an output.
} DIO_PIN_DIRECTION_TYPE;

// Type definition for a DIO port direction.
typedef enum {
  PORT_INPUT, // Port is configured as an input.
  PORT_OUTPUT = 0xFF, // Port is configured as an output, with all pins set to high.
} DIO_PORT_DIRECTION_TYPE;

// Type definition for a DIO port ID.
typedef enum {
  PORTA_ID, // Port A.
  PORTB_ID, // Port B.
  PORTC_ID, // Port C.
  PORTD_ID, // Port D.
} DIO_PORT_ID;

// Type definition for a DIO pin ID.
typedef enum {
  PIN0_ID,
  PIN1_ID,
  PIN2_ID,
  PIN3_ID,
  PIN4_ID,
  PIN5_ID,
  PIN6_ID,
  PIN7_ID,
} DIO_PIN_ID;

// Structure to represent a DIO configuration.
typedef struct {
  DIO_PIN_ID PIN; // Pin ID.
  DIO_PORT_ID PORT; // Port ID.
  DIO_PORT_DIRECTION_TYPE PORT_DIRECTION; // Port direction.
  DIO_PIN_DIRECTION_TYPE PIN_DIRECTION; // Pin direction.
} Dio_ConfigType;


#endif /* DIO_TYPES_H_ */
