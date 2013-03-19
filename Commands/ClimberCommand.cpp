#include "ClimberCommand.h"

ClimberCommand::ClimberCommand()
{
	Requires(climbersubsystem);
}

void ClimberCommand::Initialize()
{
}

void ClimberCommand::Execute()
{
	////////////////////////////////
	// CLIMBER TILT SOLENOID CODE //
	////////////////////////////////
	if (oi->GetDeploy() && !climbersubsystem->IsDeployed())
		climbersubsystem->Deploy();
	if (oi->GetUnDeploy() && climbersubsystem->IsDeployed())
		climbersubsystem->UnDeploy();

	///////////////////////////////////////
	// END OF CLIMBER TILT SOLENOID CODE //
	///////////////////////////////////////
	
#ifdef CONSOLE_DEBUG
	climbersubsystem->Debug();	//Debug text to console.
#endif
		
	climbersubsystem->ManualSet(oi->GetClimbJoystick());		
}

bool ClimberCommand::IsFinished()
{
	return false;
}

void ClimberCommand::End()
{
}

void ClimberCommand::Interrupted()
{
}
