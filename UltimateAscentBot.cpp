#include "WPILib.h"
#include "CommandBase.h"

class UltimateAscentBot : public IterativeRobot
{
private:
	LiveWindow *lw;
  virtual void RobotInit()
  {
    CommandBase::init();
    lw = LiveWindow::GetInstance();
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
	  lw->Run();
  }
};

START_ROBOT_CLASS(UltimateAscentBot);
