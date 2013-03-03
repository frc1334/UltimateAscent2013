#ifndef SHOOTER_SUBSYSTEM_H
#define SHOOTER_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShooterSubsystem : public Subsystem, public PIDSource, public PIDOutput
{
private:
  static const float tiltP  = 0.001f;
  static const float tiltI  = 0.0f;
  static const float tiltD  = 0.002f;
  static const float shootP = 0.001f;
  static const float shootI = 0.0005f;
  static const float shootD = 0.0f;
  static const float tiltTravel = 400; // dummy value

  Talon shootMotor, tiltMotorLeft, tiltMotorRight;
  GearTooth shootEncoder;
  Encoder tiltEncoderLeft, tiltEncoderRight;
  PIDController tiltMotorLeftLoop, tiltMotorRightLoop, shootLoop;
  DigitalInput tiltSwitchLeft, tiltSwitchRight;
  Solenoid shootSolenoid;
public:
  static const int minDegrees = 0;
  static const int maxDegrees = 100;
  
  ShooterSubsystem();
  void InitDefaultCommand();
  void SetTilt(float degreesTilt);
  void SetSpeed(float speed);
  void SetFire(bool fire);
  void SetShooting(bool enabled);
  void Reset();
  double PIDGet();
  void PIDWrite(float output);
  void Debug();
};

#endif
