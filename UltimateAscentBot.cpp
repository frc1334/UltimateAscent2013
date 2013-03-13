#include "WPILib.h"
#include "CommandBase.h"
#include "RobotMap.h"

class UltimateAscentBot : public IterativeRobot
{
private:
  Compressor *compressor;
	
  virtual void RobotInit()
  {
    CommandBase::init();
    SmartDashboard::init();
  }

  virtual void AutonomousInit()
  {
  }

  virtual void AutonomousPeriodic()
  {
  }

  virtual void TeleopInit()
  {
  }

  virtual void TeleopPeriodic()
  {
	  Scheduler::GetInstance()->Run();
	  CommandBase::shootersubsystem->Debug();
  }
};

START_ROBOT_CLASS(UltimateAscentBot);
