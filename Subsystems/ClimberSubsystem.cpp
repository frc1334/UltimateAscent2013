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
	
	
}
    
void ClimberSubsystem::InitDefaultCommand()
{
}
