/*
 * Air_Conditioner_Prog.c
 *
 * Created: 05/11/2023 09:46:59 م
 *  Author: JoBa
 */ 

#include "MemMap.h"
#include "Air_Conditioner_Interface.h"
#include "Utils.h"

STD_TYPE AirConditioner_Start(){
	
		STD_TYPE status = E_NOT_OK;
		//status = Relay_On();
		 	SET_BIT(PORTC,4);
			 SET_BIT(PORTC,5);
		// 	SET_BIT(PORTA,1);
		// 	SET_BIT(PORTA,2);
		// 	SET_BIT(PORTA,3);
		// 	SET_BIT(PORTA,4);
		// 	SET_BIT(PORTA,5);
		// 	SET_BIT(PORTA,6);
		// 	SET_BIT(PORTA,7);
		return status;
	
}
STD_TYPE AirConditioner_Stop(){
	
		STD_TYPE status = E_NOT_OK;
		//status = Relay_Off();
		 	CLEAR_BIT(PORTC,4);
			CLEAR_BIT(PORTC,5);
		// 	CLEAR_BIT(PORTA,1);
		// 	CLEAR_BIT(PORTA,2);
		// 	CLEAR_BIT(PORTA,3);
		// 	CLEAR_BIT(PORTA,4);
		// 	CLEAR_BIT(PORTA,5);
		// 	CLEAR_BIT(PORTA,6);
		// 	CLEAR_BIT(PORTA,7);
		return status;
}
