#ifndef DRIVETRAINSUBSYSTEM_H
#define DRIVETRAINSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class DrivetrainSubsystem : public Subsystem
{
private:
	Talon LeftMotor1, LeftMotor2, RightMotor1, RightMotor2, TiltMotor;
	Solenoid ShiftSolenoid;
	//DigitalInput TiltSwitchTop, TiltSwitchBottom;
public:
    DrivetrainSubsystem();
    void InitDefaultCommand();
    void Drive(float speed, float turn);						//SETS DRIVETRAIN MOTOR SPEEDS
    void SetShiftState(bool state);								//SETS DRIVETRAIN GEAR SHIFT
    void SetTiltSpeed(float speed);						//SETS TILT MOTOR FROM JOYSTICK
    inline float GetTiltSpeed() {return TiltMotor.Get();};
    void Reset();
};

#endif
