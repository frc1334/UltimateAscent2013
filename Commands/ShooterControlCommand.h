#ifndef SHOOTER_CONTROL_COMMAND_H
#define SHOOTER_CONTROL_COMMAND_H
 
#include "../CommandBase.h"
 
class ShooterControlCommand: public CommandBase
{
private:
	bool TriggerPressed;
	bool TriggerPressedPre;
public:
	ShooterControlCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
 
#endif
