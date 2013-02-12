#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
    Joystick Joystick_drive;
public:
    OI();
    
    inline float GetDriveSteering() { return Joystick_drive.GetX(); }
    inline float GetDriveThrottle() { return Joystick_drive.GetZ(); }
    inline bool GetShiftUp() { return Joystick_drive.GetRawButton(5); }
    inline bool GetShiftDown() { return Joystick_drive.GetRawButton(6); }
    inline bool GetTiltState() { return Joystick_drive.GetRawButton(2); }
};

#endif

