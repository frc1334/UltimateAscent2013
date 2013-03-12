#include "../Commands/AutonomousCommand.h"


AutonomousCommand::AutonomousCommand()
{
  // Use Requires() here to declare subsystem dependencies
}

void AutonomousCommand::Initialize()
{
	shootersubsystem->SetTilt(true);
}

void AutonomousCommand::Execute()
{
	shootersubsystem->SetTilt(false);
}

bool AutonomousCommand::IsFinished()
{
  return false;
}

void AutonomousCommand::End()
{
}

void AutonomousCommand::Interrupted()
{
}
