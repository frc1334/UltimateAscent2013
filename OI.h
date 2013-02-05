#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick Joystick_shoot;
public:
  OI();
  
  inline bool ButtonGet()
  { return Joystick_shoot.GetTop ();}
  inline float GetTrigger()
  {return Joystick_shoot.GetZ();}
};

#endif
