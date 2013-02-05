#include "ShooterControlCommand.h"
 
ShooterControlCommand::ShooterControlCommand()
{
	Requires(shootersubsystem);
}

 
void ShooterControlCommand::Initialize()
{
}
 
void ShooterControlCommand::Execute()
{
	 if (Joystick_Shoot.GetZ()> 90 && !TriggrtPressedPre)
	 {
		 TriggerPressed = ture;
		 ShooterSubsystem.SetShooting(!ShooterSubsytem.GetShooting());
	 }
	 
	 TriggerPressed = TriggerPressedPre;
	shootersubsystem->SetFire(oi->ButtonGet());
	if (GetButton = 5)
			tilt += 10;
		if (GetButton =6)
			tilt-= 10;
		if (tilt > ShooterSubsystem::maxDegrees)
			tilt=maxDegrees;
		if (tilt < ShooterSubsystem::minDegrees)
			tilt=minDegrees;
		shootersubsystem.SetTilt(tilt);
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
