#ifndef DRIVETRAINSUBSYSTEM_H
#define DRIVETRAINSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class DrivetrainSubsystem : public Subsystem
{
private:
	Jaguar LeftMotor, RightMotor; 
public:
    DrivetrainSubsystem();
    void InitDefaultCommand();
    void Drive(float speed, float turn);
};

#endif
