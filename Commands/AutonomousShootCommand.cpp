#include "../Commands/AutonomousShootCommand.h"

AutonomousShootCommand::AutonomousShootCommand(int discs)
 : latch(false), discs(discs)
{
    Requires(shootersubsystem);
    Requires(drivetrainsubsystem);
}

void AutonomousShootCommand::Initialize()
{
	shootersubsystem->SetSpeed(5000);
	shootersubsystem->SetTilt(true);
}

void AutonomousShootCommand::Execute()
{
	latch = shootersubsystem->ShootDiscs(discs);
}

bool AutonomousShootCommand::IsFinished()
{
    return latch;
}

void AutonomousShootCommand::End()
{
}

void AutonomousShootCommand::Interrupted()
{
}
