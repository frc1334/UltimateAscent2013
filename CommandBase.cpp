#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name)
{
}

CommandBase::CommandBase() : Command()
{
}

OI* CommandBase::oi = NULL;
ShooterSubsystem* CommandBase::shootersubsystem = NULL;

void CommandBase::init()
{
  oi = new OI();
  shootersubsystem = new ShooterSubsystem();
}
