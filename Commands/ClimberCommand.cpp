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
