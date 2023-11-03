#include "DIO_INTERFACE.h"
#include "Motion_Sensor_Interface.h"
#include "Motion_Sensor_Confg.h"
#include "Utils.h"





DIO_LEVEL_TYPE SENSOR_MotionDetect (void) 
{
	DIO_LEVEL_TYPE STATUS ; 
	//STATUS = MCAL_DIO_Std_READ_PIN_DIRECTION (& motion_confg) ; 
	if (READ_BIT(motion_PORT,motion_PIN) ==  0)
	{
		STATUS = LOGIC_LOW  ;
	}
	else
	{
		STATUS = LOGIC_HIGH ;
	}
	return STATUS ; 
}