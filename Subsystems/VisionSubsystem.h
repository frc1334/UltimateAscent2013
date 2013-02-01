#ifndef VISION_SUBSYSTEM_H
#define VISION_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class VisionSubsystem: public Subsystem
{
private:
	AxisCamera camera;
public:
  VisionSubsystem();
  void InitDefaultCommand();
};

#endif
