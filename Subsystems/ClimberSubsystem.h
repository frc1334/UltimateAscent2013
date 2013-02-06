#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ClimberSubsystem: public Subsystem
{
private:
	Talon leftMotor, rightMotor, tiltMotor;
	Encoder leftEncoder, rightEncoder, tiltEncoder;
	PIDController leftLoop, rightLoop, tiltLoop;
	Solenoid leftSolenoid, rightSolenoid;
	DigitalInput tiltSwitch, leftSwitch, rightSwitch;
public:
  ClimberSubsystem();
  void InitDefaultCommand();
};

#endif
