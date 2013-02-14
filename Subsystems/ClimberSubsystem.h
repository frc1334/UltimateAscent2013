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
	bool autoForward;
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
