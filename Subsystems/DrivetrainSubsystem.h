#ifndef DRIVETRAINSUBSYSTEM_H
#define DRIVETRAINSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class DrivetrainSubsystem : public Subsystem
{
private:
	static const float tiltP = 0.0f;
	static const float tiltI = 0.0f;
	static const float tiltD = 0.0f;
	static const float tiltUp = 0.0f;
	static const float tiltDown = 1000.0f;
	
	Jaguar LeftMotor, RightMotor, TiltMotor;
	Solenoid LeftSolenoid, RightSolenoid;
	AnalogChannel TiltEncoder;
	PIDController TiltController;
	DigitalInput TiltSwitch;
public:
    DrivetrainSubsystem();
    void InitDefaultCommand();
    void Drive(float speed, float turn);
    void SetShiftState(bool state);
    void SetTiltState(bool tilting);
    void Reset();
};

#endif
