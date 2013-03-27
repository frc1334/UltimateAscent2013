#include "../Commands/AutonomousShootCommand.h"

AutonomousShootCommand::AutonomousShootCommand()
 : latch(false), latch_2(false), latch_3(false), delayTimer()
{
    Requires(shootersubsystem);
    Requires(drivetrainsubsystem);
}

void AutonomousShootCommand::Initialize()
{
	shootersubsystem->SetSpeed(5000);
	shootersubsystem->SetTilt(true);
	delayTimer.Reset();
	delayTimer.Start();
}

void AutonomousShootCommand::Execute()
{
	if (!latch_2 && delayTimer.HasPeriodPassed(4.0f))
	{
		latch_2 = true;
		delayTimer.Stop();
	}
	if (latch_2 && !latch_1)
		if (latch_1 = shootersubsystem->ShootDiscs(4))
		{
			delayTimer.Reset();
			delayTimer.Start();			
		}
	if (latch_1 && !latch_3)
	{
		drivetrainsubsystem->Drive(1.0f, 0.0f);
		if (delayTimer.HasPeriodPassed(0.75f))
		{
			delayTimer.Stop();
			drivetrainsubsystem->Drive(0.0f, 0.0f);
			latch_3 = true;
		}
	}
}

bool AutonomousShootCommand::IsFinished()
{
    return latch_3;
}

void AutonomousShootCommand::End()
{
}

void AutonomousShootCommand::Interrupted()
{
}
