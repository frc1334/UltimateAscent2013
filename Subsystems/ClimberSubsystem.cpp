#include "ClimberSubsystem.h"
#include "../Robotmap.h"
#include "../Utility.h"

ClimberSubsystem::ClimberSubsystem() : Subsystem("ClimberSubsystem"),
climbMotor(CLIMB_MOTOR),
climbEncoder(CLIMB_ENCODER_CLIMB_A, CLIMB_ENCODER_CLIMB_B),
topSwitch(CLIMB_LIMITSWITCH_TOP),
bottomSwitch(CLIMB_LIMITSWITCH_BOTTOM),
climbSolenoid(2, 3),
climbController(P, I, D, &climbEncoder, &climbMotor)
{
	climbEncoder.SetPIDSourceParameter(Encoder::kDistance);
	climbController.SetInputRange(0, climberLength);
	climbController.SetOutputRange(-1.0f, 1.0f);
}

void ClimberSubsystem::InitDefaultCommand()
{
	//SetDefaultCommand(new ClimberCommand());
}
void ClimberSubsystem::Deploy()
{

}
bool ClimberSubsystem::IsDeployed()
{
	
}
void ClimberSubsystem::Reset()
{
	while(!bottomSwitch.Get())
	{
			climbMotor.Set(-0.9f);
			if(bottomSwitch.Get())
			{
				climbMotor.Set(0.0f);
			}
	}
		
	climbEncoder.Reset();
	climbEncoder.Start();
	climbController.Enable();
}

