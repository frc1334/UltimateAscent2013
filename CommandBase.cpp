#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name)
{
}

CommandBase::CommandBase() : Command()
{
}

OI* CommandBase::oi = NULL;
DrivetrainSubsystem* CommandBase::drivetrainsubsystem = NULL;
ShooterSubsystem* CommandBase::shootersubsystem = NULL;
ClimberSubsystem* CommandBase::climbersubsystem = NULL;

void CommandBase::init()
{
  oi = new OI();
  drivetrainsubsystem = new DrivetrainSubsystem();
  shootersubsystem = new ShooterSubsystem();
  climbersubsystem = new ClimberSubsystem();
}
