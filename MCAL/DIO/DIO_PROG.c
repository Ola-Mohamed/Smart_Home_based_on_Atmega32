/*
 * DIO_PROG.c
 *
 *  Created on: 24 Oct 2023
 *      Author: 20128
 */

#include "MemMap.h"
#include "DIO_TYPES.h"
#include "STD_TYPES.h"
#include "DIO_CONFIG.h"
#include "DIO_PRIVATE.h"
#include "DIO_INTERFACE.h"
#include "Utils.h"

void MCAL_DIO_INIT(){

	Dio_ConfigType configType;
	
	for ( configType.PORT =PORTA ; configType.PORT<TOTALPORTS_ID; configType.PORT++)
	{
		for ( configType.PIN =PIN0_ID ; configType.PIN<TOTALPINS_ID; configType.PIN++)
		{
			MCAL_DIO_INIT_PINS( &configType , pin_StatusArr[configType.PORT][configType.PIN]);
		}
	
	}
}

static void MCAL_DIO_INIT_PINS(Dio_ConfigType * configType , DIO_PIN_DIRECTION_TYPE pinStatus){
	
	if (pinStatus == PIN_OUTPUT)
	{
		switch(configType->PORT){
			case PORTA_ID :
			switch(configType->PIN){
				case PIN0_ID :
				SET_BIT(DDRA,PIN0_ID);
				SET_BIT(PORTA,PIN0_ID);
				break;
				case PIN1_ID :
				SET_BIT(DDRA,PIN1_ID);
				SET_BIT(PORTA,PIN1_ID);
				break;
				case PIN2_ID :
				SET_BIT(DDRA,PIN2_ID);
				SET_BIT(PORTA,PIN2_ID);
				break;
				case PIN3_ID :
				SET_BIT(DDRA,PIN3_ID);
				SET_BIT(PORTA,PIN3_ID);
				break;
				case PIN4_ID :
				SET_BIT(DDRA,PIN4_ID);
				SET_BIT(PORTA,PIN4_ID);
				break;
				case PIN5_ID :
				SET_BIT(DDRA,PIN5_ID);
				SET_BIT(PORTA,PIN5_ID);
				break;
				case PIN6_ID :
				SET_BIT(DDRA,PIN6_ID);
				SET_BIT(PORTA,PIN6_ID);
				break;
				case PIN7_ID :
				SET_BIT(DDRA,PIN7_ID);
				SET_BIT(PORTA,PIN7_ID);
				break;
				case TOTALPINS_ID :
				/*DoNothing*/
				break;
				default:
				/*DoNothing*/
				break;
			}
			break;
			case PORTB_ID :
			switch(configType->PIN){
				case PIN0_ID :
				SET_BIT(DDRB,PIN0_ID);
				SET_BIT(PORTB,PIN0_ID);
				break;
				case PIN1_ID :
				SET_BIT(DDRB,PIN1_ID);
				SET_BIT(PORTB,PIN1_ID);
				break;
				case PIN2_ID :
				SET_BIT(DDRB,PIN2_ID);
				SET_BIT(PORTB,PIN2_ID);
				break;
				case PIN3_ID :
				SET_BIT(DDRB,PIN3_ID);
				SET_BIT(PORTB,PIN3_ID);
				break;
				case PIN4_ID :
				SET_BIT(DDRB,PIN4_ID);
				SET_BIT(PORTB,PIN4_ID);
				break;
				case PIN5_ID :
				SET_BIT(DDRB,PIN5_ID);
				SET_BIT(PORTB,PIN5_ID);
				break;
				case PIN6_ID :
				SET_BIT(DDRB,PIN6_ID);
				SET_BIT(PORTB,PIN6_ID);
				break;
				case PIN7_ID :
				SET_BIT(DDRB,PIN7_ID);
				SET_BIT(PORTB,PIN7_ID);
				break;
				case TOTALPINS_ID :
				/*DoNothing*/
				break;
				default:
				/*DoNothing*/
				break;
			}
			break;
			case PORTC_ID :
			switch(configType->PIN){
				case PIN0_ID :
				SET_BIT(DDRC,PIN0_ID);
				SET_BIT(PORTC,PIN0_ID);
				break;
				case PIN1_ID :
				SET_BIT(DDRC,PIN1_ID);
				SET_BIT(PORTC,PIN1_ID);
				break;
				case PIN2_ID :
				SET_BIT(DDRC,PIN2_ID);
				SET_BIT(PORTC,PIN2_ID);
				break;
				case PIN3_ID :
				SET_BIT(DDRC,PIN3_ID);
				SET_BIT(PORTC,PIN3_ID);
				break;
				case PIN4_ID :
				SET_BIT(DDRC,PIN4_ID);
				SET_BIT(PORTC,PIN4_ID);
				break;
				case PIN5_ID :
				SET_BIT(DDRC,PIN5_ID);
				SET_BIT(PORTC,PIN5_ID);
				break;
				case PIN6_ID :
				SET_BIT(DDRC,PIN6_ID);
				SET_BIT(PORTC,PIN6_ID);
				break;
				case PIN7_ID :
				SET_BIT(DDRC,PIN7_ID);
				SET_BIT(PORTC,PIN7_ID);
				break;
				case TOTALPINS_ID :
				/*DoNothing*/
				break;
				default:
				/*DoNothing*/
				break;
			}
			break;
			case PORTD_ID :
			switch(configType->PIN){
				case PIN0_ID :
				SET_BIT(DDRD,PIN0_ID);
				SET_BIT(PORTD,PIN0_ID);
				break;
				case PIN1_ID :
				SET_BIT(DDRD,PIN1_ID);
				SET_BIT(PORTD,PIN1_ID);
				break;
				case PIN2_ID :
				SET_BIT(DDRD,PIN2_ID);
				SET_BIT(PORTD,PIN2_ID);
				break;
				case PIN3_ID :
				SET_BIT(DDRD,PIN3_ID);
				SET_BIT(PORTD,PIN3_ID);
				break;
				case PIN4_ID :
				SET_BIT(DDRD,PIN4_ID);
				SET_BIT(PORTD,PIN4_ID);
				break;
				case PIN5_ID :
				SET_BIT(DDRD,PIN5_ID);
				SET_BIT(PORTD,PIN5_ID);
				break;
				case PIN6_ID :
				SET_BIT(DDRD,PIN6_ID);
				SET_BIT(PORTD,PIN6_ID);
				break;
				case PIN7_ID :
				SET_BIT(DDRD,PIN7_ID);
				SET_BIT(PORTD,PIN7_ID);
				break;
				case TOTALPINS_ID :
				/*DoNothing*/
				break;
				default:
				/*DoNothing*/
				break;
			}
			break;
			case TOTALPORTS_ID :
			/*DoNothing*/
			break;
			default:
			/*DoNothing*/
			break;
		}
	}else if (pinStatus == PIN_INPUT)
	{
		switch(configType->PORT){
			case PORTA_ID :
			switch(configType->PIN){
				case PIN0_ID :
				CLEAR_BIT(DDRA,PIN0_ID);
				SET_BIT(PORTA,PIN0_ID);
				break;
				case PIN1_ID :
				CLEAR_BIT(DDRA,PIN1_ID);
				SET_BIT(PORTA,PIN1_ID);
				break;
				case PIN2_ID :
				CLEAR_BIT(DDRA,PIN2_ID);
				SET_BIT(PORTA,PIN2_ID);
				break;
				case PIN3_ID :
				CLEAR_BIT(DDRA,PIN3_ID);
				SET_BIT(PORTA,PIN3_ID);
				break;
				case PIN4_ID :
				CLEAR_BIT(DDRA,PIN4_ID);
				SET_BIT(PORTA,PIN4_ID);
				break;
				case PIN5_ID :
				CLEAR_BIT(DDRA,PIN5_ID);
				SET_BIT(PORTA,PIN5_ID);
				break;
				case PIN6_ID :
				CLEAR_BIT(DDRA,PIN6_ID);
				SET_BIT(PORTA,PIN6_ID);
				break;
				case PIN7_ID :
				CLEAR_BIT(DDRA,PIN7_ID);
				SET_BIT(PORTA,PIN7_ID);
				break;
				case TOTALPINS_ID :
				/*DoNothing*/
				break;
				default:
				/*DoNothing*/
				break;
			}
			break;
			case PORTB_ID :
			switch(configType->PIN){
				case PIN0_ID :
				CLEAR_BIT(DDRB,PIN0_ID);
				SET_BIT(PORTB,PIN0_ID);
				break;
				case PIN1_ID :
				CLEAR_BIT(DDRB,PIN1_ID);
				SET_BIT(PORTB,PIN1_ID);
				break;
				case PIN2_ID :
				CLEAR_BIT(DDRB,PIN2_ID);
				SET_BIT(PORTB,PIN2_ID);
				break;
				case PIN3_ID :
				CLEAR_BIT(DDRB,PIN3_ID);
				SET_BIT(PORTB,PIN3_ID);
				break;
				case PIN4_ID :
				CLEAR_BIT(DDRB,PIN4_ID);
				SET_BIT(PORTB,PIN4_ID);
				break;
				case PIN5_ID :
				CLEAR_BIT(DDRB,PIN5_ID);
				SET_BIT(PORTB,PIN5_ID);
				break;
				case PIN6_ID :
				CLEAR_BIT(DDRB,PIN6_ID);
				SET_BIT(PORTB,PIN6_ID);
				break;
				case PIN7_ID :
				CLEAR_BIT(DDRB,PIN7_ID);
				SET_BIT(PORTB,PIN7_ID);
				break;
				case TOTALPINS_ID :
				/*DoNothing*/
				break;
				default:
				/*DoNothing*/
				break;
			}
			break;
			case PORTC_ID :
			switch(configType->PIN){
				case PIN0_ID :
				CLEAR_BIT(DDRC,PIN0_ID);
				SET_BIT(PORTC,PIN0_ID);
				break;
				case PIN1_ID :
				CLEAR_BIT(DDRC,PIN1_ID);
				SET_BIT(PORTC,PIN1_ID);
				break;
				case PIN2_ID :
				CLEAR_BIT(DDRC,PIN2_ID);
				SET_BIT(PORTC,PIN2_ID);
				break;
				case PIN3_ID :
				CLEAR_BIT(DDRC,PIN3_ID);
				SET_BIT(PORTC,PIN3_ID);
				break;
				case PIN4_ID :
				CLEAR_BIT(DDRC,PIN4_ID);
				SET_BIT(PORTC,PIN4_ID);
				break;
				case PIN5_ID :
				CLEAR_BIT(DDRC,PIN5_ID);
				SET_BIT(PORTC,PIN5_ID);
				break;
				case PIN6_ID :
				CLEAR_BIT(DDRC,PIN6_ID);
				SET_BIT(PORTC,PIN6_ID);
				break;
				case PIN7_ID :
				CLEAR_BIT(DDRC,PIN7_ID);
				SET_BIT(PORTC,PIN7_ID);
				break;
				case TOTALPINS_ID :
				/*DoNothing*/
				break;
				default:
				/*DoNothing*/
				break;
			}
			break;
			case PORTD_ID :
			switch(configType->PIN){
				case PIN0_ID :
				CLEAR_BIT(DDRD,PIN0_ID);
				SET_BIT(PORTD,PIN0_ID);
				break;
				case PIN1_ID :
				CLEAR_BIT(DDRD,PIN1_ID);
				SET_BIT(PORTD,PIN1_ID);
				break;
				case PIN2_ID :
				CLEAR_BIT(DDRD,PIN2_ID);
				SET_BIT(PORTD,PIN2_ID);
				break;
				case PIN3_ID :
				CLEAR_BIT(DDRD,PIN3_ID);
				SET_BIT(PORTD,PIN3_ID);
				break;
				case PIN4_ID :
				CLEAR_BIT(DDRD,PIN4_ID);
				SET_BIT(PORTD,PIN4_ID);
				break;
				case PIN5_ID :
				CLEAR_BIT(DDRD,PIN5_ID);
				SET_BIT(PORTD,PIN5_ID);
				break;
				case PIN6_ID :
				CLEAR_BIT(DDRD,PIN6_ID);
				SET_BIT(PORTD,PIN6_ID);
				break;
				case PIN7_ID :
				CLEAR_BIT(DDRD,PIN7_ID);
				SET_BIT(PORTD,PIN7_ID);
				break;
				case TOTALPINS_ID :
				/*DoNothing*/
				break;
				default:
				/*DoNothing*/
				break;
			}
			break;
			case TOTALPORTS_ID :
			/*DoNothing*/
			break;
			default:
			/*DoNothing*/
			break;
		}
	}else if (pinStatus == PIN_INFREE){
		switch(configType->PORT){
			case PORTA_ID :
			switch(configType->PIN){
				case PIN0_ID :
				CLEAR_BIT(DDRA,PIN0_ID);
				CLEAR_BIT(PORTA,PIN0_ID);
				break;
				case PIN1_ID :
				CLEAR_BIT(DDRA,PIN1_ID);
				CLEAR_BIT(PORTA,PIN1_ID);
				break;
				case PIN2_ID :
				CLEAR_BIT(DDRA,PIN2_ID);
				CLEAR_BIT(PORTA,PIN2_ID);
				break;
				case PIN3_ID :
				CLEAR_BIT(DDRA,PIN3_ID);
				CLEAR_BIT(PORTA,PIN3_ID);
				break;
				case PIN4_ID :
				CLEAR_BIT(DDRA,PIN4_ID);
				CLEAR_BIT(PORTA,PIN4_ID);
				break;
				case PIN5_ID :
				CLEAR_BIT(DDRA,PIN5_ID);
				CLEAR_BIT(PORTA,PIN5_ID);
				break;
				case PIN6_ID :
				CLEAR_BIT(DDRA,PIN6_ID);
				CLEAR_BIT(PORTA,PIN6_ID);
				break;
				case PIN7_ID :
				CLEAR_BIT(DDRA,PIN7_ID);
				CLEAR_BIT(PORTA,PIN7_ID);
				break;
				case TOTALPINS_ID :
				/*DoNothing*/
				break;
				default:
				/*DoNothing*/
				break;
			}
			break;
			case PORTB_ID :
			switch(configType->PIN){
				case PIN0_ID :
				CLEAR_BIT(DDRB,PIN0_ID);
				CLEAR_BIT(PORTB,PIN0_ID);
				break;
				case PIN1_ID :
				CLEAR_BIT(DDRB,PIN1_ID);
				CLEAR_BIT(PORTB,PIN1_ID);
				break;
				case PIN2_ID :
				CLEAR_BIT(DDRB,PIN2_ID);
				CLEAR_BIT(PORTB,PIN2_ID);
				break;
				case PIN3_ID :
				CLEAR_BIT(DDRB,PIN3_ID);
				CLEAR_BIT(PORTB,PIN3_ID);
				break;
				case PIN4_ID :
				CLEAR_BIT(DDRB,PIN4_ID);
				CLEAR_BIT(PORTB,PIN4_ID);
				break;
				case PIN5_ID :
				CLEAR_BIT(DDRB,PIN5_ID);
				CLEAR_BIT(PORTB,PIN5_ID);
				break;
				case PIN6_ID :
				CLEAR_BIT(DDRB,PIN6_ID);
				CLEAR_BIT(PORTB,PIN6_ID);
				break;
				case PIN7_ID :
				CLEAR_BIT(DDRB,PIN7_ID);
				CLEAR_BIT(PORTB,PIN7_ID);
				break;
				case TOTALPINS_ID :
				/*DoNothing*/
				break;
				default:
				/*DoNothing*/
				break;
			}
			break;
			case PORTC_ID :
			switch(configType->PIN){
				case PIN0_ID :
				CLEAR_BIT(DDRC,PIN0_ID);
				CLEAR_BIT(PORTC,PIN0_ID);
				break;
				case PIN1_ID :
				CLEAR_BIT(DDRC,PIN1_ID);
				CLEAR_BIT(PORTC,PIN1_ID);
				break;
				case PIN2_ID :
				CLEAR_BIT(DDRC,PIN2_ID);
				CLEAR_BIT(PORTC,PIN2_ID);
				break;
				case PIN3_ID :
				CLEAR_BIT(DDRC,PIN3_ID);
				CLEAR_BIT(PORTC,PIN3_ID);
				break;
				case PIN4_ID :
				CLEAR_BIT(DDRC,PIN4_ID);
				CLEAR_BIT(PORTC,PIN4_ID);
				break;
				case PIN5_ID :
				CLEAR_BIT(DDRC,PIN5_ID);
				CLEAR_BIT(PORTC,PIN5_ID);
				break;
				case PIN6_ID :
				CLEAR_BIT(DDRC,PIN6_ID);
				CLEAR_BIT(PORTC,PIN6_ID);
				break;
				case PIN7_ID :
				CLEAR_BIT(DDRC,PIN7_ID);
				CLEAR_BIT(PORTC,PIN7_ID);
				break;
				case TOTALPINS_ID :
				/*DoNothing*/
				break;
				default:
				/*DoNothing*/
				break;
			}
			break;
			case PORTD_ID :
			switch(configType->PIN){
				case PIN0_ID :
				CLEAR_BIT(DDRD,PIN0_ID);
				CLEAR_BIT(PORTD,PIN0_ID);
				break;
				case PIN1_ID :
				CLEAR_BIT(DDRD,PIN1_ID);
				CLEAR_BIT(PORTD,PIN1_ID);
				break;
				case PIN2_ID :
				CLEAR_BIT(DDRD,PIN2_ID);
				CLEAR_BIT(PORTD,PIN2_ID);
				break;
				case PIN3_ID :
				CLEAR_BIT(DDRD,PIN3_ID);
				CLEAR_BIT(PORTD,PIN3_ID);
				break;
				case PIN4_ID :
				CLEAR_BIT(DDRD,PIN4_ID);
				CLEAR_BIT(PORTD,PIN4_ID);
				break;
				case PIN5_ID :
				CLEAR_BIT(DDRD,PIN5_ID);
				CLEAR_BIT(PORTD,PIN5_ID);
				break;
				case PIN6_ID :
				CLEAR_BIT(DDRD,PIN6_ID);
				CLEAR_BIT(PORTD,PIN6_ID);
				break;
				case PIN7_ID :
				CLEAR_BIT(DDRD,PIN7_ID);
				CLEAR_BIT(PORTD,PIN7_ID);
				break;
				case TOTALPINS_ID :
				/*DoNothing*/
				break;
				default:
				/*DoNothing*/
				break;
			}
			break;
			case TOTALPORTS_ID :
			/*DoNothing*/
			break;
			default:
			/*DoNothing*/
			break;
		}
	}else{
		/*DO Nothing*/
	}
	
			
}

