#ifndef _REGRET_CMD_H
#define _REGRET_CMD_H

#include "Common.h"
#include "Command.h"


class ViewModel;

class RegretCmd: public Command
{
private:
	ViewModel& m_viewmodel;
public:
	RegretCmd(ViewModel& viewmodel);
	~RegretCmd();
	virtual void execute();
};

#endif
