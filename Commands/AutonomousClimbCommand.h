#ifndef AUTONOMOUSCLIMBCOMMAND_H
#define AUTONOMOUSCLIMBCOMMAND_H

#include "../CommandBase.h"

class AutonomousClimbCommand: public CommandBase
{
private:
	Timer delayTimer;
	double seconds;
	float speed;
public:
	AutonomousClimbCommand(double seconds, float speed);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
