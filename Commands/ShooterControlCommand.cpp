#include "ShooterControlCommand.h"
 
ShooterControlCommand::ShooterControlCommand()
{
	Requires(shootersubsystem);
	TriggerPressedPre = false;
	TriggerPressed = false;
	LeftBumperPre = false;
	RightBumperPre = false;
	tilt = 0;
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
	 
	 //shootersubsystem->SetFire(oi->ButtonGet());
	 if (oi->GetLeftBumper())
		 tilt += 10;
	 if (oi->GetRightBumper())
		 tilt -= 10;
	 if (tilt > ShooterSubsystem::maxDegrees)
	     tilt = ShooterSubsystem::maxDegrees;
	 if (tilt < ShooterSubsystem::minDegrees)
		 tilt = ShooterSubsystem::minDegrees;
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
