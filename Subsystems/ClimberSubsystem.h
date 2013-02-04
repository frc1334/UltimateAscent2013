#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
//#include "Joystick.cpp"

class ClimberSubsystem: public Subsystem
{
private:
    AnalogChannel leftanalogchannel;
    Talon leftClimbMotor;
    Talon rightClimbMotor;
    AnalogChannel rightanalogchannel;
    PIDController left;
    PIDController right;

};
public:
  ClimberSubsystem();
  void InitDefaultCommand();
  double returnPIDInput();
  int usePIDOutput(double output);
};

#endif
