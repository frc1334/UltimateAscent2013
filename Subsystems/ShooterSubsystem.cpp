#include "ShooterSubsystem.h"
#include "../Robotmap.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem"),
 shootMotor(SHOOT_MOTOR), tiltMotorLeft(TILT_MOTOR_LEFT), tiltMotorRight(TILT_MOTOR_RIGHT),
 tiltEncoderLeft(TILT_ENCODER_LEFT_A, TILT_ENCODER_LEFT_B), tiltEncoderRight(TILT_ENCODER_RIGHT_A, TILT_ENCODER_RIGHT_B),
 tiltMotorLeftLoop(tiltP, tiltI, tiltD, &tiltEncoderLeft, &tiltMotorLeft),
 tiltMotorRightLoop(tiltP, tiltI, tiltD, &tiltEncoderRight, &tiltMotorRight)
{
	tiltEncoderLeft.Start();
	tiltEncoderRight.Start();
	tiltEncoderLeft.SetPIDSourceParameter(Encoder::kDistance);
	tiltEncoderRight.SetPIDSourceParameter(Encoder::kDistance);
	tiltMotorLeftLoop.SetInputRange(0, 2000);
	tiltMotorRightLoop.SetInputRange(0, 2000);
	tiltMotorLeftLoop.SetOutputRange(-1.0f, 1.0f);
	tiltMotorRightLoop.SetOutputRange(-1.0f, 1.0f);
	tiltMotorLeftLoop.Enable();
	tiltMotorRightLoop.Enable();
	tiltMotorLeftLoop.SetSetpoint(1000);
}

void ShooterSubsystem::InitDefaultCommand()
{
/*  SetDefaultCommand(new ());*/
}

void ShooterSubsystem::SetTilt(float tilt)
{
	
}

void ShooterSubsystem::SetSpeed(float speed)
{
	
}

void ShooterSubsystem::FireDisc()
{
	
}

void ShooterSubsystem::debug()
{
	std::cout << "" << std::endl;
}
