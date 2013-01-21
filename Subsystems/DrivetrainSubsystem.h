#ifndef DRIVETRAINSUBSYSTEM_H
#define DRIVETRAINSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"



class DrivetrainSubsystem: public PIDSubsystem
{
private:
	Jaguar LeftFrontMotor, RightFrontMotor, LeftBackMotor, RightBackMotor;
	AnalogChannel PIDCoder;
public:
    DrivetrainSubsystem();
    
    
};

	
#endif
