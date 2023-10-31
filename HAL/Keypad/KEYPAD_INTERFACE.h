/*
 * KeyPad.h
 *
 * Created: 29/10/2023 09:20:42 م
 *  Author: JoBa
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_


typedef struct{
	
	uint8 data;
	STD_TYPE status;
	
}KEYPAD_DataSTATUS;

/************************************************************************ KEYPAD INIT PINS *****************************************************************/
void KEYPAD_vidInit(void);

/***************************************************************** KEYPAD READ RETURN BUTTON PRESSED ********************************************************/
KEYPAD_DataSTATUS KEYPAD_unit8ReadButton(void);

#endif /* KEYPAD_H_ */