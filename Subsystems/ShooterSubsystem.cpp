#include "ShooterSubsystem.h"
#include "../Robotmap.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem")
  shootMotor(SHOOT_MOTOR), panMotor(PAN_MOTOR)
{
}

void ShooterSubsystem::InitDefaultCommand()
{
  SetDefaultCommand(new ShooterSubsystem());
}

void DriveTrainSubsystem::Shoot(float power)
{
	shootMotor.Set(power);
}
