#include "../Commands/AutonomousShootCommand.h"

AutonomousShootCommand::AutonomousShootCommand()
 : latch_1(false), latch_2(false), latch_3(false)
{
  Requires(shootersubsystem);
}

void AutonomousShootCommand::Initialize()
{
	shootersubsystem->SetSpeed(5500);
	shootersubsystem->ToggleShooterWheel(true);
	shootersubsystem->SetTilt(true);
}

void AutonomousShootCommand::Execute()
{
	if (!latch_1 && shootersubsystem->ShootDiscs(3))
		latch_1 = true;
	if (!latch_2 && shootersubsystem->Jiggly())
		latch_2 = true;
	if (!latch_3 && shootersubsystem->ShootDiscs(2))
		latch_3 = true;
}

bool AutonomousShootCommand::IsFinished()
{
  return true;
}

void AutonomousShootCommand::End()
{
}

void AutonomousShootCommand::Interrupted()
{
}
