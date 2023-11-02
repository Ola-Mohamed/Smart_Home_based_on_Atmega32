/*
 * I2C_TYPES.h
 *
 *  Created on: Nov 1, 2023
 *      Author: hp
 */

#ifndef I2C_TYPES_H_
#define I2C_TYPES_H_
#define F_CPU              16000000
#define I2C_Address        uint8
#define I2C_BaudRate       uint32

typedef struct{
 I2C_Address address;
 I2C_BaudRate bit_rate;
}TWI_ConfigType;


#endif /* I2C_TYPES_H_ */
