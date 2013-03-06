#include "ShooterSubsystem.h"
#include "../Commands/ShooterControlCommand.h"
#include "../Robotmap.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem"),
 shootMotor(SHOOT_MOTOR), tiltMotorLeft(TILT_MOTOR_LEFT), tiltMotorRight(TILT_MOTOR_RIGHT), shootEncoder(SHOOT_ENCODER),
 tiltEncoderLeft(TILT_ENCODER_LEFT_A, TILT_ENCODER_LEFT_B), tiltEncoderRight(TILT_ENCODER_RIGHT_A, TILT_ENCODER_RIGHT_B),
 shootLoop(shootP, shootI, shootD, this, this),
 tiltSwitchLeft(TILT_SWITCH_LEFT), tiltSwitchRight(TILT_SWITCH_RIGHT),
 shootSolenoid(SHOOT_SOLENOID), shooting(false)
{
	shootLoop.SetInputRange(0.0f, 6000.0f);
	shootLoop.SetOutputRange(0.0f, 1.0f);
	SetSpeed(0.0f);
	shootEncoder.Reset();
	shootEncoder.SetMaxPeriod(1.0f);
	shootEncoder.Start();
	shootLoop.SetTolerance(0.01f);
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
}

void ShooterSubsystem::SetTilt(float degreesTilt) // set the shooter angle in degrees
{
	tiltSetpoint = degreesTilt;
}

double ShooterSubsystem::PIDGet()
{
	return (30.0f / shootEncoder.GetPeriod());
}

void ShooterSubsystem::PIDWrite(float output)
{
	shootMotor.Set(output * -1.0f);
}

void ShooterSubsystem::SetSpeed(float speed)
{
	shootLoop.SetSetpoint((shooting) ? speed : (0.0f));
}

void ShooterSubsystem::SetFire(bool fire)
{
	shootSolenoid.Set(fire);
}

void ShooterSubsystem::SetShooting(bool enabled)
{
	shooting = enabled;
}

void ShooterSubsystem::DoRunning()
{
	//tiltMotorLeft.Set((((fabs(tiltSetpoint - tiltEncoderLeft.GetDistance()) <= 200.0f)) ? .25f : -.25f));
	//tiltMotorRight.Set((((fabs(tiltSetpoint - tiltEncoderRight.GetDistance()) <= 200.0f)) ? .25f : -.25f));
}

void ShooterSubsystem::Debug()
{
	if (CommandBase::oi->GetTest7())
	{
		tiltEncoderLeft.Reset();
		tiltEncoderRight.Reset();
	}
	std::cout << tiltSetpoint << " " << tiltEncoderLeft.GetDistance() << ", " << tiltEncoderRight.GetDistance() << std::endl;
}
