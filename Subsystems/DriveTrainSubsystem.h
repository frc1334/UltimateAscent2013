#ifndef DRIVETRAIN_SUBSYSTEM_H
#define DRIVETRAIN_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrainSubsystem: public Subsystem
{
private:
public:
  DriveTrainSubsystem();
  void InitDefaultCommand();
};

#endif