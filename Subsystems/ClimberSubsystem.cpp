#include "ClimberSubsystem.h"
#include "../Robotmap.h"

ClimberSubsystem::ClimberSubsystem() : Subsystem("ClimberSubsystem"),
leftMotor(CLIMBER_MOTOR_LEFT),
rightMotor(CLIMBER_MOTOR_RIGHT),
tiltMotor(CLIMBER_MOTOR_TILT),
leftLoop(0,0,0,&leftEncoder,&leftMotor),
rightLoop(0,0,0,&rightEncoder,&rightMotor),
tiltLoop(0,0,0,&tiltEncoder, &tiltMotor),
leftEncoder(CLIMBER_ENCODER_LEFT_A,CLIMBER_ENCODER,LEFT_B),
rightEncoder(CLIMBER_ENCODER_RIGHT_A,CLIMBER_ENCODER_RIGHT_B),
tiltEncoder(CLIMBER_ENCODER_TILT_A, CLIMBER_ENCODER_TILT_B),
tiltSwitch(CLIMBER_LIMITSWITCH_TILT),
leftSwitch(CLIBMER_LIMITSWITCH_LEFT),
rightSwitch(CLIMBER_LIMITSWITCH_RIGHT)
{
}
    
void ClimberSubsystem::InitDefaultCommand()
{
}
