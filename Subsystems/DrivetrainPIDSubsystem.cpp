#include "DrivetrainPIDSubsystem.h"
#include "../Robotmap.h"
#include "../Subsystems/MA3Encoder.h"

DrivetrainPIDSubsystem::DrivetrainPIDSubsystem() : PIDSubsystem("DrivetrainPIDSubsystem", 0, 0, 0),
PIDMotor(PID_LOOP_ARM_MOTOR), PIDCoder(ANALOGCHANNEL_POT)
{
	SetSetpoint(0);
	SetInputRange(0, 0);
	Enable();
};


 
