#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name)
{
}

CommandBase::CommandBase() : Command()
{
}

OI* CommandBase::oi = NULL;
VisionSubsystem* CommandBase::visionsubsystem = NULL;

void CommandBase::init()
{
  oi = new OI();
  visionsubsystem = new VisionSubsystem();
}
