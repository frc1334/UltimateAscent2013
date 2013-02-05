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
