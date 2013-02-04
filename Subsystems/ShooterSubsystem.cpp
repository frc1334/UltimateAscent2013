#include "ShooterSubsystem.h"
#include "../Commands/ShooterControlCommand.h"
#include "../Robotmap.h"
#include "../Utility.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem"),
 shootMotor(SHOOT_MOTOR), tiltMotorLeft(TILT_MOTOR_LEFT), tiltMotorRight(TILT_MOTOR_RIGHT), shootEncoder(SHOOT_ENCODER),
 tiltEncoderLeft(TILT_ENCODER_LEFT_A, TILT_ENCODER_LEFT_B), tiltEncoderRight(TILT_ENCODER_RIGHT_A, TILT_ENCODER_RIGHT_B),
 tiltMotorLeftLoop(tiltP, tiltI, tiltD, &tiltEncoderLeft, &tiltMotorLeft),
 tiltMotorRightLoop(tiltP, tiltI, tiltD, &tiltEncoderRight, &tiltMotorRight),
 shootLoop(shootP, shootI, shootD, this, &shootMotor),
 tiltSwitchLeft(TILT_SWITCH_LEFT), tiltSwitchRight(TILT_SWITCH_RIGHT),
 shootSolenoid(SHOOT_SOLENOID)
{
	shootEncoder.Start();
	tiltEncoderLeft.SetPIDSourceParameter(Encoder::kDistance);
	tiltEncoderRight.SetPIDSourceParameter(Encoder::kDistance);
	tiltMotorLeftLoop.SetInputRange(0, tiltTravel);
	tiltMotorRightLoop.SetInputRange(0, tiltTravel);
	shootLoop.SetInputRange(0.0f, 0.0f);
	tiltMotorLeftLoop.SetOutputRange(-1.0f, 1.0f);
	tiltMotorRightLoop.SetOutputRange(-1.0f, 1.0f);
	shootLoop.SetOutputRange(0.0f, 0.0f);
	SetSpeed(300);
	shootLoop.Enable();
	tiltMotorLeftLoop.Enable();
}

void ShooterSubsystem::InitDefaultCommand()
{
	SetDefaultCommand(new ShooterControlCommand());
}

void ShooterSubsystem::Reset()
{
	tiltMotorLeft.Set(1.0f);
	tiltMotorRight.Set(1.0f);
	while (tiltSwitchLeft.Get() || tiltSwitchRight.Get())
	{
		if (tiltSwitchLeft.Get())
			tiltMotorLeft.Set(0.0f);
		if (tiltSwitchRight.Get())
			tiltMotorRight.Set(0.0f);
	}
	tiltEncoderLeft.Reset();
	tiltEncoderRight.Reset();
	tiltEncoderLeft.Start();
	tiltEncoderRight.Start();
	tiltMotorLeftLoop.Enable();
	tiltMotorRightLoop.Enable();
}

void ShooterSubsystem::SetTilt(float degreesTilt) // set the shooter angle in degrees
{
	degreesTilt = Utility::Map(minDegrees, maxDegrees, 0, tiltTravel, degreesTilt); // map the shooter angles to the encoder ticks
	tiltMotorLeftLoop.SetSetpoint(degreesTilt);
	tiltMotorRightLoop.SetSetpoint(degreesTilt);
}

double ShooterSubsystem::PIDGet()
{
	return shootEncoder.GetPeriod();
}

void ShooterSubsystem::SetSpeed(float speed)
{
	shootLoop.SetSetpoint(speed);
}

void ShooterSubsystem::SetFire(bool fire)
{
	shootSolenoid.Set(fire);
}

void ShooterSubsystem::SetShooting(bool enabled)
{
	if (enabled)
		shootLoop.Enable();
	else
		shootLoop.Disable();
}
