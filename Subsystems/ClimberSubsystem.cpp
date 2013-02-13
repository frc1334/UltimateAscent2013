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
double ClimberSubsystem::ReturnPIDInput()
{
	return leftEncoder.GetPeriod();
}
void ClimberSubsystem::Climb(bool climb)
{
//	leftSwitch.DigitalInput(CLIMB_LIMITSWITCH_A);
	//rightSwitch.DigitalInput(CLIMB_LIMITSWITCH_B);
	//tiltSwitch.DigitalInput(CLIMB_LIMITSWITCH_C);
}
void ClimberSubsystem::Reset()
{
	while (topSwitch.Get())
	{
			climbMotor.Set(-3.0f);
			if(bottomSwitch.Get())
			{
				climbMotor.Set(0.0f);
			}
	}
		
	climbEncoder.Reset();
	
	climbEncoder.Start();
	
	climbController.Enable();
}
void ClimberSubsystem::SetTiltDegrees(float degrees)
{
	degrees = Utility::Map(minDegrees, maxDegrees, 0, EncoderTicksTilt, degrees); // map the shooter angles to the encoder ticks
	tiltLoop.SetSetpoint(degrees);
}

