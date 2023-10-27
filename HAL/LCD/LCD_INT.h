
#ifndef LCD_INT_H_
#define LCD_INT_H_
void LCD_Init(void);



void LCD_WriteChar(u8 ch);
void LCD_WriteString(u8*str);
void LCD_WriteNumber(s32 num);

void LCD_WriteNum_4D(u16 num);

void LCD_WriteBinary(u8 num);
void LCD_WriteHex(u8 num);
void LCD_Clear(void);

/* line 1:2
* cell 1:16*/
void LCD_SetCursor(u8 line ,u8 cell);


void LCD_CustomChar(u8*pattern,u8 ch);

void LCD_WriteStringCursor(u8 line,u8 cell,u8*str);

void LCD_ClearCursor(u8 line,u8 cell,u8 NoC);




#endif /* LCD_INT_H_ */
