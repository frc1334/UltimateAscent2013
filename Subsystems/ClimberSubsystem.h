#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
//#include "Joystick.cpp"

class ClimberSubsystem: public Subsystem
{
private:
    AnalogChannel leftanalogchannel;
    Talon leftClimbMotor;
    Talon rightClimbMotor;
    AnalogChannel rightanalogchannel;
    PIDController left;
    PIDController right;

	static const int maxBar = 3;
	static const int minBar = 0;//ground
	static const int currentBar = 0; // Dummy value
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
  void SetPosition(int bar, bool tilt, float deg);
  int GetPosition();
  bool IsAtTop();
  void InitDefaultCommand();
  double returnPIDInput();
  int usePIDOutput(double output);
};

#endif
