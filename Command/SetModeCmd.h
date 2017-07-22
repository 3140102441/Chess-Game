#ifndef _SET_MODE_CMD_H
#define _SET_MODE_CMD_H

#include "Common.h"
#include "Command.h"

class ViewModel;

class SetModeCmd: public Command
{
private:
	ViewModel& m_viewmodel;
public:
	SetModeCmd(ViewModel& viewmodel);
	~SetModeCmd();
	virtual void execute();
};

#endif