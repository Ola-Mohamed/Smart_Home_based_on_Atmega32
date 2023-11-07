/******************************************************************************
 *
  Module: Led
 *
 * File Name: Led.c
 *
 * Description: Source file for Led Module.
 ******************************************************************************/

#include "Led.h"

void LED_init(){

	MCAL_DIO_INIT();

}
/*********************************************************************************************/

void LED_setOn(LED_COLOR LED)
{
 switch(LED){
	case RED:
		MCAL_DIO_Std_WRITE_PIN(&LED_RED, LOGIC_HIGH);    /* LED ON */
		break;

	case GREEN:
		MCAL_DIO_Std_WRITE_PIN(&LED_GREEN, LOGIC_HIGH);    /* LED ON */
		break;

	case YELLOW:
		MCAL_DIO_Std_WRITE_PIN(&LED_YELLOW, LOGIC_HIGH);    /* LED ON */
		break;

	case BLUE:
		MCAL_DIO_Std_WRITE_PIN(&LED_BLUE, LOGIC_HIGH);    /* LED ON */
		break;

	}

}

/*********************************************************************************************/
void LED_setOff(LED_COLOR LED)
{
	switch(LED){
	case RED:
		MCAL_DIO_Std_WRITE_PIN(&LED_RED, LOGIC_LOW);
		break;
	case GREEN:
		MCAL_DIO_Std_WRITE_PIN(&LED_GREEN, LOGIC_LOW);
		break;
	case YELLOW:
		MCAL_DIO_Std_WRITE_PIN(&LED_YELLOW, LOGIC_LOW);
		break;
	case BLUE:
		MCAL_DIO_Std_WRITE_PIN(&LED_BLUE, LOGIC_LOW);
		break;

	}

}

/*********************************************************************************************/
void LED_toggle(LED_COLOR LED)
{
	switch(LED){
		case RED:
			MCAL_DIO_Std_FLIP_PIN_DIRECTION(&LED_RED);
			break;
		case GREEN:
			MCAL_DIO_Std_FLIP_PIN_DIRECTION(&LED_GREEN);
			break;
		case YELLOW:
			MCAL_DIO_Std_FLIP_PIN_DIRECTION(&LED_YELLOW);
			break;
		case BLUE:
			MCAL_DIO_Std_FLIP_PIN_DIRECTION(&LED_BLUE);
			break;
		default:
			break;
		}
}

/*********************************************************************************************/
