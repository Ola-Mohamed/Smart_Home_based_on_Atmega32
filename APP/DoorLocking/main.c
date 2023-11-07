
#include "Std_Types.h"
#include <util/delay.h>
#include "MemMap.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "UART_Interface.h"
#include "I2C.h"
#include "UltraSonic.h"
#include "EEPROM.h"
#include "Smart_Interface.h"
#include "Smart_Private.h"

uint16 distance;  // Variable to store the distance measured by the Ultrasonic sensor.
uint8 flag=0;  // Flag variable to control the program flow.

int main(void)
{
    DIO_Init();  // Initialize the Digital Input/Output pins.
    LCD_Init();  // Initialize the LCD display.
    UART_Init();  // Initialize the UART communication.
    UltraSonic_Init();  // Initialize the Ultrasonic sensor module.
    Smart_Init();  // Initialize the Smart Home system.

    sei();  // Enable global interrupts.

    Timer1_Init(norm,t_prescaler_8);  // Initialize Timer1 with normal mode and prescaler 8.

    while (1)
    {
        if (flag==0)
        {
            UltraSonic_begin();  // Start Ultrasonic measurement.
            _delay_ms(100);  // Delay for a short period to allow the measurement to complete.
            distance=UltraSonic_distance();  // Get the measured distance.

            if (distance<=140)
            {
                if (distance<=140 && distance>=120)
                {
                    DIO_WritePort(PORTA_ID,0);  // Turn off all pins in PORTA.
                    DIO_WritePin(PIN0_ID,LOGIC_HIGH);  // Set PIN0 of PORTA to high.
                }
                else if (distance<=119 && distance>=99)
                {
                    DIO_WritePort(PORTA_ID,0);
                    DIO_WritePin(PIN1_ID,LOGIC_HIGH);
                    DIO_WritePin(PIN0_ID,LOGIC_HIGH);
                }
                // ... (similar conditions for different distance ranges)
                else if (distance<=14 && distance>=2)
                {
                    DIO_WritePort(PORTA_ID,0);
                    DIO_WritePin(PIN1_ID,LOGIC_HIGH);
                    DIO_WritePin(PIN0_ID,LOGIC_HIGH);
                    DIO_WritePin(PIN2_ID,LOGIC_HIGH);
                    DIO_WritePin(PIN3_ID,LOGIC_HIGH);
                    DIO_WritePin(PIN4_ID,LOGIC_HIGH);
                    DIO_WritePin(PIN5_ID,LOGIC_HIGH);
                    DIO_WritePin(PIN7_ID,LOGIC_HIGH);
                    flag=1;  // Set the flag to indicate that the Smart Home system should be activated.
                }
            }
            else
            {
                DIO_WritePort(PORTC_ID,0);  // Turn off all pins in PORTC.
            }
        }

        if (flag==1)
        {
            Smart_Home_Runnable();  // Execute Smart Home system logic.
        }
    }
}
