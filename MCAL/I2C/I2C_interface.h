 /******************************************************************************
 *
 * Module: I2C
 *
 * File Name: i2c.h
 *
 * Description: Header file for the I2C AVR driver
 *
 * Author: hp
 *
 *******************************************************************************/

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "std_types.h"
#include "I2C_TYPES.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void TWI_init(const TWI_ConfigType * Config_Ptr);
void TWI_start(void);
void TWI_stop(void);
void TWI_writeByte(uint8 data);
uint8 TWI_readByteWithACK(void);
uint8 TWI_readByteWithNACK(void);
uint8 TWI_getStatus(void);


#endif /* I2C_INTERFACE_H_ */
