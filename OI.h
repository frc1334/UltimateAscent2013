#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
  Joystick* up, down;
public:
  OI();
  inline float getLeftBumper();
  inline float getRightBumper();
};

#endif
