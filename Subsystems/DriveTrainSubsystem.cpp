#include "DriveTrainSubsystem.h"
#include "../Robotmap.h"
#include "../Commands/AutonomousCommand.h"


DriveTrainSubsystem::DriveTrainSubsystem() : Subsystem("DriveTrainSubsystem"),
    LeftFrontMotor(LEFT_FRONT_MOTOR),RightFrontMotor(RIGHT_FRONT_MOTOR),LeftBackMotor(LEFT_BACK_MOTOR),RightBackMotor(RIGHT_BACK_MOTOR)
{
}

void DriveTrainSubsystem::InitDefaultCommand()
{
    SetDefaultCommand(new AutonomousCommand());
}

void DriveTrainSubsystem::Drive(float Left, float Right)
{
	RightFrontMotor.Set(Right);
	RightBackMotor.Set(Right);
	LeftBackMotor.Set(Left);
	LeftFrontMotor.Set(Left);
}
