#ifndef DRIVETRAINSUBSYSTEM_H
#define DRIVETRAINSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"



class DrivetrainSubsystem: public Subsystem
{
private:		
	
	Jaguar LeftMotor, RightMotor;
	AnalogChannel PIDCoderLeft, PIDCoderRight;
	PIDController LeftController, RightController; 

	
public:
    DrivetrainSubsystem();
    void InitDefaultCommand();
    void UsePIDOutput(double output);
    void Drive(float speed, float turn);
};
    
	
#endif
