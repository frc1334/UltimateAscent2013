#include "ShooterSubsystem.h"
#include "../Robotmap.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem"),
 shootMotor(SHOOT_MOTOR), tiltMotorLeft(TILT_MOTOR_LEFT), tiltMotorRight(TILT_MOTOR_RIGHT),
 tiltEncoderLeft(TILT_ENCODER_LEFT_A, TILT_ENCODER_LEFT_B), tiltEncoderRight(TILT_ENCODER_RIGHT_A, TILT_ENCODER_RIGHT_B),
 tiltMotorLeftLoop(tiltP, tiltI, tiltD, &tiltEncoderLeft, &tiltMotorLeft),
 tiltMotorRightLoop(tiltP, tiltI, tiltD, &tiltEncoderRight, &tiltMotorRight),
 tiltSwitchLeft(TILT_SWITCH_LEFT), tiltSwitchRight(TILT_SWITCH_RIGHT),
 shootEncoder(SHOOT_ENCODER), shootLoop(shootP, shootI, shootD, this, &shootMotor),
 shootSolenoid(SHOOT_SOLENOID)
{
	shootEncoder.Start();
	tiltEncoderLeft.SetPIDSourceParameter(Encoder::kDistance);
	tiltEncoderRight.SetPIDSourceParameter(Encoder::kDistance);
	tiltMotorLeftLoop.SetInputRange(0, 2000); // this will be set to min/max angle of the shooter
	tiltMotorRightLoop.SetInputRange(0, 2000);
	shootLoop.SetInputRange(0.0f, 0.0f);
	tiltMotorLeftLoop.SetOutputRange(-1.0f, 1.0f);
	tiltMotorRightLoop.SetOutputRange(-1.0f, 1.0f);
	shootLoop.SetOutputRange(0.0f, 0.0f);
	shootLoop.Enable();
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
