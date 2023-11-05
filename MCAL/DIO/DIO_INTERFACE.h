/******************************************************************************
 *

 * Module: DIO
 *
 * File Name: DIO_INTERFACE.h
 *
 * Author: Nti Team
 *
 * ******************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "DIO_TYPES.h"
#include"DIO_PRIVATE.h"
#include "DIO_CONFIG.h"
#include "Utils.h"
#include "MemMap.h

// Function to initialize the DIO peripheral.
void MCAL_DIO_INIT();


// Function to read the direction of a DIO port.
STD_TYPE_DIO MCAL_DIO_READ_PORT_DIRECTION(Dio_ConfigType* READ_PORT,u8PortValue*value);


// Function to read the direction of a DIO pin.
STD_TYPE_DIO MCAL_DIO_READ_PIN_DIRECTION(Dio_ConfigType* READ_PIN,u8PINValue*PIN_value);
   // Pointer to the ID of the DIO pin.

// Function to flip the direction of a DIO port.
DIO_LEVEL_TYPE MCAL_DIO_FLIP_PORT_DIRECTION(
    DIO_PORT_ID *PortId // Pointer to the ID of the DIO port.
);

// Function to flip the direction of a DIO pin.
DIO_LEVEL_TYPE MCAL_DIO_FLIP_PIN_DIRECTION(
    DIO_PIN_ID *PinId // Pointer to the ID of the DIO pin.
);
// Function to write on port of a DIO port.
STD_TYPE_DIO MCAL_DIO_Std_WRITE_PORT (
     Dio_ConfigType * Config_type , // Pointer to the ID of the DIO port.
	 uint8 data
);

// Function to write in pin of a DIO pin.
STD_TYPE_DIO MCAL_DIO_Std_WRITE_PIN (
    Dio_ConfigType * Config_type  ,  // Pointer to the ID of the DIO pin.
	DIO_LEVEL_TYPE volt
);


#endif /* DIO_INTERFACE_H_ */
