#ifndef DRIVETRAINSUBSYSTEM_H
#define DRIVETRAINSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"



class DrivetrainSubsystem: public PIDSubsystem
{
private:
	PIDController LeftController, RightController; 
	Jaguar LeftMotor, RightMotor;
	AnalogChannel PIDCoderLeft, PIDCoderRight;
public:
    DrivetrainSubsystem();
    double ReturnPIDInput() = 0;
    void UsePIDOutput(double output);
    void Drive(float speed, float turn);
};
    
	
#endif
