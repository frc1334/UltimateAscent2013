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

void DrivetrainSubsystem::Drive(float speed, float turn)
{
  LeftMotor1.Set(turn + speed);
  LeftMotor2.Set(turn + speed);
  RightMotor1.Set(turn - speed);
  RightMotor2.Set(turn - speed);
}

void DrivetrainSubsystem::SetShiftState(bool state)
{
	ShiftSolenoid.Set(state);
}

void DrivetrainSubsystem::SetTiltState(float speed)
{
	TiltMotor.Set(speed);
	//TiltMotor.Set(tilting ? 1.0f : -1.0f);
	//if ((tilting ? TiltSwitchTop : TiltSwitchBottom).Get())
	//	TiltMotor.Set(0.0f);
}

void DrivetrainSubsystem::Reset()
{
	//TiltMotor.Set(1.0f);
	//while (TiltSwitchTop.Get()) {}
	//TiltMotor.Set(0.0f);
}
