#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Subsystems/ShooterSubsystem.h"
#include "Subsystems/ClimberSubsystem.h"
#include "Subsystems/DrivetrainSubsystem.h"
#include "Commands/Command.h"
#include "OI.h"

class CommandBase : public Command
{
public:
  CommandBase(const char *name);
  CommandBase();
  static void init();

  static OI *oi;
  static DrivetrainSubsystem *drivetrainsubsystem;
  static ShooterSubsystem *shootersubsystem;
  static ClimberSubsystem *climbersubsystem;
 
};

#endif
