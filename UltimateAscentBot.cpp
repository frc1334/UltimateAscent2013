#include "WPILib.h"
#include "CommandBase.h"
#include "SmartDashboard/SmartDashboard.h"

class UltimateAscentBot : public IterativeRobot
{
private:
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
  }
  
  virtual void TestPeriodic()
  {
  }
};

START_ROBOT_CLASS(UltimateAscentBot);
