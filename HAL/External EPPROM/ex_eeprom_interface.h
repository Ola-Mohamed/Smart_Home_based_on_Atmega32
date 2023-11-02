 /******************************************************************************
 *
 * Module: External EEPROM
 *
 * File Name: external_eeprom.h
 *
 * Description: Header file for the External EEPROM Memory
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/


#ifndef EX_EEPROM_INTERFACE_H_
#define EX_EEPROM_INTERFACE_H_

#include "std_types.h"



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

uint8 EEPROM_writeByte(uint16 u16addr,uint8 u8data);
uint8 EEPROM_readByte(uint16 u16addr,uint8 *u8data);
 
#endif /* EX_EEPROM_INTERFACE_H_ */
