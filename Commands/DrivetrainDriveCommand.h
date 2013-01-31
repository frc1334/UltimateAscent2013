#ifndef DRIVETRAINDRIVE_H
#define DRIVETRAINDRIVE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author p
 */
class DrivetrainDriveCommand: public CommandBase
{
public:
	DrivetrainDriveCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
