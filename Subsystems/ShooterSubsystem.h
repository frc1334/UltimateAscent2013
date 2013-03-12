#ifndef SHOOTER_SUBSYSTEM_H
#define SHOOTER_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShooterSubsystem : public Subsystem, public PIDSource, public PIDOutput
{
private:
  static const float tiltP  = 0.0f;
  static const float tiltI  = 0.000002f;
  static const float tiltD  = 0.0f;
  static const float shootP = 0.00156f;
  static const float shootI = 0.00891f;
  static const float shootD = 0.0000683f;
  static const float tiltTravel = 4000;

  Talon shootMotor, tiltMotorLeft, tiltMotorRight;
  GearTooth shootEncoder;
  Encoder tiltEncoderLeft, tiltEncoderRight;
  PIDController shootLoop, tiltLoopLeft, tiltLoopRight;
  DigitalInput tiltSwitchLeft, tiltSwitchRight;
  Solenoid shootSolenoid, tiltSolenoid;
  bool shooting, derp;
  float p, i, d;
public:
  ShooterSubsystem();
  void InitDefaultCommand();
  void SetTilt(bool tilt);
  void SetSpeed(float speed);
  void SetFire(bool fire);
  void SetShooting(bool enabled);
  void AutomaticShooting(float delay);
  void Reset();
  double PIDGet();
  void PIDWrite(float output);
  void Debug();
};

#endif
