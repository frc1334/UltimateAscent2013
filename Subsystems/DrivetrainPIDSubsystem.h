#ifndef DRIVETRAINPIDSUBSYSTEM_H
#define DRIVETRAINPIDSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Subsystems/MA3Encoder.h"


class DrivetrainPIDSubsystem: public PIDSubsystem
{
private:
	Jaguar LeftFrontMotor, RightFrontMotor, LeftBackMotor, RightBackMotor;
    MA3Encoder PIDCoder;
public:
    DrivetrainPIDSubsystem();
    
    
};

	
#endif
