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
	//if (oi->GetTiltState() && !tiltPre)
		//tilt = !tilt;
	if (oi->GetTiltBotUp())
	{
		drivetrainsubsystem->SetTiltState(1.0f);
	}
	else if (oi->GetTiltBotDown())
	{
		drivetrainsubsystem->SetTiltState(-1.0f);
	}
	else
	{
		drivetrainsubsystem->SetTiltState(0.0f);
	}
	shiftUpPre = oi->GetShiftUp();
	shiftDownPre = oi->GetShiftDown();
	//tiltPre = oi->GetTiltState();
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
