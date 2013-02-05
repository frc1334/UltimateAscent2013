#ifndef ROBOTMAP_H
#define ROBOTMAP_H


/**
* The RobotMap is a mapping from the ports sensors and actuators are wired into
* to a variable name. This provides flexibility changing wiring, makes checking
* the wiring easier and significantly reduces the number of magic numbers
* floating around.
*/

// ALL OF THESE ARE ZERO BASED!

#define SHOOT_MOTOR                   1
#define TILT_MOTOR_LEFT               2
#define TILT_MOTOR_RIGHT              2
#define TILT_ENCODER_LEFT_A           1
#define TILT_ENCODER_LEFT_B           2
#define TILT_ENCODER_RIGHT_A          3
#define TILT_ENCODER_RIGHT_B          4
#define TILT_SWITCH_LEFT			  5
#define TILT_SWITCH_RIGHT			  6
#define SHOOT_ENCODER				  7
#define SHOOT_SOLENOID				  8

#define JOYSTICK_SHOOT                 1


#endif
