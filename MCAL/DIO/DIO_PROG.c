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

DIO_LEVEL_TYPE MCAL_DIO_Std_READ_PORT_DIRECTION(DIO_PORT_ID *PortId){





}

DIO_LEVEL_TYPE MCAL_DIO_Std_READ_PIN_DIRECTION(DIO_PIN_ID *PinId){



}

DIO_LEVEL_TYPE MCAL_DIO_Std_FLIP_PIN_DIRECTION(DIO_PORT_ID *PortId){



}

DIO_LEVEL_TYPE MCAL_DIO_Std_FLIP_PIN_DIRECTION(DIO_PIN_ID *PinId){






}
