#include "WPILib.h"
#include "CommandBase.h"
#include "RobotMap.h"

class UltimateAscentBot : public IterativeRobot
{
public:
  UltimateAscentBot()
  	  : compressor(COMPRESSOR_SWITCH, COMPRESSOR_RELAY)
  {}
	
private:
  Compressor compressor;
	
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
	  compressor.Start();
  }

  virtual void TeleopPeriodic()
  {
	  Scheduler::GetInstance()->Run();
  }
};

START_ROBOT_CLASS(UltimateAscentBot);
