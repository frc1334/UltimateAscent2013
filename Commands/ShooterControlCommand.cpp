#include "ShooterControlCommand.h"
 
ShooterControlCommand::ShooterControlCommand()
{
	Requires(shootersubsystem);
	TriggerPressedPre = TriggerPressed = LeftBumperPre = RightBumperPre = FirePre = Manual = false;
	tilt = 0;
	setPoint = 0;
	setPoints[0].speed = 0.0f;
	setPoints[0].tilt  = 0.0f;
}

void ShooterControlCommand::Initialize()
{
}
 
void ShooterControlCommand::Execute()
{
	if (oi->GetTrigger() > 90 && !TriggerPressedPre)
	{
		TriggerPressed = true;
		shootersubsystem->SetShooting(!shootersubsystem->GetShooting());
	}
	TriggerPressedPre = TriggerPressed;
	shootersubsystem->SetFire(oi->GetFire() && !FirePre);
	FirePre = oi->GetFire();
	if (Manual)
	{
		if (oi->GetLeftBumper())
			tilt += 0.1f;
		if (oi->GetRightBumper())
			tilt -= 0.1f;
		if (tilt > ShooterSubsystem::maxDegrees)
			tilt = ShooterSubsystem::maxDegrees;
		if (tilt < ShooterSubsystem::minDegrees)
			tilt = ShooterSubsystem::minDegrees;
	}
	else
	{
		if (oi->GetLeftBumper())
			setPoint += 1;
		if (oi->GetRightBumper())
			setPoint -= 1;
		setPoint %= SETPOINT_COUNT;
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
