/*
* Garage.c
*
* Created: 05/11/2023 07:27:28 م
*  Author: JoBa
*/
#include "Garage_Interface.h"
#include "Motor_DC_Interface.h"
#include "MemMap.h"
#define F_CPU CPU_CLOCK
#include "util/delay.h"

STD_TYPE Garage_Open(){
	
	STD_TYPE status = E_NOT_OK;
	 MOTOR_CW(M1);
	_delay_ms(GARAGE_MOTOR_TIME);
	 MOTOR_Stop(M1);
	 MOTOR_Stop(M1);
	return status;
}


STD_TYPE Garage_Close(){
	
	STD_TYPE status = E_NOT_OK;
	 MOTOR_CCW(M1);
	 _delay_ms(GARAGE_MOTOR_TIME);
	 MOTOR_Stop(M1);
	 MOTOR_Stop(M1);
	return status;
}