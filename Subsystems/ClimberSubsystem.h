#ifndef CLIMBER_SUBSYSTEM_H
#define CLIMBER_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
//#include "Joystick.cpp"

class ClimberSubsystem: public Subsystem
{
private:
	static const float P = 0.0f;
	static const float I = 0.0f;
	static const float D = 0.0f;
	static const float climberLength = 42.0f;
	static const float maxSetpoint = 9001.0f;
	static const float minSetpoint = -9001.0f;
	bool autoForward = true;
	Talon climbMotor;
	Encoder climbEncoder;
	Solenoid climbSolenoid;
	DigitalInput topSwitch, bottomSwitch;
	PIDController climbController;
public:
  ClimberSubsystem();
  void InitDefaultCommand();
  void Reset();
  void Deploy();
  bool IsDeployed();
  void ManualSet(float setpoint);
  void AutomaticRun();
};

#endif
