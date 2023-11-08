/*
 * TV_Prog.c
 *
 * Created: 05/11/2023 11:44:35 م
 *  Author: JoBa
 */ 


#include "TV_Interface.h"
#include "Relay_inter.h"

STD_TYPE TV_On(){
	
	STD_TYPE status = E_NOT_OK;
	Relay_on(rlay_tv);
	return status;

}
STD_TYPE TV_Off(){
	
	STD_TYPE status = E_NOT_OK;
	Relay_off(rlay_tv);

	return status;
	
}