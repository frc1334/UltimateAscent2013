#ifndef MA3ENCODER_H_
#define MA3ENCODER_H_
#include "Commands/Subsystem.h"
#include "WPILib.h"

//The MA3 is a continuous revolution magnetic encoder. From a sensor standpoint, it looks like a 1-turn pot
//Except that it can "wrap around" at 0.
//Mechanically, it can do infinite turns.
//This wrapper around an Analog input provides interfaces for getting the following:
//The # of turns of the encoder since it was initialized. Negative numbers refer to counterclockwise turns whereas positive numbers refer to clockwise turns.
//The current value being returned by the ADC (0-1023);
//The number of units the encoder has turned since it was initialized.
class MA3Encoder : public PIDSource
{
	AnalogChannel* ma3Encoder;
	int turns;
	int lastPosition;
	int offset;

	float voltsPerTick;

	//Call this function to see if the potentiometer has passed 0 since the last time it was called.
	//If it has, this function will increment/decrement turns accordingly.
	void CheckTurned();

	int Tick();

	static const int TICKS_PER_REV;

public:

	MA3Encoder(int channel, int offset = 0, float maxVoltage = 4.6875);
	virtual ~MA3Encoder();

	int GetTurns();
	int GetPosition();
	int Get();

	void SetOffset(int value);
	int GetOffset();

	//Called by the PID classes. Should behave the same as Get()
	double PIDGet();

	void SetTurns(int val);

	void Print();
};

#endif
