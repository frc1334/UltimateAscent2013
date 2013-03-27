#ifndef AUTONOMOUSSHOOT_COMMAND_H
#define AUTONOMOUSSHOOT_COMMAND_H

#include "../CommandBase.h"

class AutonomousShootCommand: public CommandBase
{
private:
	bool latch;
	int discs;
public:
  AutonomousShootCommand(int discs);
  virtual void Initialize();
  virtual void Execute();
  virtual bool IsFinished();
  virtual void End();
  virtual void Interrupted();
};

#endif
