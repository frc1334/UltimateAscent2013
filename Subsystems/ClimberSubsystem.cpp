#include "ClimberSubsystem.h"
#include "../Robotmap.h"

ClimberSubsystem::ClimberSubsystem() : Subsystem("ClimberSubsystem")
{
	
}

void ClimberSubsystem::InitDefaultCommand()
{
    leftanalogchannel = new AnalogChannel();
    rightanalogchannel = new AnalogChannel;
    left = new PIDController(0,0,0, leftanalogchannel, leftClimbMotor);
    right = new PIDController(0,0,0, rightanalogchannel, rightClimbMotor);
    leftClimbMotor = new Talon();
    rightClimbMotor = new Talon();
}
double ClimberSubsystem::returnPIDInput()
{
	
}
void ClimberSubsystem::usePIDOutput(output)
{
	
}
