
#ifndef SMART_PRIVATE_H_
#define SMART_PRIVATE_H_


// Static function to check the validity of a password.
static Check_Passowrd_type check_password (void);

// Static function to change the password.
static void Password_change(void);

// Static function to display a welcome message.
static void Welcome (void);

// Static function to control an LED.
static void Led_control (void);

// Static function to write a string to an output device.
static void Write_String (void);

// Static function to write a character to an output device.
static void Write_char (void);

// Static function to control an LCD display.
static void Lcd_control (void);

// Static function for a specific mode involving RGB lights and buttons.
static void Rgb_2button_mode (void);

// Static function for a specific mode involving RGB lights and user input.
static void Rgb_input_mode (void);

// Static function to control RGB lights.
static void RGB_control (void);

// Static function to send a password.
static void Send_password (void);


#endif /* SMART_PRIVATE_H_ */
