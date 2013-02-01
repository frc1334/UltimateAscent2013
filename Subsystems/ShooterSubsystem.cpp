#include "ShooterSubsystem.h"
#include "../Robotmap.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem"),
 shootMotor(SHOOT_MOTOR), tiltMotorLeft(TILT_MOTOR_LEFT), tiltMotorRight(TILT_MOTOR_RIGHT),
 tiltEncoderLeft(TILT_ENCODER_LEFT_A, TILT_ENCODER_LEFT_B), tiltEncoderRight(TILT_ENCODER_RIGHT_A, TILT_ENCODER_RIGHT_B),
 tiltMotorLeftLoop(tiltP, tiltI, tiltD, &tiltEncoderLeft, &tiltMotorLeft),
 tiltMotorRightLoop(tiltP, tiltI, tiltD, &tiltEncoderRight, &tiltMotorRight)
{
	tiltMotorLeftLoop.Enable();
	tiltMotorRightLoop.Enable();
	tiltMotorLeftLoop.SetSetpoint(9);
}

void ShooterSubsystem::InitDefaultCommand()
{
/*  SetDefaultCommand(new ());*/
}

void SetTilt(float tilt)
{
	
}

void SetSpeed(float speed)
{
	
}

void FireDisc()
{
	
}
