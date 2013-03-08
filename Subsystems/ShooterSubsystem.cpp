#include "ShooterSubsystem.h"
#include "../Commands/ShooterControlCommand.h"
#include "../Robotmap.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem"),
 shootMotor(SHOOT_MOTOR), tiltMotorLeft(TILT_MOTOR_LEFT), tiltMotorRight(TILT_MOTOR_RIGHT), shootEncoder(SHOOT_ENCODER),
 tiltEncoderLeft(TILT_ENCODER_LEFT_A, TILT_ENCODER_LEFT_B, false, CounterBase::k1X), tiltEncoderRight(TILT_ENCODER_RIGHT_A, TILT_ENCODER_RIGHT_B, false, CounterBase::k1X),
 shootLoop(shootP, shootI, shootD, this, this),
 tiltLoopLeft(tiltP, tiltI, tiltD, &tiltEncoderLeft, &tiltMotorLeft), tiltLoopRight(tiltP, tiltI, tiltD, &tiltEncoderRight, &tiltMotorRight),
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
	tiltLoopLeft.SetInputRange(-2500.0f, 2500.0f);
	tiltLoopRight.SetInputRange(-2500.0f, 2500.0f);
	tiltLoopLeft.SetOutputRange(-1.0f, 1.0f);
	tiltLoopRight.SetOutputRange(-1.0f, 1.0f);
	derp = false;
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
	tiltLoopLeft.Enable();
	tiltLoopRight.Enable();
}

void ShooterSubsystem::SetTilt(float degreesTilt) // set the shooter angle in degrees
{
	tiltLoopLeft.SetSetpoint(degreesTilt);
	tiltLoopRight.SetSetpoint(degreesTilt);
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

void ShooterSubsystem::Debug()
{
	float p, i, d;
	if (CommandBase::oi->GetTest1() && !derp)
		p += 0.0001f;
	if (CommandBase::oi->GetTest2() && !derp)
		p -= 0.0001f;
	if (CommandBase::oi->GetTest3() && !derp)
		i += 0.0001f;
	if (CommandBase::oi->GetTest4() && !derp)
		i -= 0.0001f;
	if (CommandBase::oi->GetTest5() && !derp)
		d += 0.0001f;
	if (CommandBase::oi->GetTest6() && !derp)
		d -= 0.0001f;
	tiltLoopLeft.SetPID(tiltLoopLeft.GetP() + p, tiltLoopLeft.GetI() + i, tiltLoopLeft.GetD() + d);
	tiltLoopRight.SetPID(tiltLoopRight.GetP() + p, tiltLoopRight.GetI() + i, tiltLoopRight.GetD() + d);
	derp = CommandBase::oi->GetTest1() || CommandBase::oi->GetTest2() || CommandBase::oi->GetTest3() || CommandBase::oi->GetTest4() || CommandBase::oi->GetTest5() || CommandBase::oi->GetTest6();
	if (CommandBase::oi->GetTest7())
	{
		tiltEncoderLeft.Reset();
		tiltEncoderRight.Reset();
	}
	std::cout << tiltSetpoint << " " << tiltEncoderLeft.GetDistance() << ", " << tiltEncoderRight.GetDistance() << " " << tiltMotorLeft.Get() << ", " << tiltMotorRight.Get() << tiltLoopLeft.GetP() << tiltLoopLeft.GetI() << tiltLoopLeft.GetD() << std::endl;
}
