#ifndef SHOOTER_SUBSYSTEM_H
#define SHOOTER_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShooterSubsystem : public Subsystem, public PIDSource
{
private:
  static const float tiltP = 1.0;
  static const float tiltI = 0.0;
  static const float tiltD = 0.0;
  static const float shootP = 1.0f;
  static const float shootI = 0.0f;
  static const float shootD = 0.0f;
  static const float tiltTravel = 400; // dummy value

  Jaguar shootMotor, tiltMotorLeft, tiltMotorRight;
  GearTooth shootEncoder;
  Encoder tiltEncoderLeft, tiltEncoderRight;
  PIDController tiltMotorLeftLoop, tiltMotorRightLoop, shootLoop;
  DigitalInput tiltSwitchLeft, tiltSwitchRight;
  Solenoid shootSolenoid;
public:
  ShooterSubsystem();
  void InitDefaultCommand();
  void SetTilt(float degreesTilt);
  void SetSpeed(float speed);
  void SetFire(bool fire);
  void Reset();
  double PIDGet();
};

#endif
