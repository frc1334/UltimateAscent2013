#include "ClimberSubsystem.h"
#include "../Robotmap.h"
#include "../Utility.h"

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
rightSolenoid(1,1),
leftLoop(P,I,D,&leftEncoder, &leftMotor),
rightLoop(P,I,D,&rightEncoder, &rightMotor),
tiltLoop(P,I,D,&tiltEncoder, &tiltMotor)
{
	leftEncoder.Start();
	rightEncoder.Start();
	tiltEncoder.Start();
	
	leftEncoder.SetPIDSourceParameter(Encoder::kDistance);
	rightEncoder.SetPIDSourceParameter(Encoder::kDistance);
	tiltEncoder.SetPIDSourceParameter(Encoder::kDistance);
	
	tiltLoop.SetInputRange(0,EncoderTicksTilt);
	leftLoop.SetInputRange(0, EncoderTicksFirstBar);
	rightLoop.SetInputRange(0,EncoderTicksFirstBar);
	
	leftLoop.SetOutputRange(-1.0f, 1.0f);
	rightLoop.SetOutputRange(-1.0f, 1.0f);
	tiltLoop.SetOutputRange(0,0);
	
	leftLoop.SetContinuous(false);
	rightLoop.SetContinuous(false);
	tiltLoop.SetContinuous(false);
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
	leftSwitch.DigitalInput(CLIMB_LIMITSWITCH_A);
	rightSwitch.DigitalInput(CLIMB_LIMITSWITCH_B);
	tiltSwitch.DigitalInput(CLIMB_LIMITSWITCH_C);
}
void ClimberSubsystem::Reset()
{
	while (leftSwitch.Get() || rightSwitch.Get())
	{
			if(leftSwitch.Get())
			{
				leftMotor.Set(0.0f);
			}
				
			if(rightSwitch.Get())
			{
				rightMotor.Set(0.0f);
			}
	}
		
	leftEncoder.Reset();
	rightEncoder.Reset();
	tiltEncoder.Reset();
	
	leftEncoder.Start();
	rightEncoder.Start();
	tiltEncoder.Start();
	
	leftLoop.Enable();
	rightLoop.Enable();
	tiltLoop.Enable();
}
void ClimberSubsystem::SetTiltDegrees(float degrees)
{
	degrees = Utility::Map(minDegrees, maxDegrees, 0, EncoderTicksTilt, degrees); // map the shooter angles to the encoder ticks
	tiltLoop.SetSetpoint(degrees);
}

