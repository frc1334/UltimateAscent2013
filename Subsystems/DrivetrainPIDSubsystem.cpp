#include "DrivetrainPIDSubsystem.h"
#include "../Robotmap.h"
#include "../Subsystems/MA3Encoder.h"

DrivetrainPIDSubsystem::DrivetrainPIDSubsystem() : PIDSubsystem("DrivetrainPIDSubsystem"),
	PIDMotor(PID_LOOP_ARM_MOTOR), PIDCoder(ANALOGCHANNEL_POT)
{
    double UPPER_BOUND=0.024;
    double LOWER_BOUND=UPPER_BOUND+0.92;
    double UP_POSITION=UPPER_BOUND+0.150;


	public DrivePIDSubsystem(){
		super(2.3, 0, 0);

		setSetpointRange(LOWER_BOUND, UPPER_BOUND);
		setSetpoint(UP_POSITION);

		enable();
}
};