STD_TYPE MCAL_DIO_Std_WRITE_PORT_DIRECTION(DIO_PORT_ID *PortId,DIO_PORT_DIRECTION_TYPE *PortLevel){


}

STD_TYPE MCAL_DIO_Std_WRITE_PIN_DIRECTION(DIO_PIN_ID *PinId,DIO_PIN_DIRECTION_TYPE *PinLevel){





}


 /* Description :
 * Read and return the value of the required port.
 */
DIO_LEVEL_TYPE MCAL_DIO_Std_READ_PORT_DIRECTION(DIO_PORT_ID PortId){

	DIO_PORT_ID port_num=PortId/8;   //result of divi is number of port
	DIO_LEVEL_TYPE value=LOGIC_LOW;



	/* Read the port value as required */
	switch(port_num)
	{
	case PORTA_ID:
		value = PINA;
		break;
	case PORTB_ID:
		value = PINB;
		break;
	case PORTC_ID:
		value = PINC;
		break;
	case PORTD_ID:
		value = PIND;
		break;
	}


	return value;
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 */

DIO_LEVEL_TYPE MCAL_DIO_Std_READ_PIN_DIRECTION(DIO_PORT_ID PortId,DIO_PIN_ID PinId){
	DIO_PORT_ID port_num=PortId/8;  //result of div is number of port
	DIO_PIN_ID pin_num =PinId %8;     //result of modulo is number of pin
	DIO_LEVEL_TYPE pin_value=LOGIC_LOW;

	switch(port_num)
	{
	case PORTA_ID:
		if(BIT_IS_SET(PINA,pin_num))
		{
			pin_value = LOGIC_HIGH;
		}
		else
		{
			pin_value = LOGIC_LOW;
		}
		break;
	case PORTB_ID:
		if(BIT_IS_SET(PINB,pin_num))
		{
			pin_value = LOGIC_HIGH;
		}
		else
		{
			pin_value = LOGIC_LOW;
		}
		break;
	case PORTC_ID:
		if(BIT_IS_SET(PINC,pin_num))
		{
			pin_value = LOGIC_HIGH;
		}
		else
		{
			pin_value = LOGIC_LOW;
		}
		break;
	case PORTD_ID:
		if(BIT_IS_SET(PIND,pin_num))
		{
			pin_value = LOGIC_HIGH;
		}
		else
		{
			pin_value = LOGIC_LOW;
		}
		break;

	}

	return pin_value;



}


STD_TYPE MCAL_DIO_Std_FLIP_PORT_DIRECTION(uint8 PortId){

	STD_TYPE ERROR= E_OK;
		if (PortId <= 3)
			{
				switch (PortId)
				{
				case PORTA_ID :  PORTA = ~PORTA;
				break ;
				case PORTB_ID : PORTB = ~PORTB;
				break ;
				case PORTC_ID : PORTB = ~PORTB;
				break ;
				case PORTD_ID : PORTB = ~PORTB;
				break ;
				}

			}
		else
			{
				/* in case of error in the Pin ID or PORT ID */
				ERROR = E_NOT_OK ;
			}


}
STD_TYPE MCAL_DIO_Std_FLIP_PIN_DIRECTION(uint8 PortId, uint8 PIN){

	STD_TYPE ERROR= E_OK;
	if (PIN <= 7)
		{
			switch (PortId)
			{
			case PORTA_ID : FLIP_BIT(PORTA,PIN);
			break ;
			case PORTB_ID : FLIP_BIT(PORTB,PIN);
			break ;
			case PORTC_ID : FLIP_BIT(PORTC,PIN);
			break ;
			case PORTD_ID : FLIP_BIT(PORTD,PIN);
			break ;
			}

		}
	else
		{
			/* in case of error in the Pin ID or PORT ID */
			ERROR = E_NOT_OK ;
		}



	return ERROR;

}

/* function to write data om port *//*Dio_ConfigType is struct cary port types and pin types , and data  */
STD_TYPE MCAL_DIO_Std_WRITE_PORT ( Dio_ConfigType * Config_type , uint8 data )
{
	/* enum to check if data assinged on port or not */
	STD_TYPE STATUS = E_NOT_OK  ; 
	/* switch to select port */
	switch (Config_type ->PORT)
	{
		/* ports types */
		case Config_type ->PORT->PORTA_ID :
		PORTA = data ;
		 STATUS = E_OK ;  
		break ;
		case Config_type ->PORT->PORTB_ID :
		PORTB = data ;
		STATUS = E_OK ; 
		break ;
		case Config_type ->PORT->PORTC_ID :
		PORTC = data ;
		STATUS = E_OK ; 
		break ;
		case Config_type ->PORT->PORTD_ID :
		PORTD_ID = data ;
		STATUS = E_OK ; 
		break ;
	}
	return STATUS ; 
}

/* function to write on pin *//*Dio_ConfigType is struct cary port types and pin types , and cases of pin status HIGH OR  LOW  */
STD_TYPE MCAL_DIO_Std_WRITE_PIN (Dio_ConfigType * Config_type  , DIO_LEVEL_TYPE volt)
{
	STD_TYPE STATUS = E_NOT_OK  ; 
	if (volt == LOGIC_HIGH)
	{
		/* SWITCH TO SELECT PORT */
		switch (Config_type ->PORT)
		{
			/* IF PORT A IS SLECTED */
			case Config_type ->PORT->PORTA_ID :
			/* SWITCH TO SELECT PIN */
			switch ( Config_type -> PIN )
			{
				case Config_type -> PIN -> PIN0_ID :
				SET_BIT(PORTA,Config_type -> PIN -> PIN0_ID);
				break ;
				case Config_type -> PIN -> PIN1_ID :
				SET_BIT(PORTA,Config_type -> PIN -> PIN1_ID);
				break ;
				case Config_type -> PIN -> PIN2_ID :
				SET_BIT(PORTA,Config_type -> PIN -> PIN2_ID);
				break ;
				case Config_type -> PIN -> PIN3_ID :
				SET_BIT(PORTA,Config_type -> PIN -> PIN3_ID);
				break ;
				case Config_type -> PIN -> PIN4_ID :
				SET_BIT(PORTA,Config_type -> PIN -> PIN4_ID);
				break ;
				case Config_type -> PIN -> PIN5_ID :
				SET_BIT(PORTA,Config_type -> PIN -> PIN5_ID);
				break ;
				case Config_type -> PIN -> PIN6_ID :
				SET_BIT(PORTA,Config_type -> PIN -> PIN6_ID);
				break ;
				case Config_type -> PIN -> PIN7_ID :
				SET_BIT(PORTA,Config_type -> PIN -> PIN7_ID);
				break ;
			}
			STATUS = E_OK ;
			break;
			/* IF PORT B IS SLECTED */
			case Config_type ->PORT->PORTB_ID :
			
			switch ( Config_type -> PIN )
			{
				case Config_type -> PIN -> PIN0_ID :
				SET_BIT(PORTB,Config_type -> PIN -> PIN0_ID);
				break ;
				case Config_type -> PIN -> PIN1_ID :
				SET_BIT(PORTB,Config_type -> PIN -> PIN1_ID);
				break ;
				case Config_type -> PIN -> PIN2_ID :
				SET_BIT(PORTB,Config_type -> PIN -> PIN2_ID);
				break ;
				case Config_type -> PIN -> PIN3_ID :
				SET_BIT(PORTB,Config_type -> PIN -> PIN3_ID);
				break ;
				case Config_type -> PIN -> PIN4_ID :
				SET_BIT(PORTB,Config_type -> PIN -> PIN4_ID);
				break ;
				case Config_type -> PIN -> PIN5_ID :
				SET_BIT(PORTB,Config_type -> PIN -> PIN5_ID);
				break ;
				case Config_type -> PIN -> PIN6_ID :
				SET_BIT(PORTB,Config_type -> PIN -> PIN6_ID);
				break ;
				case Config_type -> PIN -> PIN7_ID :
				SET_BIT(PORTB,Config_type -> PIN -> PIN7_ID);
				break ;
			}
			STATUS = E_OK ;
			break;
			
			/* IF PORT C IS SLECTED */
			case Config_type ->PORT->PORTC_ID :
			
			switch ( Config_type -> PIN )
			{
				case Config_type -> PIN -> PIN0_ID :
				SET_BIT(PORTC,Config_type -> PIN -> PIN0_ID);
				break ;
				case Config_type -> PIN -> PIN1_ID :
				SET_BIT(PORTC,Config_type -> PIN -> PIN1_ID);
				break ;
				case Config_type -> PIN -> PIN2_ID :
				SET_BIT(PORTC,Config_type -> PIN -> PIN2_ID);
				break ;
				case Config_type -> PIN -> PIN3_ID :
				SET_BIT(PORTC,Config_type -> PIN -> PIN3_ID);
				break ;
				case Config_type -> PIN -> PIN4_ID :
				SET_BIT(PORTC,Config_type -> PIN -> PIN4_ID);
				break ;
				case Config_type -> PIN -> PIN5_ID :
				SET_BIT(PORTC,Config_type -> PIN -> PIN5_ID);
				break ;
				case Config_type -> PIN -> PIN6_ID :
				SET_BIT(PORTC,Config_type -> PIN -> PIN6_ID);
				break ;
				case Config_type -> PIN -> PIN7_ID :
				SET_BIT(PORTC,Config_type -> PIN -> PIN7_ID);
				break ;
			}
			STATUS = E_OK ;
			break;
			/* IF PORT D IS SLECTED */
			case Config_type ->PORT->PORTD_ID :
			
			switch ( Config_type -> PIN )
			{
				case Config_type -> PIN -> PIN0_ID :
				SET_BIT(PORTD,Config_type -> PIN -> PIN0_ID);
				break ;
				case Config_type -> PIN -> PIN1_ID :
				SET_BIT(PORTD,Config_type -> PIN -> PIN1_ID);
				break ;
				case Config_type -> PIN -> PIN2_ID :
				SET_BIT(PORTD,Config_type -> PIN -> PIN2_ID);
				break ;
				case Config_type -> PIN -> PIN3_ID :
				SET_BIT(PORTD,Config_type -> PIN -> PIN3_ID);
				break ;
				case Config_type -> PIN -> PIN4_ID :
				SET_BIT(PORTD,Config_type -> PIN -> PIN4_ID);
				break ;
				case Config_type -> PIN -> PIN5_ID :
				SET_BIT(PORTD,Config_type -> PIN -> PIN5_ID);
				break ;
				case Config_type -> PIN -> PIN6_ID :
				SET_BIT(PORTD,Config_type -> PIN -> PIN6_ID);
				break ;
				case Config_type -> PIN -> PIN7_ID :
				SET_BIT(PORTD,Config_type -> PIN -> PIN7_ID);
				break ;
			}
			STATUS = E_OK ;
			break;
		}
	}
	// if you want to export on port 0 to  Pin
	else
	{
		/* SWITCH TO SELECT PORT */
		switch (Config_type ->PORT)
		{
			/* IF PORT A IS SLECTED */
			case Config_type ->PORT->PORTA_ID :
			/* SWITCH TO SELECT PIN */
			switch ( Config_type -> PIN )
			{
				case Config_type -> PIN -> PIN0_ID :
				CLR_BIT(PORTA,Config_type -> PIN -> PIN0_ID);
				break ;
				case Config_type -> PIN -> PIN1_ID :
				CLR_BIT(PORTA,Config_type -> PIN -> PIN1_ID);
				break ;
				case Config_type -> PIN -> PIN2_ID :
				CLR_BIT(PORTA,Config_type -> PIN -> PIN2_ID);
				break ;
				case Config_type -> PIN -> PIN3_ID :
				CLR_BIT(PORTA,Config_type -> PIN -> PIN3_ID);
				break ;
				case Config_type -> PIN -> PIN4_ID :
				CLR_BIT(PORTA,Config_type -> PIN -> PIN4_ID);
				break ;
				case Config_type -> PIN -> PIN5_ID :
				CLR_BIT(PORTA,Config_type -> PIN -> PIN5_ID);
				break ;
				case Config_type -> PIN -> PIN6_ID :
				CLR_BIT(PORTA,Config_type -> PIN -> PIN6_ID);
				break ;
				case Config_type -> PIN -> PIN7_ID :
				CLR_BIT(PORTA,Config_type -> PIN -> PIN7_ID);
				break ;
			}
			STATUS = E_OK ;
			break;
			/* IF PORT B IS SLECTED */
			case Config_type ->PORT->PORTB_ID :
			
			switch ( Config_type -> PIN )
			{
				case Config_type -> PIN -> PIN0_ID :
				CLR_BIT(PORTB,Config_type -> PIN -> PIN0_ID);
				break ;
				case Config_type -> PIN -> PIN1_ID :
				CLR_BIT(PORTB,Config_type -> PIN -> PIN1_ID);
				break ;
				case Config_type -> PIN -> PIN2_ID :
				CLR_BIT(PORTB,Config_type -> PIN -> PIN2_ID);
				break ;
				case Config_type -> PIN -> PIN3_ID :
				CLR_BIT(PORTB,Config_type -> PIN -> PIN3_ID);
				break ;
				case Config_type -> PIN -> PIN4_ID :
				CLR_BIT(PORTB,Config_type -> PIN -> PIN4_ID);
				break ;
				case Config_type -> PIN -> PIN5_ID :
				CLR_BIT(PORTB,Config_type -> PIN -> PIN5_ID);
				break ;
				case Config_type -> PIN -> PIN6_ID :
				CLR_BIT(PORTB,Config_type -> PIN -> PIN6_ID);
				break ;
				case Config_type -> PIN -> PIN7_ID :
				CLR_BIT(PORTB,Config_type -> PIN -> PIN7_ID);
				break ;
			}
			STATUS = E_OK ;
			break;
			
			/* IF PORT C IS SLECTED */
			case Config_type ->PORT->PORTC_ID :
			
			switch ( Config_type -> PIN )
			{
				case Config_type -> PIN -> PIN0_ID :
				CLR_BIT(PORTC,Config_type -> PIN -> PIN0_ID);
				break ;
				case Config_type -> PIN -> PIN1_ID :
				CLR_BIT(PORTC,Config_type -> PIN -> PIN1_ID);
				break ;
				case Config_type -> PIN -> PIN2_ID :
				CLR_BIT(PORTC,Config_type -> PIN -> PIN2_ID);
				break ;
				case Config_type -> PIN -> PIN3_ID :
				CLR_BIT(PORTC,Config_type -> PIN -> PIN3_ID);
				break ;
				case Config_type -> PIN -> PIN4_ID :
				CLR_BIT(PORTC,Config_type -> PIN -> PIN4_ID);
				break ;
				case Config_type -> PIN -> PIN5_ID :
				CLR_BIT(PORTC,Config_type -> PIN -> PIN5_ID);
				break ;
				case Config_type -> PIN -> PIN6_ID :
				CLR_BIT(PORTC,Config_type -> PIN -> PIN6_ID);
				break ;
				case Config_type -> PIN -> PIN7_ID :
				CLR_BIT(PORTC,Config_type -> PIN -> PIN7_ID);
				break ;
			}
			STATUS = E_OK ;
			break;
			/* IF PORT D IS SLECTED */
			case Config_type ->PORT->PORTD_ID :
			
			switch ( Config_type -> PIN )
			{
				case Config_type -> PIN -> PIN0_ID :
				CLR_BIT(PORTD,Config_type -> PIN -> PIN0_ID);
				break ;
				case Config_type -> PIN -> PIN1_ID :
				CLR_BIT(PORTD,Config_type -> PIN -> PIN1_ID);
				break ;
				case Config_type -> PIN -> PIN2_ID :
				CLR_BIT(PORTD,Config_type -> PIN -> PIN2_ID);
				break ;
				case Config_type -> PIN -> PIN3_ID :
				CLR_BIT(PORTD,Config_type -> PIN -> PIN3_ID);
				break ;
				case Config_type -> PIN -> PIN4_ID :
				CLR_BIT(PORTD,Config_type -> PIN -> PIN4_ID);
				break ;
				case Config_type -> PIN -> PIN5_ID :
				CLR_BIT(PORTD,Config_type -> PIN -> PIN5_ID);
				break ;
				case Config_type -> PIN -> PIN6_ID :
				CLR_BIT(PORTD,Config_type -> PIN -> PIN6_ID);
				break ;
				case Config_type -> PIN -> PIN7_ID :
				CLR_BIT(PORTD,Config_type -> PIN -> PIN7_ID);
				break ;
			}
			STATUS = E_OK ;
			break;
		}
	}
}

