#ifndef SHOOTER_SUBSYSTEM_H
#define SHOOTER_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShooterSubsystem : public Subsystem, public PIDSource, public PIDOutput
{
private:
  static const float shootP = 0.00156f;
  static const float shootI = 0.00891f;
  static const float shootD = 0.0000683f;

  Talon shootMotor;
  GearTooth shootEncoder;
  PIDController shootLoop;
  Solenoid shootSolenoid, tiltSolenoid;
  bool shootingWheelEnabled;
  int debug_console_delay_counter;
  Timer g_timer;
public:
  ShooterSubsystem();
  void InitDefaultCommand();
  void SetTilt(bool tilt);		//SETS SHOOTER TILT SOLENOIDS
  void SetSpeed(float speed);	//SETS SHOOTER WHEEL SPEED SETPOINT IN RPM
  void SetFire(bool fire);		//SETS SHOOTER DISK FEED SOLENOID
  inline bool GetFire() { return shootSolenoid.Get(); }
  void ToggleShooterWheel(bool state);	//TOGGLES SHOOTER WHEEL ON/OFF
  double PIDGet();				//RETURNS SHOOTER WHEEL SPEED IN RPM
  void PIDWrite(float output);	//DO NOT USE
  void Debug();					//DEBUG CONSOLE
  inline float GetSpeedSetpoint(){return shootLoop.GetSetpoint(); }
  bool Jiggly();
  bool ShootDiscs(unsigned int shots_fire);
};

#endif
