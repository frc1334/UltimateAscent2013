#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
<<<<<<< HEAD
    Joystick Joystick_Drive;
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
  { return Joystick_shoot.GetTwist(); }
  inline bool GetStart()
  { return Joystick_shoot.GetRawButton(8); }
  inline float getDriveSteering()
  { return Joystick_Drive.GetX(); }
  inline float getDriveThrottle()
  { return Joystick_Drive.GetZ(); }
=======
    Joystick Joystick_drive;
public:
    OI();
    
    inline float GetDriveSteering() { return Joystick_drive.GetX(); }
    inline float GetDriveThrottle() { return Joystick_drive.GetZ(); }
    inline bool GetShiftUp() { return Joystick_drive.GetRawButton(5); }
    inline bool GetShiftDown() { return Joystick_drive.GetRawButton(6); }
    inline bool GetTiltState() { return Joystick_drive.GetRawButton(2); }
>>>>>>> origin/drivetrain
};

#endif

