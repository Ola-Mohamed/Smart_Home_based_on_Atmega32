/******************************************************************************
 *
 * Module: DIO
 *
 * File Name: DIO_PROG.h
 *
 * Author: Nti Team
 *
 * ******************************************************************************/
#include "DIO_INTERFACE.h"



/************************************************************************************
* Service Name: MCAL_DIO_INIT
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Dio module.
************************************************************************************/

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

/************************************************************************************
* Service Name: MCAL_DIO_INIT_PINS
* Parameters (in): Dio_ConfigType -  Pointer to post-build configuration data
*                  DIO_PIN_DIRECTION_TYPE - direction for pins
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Dio module.
************************************************************************************/

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

/************************************************************************************
* Service Name:  MCAL_DIO_READ_PORT_DIRECTION
* Parameters (in): DIO_PORT_ID - port id
* Parameters (inout): None
* Parameters (out): None
* Return value: DIO_LEVEL_TYPE
* Description: Function to Read and return the value of the required port.
************************************************************************************/
STD_TYPE_DIO MCAL_DIO_READ_PORT_DIRECTION(Dio_ConfigType* READ_PORT,u8PortValue*value){

	STD_TYPE_DIO error=E_OK ;  //result of divi is number of port
	if(READ_PORT->PORT >= DIO_PORTS)
	{

		error = E_NOT_OK;
	}
	else
	{
		switch (READ_PORT->PORT )
		{



		/*Read the port value as required */

		case PORTA_ID:
			*value = PINA;
			break;
		case PORTB_ID:
			*value = PINB;
			break;
		case PORTC_ID:
			*value = PINC;
			break;
		case PORTD_ID:
			*value = PIND;
			break;
		}

	}
	return error;
}


/************************************************************************************
* Service Name:  MCAL_DIO_READ_PIN_DIRECTION
* Parameters (in): DIO_PORT_ID - port id
*                  DIO_PIN_ID  - pin id
* Parameters (inout): None
* Parameters (out): None
* Return value: DIO_LEVEL_TYPE
* Description: Function to Read and return the value for the required pin, it should
* be Logic High or Logic Low.
************************************************************************************/

STD_TYPE_DIO MCAL_DIO_READ_PIN_DIRECTION(Dio_ConfigType* READ_PIN,u8PINValue*PIN_value)
	{
		STD_TYPE_DIO ERROR = E_OK;
		if(READ_PIN->PIN >= DIO_PINS)
		{

			ERROR = E_NOT_OK;

		}
		else
		{

			switch(READ_PIN->PIN >= DIO_PINS)
			{
			case PORTA_ID:
				if(BIT_IS_SET(PINA,READ_PIN->PIN))
				{
					*PIN_value = LOGIC_HIGH;
				}
				else
				{
					*PIN_value = LOGIC_LOW;
				}
				break;
			case PORTB_ID:
				if(BIT_IS_SET(PINB,READ_PIN->PIN))
				{
					*PIN_value = LOGIC_HIGH;
				}
				else
				{
					*PIN_value = LOGIC_LOW;
				}
				break;
			case PORTC_ID:
				if(BIT_IS_SET(PINC,READ_PIN->PIN))
				{
					*PIN_value = LOGIC_HIGH;
				}
				else
				{
					*PIN_value = LOGIC_LOW;
				}
				break;
			case PORTD_ID:
				if(BIT_IS_SET(PIND,READ_PIN->PIN))
				{
					*PIN_value = LOGIC_HIGH;
				}
				else
				{
					*PIN_value = LOGIC_LOW;
				}
				break;

			}
		}
			return ERROR;
}

/************************************************************************************
* Service Name:  MCAL_DIO_Std_FLIP_PORT_DIRECTION
* Parameters (in): DIO_PORT_ID - port id
* Parameters (inout): None
* Parameters (out): None
* Return value: STD_TYPE_DIO
* Description: Function to toggle port
************************************************************************************/

