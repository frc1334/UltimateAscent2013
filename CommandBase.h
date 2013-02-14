#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/Command.h"
#include "Subsystems/ShooterSubsystem.h"
#include "Subsystems/ClimberSubsystem.h"
#include "OI.h"

class CommandBase : public Command
{
public:
  CommandBase(const char *name);
  CommandBase();
  static void init();

  static OI *oi;
  static ShooterSubsystem *shootersubsystem;
  static ClimberSubsystem *climbersubsystem;
};

#endif
