#include "DrivetrainSubsystem.h"
#include "../Commands/DrivetrainDriveCommand.h"
#include "../Robotmap.h"
#include "WPILib.h"

DrivetrainSubsystem::DrivetrainSubsystem():Subsystem("DrivetrainSubsystem"),
LeftMotor(LEFT_MOTOR), RightMotor(RIGHT_MOTOR)
{
}

void DrivetrainSubsystem::InitDefaultCommand()
{
  SetDefaultCommand(new DrivetrainDriveCommand());
}

void DrivetrainSubsystem::Drive(float speed, float turn)
{
  LeftMotor.Set((speed + turn) * .99); // limit the output, as without this, jaguars can blow their breakers
  RightMotor.Set((speed - turn) * .99);
}

void DrivetrainSubsystem::SetShiftState(bool state)
{
	LeftSolenoid->Set(state);
	RightSolenoid->Set(state);
}
