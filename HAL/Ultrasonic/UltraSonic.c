#include "DIO_INTERFACE.h"
#include "MemMap.h"
#include "ICU.h"
#include "UltraSonic.h"
#include "UltraSonic_Cfg.h"
#include <util/delay.h>

static uint16 t1,t2,distance,flag=0;  // Declaration of static variables for time measurements and flag.

static void ICU_F (void);  // Declaration of the static function ICU_F.

void UltraSonic_Init (void)
{
	Timer1_ICU_SetCallBack(ICU_F);  // Initialize the Ultrasonic sensor using Timer1 and set the callback function to ICU_F.
}

void UltraSonic_begin (void)
{
	TCNT1=0;  // Reset Timer1 counter.
	Timer1_InputCaptureEdge(RISING);  // Set input capture edge to rising edge for measuring the echo pulse.
	DIO_WritePin(UltraSonic_Trigger,LOGIC_HIGH);  // Trigger the Ultrasonic sensor by setting the trigger pin to high.
	_delay_us(10);  // Delay for a short period of time to ensure the trigger pulse is detected.
	DIO_WritePin(UltraSonic_Trigger,LOGIC_LOW);  // Set the trigger pin back to low.
	Timer1_ICU_InterruptEnable();  // Enable the input capture interrupt for Timer1.
}

static void ICU_F (void)
{
	if (flag==0)
	{
		t1=ICR1;  // Record the time of the rising edge of the echo pulse.
		Timer1_InputCaptureEdge(FALLING);  // Set input capture edge to falling edge for measuring the pulse width.
		flag=1;  // Set the flag to indicate that the rising edge has been detected.
	}
	else if (flag==1)
	{
		t2=ICR1;  // Record the time of the falling edge of the echo pulse.
		Timer1_ICU_InterruptDisable();  // Disable the input capture interrupt.
		distance=(t2-t1)/58/2;  // Calculate the distance based on the time difference between rising and falling edges.
		flag=0;  // Reset the flag for the next measurement.
	}
}

uint16 UltraSonic_distance (void)
{
	return distance;  // Return the calculated distance in centimeters.
}
