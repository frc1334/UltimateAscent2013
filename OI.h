#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
    Joystick Joystick_Drive;
public:
    OI();
    
    inline float getDriveSteering() { return Joystick_Drive.GetX(); }
    inline float getDriveThrottle() { return Joystick_Drive.GetZ(); }
};

#endif

