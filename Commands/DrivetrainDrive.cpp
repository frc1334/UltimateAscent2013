#include "DrivetrainDrive.h"

DrivetrainDrive::DrivetrainDrive()
{
	Requires(drivetrainsubsystem);
}

void DrivetrainDrive::Initialize()
{
}

void DrivetrainDrive::Execute()
{
	drivetrainsubsystem->Drive(oi->getDriveThrottle(), oi->getDriveSteering());
}

bool DrivetrainDrive::IsFinished()
{
	return false;
}

void DrivetrainDrive::End()
{
}

void DrivetrainDrive::Interrupted()
{
}
