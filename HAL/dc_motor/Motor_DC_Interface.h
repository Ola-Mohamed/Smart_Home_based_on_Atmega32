
#ifndef MOTOR_DC_INTERFACE_H_
#define MOTOR_DC_INTERFACE_H_
#include "DIO_TYPES.h"

typedef enum{
	M1,
	M2
}MOTOR_t;


STD_TYPE MOTOR_Init();

STD_TYPE MOTOR_CW(MOTOR_t motor);
STD_TYPE MOTOR_CCW(MOTOR_t motor);
STD_TYPE MOTOR_Stop(MOTOR_t motor);









#endif /* MOTOR_DC_INTERFACE_H_ */