STD_TYPE_DIO MCAL_DIO_Std_FLIP_PORT_DIRECTION(DIO_PORT_ID PortId){

	STD_TYPE_DIO LOC_error= E_OK;
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
			LOC_error = E_NOT_OK ;
			}
       return LOC_error;
}

/************************************************************************************
* Service Name:  MCAL_DIO_Std_FLIP_PIN_DIRECTION
* Parameters (in): DIO_PORT_ID - port id
*                  DIO_PIN_ID  - pin id
* Parameters (inout): None
* Parameters (out): None
* Return value: STD_TYPE_DIO
* Description: Function to toggle specific pin
************************************************************************************/
STD_TYPE_DIO MCAL_DIO_Std_FLIP_PIN_DIRECTION(DIO_PORT_ID PortId, DIO_PIN_ID PIN){

	STD_TYPE_DIO ERROR= E_OK;
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

/************************************************************************************
* Service Name:  MCAL_DIO_Std_WRITE_PORT
* Parameters (in): Dio_ConfigType - Pointer to post-build configuration data
*                  Data
* Parameters (inout): None
* Parameters (out): None
* Return value: STD_TYPE_DIO
* Description: Function to write data on specific port
************************************************************************************/
STD_TYPE_DIO MCAL_DIO_Std_WRITE_PORT ( Dio_ConfigType * Config_type , uint8 data )
{
	/* enum to check if data assigned on port or not */
	STD_TYPE_DIO LOC_status = E_NOT_OK  ;
	/* switch to select port */
	switch (Config_type ->PORT)
	{
		/* ports types */
		case PORTA_ID :
		PORTA = data ;
		LOC_status = E_OK ;
		break ;
		case PORTB_ID :
		PORTB = data ;
		LOC_status = E_OK ;
		break ;
		case PORTC_ID :
		PORTC = data ;
		LOC_status = E_OK ;
		break ;
		case PORTD_ID :
		PORTD = data ;
		LOC_status = E_OK ;
		break ;
		case TOTALPORTS_ID :
		/*Do Nothing*/
		break;
		default:
		/*Do Nothing*/
		break;
	}
	return LOC_status ;
}


/************************************************************************************
* Service Name:  MCAL_DIO_Std_WRITE_PORT
* Parameters (in): Dio_ConfigType -  Pointer to post-build configuration data
*                  VOLT
* Parameters (inout): None
* Parameters (out): None
* Return value: STD_TYPE_DIO
* Description: Function to write data on specific pin
************************************************************************************/
STD_TYPE_DIO MCAL_DIO_Std_WRITE_PIN (Dio_ConfigType * Config_type  , DIO_LEVEL_TYPE VOLT)
{
	STD_TYPE_DIO LOC_status = E_NOT_OK  ;
	if (VOLT == LOGIC_HIGH)
	{
		/* SWITCH TO SELECT PORT */
		switch (Config_type ->PORT)
		{
			/* IF PORT A IS SLECTED */
			case PORTA_ID :
			/* SWITCH TO SELECT PIN */
			switch ( Config_type -> PIN )
			{
				case  PIN0_ID :
				SET_BIT(PORTA, PIN0_ID);
				break ;
				case  PIN1_ID :
				SET_BIT(PORTA, PIN1_ID);
				break ;
				case PIN2_ID :
				SET_BIT(PORTA, PIN2_ID);
				break ;
				case  PIN3_ID :
				SET_BIT(PORTA, PIN3_ID);
				break ;
				case  PIN4_ID :
				SET_BIT(PORTA, PIN4_ID);
				break ;
				case PIN5_ID :
				SET_BIT(PORTA, PIN5_ID);
				break ;
				case PIN6_ID :
				SET_BIT(PORTA, PIN6_ID);
				break ;
				case  PIN7_ID :
				SET_BIT(PORTA, PIN7_ID);
				break ;

				case TOTALPINS_ID :
				/*Do Nothing*/
				break;

				default :
				/*Do Nothing*/
				break;
			}
			LOC_status = E_OK ;
			break;
			/* IF PORT B IS SLECTED */
			case PORTB_ID :

			switch ( Config_type -> PIN )
			{
				case  PIN0_ID :
				SET_BIT(PORTB, PIN0_ID);
				break ;
				case  PIN1_ID :
				SET_BIT(PORTB, PIN1_ID);
				break ;
				case PIN2_ID :
				SET_BIT(PORTB, PIN2_ID);
				break ;
				case  PIN3_ID :
				SET_BIT(PORTB, PIN3_ID);
				break ;
				case  PIN4_ID :
				SET_BIT(PORTB, PIN4_ID);
				break ;
				case  PIN5_ID :
				SET_BIT(PORTB, PIN5_ID);
				break ;
				case  PIN6_ID :
				SET_BIT(PORTB, PIN6_ID);
				break ;
				case  PIN7_ID :
				SET_BIT(PORTB, PIN7_ID);
				break ;

				case TOTALPINS_ID :
				/*Do Nothing*/
				break;

				default :
				/*Do Nothing*/
				break;
			}
			LOC_status = E_OK ;
			break;

			/* IF PORT C IS SLECTED */
			case PORTC_ID :

			switch ( Config_type -> PIN )
			{
				case  PIN0_ID :
				SET_BIT(PORTC, PIN0_ID);
				break ;
				case  PIN1_ID :
				SET_BIT(PORTC, PIN1_ID);
				break ;
				case  PIN2_ID :
				SET_BIT(PORTC, PIN2_ID);
				break ;
				case  PIN3_ID :
				SET_BIT(PORTC, PIN3_ID);
				break ;
				case  PIN4_ID :
				SET_BIT(PORTC, PIN4_ID);
				break ;
				case PIN5_ID :
				SET_BIT(PORTC, PIN5_ID);
				break ;
				case  PIN6_ID :
				SET_BIT(PORTC, PIN6_ID);
				break ;
				case  PIN7_ID :
				SET_BIT(PORTC, PIN7_ID);
				break ;

				case TOTALPINS_ID :
				/*Do Nothing*/
				break;

				default :
				/*Do Nothing*/
				break;
			}
			LOC_status = E_OK ;
			break;
			/* IF PORT D IS SLECTED */
			case PORTD_ID :

			switch ( Config_type -> PIN )
			{
				case  PIN0_ID :
				SET_BIT(PORTD, PIN0_ID);
				break ;
				case  PIN1_ID :
				SET_BIT(PORTD, PIN1_ID);
				break ;
				case  PIN2_ID :
				SET_BIT(PORTD, PIN2_ID);
				break ;
				case  PIN3_ID :
				SET_BIT(PORTD, PIN3_ID);
				break ;
				case PIN4_ID :
				SET_BIT(PORTD, PIN4_ID);
				break ;
				case PIN5_ID :
				SET_BIT(PORTD, PIN5_ID);
				break ;
				case  PIN6_ID :
				SET_BIT(PORTD, PIN6_ID);
				break ;
				case  PIN7_ID :
				SET_BIT(PORTD, PIN7_ID);
				break ;

				case TOTALPINS_ID :
				/*Do Nothing*/
				break;

				default :
				/*Do Nothing*/
				break;
			}
			LOC_status = E_OK ;
			break;

			case TOTALPORTS_ID :
			/*Do Nothing*/
			break;

			default :
			/*Do Nothing*/
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
			case PORTA_ID :
			/* SWITCH TO SELECT PIN */
			switch ( Config_type -> PIN )
			{
				case  PIN0_ID :
				CLEAR_BIT(PORTA, PIN0_ID);
				break ;
				case  PIN1_ID :
				CLEAR_BIT(PORTA, PIN1_ID);
				break ;
				case  PIN2_ID :
				CLEAR_BIT(PORTA, PIN2_ID);
				break ;
				case PIN3_ID :
				CLEAR_BIT(PORTA, PIN3_ID);
				break ;
				case  PIN4_ID :
				CLEAR_BIT(PORTA, PIN4_ID);
				break ;
				case  PIN5_ID :
				CLEAR_BIT(PORTA, PIN5_ID);
				break ;
				case  PIN6_ID :
				CLEAR_BIT(PORTA, PIN6_ID);
				break ;
				case  PIN7_ID :
				CLEAR_BIT(PORTA, PIN7_ID);
				break ;
				case TOTALPINS_ID :
				/*Do Nothing*/
				break;
				default :
				/*Do Nothing*/
				break;
			}
			LOC_status = E_OK ;
			break;
			/* IF PORT B IS SLECTED */
			case PORTB_ID :

			switch ( Config_type -> PIN )
			{
				case  PIN0_ID :
				CLEAR_BIT(PORTB, PIN0_ID);
				break ;
				case  PIN1_ID :
				CLEAR_BIT(PORTB, PIN1_ID);
				break ;
				case  PIN2_ID :
				CLEAR_BIT(PORTB, PIN2_ID);
				break ;
				case  PIN3_ID :
				CLEAR_BIT(PORTB, PIN3_ID);
				break ;
				case  PIN4_ID :
				CLEAR_BIT(PORTB, PIN4_ID);
				break ;
				case  PIN5_ID :
				CLEAR_BIT(PORTB, PIN5_ID);
				break ;
				case  PIN6_ID :
				CLEAR_BIT(PORTB, PIN6_ID);
				break ;
				case  PIN7_ID :
				CLEAR_BIT(PORTB, PIN7_ID);
				break ;

				case TOTALPINS_ID :
				/*Do Nothing*/
				break;

				default :
				/*Do Nothing*/
				break;
			}
			LOC_status = E_OK ;
			break;

			/* IF PORT C IS SLECTED */
			case PORTC_ID :

			switch ( Config_type -> PIN )
			{
				case  PIN0_ID :
				CLEAR_BIT(PORTC, PIN0_ID);
				break ;
				case  PIN1_ID :
				CLEAR_BIT(PORTC, PIN1_ID);
				break ;
				case  PIN2_ID :
				CLEAR_BIT(PORTC, PIN2_ID);
				break ;
				case  PIN3_ID :
				CLEAR_BIT(PORTC, PIN3_ID);
				break ;
				case PIN4_ID :
				CLEAR_BIT(PORTC, PIN4_ID);
				break ;
				case  PIN5_ID :
				CLEAR_BIT(PORTC, PIN5_ID);
				break ;
				case  PIN6_ID :
				CLEAR_BIT(PORTC, PIN6_ID);
				break ;
				case  PIN7_ID :
				CLEAR_BIT(PORTC, PIN7_ID);
				break ;

				case TOTALPINS_ID :
				/*Do Nothing*/
				break;

				default :
				/*Do Nothing*/
				break;
			}
			LOC_status = E_OK ;
			break;
			/* IF PORT D IS SLECTED */
			case PORTD_ID :

			switch ( Config_type -> PIN )
			{
				case  PIN0_ID :
				CLEAR_BIT(PORTD, PIN0_ID);
				break ;
				case  PIN1_ID :
				CLEAR_BIT(PORTD, PIN1_ID);
				break ;
				case  PIN2_ID :
				CLEAR_BIT(PORTD, PIN2_ID);
				break ;
				case  PIN3_ID :
				CLEAR_BIT(PORTD, PIN3_ID);
				break ;
				case  PIN4_ID :
				CLEAR_BIT(PORTD, PIN4_ID);
				break ;
				case  PIN5_ID :
				CLEAR_BIT(PORTD, PIN5_ID);
				break ;
				case  PIN6_ID :
				CLEAR_BIT(PORTD, PIN6_ID);
				break ;
				case  PIN7_ID :
				CLEAR_BIT(PORTD, PIN7_ID);
				break ;

				case TOTALPINS_ID :
				/*Do Nothing*/
				break;

				default :
				/*Do Nothing*/
				break;
			}
			LOC_status = E_OK ;
			break;
			case TOTALPORTS_ID :
			/*Do Nothing*/
			break;
			default:
			/*Do Nothing*/
			break;
		}
	}
	return LOC_status;
}

