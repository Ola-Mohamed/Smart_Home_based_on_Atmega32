/*
 * Lighting_Prog.c
 *
 * Created: 05/11/2023 11:41:06 م
 *  Author: JoBa
 */ 


#include "Lighting_Interface.h"
#include "Led.h"

STD_TYPE Lighting_On(){
	
		STD_TYPE status = E_NOT_OK;
		LED_setOn(YELLOW);
		LED_setOn(BLUE);
		LED_setOn(GREEN);
		LED_setOn(RED);	
		return status;

}
STD_TYPE Lighting_Off(){
	
		STD_TYPE status = E_NOT_OK;
		LED_setOff(YELLOW);
		LED_setOff(BLUE);
		LED_setOff(GREEN);
		LED_setOff(RED);
			return status;
	
}