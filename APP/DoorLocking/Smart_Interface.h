#ifndef SMART_INTERFACE_H_
#define SMART_INTERFACE_H_


// Enumeration type for password check result.
typedef enum{
	Invalid=0   // Represents an invalid password check.
	,Valid      // Represents a valid password check.
}Check_Passowrd_type;

// Function prototype to initialize the Smart Home system.
void Smart_Init (void);

// Function prototype for the main logic of the Smart Home system.
void Smart_Home_Runnable (void);

#endif /* SMART_INTERFACE_H_ */
