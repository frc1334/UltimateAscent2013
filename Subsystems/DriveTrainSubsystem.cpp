#include "DriveTrainSubsystem.h"
#include "../Robotmap.h"

static DriveTrainSubsystem::final (double UPPER_BOUND, double LOWER_BOUND, double UP_POSITION)
{
    UPPER_BOUND = 0.024;
    LOWER_BOUND = UPPER_BOUND + 0.92;
    UP_POSITION = UPPER_BOUND + 0.150;
}

DriveTrainSubsystem::PIDDriveTrainSubsystem() : PIDSubsystem("DriveTrainSubsystem")
    PIDMotor(PID_LOOP_ARM_MOTOR)
    Encoder(ANALOGCHANNEL_POT)
{
}

public DriveTrainSubsystem::Arm(){
    super(2.3, 0, 0);

    setSetpointRange(LOWER_BOUND, UPPER_BOUND);
    setSetpoint(UP_POSITION);

    enable();
}


DriveTrainSubsystem::DriveTrainSubsystem() : Subsystem("DriveTrainSubsystem")
    LeftMotor(LEFT_MOTOR),RightMotor(RIGHT_MOTOR)
{
}

void DriveTrainSubsystem::InitDefaultCommand()
{
    SetDefault(NewCommand());
}

void DriveTrainSubsystem::Drive(float xxxx, float yyyy)
{
	RightMotor.Set(xxxx);
	LeftMotor.Set(yyyy);
}
