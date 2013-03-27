#ifndef AUTONOMOUSSHOOT_COMMAND_H
#define AUTONOMOUSSHOOT_COMMAND_H

#include "../CommandBase.h"

class AutonomousShootCommand: public CommandBase
{
private:
	bool latch_1, latch_2, latch_3;
	Timer delayTimer;
public:
  AutonomousShootCommand();
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif
