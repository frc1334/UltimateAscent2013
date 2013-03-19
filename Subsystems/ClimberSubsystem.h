#ifndef CLIMBER_SUBSYSTEM_H
#define CLIMBER_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ClimberSubsystem: public Subsystem
{
private:
	Solenoid climbSolenoid, climbResetSolenoid;
	bool autoUp, topPre, bottomPre;
public:
	Talon climbMotor1, climbMotor2;
	DigitalInput topSwitch, bottomSwitch;
  ClimberSubsystem();
  void InitDefaultCommand();
  void Deploy();				//TILTS CLIMBER AWAY FROM ROBOT
  void UnDeploy();				//TILTS CLIMBER BACK ONTO ROBOT
  bool IsDeployed() {return climbSolenoid.Get();};			//RETURNS IF THE CLIMBER IS DEPLOYED
  void ManualSet(float speed);	//SETS THE CLIMBER MOTORS FROM THE SHOOTER JOYSTICK
//  void AutomaticRun();			//AUTOMATICALLY CLIMBS THE PYRAMID
  void Debug();					//DEBUG TEXT FOR CONSOLE
  
};

#endif
