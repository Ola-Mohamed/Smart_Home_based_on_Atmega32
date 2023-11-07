
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

// This function initializes the Ultrasonic sensor module.
void UltraSonic_Init (void);

// This function starts the Ultrasonic measurement process.
void UltraSonic_begin (void);

// This function returns the distance measured by the Ultrasonic sensor in centimeters.
uint16 UltraSonic_distance (void);


#endif /* ULTRASONIC_H_ */
