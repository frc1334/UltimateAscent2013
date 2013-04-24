#include "AutonomousClimbCommand.h"

AutonomousClimbCommand::AutonomousClimbCommand(double seconds, float speed)
	: seconds(seconds), speed(speed)
{
	Requires(climbersubsystem);
}

void AutonomousClimbCommand::Initialize()
{
	delayTimer.Reset();
	delayTimer.Start();
}

void AutonomousClimbCommand::Execute()
{
	climbersubsystem->ManualSet(speed);
}

bool AutonomousClimbCommand::IsFinished()
{
	return delayTimer.HasPeriodPassed(seconds);
}

void AutonomousClimbCommand::End()
{
	climbersubsystem->ManualSet(0.0f);
	delayTimer.Stop();
	delayTimer.Reset();
}

void AutonomousClimbCommand::Interrupted()
{
	delayTimer.Stop();
	delayTimer.Reset();
}
