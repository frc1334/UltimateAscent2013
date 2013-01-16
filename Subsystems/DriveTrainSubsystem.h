#ifndef DRIVETRAIN_SUBSYSTEM_H
#define DRIVETRAIN_SUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class PIDDriveTrainSubsystem: public PIDSubsystem
{
private:
    Jaguar PIDMotor
    Analogchannel Encoder
public:
    static final
{
        double UPPER_BOUND;
        double LOWER_BOUND;
        double UP_POSITION;
}
    Arm();

}


class DriveTrainSubsystem: public Subsystem
{
private:
    Jaguar LeftMotor, RightMotor;
public:
  DriveTrainSubsystem();
  void InitDefaultCommand();
  void Drive(float Left, float Right);
};

#endif*/
