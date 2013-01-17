#ifndef PID_SUBSYSTEM_H
#define PID_SUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class DrivetrainPIDSubsystem: public PIDSubsystem
{
private:
    Jaguar PIDMotor
    MA3Encoder PIDCoder
public:
    DrivetrainPIDSubsystem();
}
