#include "AutonomousCommandGroup.h"
#include "AutonomousWaitCommand.h"
#include "AutonomousShootCommand.h"
#include "AutonomousDriveCommand.h"

AutonomousCommandGroup::AutonomousCommandGroup()
{
	AddSequential(new AutonomousWaitCommand(4.0f));
	AddSequential(new AutonomousShootCommand(4));
	AddSequential(new AutonomousDriveCommand(0.75f, 1.0f, 0.0f));
}
