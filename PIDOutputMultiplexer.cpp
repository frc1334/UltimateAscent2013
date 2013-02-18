#include "PIDOutputMultiplexer.h"

PIDOutputMultiplexer::PIDOutputMultiplexer(PIDOutput* out1, PIDOutput* out2)
{
	this->out1 = out1;
	this->out2 = out2;
}

void PIDOutputMultiplexer::PIDWrite(float output)
{
	out1->PIDWrite(output);
	out2->PIDWrite(output);
}
