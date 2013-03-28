#include "AutonomousCommandGroup.h"
#include "AutonomousWaitCommand.h"
#include "AutonomousShootCommand.h"
#include "AutonomousDriveCommand.h"
#include "RobotMap.h"

AutonomousCommandGroup::AutonomousCommandGroup()
{
	DigitalInput dg1(AUTONOMOUS_MODE1), dg2(AUTONOMOUS_MODE2), dg3(AUTONOMOUS_MODE3), dg4(AUTONOMOUS_MODE4);
	cout << "Autonomous Startup : " << (dg1.Get() + (dg2.Get() << 1)) << ", " << (dg3.Get() + (dg4.Get() << 1)) << endl;
	switch (dg1.Get() + (dg2.Get() << 1))
	{
	case 0:
		AddSequential(new AutonomousWaitCommand(4.0f));
		if ((dg3.Get() + (dg4.Get() << 1)) == 0) break;
	case 1:
		AddSequential(new AutonomousShootCommand(4));
		if ((dg3.Get() + (dg4.Get() << 1)) == 1) break;
	case 2:
		AddSequential(new AutonomousDriveCommand(0.75f, 1.0f, 0.0f));
		if ((dg3.Get() + (dg4.Get() << 1)) == 2) break;
	case 3:
		AddSequential(new AutonomousDriveCommand(0.75f, 1.0f, 1.0f));
		if ((dg3.Get() + (dg4.Get() << 1)) == 3) break;
		break;
	}
}
