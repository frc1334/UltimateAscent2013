#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include <math.h>

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
  inline float GetDriveSteering() { return AddDeadZone(Joystick_Drive.GetX(), 0.15f); }
  inline float GetDriveThrottle() { return Joystick_Drive.GetZ(); }
  inline bool GetShiftUp() { return Joystick_Drive.GetRawButton(5); }
  inline bool GetShiftDown() { return Joystick_Drive.GetRawButton(6); }
  inline bool GetTiltState() { return Joystick_Drive.GetRawButton(2); }
  inline bool GetDeploy() { return Joystick_Drive.GetRawButton(3); }
  inline bool GetAutoclimb() { return Joystick_Drive.GetRawButton(1); }
  inline float GetClimbFudge() { return Joystick_Drive.GetTwist(); }
  
  inline float AddDeadZone(float original, float deadzone)
  {
	  float thing = ((fabs(original) <= deadzone) ? 0 : original);
	  printf("%f to %f", original, thing);
	  return thing;
  }
};

#endif

