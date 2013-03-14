#ifndef SHOOTER_CONTROL_COMMAND_H
#define SHOOTER_CONTROL_COMMAND_H

#define SETPOINT_COUNT 1
#define FUDGEFACTOR 1.0f
#include "../CommandBase.h"
 
class ShooterControlCommand: public CommandBase
{
private:
	struct SetPoint
	{
		float tilt;
		float speed;
		
		SetPoint() : tilt(0.0f), speed(0.0f) {}
		SetPoint(float t, float s) : tilt(t), speed(s) {}
	} setPoints[SETPOINT_COUNT];
	
	bool m_buttonlatch;	//STOPS CONTROLLER BUTTON BOUNCING
	int setPoint;		//HARDCODED SHOOTER WHEEL SPEED
public:
	ShooterControlCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
 
#endif
