#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include <math.h>

class OI
{
private:
    Joystick Joystick_Drive;	//JOYSTICK PORT 1
	Joystick Joystick_Shoot;	//JOYSTICK PORT 2
	Joystick Joystick_Test;		//JOYSTICK PORT 3
public:
  OI();
  
  //**ALL JOYSTICK DEFINITIONS SHOULD BE FROM LOW TO HIGH JOYSTICK PORT
  //**AND FROM LOW TO HIGH RAW BUTTON NUMBER
  
  /////////////////////////
  // DRIVER JOYSTICK (1) //
  /////////////////////////  
  inline float GetDriveSteering() { return -AddDeadZone(Joystick_Drive.GetX(), 0.15f); } // there's a negative hiding in there
  inline float GetDriveThrottle() { return Joystick_Drive.GetZ(); }
  inline bool GetAutoclimb() { return Joystick_Drive.GetRawButton(1); }
  inline bool GetTiltState() { return Joystick_Drive.GetRawButton(2); }
  inline bool GetTiltBotUp() { return Joystick_Drive.GetRawButton(3); }
  inline bool GetTiltBotDown() { return Joystick_Drive.GetRawButton(4);}
  inline bool GetShiftUp() { return Joystick_Drive.GetRawButton(5); }
  inline bool GetShiftDown() { return Joystick_Drive.GetRawButton(6); }

  //////////////////////////
  // SHOOTER JOYSTICK (2) //
  //////////////////////////
  inline float GetTrigger() { return Joystick_Shoot.GetZ(); }
  inline float GetClimbJoystick() { return AddDeadZone(Joystick_Shoot.GetRawAxis(5), 0.15f); }
  inline bool GetDeploy() { return Joystick_Shoot.GetRawButton(3); }
  inline bool GetShooterTilt() { return Joystick_Shoot.GetRawButton(4);}
  inline bool GetShootLeftBumper(){ return Joystick_Shoot.GetRawButton(5); }
  inline bool GetFire() { return Joystick_Shoot.GetRawButton(6); }
  inline bool GetUnDeploy() { return Joystick_Shoot.GetRawButton(7);}
  inline bool GetStart() { return Joystick_Shoot.GetRawButton(8); }

  ////////////////////////
  // DEBUG JOYSTICK (3) //
  ////////////////////////  
  inline bool GetTest1() { return Joystick_Test.GetRawButton(1); }
  inline bool GetTest2() { return Joystick_Test.GetRawButton(2); }
  inline bool GetTest3() { return Joystick_Test.GetRawButton(3); }
  inline bool GetTest4() { return Joystick_Test.GetRawButton(4); }
  inline bool GetTest5() { return Joystick_Test.GetRawButton(5); }
  inline bool GetTest6() { return Joystick_Test.GetRawButton(6); }
  inline bool GetTest7() { return Joystick_Test.GetRawButton(7); }
  
  ///////////////////////
  // UTILITY FUNCTIONS //
  ///////////////////////  
  inline float AddDeadZone(float original, float deadzone)
  {
	  return ((fabs(original) <= deadzone) ? 0 : original);
  }
};

#endif

