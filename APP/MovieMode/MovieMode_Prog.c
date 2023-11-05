/*
* MovieMode_Prog.c
*
* Created: 05/11/2023 11:54:31 م
*  Author: JoBa
*/


#include "MovieMode_Interface.h"
#include "TV/TV_Interface.h"
#include "Lighting/Lighting_Interface.h"
#include "Blinds/Blinds_Interface.h"


STD_TYPE MovieMode_On(){
	
	STD_TYPE status = E_NOT_OK;
	TV_On();
	Lighting_Off();
	Blinds_Close();
	return status;

	
}
STD_TYPE MovieMode_Off(){
	STD_TYPE status = E_NOT_OK;
	TV_Off();
	Lighting_On();
	Blinds_Open();
	return status;
}
