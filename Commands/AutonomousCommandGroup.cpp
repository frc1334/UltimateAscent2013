#include "AutonomousCommandGroup.h"
#include "AutonomousWaitCommand.h"
#include "AutonomousShootCommand.h"
#include "AutonomousDriveCommand.h"
#include "AutonomousClimbCommand.h"
#include "../RobotMap.h"

AutonomousCommandGroup::AutonomousCommandGroup()
{
	DigitalInput dg1(AUTONOMOUS_MODE1), dg2(AUTONOMOUS_MODE2), dg3(AUTONOMOUS_MODE3), dg4(AUTONOMOUS_MODE4);
	AddParallel(new AutonomousClimbCommand(1.15f, -0.5f));
	AddSequential(new AutonomousShootCommand(4));
	if (dg1.Get())
	{
		// do nothing, but maybe later we will do something here
	}
	else if (dg2.Get()) // straight back
	{
		AddSequential(new AutonomousDriveCommand(0.75f, 1.0f, 0.0f));
		AddSequential(new AutonomousDriveCommand(0.55f, 0.0f, 1.0f));
	}
	else if (dg3.Get()) // left
	{
		AddSequential(new AutonomousDriveCommand(0.75f, 1.0f, 0.0f));
		AddSequential(new AutonomousDriveCommand(0.55f, 0.0f, 1.0f));
	}
	else if (dg4.Get()) // right
	{
		AddSequential(new AutonomousDriveCommand(0.75f, 1.0f, 0.0f));
		AddSequential(new AutonomousDriveCommand(0.55f, 0.0f, 1.0f));
	}
}
