#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ClimberSubsystem: public Subsystem
{
private:
	static const float P = 0.0f;
	static const float I = 0.0f;
	static const float D = 0.0f;
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
