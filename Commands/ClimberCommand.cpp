#include "ClimberCommand.h"

ClimberCommand::ClimberCommand()
{
	Requires(climbersubsystem);
	deployPre = false;
	isDeployed = false;
}

void ClimberCommand::Initialize()
{
}

void ClimberCommand::Execute()
{
	if (oi->GetDeploy() && !deployPre)
	{
		climbersubsystem->Deploy();
		isDeployed = true;
	}
	if (!isDeployed && climbersubsystem->IsDeployed())
	{
		if (oi->GetAutoclimb())
			climbersubsystem->AutomaticRun();
		climbersubsystem->ManualSet(oi->GetClimbFudge());
	}
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
