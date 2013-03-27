#ifndef AUTONOMOUSDRIVECOMMAND_H
#define AUTONOMOUSDRIVECOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author p
 */
class AutonomousDriveCommand: public CommandBase {
public:
	AutonomousDriveCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
