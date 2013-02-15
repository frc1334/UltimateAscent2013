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
private:
	bool deployPre, isDeployed;
public:
	ClimberCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
