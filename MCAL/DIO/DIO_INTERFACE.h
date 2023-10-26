/*
 * DIO_INTERFACE.h
 *
 *  Created on: 24 Oct 2023
 *      Author: 20128
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "DIO_TYPES.h"
#include"DIO_PRIVATE.h"

// Function to initialize the DIO peripheral.
void MCAL_DIO_INIT();

// Function to set the direction of a DIO port.
STD_TYPE MCAL_DIO_Std_WRITE_PORT_DIRECTION(
    DIO_PORT_ID *PortId, // Pointer to the ID of the DIO port.
    DIO_PORT_DIRECTION_TYPE *PortLevel // Pointer to the direction to set the DIO port to.
);

// Function to set the direction of a DIO pin.
STD_TYPE MCAL_DIO_Std_WRITE_PIN_DIRECTION(
    DIO_PIN_ID *PinId, // Pointer to the ID of the DIO pin.
    DIO_PIN_DIRECTION_TYPE *PinLevel // Pointer to the direction to set the DIO pin to.
);


// Function to read the direction of a DIO port.
DIO_LEVEL_TYPE MCAL_DIO_Std_READ_PORT_DIRECTION( DIO_PORT_ID PortId); // Pointer to the ID of the DIO port.


// Function to read the direction of a DIO pin.
DIO_LEVEL_TYPE MCAL_DIO_Std_READ_PIN_DIRECTION(DIO_PORT_ID PortId,DIO_PIN_ID PinId);
   // Pointer to the ID of the DIO pin.

// Function to flip the direction of a DIO port.
DIO_LEVEL_TYPE MCAL_DIO_Std_FLIP_PORT_DIRECTION(
    DIO_PORT_ID *PortId // Pointer to the ID of the DIO port.
);

// Function to flip the direction of a DIO pin.
DIO_LEVEL_TYPE MCAL_DIO_Std_FLIP_PIN_DIRECTION(
    DIO_PIN_ID *PinId // Pointer to the ID of the DIO pin.
);


#endif /* DIO_INTERFACE_H_ */
