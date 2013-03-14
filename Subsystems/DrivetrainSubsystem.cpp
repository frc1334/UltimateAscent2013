#include "DrivetrainSubsystem.h"
#include "../Commands/DrivetrainDriveCommand.h"
#include "../Robotmap.h"
#include "WPILib.h"

DrivetrainSubsystem::DrivetrainSubsystem():Subsystem("DrivetrainSubsystem"),
LeftMotor1(LEFT_MOTOR_1), LeftMotor2(LEFT_MOTOR_2), RightMotor1(RIGHT_MOTOR_1), RightMotor2(RIGHT_MOTOR_2), TiltMotor(TILT_MOTOR),
ShiftSolenoid(DRIVE_SOLENOID)
{
}

void DrivetrainSubsystem::InitDefaultCommand()
{
  SetDefaultCommand(new DrivetrainDriveCommand());
}

//Drives robot based on driver joystick input
void DrivetrainSubsystem::Drive(float speed, float turn)
{
  LeftMotor1.Set(turn + speed);
  LeftMotor2.Set(turn + speed);
  RightMotor1.Set(turn - speed);
  RightMotor2.Set(turn - speed);
}

//Toggles drivetrain gear shift state
void DrivetrainSubsystem::SetShiftState(bool state)
{
	ShiftSolenoid.Set(state);
}

//Sets tilt motor speed from two buttons
void DrivetrainSubsystem::SetTiltSpeed(float speed)
{
	TiltMotor.Set(speed);
}

void DrivetrainSubsystem::Reset()
{
}
