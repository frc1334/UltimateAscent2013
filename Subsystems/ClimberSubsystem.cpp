#include "ClimberSubsystem.h"
#include "../Robotmap.h"

ClimberSubsystem::ClimberSubsystem() : Subsystem("ClimberSubsystem"),
leftMotor(CLIMB_MOTOR_LEFT),
rightMotor(CLIMB_MOTOR_RIGHT),
tiltMotor(CLIMB_MOTOR_TILT),
leftEncoder(CLIMB_ENCODER_LEFT_A, CLIMB_ENCODER_LEFT_B),
rightEncoder(CLIMB_ENCODER_RIGHT_A, CLIMB_ENCODER_RIGHT_B),
tiltEncoder(CLIMB_ENCODER_TILT_A, CLIMB_ENCODER_TILT_B),
tiltSwitch(CLIMB_LIMITSWITCH_TILT),
leftSwitch(CLIMB_LIMITSWITCH_LEFT),
rightSwitch(CLIMB_LIMITSWITCH_RIGHT),
leftSolenoid(2,3),
rightSolenoid(1),
leftLoop(P,I,D,&leftEncoder,&leftMotor),
rightLoop(P,I,D,&rightEncoder,&rightMotor),
tiltLoop(P,I,D,&tiltEncoder, &tiltMotor)
{
	leftEncoder.Start();
	rightEncoder.Start();
	tiltEncoder.Start();
	leftEncoder.SetPIDSourceParameter(Encoder::kDistance);
	rightEncoder.SetPIDSourceParameter(Encoder::kDistance);
	tiltEncoder.SetPIDSourceParameter(Encoder::kDistance);	
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
void ClimberSubsystem::SetPosition(int bar, bool tilt, float deg)
{
	if(bar == 0)
	{
		leftLoop.SetSetpoint(bar + 1);
		rightLoop.SetSetpoint(bar + 1);
	}
	if(bar == 0 && tilt)
	{
		leftLoop.SetSetpoint(bar+1);
		rightLoop.SetSetpoint(bar+1);
		
	}
}
int ClimberSubsystem::GetPosition()
{
	return currentBar;
}
bool ClimberSubsystem::IsAtTop()
{
	if(currentBar == 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}
