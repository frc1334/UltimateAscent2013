#include "ShooterControlCommand.h"

ShooterControlCommand::ShooterControlCommand()
{
	Requires(shootersubsystem);
	m_buttonlatch = false;
	autofire=false;
	setPoint = 0;
	setPoints[0].speed = 0.0f;
	setPoints[0].tilt  = 0.0f;
	m_autofire_timer = new Timer;
}

void ShooterControlCommand::Initialize()
{
	shootersubsystem->Reset();
	shootersubsystem->SetTilt(false);
	shootersubsystem->SetSpeed(0.0f);
}
 
 void ShooterControlCommand::Execute()
{
	////////////////////////////
	// Shooter Tilt/Fire Code //
	////////////////////////////
	if ((oi->GetShooterTilt() || oi->GetFire() || oi->GetAutoFire()) && !m_buttonlatch)
	{
		if (oi->GetShooterTilt())
			shootersubsystem->SetTilt(shootersubsystem->GetTilt());
		
		if (oi->GetAutoFire() && !autofire)
			autofire=true;
		else if (oi->GetAutoFire() && autofire)
		{
			autofire=false;
			m_autofire_timer->Stop();
			m_autofire_timer->Reset();
		}
		
		shootersubsystem->SetFire(oi->GetFire());
		m_buttonlatch=true;
	}
	else
		m_buttonlatch=false;

	///////////////////////////////////
	// End of Shooter Tilt/Fire Code //
	///////////////////////////////////
	
	////////////////////////
	// Shooter Wheel Code //
	////////////////////////
	
	//Enables shooter wheel spinning if shooter controller right trigger is fully pressed.
	if(autofire)
		Autofire();
	else{
		if(oi->GetTrigger() <= -0.9f)
			shootersubsystem->SetSpeed(5000.0f);
		else
			shootersubsystem->SetSpeed(0.0f);
	}
	
	///////////////////////////////
	// End of Shooter Wheel Code //
	///////////////////////////////	
	std::cout << "AUTOFIRE: " << autofire << std::endl;
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

//Shoots through 4 disks when A button is pressed.
void ShooterControlCommand::Autofire()
{
	m_autofire_timer->Start();
	//Set shooter wheel to a speed
	if(shootersubsystem->GetSpeedSetpoint() != 5000.0f)
		shootersubsystem->SetSpeed(5000.0f);
	//Shoot disk if speed is over PID setpoint
	if(shootersubsystem->PIDGet()>= shootersubsystem->GetSpeedSetpoint() && m_autofire_timer->Get() > 0.2f)
	{
		shootersubsystem->SetFire(true);
		m_autofire_timer->Reset();
	}
	else if (m_autofire_timer->Get()>0.1f)
		shootersubsystem->SetFire(false);
}
