#include "WPILib.h"
#include "CommandBase.h"
#include "RobotMap.h"
#include "Commands/AutonomousCommandGroup.h"

class UltimateAscentBot : public IterativeRobot
{
public:
	static bool AllowFalling, IsSmiling;
private:
	Command *autonomousCommand;
	Compressor *compressor;

  virtual void RobotInit()
  {
    CommandBase::init();
    SmartDashboard::init();
    autonomousCommand = new AutonomousCommandGroup();
    compressor = new Compressor(COMPRESSOR_SWITCH, COMPRESSOR_RELAY);
    compressor->Start();
  }

  virtual void AutonomousInit()
  {
	  autonomousCommand->Start();
  }

  virtual void AutonomousPeriodic()
  {
	  Scheduler::GetInstance()->Run();
  }

  virtual void TeleopInit()
  {
	  autonomousCommand->Cancel();
  }

  virtual void TeleopPeriodic()
  {
	  Scheduler::GetInstance()->Run();
  }
};

bool UltimateAscentBot::AllowFalling = false; // should keep the robot from falling off the pyramid

bool UltimateAscentBot::IsSmiling = true; // Jebediah is always smiling

START_ROBOT_CLASS(UltimateAscentBot);
