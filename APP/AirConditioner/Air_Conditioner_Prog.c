/*
 * Air_Conditioner_Prog.c
 *
 * Created: 05/11/2023 09:46:59 م
 *  Author: JoBa
 */ 

#include "MemMap.h"
#include "Air_Conditioner_Interface.h"
#include "Utils.h"
#include "Relay_inter.h"

STD_TYPE AirConditioner_Start(){
	
		STD_TYPE status = E_NOT_OK;
		Relay_on(relay_air);
		return status;
	
}
STD_TYPE AirConditioner_Stop(){
	
		STD_TYPE status = E_NOT_OK;
		Relay_off(relay_air);
		return status;
}
