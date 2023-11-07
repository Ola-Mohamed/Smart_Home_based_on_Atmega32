#ifndef EEPROM_H_
#define EEPROM_H_

typedef enum{
	DONE,             // Enumeration value representing successful operation.
	OUT_OF_RANGE      // Enumeration value representing an out of range error.
}Write_Status_type;   // Definition of an enumeration type named Write_Status_type.

void EEPROM_Init(void);  // Function prototype for initializing the EEPROM.

Write_Status_type EEPROM_write(uint16 Address, uint8 Data);  // Function prototype for writing a byte to the EEPROM.

uint8 EEPROM_read(uint16 Address);  // Function prototype for reading a byte from the EEPROM.

void EEPROM_InterruptEnable(void);  // Function prototype to enable EEPROM write completion interrupt.

void EEPROM_InterruptDisable(void);  // Function prototype to disable EEPROM write completion interrupt.

void EEPROM_EE_RDY_SetCallBack(void(*LocalFptr)(void));  // Function prototype to set a callback function for EEPROM write completion.

Write_Status_type EEPROM_write_array(uint16 Address,uint8* data,uint16 size);  // Function prototype for writing an array of bytes to the EEPROM.

void EEPROM_read_array(uint16 Address, uint16 size, uint8* arr);  // Function prototype for reading an array of bytes from the EEPROM.


#endif /* EEPROM_H_ */
