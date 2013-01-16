#ifndef SHOOTER_SUBSYSTEM_H
#define SHOOTER_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShooterSubsystem: public Subsystem
{
private:
    Jaguar shootMotor, panMotor;
public:
  ShooterSubsystem();
  void InitDefaultCommand();
  void Shoot(float power);
};

#endif
