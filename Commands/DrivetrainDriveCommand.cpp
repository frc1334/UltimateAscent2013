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
	//////////////////////
	// DRIVE MOTOR CODE //
	//////////////////////
	drivetrainsubsystem->Drive(oi->GetDriveThrottle(), oi->GetDriveSteering());
	
	///////////////////////////
	// DRIVE GEAR SHIFT CODE //
	///////////////////////////
	if (oi->GetShiftUp() && !shiftUpPre)
		drivetrainsubsystem->SetShiftState(true);
	if (oi->GetShiftDown() && !shiftDownPre)
		drivetrainsubsystem->SetShiftState(false);
	shiftUpPre = oi->GetShiftUp();
	shiftDownPre = oi->GetShiftDown();
	//////////////////////////////////
	// END OF DRIVE GEAR SHIFT CODE //
	//////////////////////////////////
	
	//////////////////////////
	// DRIVETRAIN TILT CODE //
	//////////////////////////
	if (oi->GetTiltBotUp())
		drivetrainsubsystem->SetTiltSpeed(1.0f);
	else if (oi->GetTiltBotDown())
		drivetrainsubsystem->SetTiltSpeed(-1.0f);
	else
		drivetrainsubsystem->SetTiltSpeed(0.0f);
	/////////////////////////////////
	// END OF DRIVETRAIN TILT CODE //
	/////////////////////////////////
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
