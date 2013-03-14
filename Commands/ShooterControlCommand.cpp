#include "ShooterControlCommand.h"

ShooterControlCommand::ShooterControlCommand()
{
	Requires(shootersubsystem);
	m_buttonlatch = false;
	setPoint = 0;
	setPoints[0].speed = 0.0f;
	setPoints[0].tilt  = 0.0f;
}

void ShooterControlCommand::Initialize()
{
	shootersubsystem->Reset();
	shootersubsystem->SetTilt(false);
	shootersubsystem->SetSpeed(0.0f);
}
 
 void ShooterControlCommand::Execute()
{
	///////////////////////
	// Shooter Tilt Code //
	///////////////////////
	if (oi->GetShooterTilt() || oi->GetFire())
	{
		if (oi->GetShooterTilt())
			shootersubsystem->SetTilt(shootersubsystem->GetTilt());
		shootersubsystem->SetFire(oi->GetFire());
		m_buttonlatch=true;
	}
	else
		m_buttonlatch=false;

	//////////////////////////////
	// End of Shooter Tilt Code //
	//////////////////////////////
	
	////////////////////////
	// Shooter Wheel Code //
	////////////////////////
	
	//Enables shooter wheel spinning if shooter controller right trigger is fully pressed.
	if(oi->GetTrigger() <= -0.9f)
		shootersubsystem->SetSpeed(5000.0f);
	else
		shootersubsystem->SetSpeed(0.0f);
	
	///////////////////////////////
	// End of Shooter Wheel Code //
	///////////////////////////////
	
	shootersubsystem->Debug(); //Debug Console
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
