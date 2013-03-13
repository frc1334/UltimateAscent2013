#include "ClimberCommand.h"

ClimberCommand::ClimberCommand()
{
	Requires(climbersubsystem);
}

void ClimberCommand::Initialize()
{
	climbersubsystem->Reset();
}

void ClimberCommand::Execute()
{
	if (oi->GetDeploy() && !climbersubsystem->IsDeployed())
		climbersubsystem->Deploy();
	if (oi->GetUnDeploy() && climbersubsystem->IsDeployed())
		climbersubsystem->UnDeploy();
/*	if (climbersubsystem->IsDeployed())
	{*/
		/*if (oi->GetAutoclimb())
			climbersubsystem->AutomaticRun();*/
		std::cout << oi->GetClimbFudge() << " " << climbersubsystem->bottomSwitch.Get() << " " << climbersubsystem->topSwitch.Get() << " " << climbersubsystem->climbMotor1.Get() << " " << climbersubsystem->climbMotor2.Get() << std::endl;
		climbersubsystem->ManualSet(oi->GetClimbFudge());		
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
