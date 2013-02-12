#ifndef CLIMBER_SUBSYSTEM_H
#define CLIMBER_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
//#include "Joystick.cpp"

class ClimberSubsystem: public Subsystem, public PIDSource
{
private:
	static const int maxBar = 3;
	static const int minBar = 0;//ground
	static const int currentBar = 0; // Dummy value
	static const float P = 0.0f;
	static const float I = 0.0f;
	static const float D = 0.0f;
	static const float EncoderTicksFirstBar = 42000;
	static const float EncoderTicksTilt = 2100;
	Talon leftMotor, rightMotor, tiltMotor;
	Encoder leftEncoder, rightEncoder, tiltEncoder;
	Solenoid leftSolenoid, rightSolenoid;
	DigitalInput tiltSwitch, leftSwitch, rightSwitch;
	PIDController leftLoop, rightLoop, tiltLoop;
public:
  static const int minDegrees = 20;
  static const int maxDegrees = 50;
  ClimberSubsystem();
  void Climb(bool climb);
  void InitDefaultCommand();
  double ReturnPIDInput();
  void Reset();
  void SetTiltDegrees(float degrees);
};

#endif
