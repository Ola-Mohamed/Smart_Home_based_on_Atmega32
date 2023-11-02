 /******************************************************************************
 *
 * Module: TWI(I2C)

 *
 * File Name: I2C_PROG.C
 *
 * Description: Source file for the I2C AVR driver

 *
 *******************************************************************************/


#include <avr/io.h>
#include "I2C_interface.h"

/************************************************************************************
* Service Name: TWI_init
* Parameters (in): TWI_ConfigType
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the I2C module.
************************************************************************************/

void TWI_init(const TWI_ConfigType * Config_Ptr)
{
    /* Bit Rate: using zero pre-scaler TWPS=00 and F_CPU=16Mhz */
    TWBR = ((F_CPU/(Config_Ptr->bit_rate))-16)/(2*4);
	TWSR = 0x00;

    /* Two Wire Bus address my address if any master device want to call me: 0x1 (used in case this MC is a slave device)
       General Call Recognition: Off */
    TWAR = ((Config_Ptr->address)<<1); // my address = 0x01 :)

    TWCR = (1<<TWEN); /* enable TWI */
}
/************************************************************************************
* Service Name: TWI_start
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to start I2C module.
************************************************************************************/
void TWI_start(void)
{
    /*
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

    /* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
}
/************************************************************************************
* Service Name: TWI_stop
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Stop I2C module
************************************************************************************/
void TWI_stop(void)
{
    /*
	 * Clear the TWINT flag before sending the stop bit TWINT=1
	 * send the stop bit by TWSTO=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}
/************************************************************************************
* Service Name: TWI_writeByte
* Parameters (in): data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to write byte in data register
************************************************************************************/
void TWI_writeByte(uint8 data)
{
    /* Put data On TWI data Register */
    TWDR = data;
    /*
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register(data is send successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
}
/************************************************************************************
* Service Name: TWI_readByteWithACK
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: TWDR
* Description: Function to read byte and send NACK
************************************************************************************/
uint8 TWI_readByteWithACK(void)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}
/************************************************************************************
* Service Name: TWI_readByteWithNACK
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: TWDR
* Description: Function to write byte and send NACK
************************************************************************************/
uint8 TWI_readByteWithNACK(void)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}
/************************************************************************************
* Service Name: TWI_getStatus
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: Status
* Description: Function to get states of specific bits
************************************************************************************/
uint8 TWI_getStatus(void)
{
    uint8 status;
    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
    status = TWSR & 0xF8;
    return status;
}
