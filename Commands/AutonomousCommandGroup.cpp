#include "AutonomousCommandGroup.h"
#include "AutonomousWaitCommand.h"
#include "AutonomousShootCommand.h"
#include "AutonomousDriveCommand.h"
#include "AutonomousClimbCommand.h"
#include "../RobotMap.h"

#define MOVE_DELAY 0

AutonomousCommandGroup::AutonomousCommandGroup()
{
	DigitalInput dg1(AUTONOMOUS_MODE1), dg2(AUTONOMOUS_MODE2), dg3(AUTONOMOUS_MODE3), dg4(AUTONOMOUS_MODE4);
	AddParallel(new AutonomousClimbCommand(1.15f, -0.5f));
	AddSequential(new AutonomousShootCommand(4));
	AddSequential(new AutonomousWaitCommand(MOVE_DELAY));
	cout << !dg1.Get() << !dg2.Get() << !dg3.Get() << !dg4.Get() << endl;
	if (!dg1.Get())
	{
		// do nothing, but maybe later we will do something here
	}
	else if (!dg2.Get())
	{
		AddSequential(new AutonomousDriveCommand(0.3f, 1.0f, 0.0f));
		AddSequential(new AutonomousDriveCommand(0.2f, 0.0f, 1.0f));
		AddSequential(new AutonomousDriveCommand(0.95f, 1.0f, 0.0f));
	}
	else if (!dg3.Get())
	{
		AddSequential(new AutonomousDriveCommand(0.98f, 1.0f, 0.0f));
	}
	else if (!dg4.Get())
	{
		AddSequential(new AutonomousDriveCommand(0.3f, 1.0f, 0.0f));
		AddSequential(new AutonomousDriveCommand(0.2f, 0.0f, -1.0f));
		AddSequential(new AutonomousDriveCommand(0.9f, 1.0f, 0.0f));
	}
}
