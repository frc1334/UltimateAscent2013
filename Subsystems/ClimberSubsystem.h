#ifndef CLIMBER_SUBSYSTEM_H
#define CLIMBER_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ClimberSubsystem: public Subsystem
{
private:
	Talon climbMotor1, climbMotor2;
	DigitalInput topSwitch, bottomSwitch;
	Solenoid climbSolenoid;
	bool autoForward, topPre, bottomPre;
public:
  ClimberSubsystem();
  void InitDefaultCommand();
  void Reset();
  void Deploy();
  bool IsDeployed();
  void ManualSet(float speed);
  void AutomaticRun();
};

#endif
