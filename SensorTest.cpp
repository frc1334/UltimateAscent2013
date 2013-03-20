#include "WPILib.h"

class BuiltinDefaultCode : public IterativeRobot
{
  Jaguar jags[];
  DigitalInput inputs[];
  Solenoid solenoids[];
public:
	BuiltinDefaultCode(void)
  {
    jags = new Jaguar[10];
    for (unsigned int i = 1; i < 11; ++i)
      jags[i - 1] = Jaguar(i);
    inputs = new DigitalInput[20];
    for (unsigned int i = 1; i < 21; ++i)
      inputs[i - 1] = DigitalInput(i);
    solenoids = new Solenoid[8];
    for (unsigned int i = 1; i < 9; ++i)
      solenoids[i - 1] = Solenoid(i);
	}
	
	
	/********************************** Init Routines *************************************/

	void RobotInit(void)
  {
	}
	
	void DisabledInit(void)
  {
	}

	void AutonomousInit(void)
  {
	}

	void TeleopInit(void)
  {
	}

	/********************************** Periodic Routines *************************************/
	
	void DisabledPeriodic(void)
  {
	}

	void AutonomousPeriodic(void)
  {
		GetWatchdog().Feed();
    for (unsigned int i = 1; i < 11; ++i)
      jags[i - 1].Set(0.00001f);
    for (unsigned int i = 1; i < 21; ++i)
      cout << i << " : " << inputs[i - 1].Get() << " ";
    cout << endl;
    for (unsigned int i = 1; i < 9; ++i)
      solenoids[i - 1].Set()(!solenoids[i - 1].Get());
	}

	
	void TeleopPeriodic(void)
  {
		GetWatchdog().Feed();
	}


/********************************** Continuous Routines *************************************/

	/* 
	void DisabledContinuous(void)
  {
	}

	void AutonomousContinuous(void)
  {
	}

	void TeleopContinuous(void)
  {
	}
	*/
};

START_ROBOT_CLASS(BuiltinDefaultCode);
