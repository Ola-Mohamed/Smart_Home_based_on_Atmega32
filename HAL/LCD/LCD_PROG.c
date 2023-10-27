#include "StdTypes.h"
#include "UTILS.h"
#include "DIO_INTERFACE.h"
#include "LCD_Int.h"
#include "LCD_CFG.h"

#define  F_CPU 8000000
#include <util/delay.h>

#if LCD_MODE==_4_BIT

static void WriteIns(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,GET_BIT(ins,7));
	DIO_WritePin(D6,GET_BIT(ins,6));
	DIO_WritePin(D5,GET_BIT(ins,5));
	DIO_WritePin(D4,GET_BIT(ins,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,GET_BIT(ins,3));
	DIO_WritePin(D6,GET_BIT(ins,2));
	DIO_WritePin(D5,GET_BIT(ins,1));
	DIO_WritePin(D4,GET_BIT(ins,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
static void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,GET_BIT(data,7));
	DIO_WritePin(D6,GET_BIT(data,6));
	DIO_WritePin(D5,GET_BIT(data,5));
	DIO_WritePin(D4,GET_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,GET_BIT(data,3));
	DIO_WritePin(D6,GET_BIT(data,2));
	DIO_WritePin(D5,GET_BIT(data,1));
	DIO_WritePin(D4,GET_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_Init(void)
{
	_delay_ms(50);
	WriteIns(0x02);  //  2  0  2   8
	WriteIns(0x28);
	WriteIns(0x0c);// 0X0E 0X0F  cursor
	WriteIns(0x01);//clear lcd
	_delay_ms(1);
	WriteIns(0x06);// DDRAM inc
}


#elif LCD_MODE==_8_BIT


static void WriteIns(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,ins);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

static void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}


void LCD_Init(void)
{
	_delay_ms(50);
	
	WriteIns(0x38);
	WriteIns(0x0c);// 0X0E 0X0F  cursor
	WriteIns(0x01);//clear lcd
	_delay_ms(1);
	WriteIns(0x06);// DDRAM inc
}

#endif

/*********************************************************************************************************/


void LCD_WriteChar(u8 ch)
{
	WriteData(ch);
	
}

void LCD_WriteString(u8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		WriteData(str[i]);
	}
}

void LCD_WriteNumber(s32 num)
{
	u8 str[16],i=0;
	s8 j;
	if (num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	if (num<0)
	{
		LCD_WriteChar('-');
		num=num*-1;
	}
	while(num)
	{
		str[i]=num%10+'0';
		num=num/10;
		i++;
	}
	
	for (j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
	
	
}
void LCD_Clear(void)
{
	
	WriteIns(0x01);//clear lcd
	_delay_ms(1);
	
}

void LCD_SetCursor(u8 line ,u8 cell)
{
	if (line==1)
	{
		WriteIns(0x80+(cell-1));
	}
	else if (line ==2)
	{
		WriteIns(0x80+0x40+(cell-1));
	}
	
}


void LCD_WriteBinary(u8 num)
{
	s8 i;
	for(i=7;i>=0;i--)
	{
		LCD_WriteChar(GET_BIT(num,i)+'0');
	}
	
}
void LCD_WriteHex(u8 num) //1010 0011  a3
{
	u8 LN,HN;
	LN=num&0x0f;
	HN=num>>4;
	if (HN<10)
	{
		LCD_WriteChar(HN+'0');
	}
	else
	{
		LCD_WriteChar(HN+'A'-10);
	}
	if (LN<10)
	{
		LCD_WriteChar(LN+'0');
	}
	else
	{
		LCD_WriteChar(LN+'A'-10);
	}
	
}

void LCD_WriteNum_4D(u16 num)//15214
{
	LCD_WriteChar(((num%10000)/1000)+'0');
	LCD_WriteChar(((num%1000)/100)+'0');
	LCD_WriteChar(((num%100)/10)+'0');
	LCD_WriteChar(((num%10)/1)+'0');
}

void LCD_CustomChar(u8*pattern,u8 address)
{
	WriteIns(0x40+address*8);
	for (u8 i=0;i<8;i++)
	{
		WriteData(pattern[i]);
	}
	WriteIns(0x80);
}

void LCD_WriteStringCursor(u8 line,u8 cell,u8*str)
{
	LCD_SetCursor(line,cell);
	LCD_WriteString(str);
	
}
