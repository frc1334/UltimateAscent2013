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
	climbMotor1.Set(0.3f);
	climbMotor2.Set(0.3f);
	while(!bottomSwitch.Get());
	climbMotor1.Set(0.0f);
	climbMotor2.Set(0.0f);
	std::cout << "Reset." << std::endl;
}

void ClimberSubsystem::Deploy()
{
	//climbSolenoid.Set(true);
}

bool ClimberSubsystem::IsDeployed()
{
	return true;//climbSolenoid.Get();
}

void ClimberSubsystem::ManualSet(float speed)
{
	climbMotor1.Set(speed);
	climbMotor2.Set(speed);
	if (!topSwitch.Get() || !bottomSwitch.Get())
	{
		climbMotor1.Set(0.0f);
		climbMotor2.Set(0.0f);
	}
}
void ClimberSubsystem::AutomaticRun()
{
	this->ManualSet(autoForward ? -0.2f : 0.2f);
	if (autoForward && topSwitch.Get())
		autoForward = false;
	else if (!autoForward && bottomSwitch.Get())
		autoForward = true;
}
