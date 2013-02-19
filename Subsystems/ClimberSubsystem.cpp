#include "ClimberSubsystem.h"
#include "../Robotmap.h"
#include "../Commands/ClimberCommand.h"
#include "../PIDOutputMultiplexer.h"

ClimberSubsystem::ClimberSubsystem() : Subsystem("ClimberSubsystem"),
climbMotor1(CLIMB_MOTOR_1), climbMotor2(CLIMB_MOTOR_2),
climbSolenoid(CLIMB_SOLENOID),
topSwitch(CLIMB_LIMITSWITCH_TOP), bottomSwitch(CLIMB_LIMITSWITCH_BOTTOM),
autoForward(true), topPre(false), bottomPre(false)
{ }

void ClimberSubsystem::InitDefaultCommand()
{
	SetDefaultCommand(new ClimberCommand());
}

void ClimberSubsystem::Reset()
{
	climbMotor1.Set(-0.01f);
	climbMotor2.Set(-0.01f);
	while(!bottomSwitch.Get()) {}
	climbMotor1.Set(0.0f);
	climbMotor2.Set(0.0f);
}

void ClimberSubsystem::Deploy()
{
	climbSolenoid.Set(true);
}

bool ClimberSubsystem::IsDeployed()
{
	return climbSolenoid.Get();
}

void ClimberSubsystem::ManualSet(float speed)
{
	climbMotor1.Set(speed);
	climbMotor2.Set(speed);
	if (topSwitch.Get() || bottomSwitch.Get())
	{
		climbMotor1.Set(0.0f);
		climbMotor2.Set(0.0f);
	}
}
void ClimberSubsystem::AutomaticRun()
{
	this->ManualSet(autoForward ? 1 : -1);
	if (autoForward && topSwitch.Get())
		autoForward = false;
	else if (!autoForward && bottomSwitch.Get())
		autoForward = true;
}
