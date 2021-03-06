#ifndef AUTONOMOUSDRIVECOMMAND_H
#define AUTONOMOUSDRIVECOMMAND_H

#include "../CommandBase.h"

class AutonomousDriveCommand: public CommandBase
{
private:
	bool latch;
	Timer delayTimer;
	double seconds;
	float speed, turn;
public:
	AutonomousDriveCommand(double seconds, float speed, float turn);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
