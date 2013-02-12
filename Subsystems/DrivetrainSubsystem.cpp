#include "DrivetrainSubsystem.h"
#include "../Commands/DrivetrainDriveCommand.h"
#include "../Robotmap.h"
#include "WPILib.h"

DrivetrainSubsystem::DrivetrainSubsystem():Subsystem("DrivetrainSubsystem"),
LeftMotor(LEFT_MOTOR), RightMotor(RIGHT_MOTOR), TiltMotor(TILT_MOTOR),
LeftSolenoid(DRIVE_LEFT_SOLENOID), RightSolenoid(DRIVE_RIGHT_SOLENOID),
TiltEncoder(TILT_ENCODER), TiltController(tiltP, tiltI, tiltD, &TiltEncoder, &TiltMotor),
TiltSwitch(TILT_LIMIT_SWITCH)
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
	LeftSolenoid.Set(state);
	RightSolenoid.Set(state);
}

void DrivetrainSubsystem::SetTiltState(bool tilting)
{
	TiltController.SetSetpoint(tilting ? tiltUp : tiltDown);
}

void DrivetrainSubsystem::Reset()
{
	TiltMotor.Set(1.0f);
	while (TiltSwitch.Get()) {}
	TiltMotor.Set(0.0f);
	TiltController.Reset();
	TiltController.Enable();
}
