#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Joystick.cpp"

class ClimberSubsystem: public Subsystem
{
private:
public:
  ClimberSubsystem();
  void InitDefaultCommand();
  void ClimbUp(int barsUp);
  void ClimbDown(int barsDown);
};

#endif