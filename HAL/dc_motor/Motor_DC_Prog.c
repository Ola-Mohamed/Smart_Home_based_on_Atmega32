#include "MemMap.h"
#include "STD_TYPES.h"
#include "UTILS.h"
#include "DIO_INTERFACE.h"
#include "Motor_DC_Interface.h"
#include "Mototr_DC_Con.h"
#define  F_CPU CPU_CLOCK
#include <util/delay.h>




STD_TYPE MOTOR_Init(void)
{
	/***/
}

STD_TYPE MOTOR_CW(MOTOR_t motor)
{
	STD_TYPE error_status = E_NOT_OK ; 
	switch(motor)
	{
		case M1:
		MCAL_DIO_Std_WRITE_PIN(&M1_IN1,LOGIC_HIGH);
		MCAL_DIO_Std_WRITE_PIN(&M1_IN2,LOGIC_LOW);
		error_status = E_OK ; 
		break;
		case M2:
		MCAL_DIO_Std_WRITE_PIN(&M2_IN1,LOGIC_HIGH);
		MCAL_DIO_Std_WRITE_PIN(&M2_IN2,LOGIC_LOW);
		error_status = E_OK ; 
		break;
	}
	return error_status ; 
}
STD_TYPE MOTOR_CCW(MOTOR_t motor)
{
	STD_TYPE error_status = E_NOT_OK ; 
	switch(motor)
	{
		case M1:
		MCAL_DIO_Std_WRITE_PIN(&M1_IN1,LOGIC_LOW);
		MCAL_DIO_Std_WRITE_PIN(&M1_IN2,LOGIC_HIGH);
		error_status = E_OK;
		break;
		case M2:
		MCAL_DIO_Std_WRITE_PIN(&M2_IN1,LOGIC_LOW);
		MCAL_DIO_Std_WRITE_PIN(&M2_IN2,LOGIC_HIGH);
		error_status = E_OK;
		break;
	}
	return error_status ; 
}

STD_TYPE MOTOR_Stop(MOTOR_t motor)
{
	STD_TYPE error_status = E_NOT_OK ; 
	switch(motor)
	{
		case M1:
		MCAL_DIO_Std_WRITE_PIN(&M1_IN1,LOGIC_LOW);
		MCAL_DIO_Std_WRITE_PIN(&M1_IN2,LOGIC_LOW);
		error_status = E_OK ; 
		break;
		case M2:
		MCAL_DIO_Std_WRITE_PIN(&M2_IN1,LOGIC_LOW);
		MCAL_DIO_Std_WRITE_PIN(&M2_IN2,LOGIC_LOW);
		error_status = E_OK ; 
		break;
	}
	return error_status ; 
}