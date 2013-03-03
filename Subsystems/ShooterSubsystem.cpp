#include "ShooterSubsystem.h"
#include "../Commands/ShooterControlCommand.h"
#include "../Robotmap.h"
#include <limits>

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem"),
 shootMotor(SHOOT_MOTOR), tiltMotorLeft(TILT_MOTOR_LEFT), tiltMotorRight(TILT_MOTOR_RIGHT), shootEncoder(SHOOT_ENCODER),
 tiltEncoderLeft(TILT_ENCODER_LEFT_A, TILT_ENCODER_LEFT_B), tiltEncoderRight(TILT_ENCODER_RIGHT_A, TILT_ENCODER_RIGHT_B),
 tiltMotorLeftLoop(tiltP, tiltI, tiltD, &tiltEncoderLeft, &tiltMotorLeft),
 tiltMotorRightLoop(tiltP, tiltI, tiltD, &tiltEncoderRight, &tiltMotorRight),
 shootLoop(shootP, shootI, shootD, this, this),
 tiltSwitchLeft(TILT_SWITCH_LEFT), tiltSwitchRight(TILT_SWITCH_RIGHT),
 shootSolenoid(SHOOT_SOLENOID)
{
	tiltEncoderLeft.SetPIDSourceParameter(Encoder::kDistance);
	tiltEncoderRight.SetPIDSourceParameter(Encoder::kDistance);
	tiltMotorLeftLoop.SetInputRange(0, tiltTravel);
	tiltMotorRightLoop.SetInputRange(0, tiltTravel);
	shootLoop.SetInputRange(0.0f, 6000.0f);
	tiltMotorLeftLoop.SetOutputRange(-1.0f, 1.0f);
	tiltMotorRightLoop.SetOutputRange(-1.0f, 1.0f);
	shootLoop.SetOutputRange(0.0f, 1.0f);
	SetSpeed(0.0f);
	shootEncoder.Reset();
	shootEncoder.SetMaxPeriod(1.0f);
	shootEncoder.Start();
	shootLoop.Enable();
}

void ShooterSubsystem::InitDefaultCommand()
{
	SetDefaultCommand(new ShooterControlCommand());
}

inline float Map(float minIn, float maxIn, float minOut, float maxOut, float val)
{
	return ((val - minIn) / (maxIn - minIn)) * (maxOut - minOut) + minOut;
}

void ShooterSubsystem::Reset()
{
	/*tiltMotorLeft.Set(0.01f);
	tiltMotorRight.Set(0.01f);
	while (tiltSwitchLeft.Get() || tiltSwitchRight.Get())
	{
		if (tiltSwitchLeft.Get())
			tiltMotorLeft.Set(0.0f);
		if (tiltSwitchRight.Get())
			tiltMotorRight.Set(0.0f);
	}*/
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
	std::cout << "s\t" << (30.0f / shootEncoder.GetPeriod()) << std::endl;
	return (30.0f / shootEncoder.GetPeriod());
}

void ShooterSubsystem::PIDWrite(float output)
{
	shootMotor.Set(output * -1.0f);
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
	SetSpeed((enabled) ? (4800.0f) : (0.0f));
}

void ShooterSubsystem::Debug()
{
}
