#include "MA3Encoder.h"
#include <cassert>
#include "../Robotmap.h"

const int MA3Encoder::TICKS_PER_REV = 1024;

MA3Encoder::MA3Encoder(int channel, int offset, float maxVoltage)
{
	ma3Encoder = new AnalogChannel(channel);
	turns = 0;

	voltsPerTick = TICKS_PER_REV / maxVoltage;

	this->offset = offset;

	lastPosition = Tick();
}

MA3Encoder::~MA3Encoder()
{
	delete ma3Encoder;
}

int MA3Encoder::GetTurns()
{
	CheckTurned();
	return turns;
}

int MA3Encoder::GetPosition()
{
	CheckTurned();
	return Tick();
}

int MA3Encoder::Get()
{
	CheckTurned();
	return turns * TICKS_PER_REV + Tick();
}

double MA3Encoder::PIDGet()
{
	return Get();
}

void MA3Encoder::CheckTurned()
{
	int position = Tick();
	int diff = lastPosition - position;

	if (diff > TICKS_PER_REV * 0.5)
		turns++;
	else if (diff < -TICKS_PER_REV * 0.5)
		turns--;

	lastPosition = position;
}

int MA3Encoder::Tick()
{
	static double highestVoltage = 0;
	if (ma3Encoder->GetVoltage() > highestVoltage)
	{
		highestVoltage = ma3Encoder->GetVoltage();
	}

	return (int)(ma3Encoder->GetVoltage() * voltsPerTick) + offset;
}

void MA3Encoder::SetOffset(int value)
{
	offset = value;
	lastPosition = Tick();
}

int MA3Encoder::GetOffset()
{
	return offset;
}

void MA3Encoder::SetTurns(int val)
{
	turns = val;
}

void MA3Encoder::Print()
{
	int tick = Tick();

	printf(
		"Turns: %d Voltage: %.2f Tick: %d Position: %d\n",
		turns,
		ma3Encoder->GetVoltage(),
		tick,
		turns * TICKS_PER_REV + tick
	);
}
