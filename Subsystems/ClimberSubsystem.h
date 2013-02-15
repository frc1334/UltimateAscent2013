#ifndef CLIMBER_SUBSYSTEM_H
#define CLIMBER_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ClimberSubsystem: public Subsystem
{
private:
	static const float climbP = 0.0f;
	static const float climbI = 0.0f;
	static const float climbD = 0.0f;
	static const float climberLength = 42.0f;
	static const float maxSetpoint = 9000.0f;
	static const float minSetpoint = -9000.0f;
	static const float deploySetpoint = 42.0f;
	Talon climbMotor;
	Encoder climbEncoder;
	DigitalInput topSwitch, bottomSwitch;
	Solenoid climbSolenoid;
	PIDController climbController;
	bool autoForward;
public:
  ClimberSubsystem();
  void InitDefaultCommand();
  void Reset();
  void Deploy();
  bool IsDeployed();
  void ManualSet(float setpoint);
  float ManualGet();
  void AutomaticRun();
};

#endif
