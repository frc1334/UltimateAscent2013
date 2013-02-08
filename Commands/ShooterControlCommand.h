#ifndef SHOOTER_CONTROL_COMMAND_H
#define SHOOTER_CONTROL_COMMAND_H

#define SETPOINT_COUNT 1
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
	bool TriggerPressed, TriggerPressedPre, LeftBumperPre, RightBumperPre, FirePre, Manual;
	float tilt;
	int setPoint;
public:
	ShooterControlCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
 
#endif
