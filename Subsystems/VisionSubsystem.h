#ifndef VISION_SUBSYSTEM_H
#define VISION_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class VisionSubsystem: public Subsystem
{
private:
	AxisCamera& camera;
	static const double HORIZONTAL_STRIP_ASPECT = 4/1.5;
	static const double VERTICAL_STRIP_ASPECT = 4/1.5;
public:
  VisionSubsystem();
  void InitDefaultCommand();
  
  void UpdateTracking();
};

#endif
