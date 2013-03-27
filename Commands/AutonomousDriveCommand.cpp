#include "AutonomousDriveCommand.h"

AutonomousDriveCommand::AutonomousDriveCommand(double seconds, float speed, float turn)
	: latch(false), delayTimer(), seconds(seconds), speed(speed), turn(turn)
{
	Requires(drivetrainsubsystem);
}

void AutonomousDriveCommand::Initialize()
{
	delayTimer.Reset();
	delayTimer.Start();
	drivetrainsubsystem->Drive(speed, turn);
}

void AutonomousDriveCommand::Execute()
{
}

bool AutonomousDriveCommand::IsFinished()
{
	return delayTimer.HasPeriodPassed(seconds);
}

void AutonomousDriveCommand::End()
{
	drivetrainsubsystem->Drive(0.0f, 0.0f);
	delayTimer.Stop();
}

void AutonomousDriveCommand::Interrupted()
{
	delayTimer.Reset();
	delayTimer.Stop();
}
