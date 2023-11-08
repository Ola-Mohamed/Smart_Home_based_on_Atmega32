/*
 * Blinds_Prog.c
 *
 * Created: 05/11/2023 11:18:49 م
 *  Author: JoBa
 */ 

#include "Blinds_Interface.h"
#include "Motor_DC_Interface.h"
#include "MemMap.h"
#include "Servo.h"
#define F_CPU CPU_CLOCK
#include "util/delay.h"


STD_TYPE Blinds_Open(){
	STD_TYPE status = E_NOT_OK;
	Servo_Move(OPEN);

	return status;

}
STD_TYPE Blinds_Close(){
	STD_TYPE status = E_NOT_OK;
	Servo_Move(CLOSE);
	return status;
}
