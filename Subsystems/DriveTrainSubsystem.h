#ifndef DRIVETRAIN_SUBSYSTEM_H
#define DRIVETRAIN_SUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"




class DriveTrainSubsystem: public Subsystem
{
private:
    Jaguar LeftFrontMotor, RightFrontMotor, LeftBackMotor, RightBackMotor;
public:
  DriveTrainSubsystem();
  void InitDefaultCommand();
  
  void Drive(float Left, float Right);
};

#endif

