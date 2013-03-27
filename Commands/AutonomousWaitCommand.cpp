#include "AutonomousWaitCommand.h"

AutonomousWaitCommand::AutonomousWaitCommand(double seconds)
	: delayTimer(), seconds(seconds)
{
}

void AutonomousWaitCommand::Initialize()
{
	delayTimer.Reset();
	delayTimer.Start();
}

void AutonomousWaitCommand::Execute()
{
}

bool AutonomousWaitCommand::IsFinished()
{
	return delayTimer.HasPeriodPassed(seconds);
}

void AutonomousWaitCommand::End()
{
	delayTimer.Stop();
}

void AutonomousWaitCommand::Interrupted()
{
	delayTimer.Reset();
	delayTimer.Stop();
}
