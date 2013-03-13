#include "ShooterControlCommand.h"

ShooterControlCommand::ShooterControlCommand()
{
	Requires(shootersubsystem);
	StartPre = LeftBumperPre = RightBumperPre = false;
	Manual = false;
	tilt = 0;
	setPoint = 0;
	setPoints[0].speed = 0.0f;
	setPoints[0].tilt  = 0.0f;
}

void ShooterControlCommand::Initialize()
{
	shootersubsystem->Reset();
	shootersubsystem->SetTilt(false);
}
 
 void ShooterControlCommand::Execute()
{
	shootersubsystem->SetShooting(oi->GetTrigger() < -0.9f);
	shootersubsystem->SetFire(oi->GetFire());
	std::cout << "Get Tilt(): " << shootersubsystem->GetTilt() << std::endl;
	if (oi->GetShooterTilt())
	{
		shootersubsystem->SetTilt(shootersubsystem->GetTilt());
	}
	if (oi->GetTrigger() < -0.9f)
		Manual=true;
	else
		Manual = false;
	if (Manual)
	{
		if(setPoint != 5000.0f)
		{			
			setPoint=5000.0;
			shootersubsystem->SetSpeed(setPoint);
		}
	}
	else
	{
		shootersubsystem->SetSpeed(0);
		setPoint=0.0;
	}
	
	/*
	if (oi->GetStart() && !StartPre)
		Manual = !Manual;
	StartPre = oi->GetStart();
	if (Manual)
	{
		if (oi->GetLeftBumper())
			tilt += .1f;
		if (oi->GetRightBumper())
			tilt -= .1f;
		shootersubsystem->SetSpeed(5450.0f);
		if (tilt > ShooterSubsystem::maxDegrees)
			tilt = ShooterSubsystem::maxDegrees;
		if (tilt < ShooterSubsystem::minDegrees)
			tilt = ShooterSubsystem::minDegrees;
	}
	else
	{
		if (oi->GetLeftBumper() && !LeftBumperPre)
			setPoint += 1;
		if (oi->GetRightBumper() && !RightBumperPre)
			setPoint -= 1;
		setPoint %= SETPOINT_COUNT;
		tilt = setPoints[setPoint].tilt + (oi->GetFudge() * FUDGEFACTOR);
		shootersubsystem->SetSpeed(setPoints[setPoint].speed);
	}
	LeftBumperPre = oi->GetLeftBumper();
	RightBumperPre = oi->GetRightBumper();
	shootersubsystem->SetTilt(tilt);
	*/
}

bool ShooterControlCommand::IsFinished()
{ 
	return false;
}
 
void ShooterControlCommand::End()
{
}
 
void ShooterControlCommand::Interrupted()
{
}
