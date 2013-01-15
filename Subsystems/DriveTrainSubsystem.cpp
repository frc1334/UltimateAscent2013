#include "DriveTrainSubsystem.h"
#include "../Robotmap.h"

DriveTrainSubsystem::DriveTrainSubsystem() : Subsystem("DriveTrainSubsystem")
    LeftMotor(LEFT_MOTOR),RightMotor(RIGHT_MOTOR)
{
}

void DriveTrainSubsystem::InitDefaultCommand()
{
    SetDefault(NewCommand());
}

void DriveTrainSubsystem::Drive(float Left, float Right)
{
	RightMotor.Set(Right);
	LeftMotor.Set(Left);
}
