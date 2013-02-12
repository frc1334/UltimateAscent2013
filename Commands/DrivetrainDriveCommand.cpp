#include "DrivetrainDriveCommand.h"

DrivetrainDriveCommand::DrivetrainDriveCommand()
{
	Requires(drivetrainsubsystem);
	shiftUpPre = shiftDownPre = tiltPre = false;
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
	if (oi->GetTiltState() && !tiltPre)
		tilt = !tilt;
	drivetrainsubsystem->SetTiltState(tilt);
	shiftUpPre = oi->GetShiftUp();
	shiftDownPre = oi->GetShiftDown();
	tiltPre = oi->GetTiltState();
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
