#include "DrivetrainSubsystem.h"
#include "../Robotmap.h"
#include "WPILib.h"

DrivetrainSubsystem::DrivetrainSubsystem():Subsystem("DrivetrainSubsystem"),
LeftMotor(LEFT_MOTOR),RightMotor(RIGHT_MOTOR), PIDCoderLeft(ANALOGCHANNEL_POT_LEFT),  PIDCoderRight(ANALOGCHANNEL_POT_RIGHT),
LeftController(0, 0, 0, &PIDCoderLeft, &LeftMotor), RightController(0, 0, 0, &PIDCoderRight, &RightMotor)
{
	PIDCoderRight.Enable();
	PIDCoderLeft.Enable();	
}

void DriveTrainSubsystem::InitDefaultCommand()
{
  SetDefaultCommand(new TankDriveCommand());
}

void DriveTrainSubsystem::Drive(float speed, float turn)
{
	
  LeftController.SetSetpoint((speed + turn) * .99); // limit the output, as without this, jaguars can blow their breakers
  RightController.SetSetpoint((speed - turn) * .99);
}



