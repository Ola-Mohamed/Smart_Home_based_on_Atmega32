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
//status = SensorMotion_On();
SET_BIT(PORTC,0);
//SET_BIT(PORTC,5);
// 	SET_BIT(PORTA,1);
// 	SET_BIT(PORTA,2);
// 	SET_BIT(PORTA,3);
// 	SET_BIT(PORTA,4);
// 	SET_BIT(PORTA,5);
// 	SET_BIT(PORTA,6);
// 	SET_BIT(PORTA,7);	
return status;
}
STD_TYPE MotionMode_Stop(){
		
		STD_TYPE status = E_NOT_OK;
		//status = SensorMotion_Off();
		CLEAR_BIT(PORTC,0);
		//CLEAR_BIT(PORTC,5);
		// 	CLEAR_BIT(PORTA,1);
		// 	CLEAR_BIT(PORTA,2);
		// 	CLEAR_BIT(PORTA,3);
		// 	CLEAR_BIT(PORTA,4);
		// 	CLEAR_BIT(PORTA,5);
		// 	CLEAR_BIT(PORTA,6);
		// 	CLEAR_BIT(PORTA,7);
		return status;
}

STD_TYPE MotionMode_Detect(){
	
			STD_TYPE status = E_NOT_OK;
			DIO_LEVEL_TYPE motionLevel = LOGIC_LOW;
			//motionLevel SENSOR_MotionDetect();
			if (motionLevel == LOGIC_HIGH)
			{
				status = E_OK;
			}else {
				status = E_NOT_OK;
			}
			//CLEAR_BIT(PORTC,0);
			//CLEAR_BIT(PORTC,5);
			// 	CLEAR_BIT(PORTA,1);
			// 	CLEAR_BIT(PORTA,2);
			// 	CLEAR_BIT(PORTA,3);
			// 	CLEAR_BIT(PORTA,4);
			// 	CLEAR_BIT(PORTA,5);
			// 	CLEAR_BIT(PORTA,6);
			// 	CLEAR_BIT(PORTA,7);
			return status;
}
