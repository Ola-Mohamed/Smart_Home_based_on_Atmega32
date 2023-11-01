

#ifndef LCD_INT_H_
#define LCD_INT_H_

#include "UTILS.h"
#include "STD_TYPES.h"
#include "DIO_INTERFACE.h"
#include "DIO_TYPES.h"

typedef struct {
	DIO_PIN_ID PIN; // Pin ID.
	DIO_PORT_ID PORT; // Port ID.
	DIO_PORT_DIRECTION_TYPE PORT_DIRECTION; // Port direction.
	DIO_PIN_DIRECTION_TYPE PIN_DIRECTION; // Pin direction.
} lcd_ConfigType;

void LCD_Init(void);
void LCD_WriteChar(uint8 ch);
void LCD_WriteString(uint8*str);
void LCD_WriteNumber(sint32 num);
void LCD_WriteNum_4D(uint16 num);
void LCD_WriteBinary(uint8 num);
void LCD_WriteHex(uint8 num);
void LCD_Clear(void);
/* line 1:4
* cell 1:20*/
void LCD_SetCursor(uint8 line ,uint8 cell);
void LCD_CustomChar(uint8*pattern,uint8 ch);
void LCD_WriteStringCursor(uint8 line,uint8 cell,uint8*str);
void LCD_ClearCursor(uint8 line,uint8 cell,uint8 NoC);




#endif /* LCD_INT_H_ */
