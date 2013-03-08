#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include <math.h>

class OI
{
private:
    Joystick Joystick_Drive;
	Joystick Joystick_Shoot;
	Joystick Joystick_Test;
public:
  OI();
  
  inline float GetTrigger() { return Joystick_Shoot.GetZ(); }
  inline bool GetLeftBumper() { return Joystick_Shoot.GetRawButton(5); }
  inline bool GetRightBumper() { return Joystick_Shoot.GetRawButton(6); }
  inline bool GetFire() { return Joystick_Shoot.GetRawButton(1); }
  inline float GetFudge() { return Joystick_Shoot.GetTwist(); }
  inline bool GetStart() { return Joystick_Shoot.GetRawButton(8); }
  inline float GetDriveSteering() { return -AddDeadZone(Joystick_Drive.GetX(), 0.15f); } // there's a negative hiding in there
  inline float GetDriveThrottle() { return Joystick_Drive.GetZ(); }
  inline bool GetShiftUp() { return Joystick_Drive.GetRawButton(5); }
  inline bool GetShiftDown() { return Joystick_Drive.GetRawButton(6); }
  inline bool GetTiltState() { return Joystick_Drive.GetRawButton(2); }
  inline bool GetDeploy() { return Joystick_Drive.GetRawButton(3); }
  inline bool GetAutoclimb() { return Joystick_Drive.GetRawButton(1); }
  inline float GetClimbFudge() { return AddDeadZone(Joystick_Drive.GetRawAxis(5), 0.15f); }
  inline bool GetTest1() { return Joystick_Test.GetRawButton(1); }
  inline bool GetTest2() { return Joystick_Test.GetRawButton(2); }
  inline bool GetTest3() { return Joystick_Test.GetRawButton(3); }
  inline bool GetTest4() { return Joystick_Test.GetRawButton(4); }
  inline bool GetTest5() { return Joystick_Test.GetRawButton(5); }
  inline bool GetTest6() { return Joystick_Test.GetRawButton(6); }
  inline bool GetTest7() { return Joystick_Test.GetRawButton(7); }
  
  inline float AddDeadZone(float original, float deadzone)
  {
	  return ((fabs(original) <= deadzone) ? 0 : original);
  }
};

#endif

