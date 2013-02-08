#ifndef ROBOTMAP_H
#define ROBOTMAP_H


/**
* The RobotMap is a mapping from the ports sensors and actuators are wired into
* to a variable name. This provides flexibility changing wiring, makes checking
* the wiring easier and significantly reduces the number of magic numbers
* floating around.
*/

//Buttons

// A button
#define BUTTON_1 1
// B Button
#define BUTTON_2 2
// X Button
#define BUTTON_3 3
// Y Button
#define BUTTON_4 4
// Left Bumper 
#define BUTTON_5 5
// Right Bumper
#define BUTTON_6 6
// Back Button
#define BUTTON_7 7 
// Start Button
#define BUTTON_8 8
// Clicking the Left Joystick Down
#define BUTTON_9 9
// Clicking the Right Joystick Down
#define BUTTON_10 10


// Joysticks
#define RIGHT_JOYSTICK 11
#define LEFT_JOYSTICK 12



// DPad control mapping or + pad.
#define DPAD_LEFT 13
#define DPAD_RIGHT 14
#define DPAD_UP 15
#define DPAD_DOWN 16
#define DPAD_UPLEFT 17
#define DPAD_UPRIGHT 18
#define DPAD_DOWNLEFT 19
#define DPAD_DOWNRIGHT 20

// ALL OF THESE ARE ZERO BASED!

#define SHOOT_MOTOR                   1
#define TILT_MOTOR_LEFT               2
#define TILT_MOTOR_RIGHT              3
#define TILT_ENCODER_LEFT_A           1
#define TILT_ENCODER_LEFT_B           2
#define TILT_ENCODER_RIGHT_A          3
#define TILT_ENCODER_RIGHT_B          4
#define TILT_SWITCH_LEFT			  5
#define TILT_SWITCH_RIGHT			  6
#define SHOOT_ENCODER				  7
#define SHOOT_SOLENOID				  8

#define CLIMB_SOLENOID_LEFT			  1
#define CLIMB_MOTOR_LEFT			  2
#define CLIMB_MOTOR_RIGHT             3
#define CLIMB_ENCODER_RIGHT_A         4
#define CLIMB_ENCODER_RIGHT_B         5
#define CLIMB_ENCODER_LEFT_A          6
#define CLIMB_ENCODER_LEFT_B          7
#define CLIMB_LIMITSWITCH_TILT        8
#define CLIMB_MOTOR_TILT              9
#define CLIMB_SOLENOID_RIGHT          10
#define CLIMB_LIMITSWITCH_LEFT        11
#define CLIMB_LIMITSWITCH_RIGHT       12
#define CLIMB_ENCODER_TILT_A          13
#define CLIMB_ENCODER_TILT_B          14

#define JOYSTICK_SHOOT                 1


#endif
