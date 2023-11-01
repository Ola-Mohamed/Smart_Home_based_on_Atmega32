
#ifndef LCD_CFG_H_
#define LCD_CFG_H_


#include "MemMap.h"
#include "DIO_TYPES.h"



#define  _4_BIT   1
#define  _8_BIT   2




/* _4_BIT, _8_BIT*/
#define  LCD_MODE  _4_BIT


 
extern Dio_ConfigType LCD_PORT  ;
extern Dio_ConfigType RS ; 
extern Dio_ConfigType EN ; 
extern Dio_ConfigType D4 ; 
extern Dio_ConfigType D5 ; 
extern Dio_ConfigType D6 ; 
extern Dio_ConfigType D7 ; 

#endif /* LCD_CFG_H_ */
