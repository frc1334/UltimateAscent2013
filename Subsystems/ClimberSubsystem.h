#ifndef CLIMBER_SUBSYSTEM_H
#define CLIMBER_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
//#include "Joystick.cpp"

class ClimberSubsystem: public Subsystem
{
private:
	static const int maxBar = 3;
	static const int minBar = 0;//ground
	static const int currentBar = 0; // Dummy value
	static const float P = 0.0f;
	static const float I = 0.0f;
	static const float D = 0.0f;
	Talon leftMotor, rightMotor, tiltMotor;
	Encoder leftEncoder, rightEncoder, tiltEncoder;
	Solenoid leftSolenoid, rightSolenoid;
	DigitalInput tiltSwitch, leftSwitch, rightSwitch;
	PIDController leftLoop, rightLoop, tiltLoop;
public:
  ClimberSubsystem();
  void SetPosition(int bar, bool tilt, float deg);
  int GetPosition();
  bool IsAtTop();
  void InitDefaultCommand();
  double returnPIDInput();
};

#endif
