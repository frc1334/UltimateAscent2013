#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
    Joystick Joystick_Drive;
	Joystick Joystick_Shoot;
public:
  OI();
  
  inline float GetTrigger() { return Joystick_Shoot.GetZ(); }
  inline bool GetLeftBumper() { return Joystick_Shoot.GetRawButton(5); }
  inline bool GetRightBumper() { return Joystick_Shoot.GetRawButton(6); }
  inline bool GetFire() { return Joystick_Shoot.GetRawButton(1); }
  inline float GetFudge() { return Joystick_Shoot.GetTwist(); }
  inline bool GetStart() { return Joystick_Shoot.GetRawButton(8); }
  inline float getDriveSteering() { return Joystick_Drive.GetX(); }
  inline float getDriveThrottle() { return Joystick_Drive.GetZ(); }
  inline float GetDriveSteering() { return Joystick_Drive.GetX(); }
  inline float GetDriveThrottle() { return Joystick_Drive.GetZ(); }
  inline bool GetShiftUp() { return Joystick_Drive.GetRawButton(5); }
  inline bool GetShiftDown() { return Joystick_Drive.GetRawButton(6); }
  inline bool GetTiltState() { return Joystick_Drive.GetRawButton(2); }
};

#endif

