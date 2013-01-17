#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
    Joystick Joystick_A;
public:
    OI();
    inline float getDrive(){return Joystick_A.GetY();};
};

#endif

