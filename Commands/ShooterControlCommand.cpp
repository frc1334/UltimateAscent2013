#include "ShooterControlCommand.h"

ShooterControlCommand::ShooterControlCommand()
{
	Requires(shootersubsystem);
	StartPre = LeftBumperPre = RightBumperPre = false;
	Manual = true;
	tilt = 0;
	setPoint = 0;
	setPoints[0].speed = 0.0f;
	setPoints[0].tilt  = 0.0f;
}

void ShooterControlCommand::Initialize()
{
	shootersubsystem->Reset();
}
 
void ShooterControlCommand::Execute()
{
	shootersubsystem->SetShooting(oi->GetTrigger() < -0.9f);
	shootersubsystem->SetFire(oi->GetFire());
	if (oi->GetStart() && !StartPre)
		Manual = !Manual;
	StartPre = oi->GetStart();
	if (Manual)
	{
		if (oi->GetLeftBumper())
			tilt += 10.0f;
		if (oi->GetRightBumper())
			tilt -= 10.0f;
		/*if (tilt > ShooterSubsystem::maxDegrees)
			tilt = ShooterSubsystem::maxDegrees;
		if (tilt < ShooterSubsystem::minDegrees)
			tilt = ShooterSubsystem::minDegrees;*/
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
