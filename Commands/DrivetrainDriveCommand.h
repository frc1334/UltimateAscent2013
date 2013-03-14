#ifndef DRIVETRAINDRIVE_H
#define DRIVETRAINDRIVE_H

#include "../CommandBase.h"

class DrivetrainDriveCommand: public CommandBase
{
private:
	bool shiftUpPre, shiftDownPre, tiltPre;
public:
	DrivetrainDriveCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
