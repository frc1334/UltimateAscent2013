#include "DrivetrainDriveCommand.h"

DrivetrainDriveCommand::DrivetrainDriveCommand()
{
	Requires(drivetrainsubsystem);
}

void DrivetrainDriveCommand::Initialize()
{
}

void DrivetrainDriveCommand::Execute()
{
	drivetrainsubsystem->Drive(oi->getDriveThrottle(), oi->getDriveSteering());
}

bool DrivetrainDriveCommand::IsFinished()
{
	return false;
}

void DrivetrainDriveCommand::End()
{
}

void DrivetrainDriveCommand::Interrupted()
{
}
