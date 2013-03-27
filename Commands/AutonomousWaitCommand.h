#ifndef AUTONOMOUSWAITCOMMAND_H
#define AUTONOMOUSWAITCOMMAND_H

#include "../CommandBase.h"

class AutonomousWaitCommand: public CommandBase
{
private:
	Timer delayTimer;
	double seconds;
public:
	AutonomousWaitCommand(double seconds);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
