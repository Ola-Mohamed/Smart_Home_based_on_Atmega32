#include "MemMap.h"
#include "STD_TYPES.h"
#include "UTILS.h"
#include "DIO_INTERFACE.h"
#include "LCD_Int.h"
#define  F_CPU CPU_CLOCK
#include <util/delay.h>
#include "LCD_CFG.h"
/* ****************************************************************************************************************** */


#if LCD_MODE==_4_BIT

static void WriteIns(uint8 ins)
{
	MCAL_DIO_Std_WRITE_PIN(&RS,LOGIC_LOW);
	
	MCAL_DIO_Std_WRITE_PIN(&D7,READ_BIT(ins,7));
	MCAL_DIO_Std_WRITE_PIN(&D6,READ_BIT(ins,6));
	MCAL_DIO_Std_WRITE_PIN(&D5,READ_BIT(ins,5));
	MCAL_DIO_Std_WRITE_PIN(&D4,READ_BIT(ins,4));
	
	MCAL_DIO_Std_WRITE_PIN(&EN,LOGIC_HIGH);
	_delay_ms(1);
	MCAL_DIO_Std_WRITE_PIN(&EN,LOGIC_LOW);
	_delay_ms(1);
	
	MCAL_DIO_Std_WRITE_PIN(&D7,READ_BIT(ins,3));
	MCAL_DIO_Std_WRITE_PIN(&D6,READ_BIT(ins,2));
	MCAL_DIO_Std_WRITE_PIN(&D5,READ_BIT(ins,1));
	MCAL_DIO_Std_WRITE_PIN(&D4,READ_BIT(ins,0));
	
	MCAL_DIO_Std_WRITE_PIN(&EN,LOGIC_HIGH);
	_delay_ms(1);
	MCAL_DIO_Std_WRITE_PIN(&EN,LOGIC_LOW);
	_delay_ms(1);
}
static void WriteData(uint8 data)
{
	MCAL_DIO_Std_WRITE_PIN(&RS,LOGIC_HIGH);
	
	MCAL_DIO_Std_WRITE_PIN(&D7,READ_BIT(data,7));
	MCAL_DIO_Std_WRITE_PIN(&D6,READ_BIT(data,6));
	MCAL_DIO_Std_WRITE_PIN(&D5,READ_BIT(data,5));
	MCAL_DIO_Std_WRITE_PIN(&D4,READ_BIT(data,4));
	
	MCAL_DIO_Std_WRITE_PIN(&EN,LOGIC_HIGH);
	_delay_ms(1);
	MCAL_DIO_Std_WRITE_PIN(&EN,LOGIC_LOW);
	_delay_ms(1);
	
	MCAL_DIO_Std_WRITE_PIN(&D7,READ_BIT(data,3));
	MCAL_DIO_Std_WRITE_PIN(&D6,READ_BIT(data,2));
	MCAL_DIO_Std_WRITE_PIN(&D5,READ_BIT(data,1));
	MCAL_DIO_Std_WRITE_PIN(&D4,READ_BIT(data,0));

	MCAL_DIO_Std_WRITE_PIN(&EN,LOGIC_HIGH);
	_delay_ms(1);
	MCAL_DIO_Std_WRITE_PIN(&EN,LOGIC_LOW);
	_delay_ms(1);
}

void LCD_Init(void)
{
	_delay_ms(50);
	WriteIns(0x02);  //  2  0  2   8
	WriteIns(0x28);
	WriteIns(0x0C);// 0X0E 0X0F  cursor
	WriteIns(0x01);//clear lcd
	_delay_ms(1);
	WriteIns(0x06);// DDRAM inc
	//WriteIns(0x40);
}


#elif LCD_MODE==_8_BIT


static void WriteIns(uint8 ins)
{
	MCAL_DIO_Std_WRITE_PIN(&RS,LOGIC_LOW);
	MCAL_DIO_Std_WRITE_PORT(&LCD_PORT,ins);
	MCAL_DIO_Std_WRITE_PIN(&EN,LOGIC_HIGH);
	_delay_ms(1);
	MCAL_DIO_Std_WRITE_PIN(&EN,LOGIC_LOW);
	_delay_ms(1);
}

static void WriteData(uint8 data)
{
	MCAL_DIO_Std_WRITE_PIN(&RS,LOGIC_HIGH);
	MCAL_DIO_Std_WRITE_PORT(&LCD_PORT,data);
	MCAL_DIO_Std_WRITE_PIN(&EN,LOGIC_HIGH);
	_delay_ms(1);
	MCAL_DIO_Std_WRITE_PIN(&EN,LOGIC_LOW);
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


void LCD_WriteChar(uint8 ch)
{
	WriteData(ch);
	
}

void LCD_WriteString(uint8*str)
{
	uint8 i;
	for (i=0;str[i];i++)
	{
		WriteData(str[i]);
	}
}

void LCD_WriteNumber(sint32 num)
{
	uint8 str[20] , rem=0 , i=0 ;
	sint8 j = 0 ; 
	if (num == 0)
	{
		LCD_WriteChar('0') ;
		return ;
	}
	if ( num < 0 )
	{
		LCD_WriteChar('-') ;
		num = num * -1 ;
	}
	while(num > 0 )
	{
		rem=num%10 ;
		str[i]= rem + '0'  ;
		num = num / 10 ;
		i++ ;
	}
	for (sint8 j=i-1 ; j >= 0 ; j --)
	{
		LCD_WriteChar(str[j]);
	}
	str[j] = 0 ;
	
	
}
void LCD_Clear(void)
{
	
	WriteIns(0x01);//clear lcd
	_delay_ms(1);
	
}

void LCD_SetCursor(uint8 line ,uint8 cell)
{
	if (line==1)
	{
		WriteIns(0x80+(cell-1));
	}
	else if (line ==2)
	{
		WriteIns(0x80+0x40+(cell-1));
	}
	else if (line ==3)
	{
		WriteIns(0x80+0x14+(cell-1));
	}
	else if (line ==4)
	{
		WriteIns(0x80+0x54+(cell-1));
	}
	
}


void LCD_WriteBinary(uint8 num)
{
	sint64 i;
	for(i=7;i>=0;i--)
	{
		LCD_WriteChar(READ_BIT(num,i)+'0');
	}
	
}
void LCD_WriteHex(uint8 num) //1010 0011  a3
{
	uint8 LN,HN;
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

void LCD_WriteNum_4D(uint16 num)//15214
{
	LCD_WriteChar(((num%10000)/1000)+'0');
	LCD_WriteChar(((num%1000)/100)+'0');
	LCD_WriteChar(((num%100)/10)+'0');
	LCD_WriteChar(((num%10)/1)+'0');
}

void LCD_CustomChar(uint8*pattern,uint8 address)
{
	WriteIns(0x40+address*8);
	for (uint8 i=0;i<8;i++)
	{
		WriteData(pattern[i]);
	}
	WriteIns(0x80);
}

void LCD_WriteStringCursor(uint8 line,uint8 cell,uint8*str)
{
	LCD_SetCursor(line,cell);
	LCD_WriteString(str);
	
}
