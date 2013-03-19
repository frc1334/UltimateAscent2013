#ifndef SHOOTER_CONTROL_COMMAND_H
#define SHOOTER_CONTROL_COMMAND_H

#define FUDGEFACTOR 1.0f
#include "../CommandBase.h"
 
class ShooterControlCommand: public CommandBase
{
private:	
	bool m_buttonlatch;	//STOPS CONTROLLER BUTTON BOUNCING
	float setpoint;
public:
	ShooterControlCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	void Autofire();
};
 
#endif
