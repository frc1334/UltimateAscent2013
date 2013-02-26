#include "WPILib.h"
#include "CommandBase.h"

class UltimateAscentBot : public IterativeRobot
{
private:
  virtual void RobotInit()
  {
    CommandBase::init();
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
    CommandBase::visionsubsystem->UpdateTracking();
  }
};

START_ROBOT_CLASS(UltimateAscentBot);
