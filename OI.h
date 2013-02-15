#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick Joystick_shoot;
	Joystick Joystick_Drive;
public:
  OI();
  
  inline float GetTrigger()
  { return Joystick_shoot.GetZ(); }
  inline bool GetLeftBumper()
  { return Joystick_shoot.GetRawButton(5); }
  inline bool GetRightBumper()
  { return Joystick_shoot.GetRawButton(6); }
  inline bool GetFire()
  { return Joystick_shoot.GetRawButton(1); }
  inline bool GetDeploy()
  { return Joystick_Drive.GetRawButton(3); }
  inline bool GetAutoclimb()
  { return Joystick_Drive.GetRawButton(1); }
  inline float GetClimbFudge()
  { return Joystick_Drive.GetTwist(); }
};

#endif
