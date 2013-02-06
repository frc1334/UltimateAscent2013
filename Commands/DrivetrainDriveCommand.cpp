#include "DrivetrainDriveCommand.h"

DrivetrainDriveCommand::DrivetrainDriveCommand()
{
	Requires(drivetrainsubsystem);
	shiftUpPre = false;
	shiftDownPre = false;
}

void DrivetrainDriveCommand::Initialize()
{
}

void DrivetrainDriveCommand::Execute()
{
	drivetrainsubsystem->Drive(oi->GetDriveThrottle(), oi->GetDriveSteering());
	if (oi->GetShiftUp() && !shiftUpPre)
		drivetrainsubsystem->SetShiftState(true);
	if (oi->GetShiftDown() && !shiftDownPre)
		drivetrainsubsystem->SetShiftState(false);
	shiftUpPre = oi->GetShiftUp();
	shiftDownPre = oi->GetShiftDown();
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
