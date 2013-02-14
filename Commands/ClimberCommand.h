#ifndef CLIMBERCOMMAND_H
#define CLIMBERCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author p
 */
class ClimberCommand: public CommandBase
{
public:
	ClimberCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
