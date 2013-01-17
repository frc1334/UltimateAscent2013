#include "OI.h"

OI::OI()
{
	up = new Joystick(RobotMap::BUTTON_6);
	down = new Joystick(RobotMap::BUTTON_5);
}
inline float OI::getLeftBumper()
{
  return up->GetRawButton(5);
}
inline float OI::getRightBumper()
{
  return down->GetRawButton(6);
}