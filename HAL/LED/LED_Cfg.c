/******************************************************************************
 *
  Module: Led
 *
 * File Name: LED_Config.c
 *
 * Description: source file for Led Configration.
 *
 ******************************************************************************/


#include"LED_Cfg.h"




Dio_ConfigType LED_RED  =  {PIN7_ID , PORTB_ID ,0 ,0};

Dio_ConfigType LED_GREEN  = {PIN4_ID , PORTA_ID ,0 ,0};

Dio_ConfigType LED_YELLOW = {PIN6_ID , PORTA_ID ,0 ,LOGIC_LOW};

Dio_ConfigType LED_BLUE  = {PIN5_ID , PORTA_ID ,0,LOGIC_LOW};




