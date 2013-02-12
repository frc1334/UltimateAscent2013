#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#define LEFT_MOTOR              1
#define RIGHT_MOTOR             2

#define JOYSTICK_DRIVE          1
#define JOYSTICK_SHOOT          2
/**
* The RobotMap is a mapping from the ports sensors and actuators are wired into
* to a variable name. This provides flexibility changing wiring, makes checking
* the wiring easier and significantly reduces the number of magic numbers
* floating around.
*/

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
#define TILT_MOTOR					  42
#define TILT_ENCODER				  42
#define DRIVE_RIGHT_SOLENOID		  42
#define DRIVE_LEFT_SOLENOID			  42
#define TILT_LIMIT_SWITCH			  45

#endif
