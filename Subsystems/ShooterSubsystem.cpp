#include "ShooterSubsystem.h"
#include "../Commands/ShooterControlCommand.h"
#include "../Robotmap.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem"),
 shootMotor(SHOOT_MOTOR), tiltMotorLeft(TILT_MOTOR_LEFT), tiltMotorRight(TILT_MOTOR_RIGHT), shootEncoder(SHOOT_ENCODER),
 tiltEncoderLeft(TILT_ENCODER_LEFT_A, TILT_ENCODER_LEFT_B, true, CounterBase::k1X), tiltEncoderRight(TILT_ENCODER_RIGHT_A, TILT_ENCODER_RIGHT_B, true, CounterBase::k1X),
 shootLoop(shootP, shootI, shootD, this, this),
 tiltLoopLeft(tiltP, tiltI, tiltD, &tiltEncoderLeft, &tiltMotorLeft), tiltLoopRight(tiltP, tiltI, tiltD, &tiltEncoderRight, &tiltMotorRight),
 tiltSwitchLeft(TILT_SWITCH_LEFT), tiltSwitchRight(TILT_SWITCH_RIGHT),
 shootSolenoid(SHOOT_SOLENOID),
 tiltSolenoid(SHOOT_TILT_SOLENOID),
 shooting(false)
{
	p = i = d = 0;
	shootLoop.SetInputRange(0.0f, 7000.0f);
	shootLoop.SetOutputRange(0.0f, 1.0f);
	SetSpeed(0.0f);
	shootEncoder.Reset();
	shootEncoder.SetMaxPeriod(1.0f);
	shootEncoder.Start();
	shootLoop.SetTolerance(0.01f);
	shootLoop.Enable();

	tiltEncoderLeft.SetDistancePerPulse(0.01);
	tiltEncoderRight.SetDistancePerPulse(0.01);
	tiltLoopLeft.SetContinuous(false);
	tiltLoopRight.SetContinuous(false);
	tiltLoopLeft.SetInputRange(-2500.0f, 2500.0f);
	tiltLoopRight.SetInputRange(-2500.0f, 2500.0f);
	tiltLoopLeft.SetOutputRange(-1.0f, 1.0f);
	tiltLoopRight.SetOutputRange(-1.0f, 1.0f);
	tiltLoopLeft.SetSetpoint(0.0f);
	tiltLoopRight.SetSetpoint(0.0f);
	tiltLoopLeft.SetTolerance(0.01f);
	tiltLoopRight.SetTolerance(0.01f);
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
	tiltLoopLeft.Disable();
	tiltLoopRight.Disable();
}

void ShooterSubsystem::SetTilt(bool tilt) // Set the shoot solenoid to  activate the 2 pistons that elevate the shooter
{
	if(!tiltSolenoid.Get())
	{
		tiltSolenoid.Set(true);	
	}
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
void ShooterSubsystem::AutomaticShooting(float delay)
{
	 SetFire(true);
	 SetShooting(true);
}
void ShooterSubsystem::Debug()
{
	if (CommandBase::oi->GetTest1() && !derp)
		p += 0.0001f;
	if (CommandBase::oi->GetTest2() && !derp)
		p -= 0.0001f;
	if (CommandBase::oi->GetTest5() && !derp)
		i += 0.0001f;
	if (CommandBase::oi->GetTest6() && !derp)
		i -= 0.0001f;
	if (CommandBase::oi->GetTest3() && !derp)
		d += 0.0001f;
	if (CommandBase::oi->GetTest4() && !derp)
		d -= 0.0001f;
	
	//tiltLoopLeft.SetPID(p, i, d);
	//tiltLoopRight.SetPID(p, i, d);
	derp = CommandBase::oi->GetTest1() || CommandBase::oi->GetTest2() || CommandBase::oi->GetTest3() || CommandBase::oi->GetTest4() || CommandBase::oi->GetTest5() || CommandBase::oi->GetTest6();
	if (CommandBase::oi->GetTest7())
	{
		tiltEncoderLeft.Reset();
		tiltEncoderRight.Reset();
	}
	
	std::cout << "Setpoint: " << shootLoop.GetSetpoint();
	if (shootEncoder.GetPeriod()>0 && shootEncoder.GetPeriod()<1){
		std::cout << "|| Enc Rate: " << 30.0f / shootEncoder.GetPeriod() <<std::endl;
	}
	std::cout << "===========" << std::endl;
	
	//std::cout << "Setpoint:" << shootLoop.GetSetpoint() << " P: " << shootLoop.GetP() << " I: " << shootLoop.GetI() << " D: " << shootLoop.GetD() << (30.0f / shootEncoder.GetPeriod()) << std::endl;
	/*std::cout << "Left OT: " << tiltLoopLeft.OnTarget() << " || Right OT: " << tiltLoopRight.OnTarget() << std::endl;
	std::cout << "Setpoint: " << tiltLoopLeft.GetSetpoint() << " || P,I,D: " << tiltLoopLeft.GetP() << ", " << tiltLoopLeft.GetI() << ", " << tiltLoopLeft.GetD() << std::endl;
	std::cout << tiltEncoderLeft.GetDistance() << ", " << tiltEncoderRight.GetDistance() << " " << tiltMotorLeft.Get() << ", " << tiltMotorRight.Get() << std::endl;
	std::cout <<"==================" << std::endl;*/
}
