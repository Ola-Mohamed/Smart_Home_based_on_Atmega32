/*
 * Motion_Mode_Prog.c
 *
 * Created: 05/11/2023 10:09:35 م
 *  Author: JoBa
 */ 
#include "MemMap.h"
#include "Motion_Mode_Interface.h"
#include "Utils.h"


STD_TYPE MotionMode_Start(){

STD_TYPE status = E_NOT_OK;
DIO_LEVEL_TYPE type;
		type = SENSOR_MotionDetect();
		if (type == LOGIC_HIGH)
		{
			//LCD_Clear();
			LCD_WriteChar('H');
			BUZZER_setOn();
			status = E_OK;
		}else {
			//LCD_Clear();
			LCD_WriteChar('L');
			BUZZER_setOff();
			status = E_NOT_OK;
		}
	return status;
}

STD_TYPE MotionMode_Stop(){
		
STD_TYPE status = E_NOT_OK;
	LCD_Clear();
	BUZZER_setOff();
	status = E_OK;
	
return status;
}
