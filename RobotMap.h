#ifndef ROBOTMAP_H
#define ROBOTMAP_H


/**
* The RobotMap is a mapping from the ports sensors and actuators are wired into
* to a variable name. This provides flexibility changing wiring, makes checking
* the wiring easier and significantly reduces the number of magic numbers
* floating around.
*/

#define JOYSTICK_DRIVE				1
#define JOYSTICK_SHOOT				2

#define CLIMB_MOTOR_1				7
#define CLIMB_MOTOR_2				8
#define CLIMB_LIMITSWITCH_BOTTOM	-1
#define CLIMB_LIMITSWITCH_TOP		-1
#define CLIMB_SOLENOID				1
#define LEFT_MOTOR_1				2
#define LEFT_MOTOR_2				3
#define RIGHT_MOTOR_1				9
#define RIGHT_MOTOR_2				10
#define SHOOT_MOTOR					5
#define TILT_MOTOR_LEFT				1
#define TILT_MOTOR_RIGHT			6
#define TILT_ENCODER_LEFT_A			-1
#define TILT_ENCODER_LEFT_B			-1
#define TILT_ENCODER_RIGHT_A		-1
#define TILT_ENCODER_RIGHT_B		-1
#define TILT_SWITCH_LEFT			-1
#define TILT_SWITCH_RIGHT			-1
#define SHOOT_ENCODER				-1
#define SHOOT_SOLENOID				3
#define TILT_MOTOR					4
#define TILT_ENCODER				-1
#define DRIVE_SOLENOID				2
#define TILT_LIMIT_SWITCH_TOP		-1
#define TILT_LIMIT_SWITCH_BOTTOM	-1
#define COMPRESSOR_SWITCH			1
#define COMPRESSOR_RELAY			1

#endif
