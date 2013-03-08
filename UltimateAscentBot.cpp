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
    compressor = new Compressor(COMPRESSOR_SWITCH, COMPRESSOR_RELAY);
  }

  virtual void AutonomousInit()
  {
  }

  virtual void AutonomousPeriodic()
  {
  }

  virtual void TeleopInit()
  {
	  compressor->Start();
  }

  virtual void TeleopPeriodic()
  {
	  Scheduler::GetInstance()->Run();
	  CommandBase::shootersubsystem->Debug();
  }
};

START_ROBOT_CLASS(UltimateAscentBot);
