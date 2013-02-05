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
};

#endif
