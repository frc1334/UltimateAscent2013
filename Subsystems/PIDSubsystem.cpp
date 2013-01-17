#include "PIDSubsystem.h"
#include "../Robotmap.h"
#include "/MA3Encoder.h"

DrivetrainPIDSubsystem::DrivetrainPIDSubsystem() : PIDSubsystem("PIDSubsystem")
{
    double UPPER_BOUND=0.024;
    double LOWER_BOUND=UPPER_BOUND+0.92;
    double UP_POSITION=UPPER_BOUND+0.150;

    PIDMotor(PID_LOOP_ARM_MOTOR)
    MA3ENCODER(ANALOGCHANNEL_POT)
}

public DriveTrainSubsystem(){
    super(2.3, 0, 0);

    setSetpointRange(LOWER_BOUND, UPPER_BOUND);
    setSetpoint(UP_POSITION);

    enable();
}
