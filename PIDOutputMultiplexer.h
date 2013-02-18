#ifndef PIDOUTPUTMULTIPLEXER
#define PIDOUTPUTMULTIPLEXER

#include "WPILib.h"

class PIDOutputMultiplexer : public PIDOutput
{
private:
	PIDOutput* out1;
	PIDOutput* out2;
public:
	PIDOutputMultiplexer(PIDOutput* out1, PIDOutput* out2);
	
	virtual void PIDWrite(float output);
};

#endif
