#include "ShooterControlCommand.h"

ShooterControlCommand::ShooterControlCommand()
{
	Requires(shootersubsystem);
	m_buttonlatch = false;
}

void ShooterControlCommand::Initialize()
{
	shootersubsystem->SetTilt(true);
	shootersubsystem->SetSpeed(setpoint = 5000.0f);
}
 
void ShooterControlCommand::Execute()
{
	////////////////////////////
	// Shooter Tilt/Fire Code //
	////////////////////////////

	shootersubsystem->SetTilt(!oi->GetShooterTilt());
	if ((oi->GetFire() || oi->GetAutoFire() || oi->GetStart() || oi->GetShootLeftBumper()) && !m_buttonlatch)
	{
		m_buttonlatch = true;
		
		if(oi->GetStart())
			setpoint += 100;
		if(oi->GetShootLeftBumper() && setpoint > 3000)
			setpoint -= 100;
		
		if (oi->GetAutoFire())
			shootersubsystem->ShootDiscs(100);
	}
	else
		m_buttonlatch = false;
	
	shootersubsystem->SetFire(oi->GetFire());

	///////////////////////////////////
	// End of Shooter Tilt/Fire Code //
	///////////////////////////////////
	
	////////////////////////
	// Shooter Wheel Code //
	////////////////////////
	
	//Enables shooter wheel spinning if shooter controller right trigger is fully pressed.
	shootersubsystem->SetSpeed((oi->GetTrigger() <= -0.9f) ? setpoint : 0.0f);
	
	///////////////////////////////
	// End of Shooter Wheel Code //
	///////////////////////////////	

#ifdef DEBUG_CONSOLE
	shootersubsystem->Debug(); //Debug Console
#endif
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
