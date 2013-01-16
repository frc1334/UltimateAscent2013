#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
    Joystick A;
public:
  OI();
    inline float GetArmWork()
    { return A.GetY(); }

};

#endif
