#include "DrivetrainSubsystem.h"
#include "../Commands/DrivetrainDriveCommand.h"
#include "../Robotmap.h"
#include "WPILib.h"

DrivetrainSubsystem::DrivetrainSubsystem():Subsystem("DrivetrainSubsystem"),
LeftMotor1(LEFT_MOTOR_1), LeftMotor2(LEFT_MOTOR_2), RightMotor1(RIGHT_MOTOR_1), RightMotor2(RIGHT_MOTOR_2), TiltMotor(TILT_MOTOR),
ShiftSolenoid(DRIVE_SOLENOID),
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
  LeftMotor1.Set((speed + turn) * .99); // limit the output, as without this, jaguars can blow their breakers
  LeftMotor2.Set((speed + turn) * .99);
  RightMotor1.Set((speed - turn) * .99);
  RightMotor2.Set((speed - turn) * .99);
}

void DrivetrainSubsystem::SetShiftState(bool state)
{
	ShiftSolenoid.Set(state);
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
