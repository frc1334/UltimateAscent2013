#include "ClimberSubsystem.h"
#include "../Robotmap.h"
#include "../Commands/ClimberCommand.h"
#include "../PIDOutputMultiplexer.h"

ClimberSubsystem::ClimberSubsystem() : Subsystem("ClimberSubsystem"),
climbMotor1(CLIMB_MOTOR_1), climbMotor2(CLIMB_MOTOR_2),
climbEncoder(CLIMB_ENCODER_CLIMB_A, CLIMB_ENCODER_CLIMB_B),
topSwitch(CLIMB_LIMITSWITCH_TOP),
bottomSwitch(CLIMB_LIMITSWITCH_BOTTOM),
climbSolenoid(CLIMB_SOLENOID),
climbController(climbP, climbI, climbD, &climbEncoder, new PIDOutputMultiplexer(&climbMotor1, &climbMotor2)),
autoForward(true)
{
	climbEncoder.SetPIDSourceParameter(Encoder::kDistance);
	climbController.SetInputRange(0, climberLength);
	climbController.SetOutputRange(-1.0f, 1.0f);
}

void ClimberSubsystem::InitDefaultCommand()
{
	SetDefaultCommand(new ClimberCommand());
}

void ClimberSubsystem::Reset()
{
	while(!bottomSwitch.Get())
	{
			climbMotor1.Set(-0.9f);
			climbMotor1.Set(-0.9f);
			if(bottomSwitch.Get())
			{
				climbMotor1.Set(0.0f);
				climbMotor1.Set(0.0f);
			}
	}
		
	climbEncoder.Reset();
	climbEncoder.Start();
	climbController.Enable();
}

void ClimberSubsystem::Deploy()
{
	climbSolenoid.Set(true);
	climbController.SetSetpoint(deploySetpoint);
}

bool ClimberSubsystem::IsDeployed()
{
	return climbController.GetSetpoint() >= deploySetpoint;
}

void ClimberSubsystem::ManualSet(float setpoint)
{
	climbController.SetSetpoint(setpoint);
}

float ClimberSubsystem::ManualGet()
{
	return climbController.GetSetpoint();
}

void ClimberSubsystem::AutomaticRun()
{
	climbController.SetSetpoint(climbController.GetSetpoint() + (autoForward ? 1 : -1));
	if (autoForward && climbController.GetSetpoint() > maxSetpoint)
		autoForward = false;
	else if (!autoForward && climbController.GetSetpoint() < minSetpoint)
		autoForward = true;
}
