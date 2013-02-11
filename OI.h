#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick Joystick_shoot;
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
  inline float GetFudge()
  { return 42.0; } // dummy val, will fill out later
};

#endif
