#include "DrivetrainSubsystem.h"
#include "../Robotmap.h"


DrivetrainSubsystem::DrivetrainSubsystem():Subsystem("DrivetrainPIDSubsystem"),
LeftMotor(LEFT_FRONT_MOTOR),RightMotor(RIGHT_FRONT_MOTOR), PIDCoderLeft(ANALOGCHANNEL_POT_LEFT),  PIDCoderRight(ANALOGCHANNEL_POT_RIGHT),
LeftController(0, 0, 0, &PIDCoderLeft, &LeftMotor), RightController(0, 0, 0, &PIDCoderRight, &RightMotor)
{
	SetSetpoint(0);
	SetInputRange(0, 0);

	
	Enable();
}
 
