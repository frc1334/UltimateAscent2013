#include "DrivetrainSubsystem.h"
#include "../Robotmap.h"
#include "WPILib.h"

DrivetrainSubsystem::DrivetrainSubsystem():Subsystem("DrivetrainSubsystem"),
LeftMotor(LEFT_MOTOR), RightMotor(RIGHT_MOTOR)
{
}

void DrivetrainSubsystem::InitDefaultCommand()
{
  //SetDefaultCommand(new TankDriveCommand());
}

void DrivetrainSubsystem::Drive(float speed, float turn)
{
  LeftMotor.Set((speed + turn) * .99); // limit the output, as without this, jaguars can blow their breakers
  RightMotor.Set((speed - turn) * .99);
}
