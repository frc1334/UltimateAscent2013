#include "DrivetrainSubsystem.h"
#include "../Robotmap.h"


Drivetrainubsystem::DrivetrainSubsystem() : PIDSubsystem("DrivetrainPIDSubsystem", 0, 0, 0),
LeftFrontMotor(LEFT_FRONT_MOTOR),RightFrontMotor(RIGHT_FRONT_MOTOR),LeftBackMotor(LEFT_BACK_MOTOR),RightBackMotor(RIGHT_BACK_MOTOR), PIDCoder(ANALOGCHANNEL_POT)
{
	SetSetpoint(0);
	SetInputRange(0, 0);
	Enable();
};


 
