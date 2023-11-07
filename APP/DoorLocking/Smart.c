#include "Std_Types.h"
#include "UART_Interface.h"
#include "DIO_Interface.h"
#include "EEPROM.h"
#include "Smart_Interface.h"
#include "Smart_Private.h"
#include <util/delay.h>
extern uint8 flag;  // Declaration of an external variable named flag.
uint8 mode=0;  // Variable to keep track of the current mode.
uint8 Lcd_control_mode=0;  // Variable related to LCD control mode.
uint8 Rgb_mode=0;  // Variable related to RGB mode.
uint8 uart,c;  // Variables related to UART communication.
uint8 str[32];  // Character array to store strings.
uint8 password[6]={0};  // Array to store the password.
Dio_ConfigType led=PIN0_ID;  // Configuration for a digital pin.
uint8 buzzer_flag=0;  // Flag for controlling the buzzer.

// Function to initialize the Smart Home system.
void Smart_Init (void)
{
	if (EEPROM_read(0)==1)
	{
		EEPROM_read_array(1,6,password);
	}
}

// Static function to check the validity of a password.
static Check_Passowrd_type check_password (void)
{
	uint8 check[6];
	Check_Passowrd_type answer= Valid;
	UART_ReceivePassword(check);
	
	for (uint8 i=0;i<6;i++)
	{
		if (check[i]!=password[i])
		{
			answer=Invalid;
			break;
		}
	} 
	return answer;
}

// Static function to change the password.
static void Password_change(void)
{
	LCD_Clear();
	LCD_WriteString(" Enter Password");
	if (check_password()==Valid)
	{
		LCD_Clear();
		LCD_WriteString("  New Password");
		uint8 new[6];
		UART_ReceivePassword(new);
		
		for (uint8 i=0;i<6;i++)
		{
			password[i]=new[i];
		}
		
		LCD_Clear();
		LCD_WriteStringGoto(1,10,"Done");
		EEPROM_write(0,1);
		EEPROM_InterruptEnable();
		EEPROM_EE_RDY_SetCallBack(Send_password);
		_delay_ms(1000);
		LCD_Clear();
	}
	else
	{
		LCD_Clear();
		LCD_WriteString("  Invalid Password");
		_delay_ms(1000);
		LCD_Clear();
	}
}

// Static function to display a welcome message.
static void Welcome (void)
{
	LCD_WriteString("     Smart Home");
	_delay_ms(1000);
	again:
	LCD_Clear();
	LCD_WriteString("   Enter Password");
	
	if (check_password()==Valid)
	{
		LCD_Clear();
		LCD_WriteString("    Welcome Home");
		_delay_ms(1000);
		mode=1;
	}
	else
	{
		buzzer_flag++;
		LCD_Clear();
		LCD_WriteString("   Wrong Password");
		if (buzzer_flag==3)
		{
			DIO_WritePin(PIN6_ID,LOGIC_HIGH);
			_delay_ms(5000);
			DIO_WritePin(PIN6_ID,LOGIC_LOW);
		}
		else
		{
			_delay_ms(5000);
		}
		LCD_Clear();
		goto again;
	}
}

// Main logic of the Smart Home system.
void Smart_Home_Runnable (void)
{
	if (mode==0)
	{
		Welcome();
	}
	
	if (mode==1)
	{
		LCD_Clear();
		LCD_WriteString("    Welcome Home");
		DIO_WritePort(PORTC_ID,0);
		
		uart=UART_Receive();
		
		if (uart==0x97 || uart==0x98 || uart==0x99 || uart==0xCC || uart==0xBB)
		{
			mode=uart;
			LCD_Clear();
		}
	}
	
	if (mode==0xCC)
	{
		Password_change();
		mode=1;
	}
	else if (mode==0xBB)
	{
		flag=0;
		mode=0;
	}
}

// Static function to send the password to EEPROM.
static void Send_password (void)
{
	EEPROM_write_array(1,password,6);
}
