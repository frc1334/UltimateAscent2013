#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
  Joystick* up, deploy;
};
public:
  OI();
  inline float getAButton();
  inline float getYButton();
};

#endif
