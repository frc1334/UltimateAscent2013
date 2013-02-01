#ifndef SHOOTER_SUBSYSTEM_H
#define SHOOTER_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShooterSubsystem: public Subsystem
{
private:
  static const float tiltP = 1.0;
  static const float tiltI = 0.0;
  static const float tiltD = 0.0;

  Jaguar shootMotor, tiltMotorLeft, tiltMotorRight;
  Encoder tiltEncoderLeft, tiltEncoderRight;
  PIDController tiltMotorLeftLoop, tiltMotorRightLoop;
public:
  ShooterSubsystem();
  void InitDefaultCommand();
  void SetTilt(float tilt);
  void SetSpeed(float speed);
  void FireDisc();
  void debug();
};

#endif
