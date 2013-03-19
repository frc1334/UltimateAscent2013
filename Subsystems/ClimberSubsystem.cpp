#include "ClimberSubsystem.h"
#include "../Robotmap.h"
#include "../Commands/ClimberCommand.h"
#include "../PIDOutputMultiplexer.h"

ClimberSubsystem::ClimberSubsystem() : Subsystem("ClimberSubsystem"),
climbSolenoid(CLIMB_SOLENOID),climbResetSolenoid(CLIMB_RESET),
autoUp(true), topPre(false), bottomPre(false),
climbMotor1(CLIMB_MOTOR_1), climbMotor2(CLIMB_MOTOR_2),
topSwitch(CLIMB_LIMITSWITCH_TOP), bottomSwitch(CLIMB_LIMITSWITCH_BOTTOM)
{
	climbMotor1.Set(0.0f);
	climbMotor2.Set(0.0f);
}

void ClimberSubsystem::InitDefaultCommand()
{
	SetDefaultCommand(new ClimberCommand());
}

//IF CALLED THE ROBOT WILL DEPLOY THE CLIMBER (TILT IT TOWARDS THE PYRAMID)
void ClimberSubsystem::Deploy()
{
	if (IsDeployed())				//ONLY CHANGE THE SOLENOIDS IF THE CLIMBER IS NOT DEPLOYED
	{
		climbSolenoid.Set(true);
		climbResetSolenoid.Set(false);
	}
}

//IF CALLED THE ROBOT WILL UNDEPLOY THE CLIMBER (TILT IT AWAY FROM THE PYRAMID)
void ClimberSubsystem::UnDeploy()
{
	if (!IsDeployed())				//ONLY CHANGE THE SOLENOIDS IF THE CLIMBER IS DEPLOYED
	{
		climbSolenoid.Set(false);
		climbResetSolenoid.Set(true);
	}
}

//MANUALLY CONTROLS THE CLIMBER MOTOR SPEEDS FROM THE SHOOTER JOYSTICK
void ClimberSubsystem::ManualSet(float speed)
{
	//IF THE DRIVER TRIES TO DRIVE THE CLIMBER PAST THE TOP SWITCH, STOP THEM
	if (topSwitch.Get() && (speed < 0 || speed < 0))
	{
		climbMotor1.Set(0.0f);
		climbMotor2.Set(0.0f);
	}
	else if (bottomSwitch.Get() && (speed > 0 || speed > 0))	//IF THE DRIVER TRIES TO DRIVE PAST THE BOTTOM SWITCH, STOP THEM
	{
		climbMotor1.Set(0.0f);
		climbMotor2.Set(0.0f);
	}
	else	//IF NO SWITCHES ARE HIT, ALLOW DRIVER TO MOVE CLIMBER BOTH WAYS.
	{
		if(fabs(speed) >= 0.3f){
			climbMotor1.Set(speed);
			climbMotor2.Set(speed);
		}
		else
		{
			climbMotor1.Set(0.0f);
			climbMotor2.Set(0.0f);
		}
	}
}

//AUTOMATIC CLIMB CODE - TO BE EXTERMINATED
//void ClimberSubsystem::AutomaticRun()
//{
	/*ManualSet(autoUp ? -0.2f : 0.2f);
	if (!topSwitch.Get())
		autoUp = false;
	if (!bottomSwitch.Get())
		autoUp = true;
	*/
//}

//Any information that should go out to console when debugging climbing.
void ClimberSubsystem::Debug()
{
	std::cout << bottomSwitch.Get() << " " 	<< topSwitch.Get() << " " << climbMotor1.Get() 
			<< " " << climbMotor2.Get() << std::endl;
}
