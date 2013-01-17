#include "DriveTrainSubsystem.h"
#include "../Robotmap.h"
#include "../Commands/AutonomousCommand.h"


DriveTrainSubsystem::DriveTrainSubsystem() : Subsystem("DriveTrainSubsystem"),
    LeftMotor(LEFT_MOTOR),RightMotor(RIGHT_MOTOR)
{
}

void DriveTrainSubsystem::InitDefaultCommand()
{
    SetDefaultCommand(new AutonomousCommand());
}

void DriveTrainSubsystem::Drive(float Left, float Right)
{
	RightMotor.Set(Right);
	LeftMotor.Set(Left);
}
