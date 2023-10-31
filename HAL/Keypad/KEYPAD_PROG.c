/*
* KeyPad.c
*
* Created: 29/10/2023 09:20:27 م
*  Author: JoBa
*/
#include "MemMap.h"
#include "STD_TYPES.h"
#include "Utils.h"
#include "DIO_TYPES.h"
#include "DIO_INTERFACE.h"
#include "KEYPAD_INTERFACE.h"
#include "KEYPAD_CONFIG.h"


/************************************************************* KEYPAD STRUCT TO INIT PINS AND PORT *********************************************************/
Dio_ConfigType KP_P0 , KP_P1 , KP_P2 , KP_P3 , KP_P4 , KP_P5 , KP_P6,KP_P7 ;

/********************************************************* INIT FUNCTION SHOULD CALL BEFORE USED KEYPAD ****************************************************/
void KEYPAD_vidInit(){
	KP_P0.PIN = KEYPAD_ROW0;
	KP_P0.PORT = KEYPAD_PORT;
	
	KP_P1.PIN = KEYPAD_ROW1;
	KP_P1.PORT = KEYPAD_PORT;
	
	KP_P2.PIN = KEYPAD_ROW2;
	KP_P2.PORT = KEYPAD_PORT;
	
	KP_P3.PIN = KEYPAD_ROW3;
	KP_P3.PORT = KEYPAD_PORT;
	
	KP_P4.PIN = KEYPAD_COULMN0;
	KP_P4.PORT = KEYPAD_PORT;
	
	KP_P5.PIN = KEYPAD_COULMN1;
	KP_P5.PORT = KEYPAD_PORT;
	
	KP_P6.PIN = KEYPAD_COULMN2;
	KP_P6.PORT = KEYPAD_PORT;
	
	KP_P7.PIN = KEYPAD_COULMN3;
	KP_P7.PORT = KEYPAD_PORT;
	

	MCAL_DIO_Std_WRITE_PIN(&KP_P0,LOGIC_HIGH);
	MCAL_DIO_Std_WRITE_PIN(&KP_P1,LOGIC_HIGH);
	MCAL_DIO_Std_WRITE_PIN(&KP_P2,LOGIC_HIGH);
	MCAL_DIO_Std_WRITE_PIN(&KP_P3,LOGIC_HIGH);

	MCAL_DIO_Std_WRITE_PIN(&KP_P4,LOGIC_HIGH);
	MCAL_DIO_Std_WRITE_PIN(&KP_P5,LOGIC_HIGH);
	MCAL_DIO_Std_WRITE_PIN(&KP_P6,LOGIC_HIGH);
	MCAL_DIO_Std_WRITE_PIN(&KP_P7,LOGIC_HIGH);
}

/********************************************************* FUNCTION RETURN STRUCT HAVE DATA AND STATUS *****************************************************/
KEYPAD_DataSTATUS KEYPAD_unit8ReadButton(void){
	
	KEYPAD_DataSTATUS keypadDataAndStatus;
	keypadDataAndStatus.status = E_NOT_OK;
	keypadDataAndStatus.data = '\0'; // null data
	
	sint8 coulmnFlag =-1,rowFlag=-1;

		for (uint8 cCol=0; cCol<KEYPAD_COULMN_COUNT; cCol++)
		{
			switch(cCol){
				case 0 :
				MCAL_DIO_Std_WRITE_PIN(&KP_P4,LOGIC_LOW);
				MCAL_DIO_Std_WRITE_PIN(&KP_P5,LOGIC_HIGH);
				MCAL_DIO_Std_WRITE_PIN(&KP_P6,LOGIC_HIGH);
				MCAL_DIO_Std_WRITE_PIN(&KP_P7,LOGIC_HIGH);
				coulmnFlag=0;
				break;
				case 1 :
				MCAL_DIO_Std_WRITE_PIN(&KP_P5,LOGIC_LOW);
				MCAL_DIO_Std_WRITE_PIN(&KP_P4,LOGIC_HIGH);
				MCAL_DIO_Std_WRITE_PIN(&KP_P6,LOGIC_HIGH);
				MCAL_DIO_Std_WRITE_PIN(&KP_P7,LOGIC_HIGH);
				coulmnFlag=1;
				break;
				case 2 :
				MCAL_DIO_Std_WRITE_PIN(&KP_P6,LOGIC_LOW);
				MCAL_DIO_Std_WRITE_PIN(&KP_P4,LOGIC_HIGH);
				MCAL_DIO_Std_WRITE_PIN(&KP_P5,LOGIC_HIGH);
				MCAL_DIO_Std_WRITE_PIN(&KP_P7,LOGIC_HIGH);
				coulmnFlag=2;
				break;
				case 3 :
				MCAL_DIO_Std_WRITE_PIN(&KP_P7,LOGIC_LOW);
				MCAL_DIO_Std_WRITE_PIN(&KP_P4,LOGIC_HIGH);
				MCAL_DIO_Std_WRITE_PIN(&KP_P5,LOGIC_HIGH);
				MCAL_DIO_Std_WRITE_PIN(&KP_P6,LOGIC_HIGH);
				coulmnFlag=3;
				break;
				default:
				coulmnFlag=-1;
				break;
			}
			
			if ((READ_BIT(PINC,0))== 0)
			{
				rowFlag=0;
				}else if((READ_BIT(PINC,1))==0){
				rowFlag=1;
				}else if(READ_BIT(PINC,2)==0){
				rowFlag=2;
				}else if(READ_BIT(PINC,3)==0){
				rowFlag=3;
				}else{
				/*Do Nothing*/
			}
			
			/*BUSY WAIT TO PULL HAND*/
			while((coulmnFlag>-1) && (rowFlag >-1)){
				if ((READ_BIT(PINC,0)==LOGIC_HIGH) && (READ_BIT(PINC,1)==LOGIC_HIGH)&& (READ_BIT(PINC,2)==LOGIC_HIGH)&& (READ_BIT(PINC,3)==LOGIC_HIGH))
				{
					rowFlag=-1;
					coulmnFlag=-1;
				}else{
						keypadDataAndStatus.data = KEYPAD_arrConfig[rowFlag][coulmnFlag];
						keypadDataAndStatus.status = E_OK;
						while((READ_BIT(PINC,0)==LOGIC_LOW)|| (READ_BIT(PINC,1)==LOGIC_LOW)|| (READ_BIT(PINC,2)==LOGIC_LOW)|| (READ_BIT(PINC,3)==LOGIC_LOW));
					rowFlag=-1;
					coulmnFlag=-1;
				}
			}/*End While*/
		}/*End for col*/

			
			return keypadDataAndStatus;
}