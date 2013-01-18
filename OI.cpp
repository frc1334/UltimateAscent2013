#include "OI.h"

OI::OI()
{
	up = new Joystick(RobotMap::BUTTON_1);
	deploy = new Joystick(RobotMap::BUTTON_4);
}
inline float OI::getAButton()
{
  return up->GetRawButton(1);
}
inline float OI::getYButton()
{
  return deploy->GetRawButton(4);
}