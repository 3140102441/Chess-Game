#ifndef _INIT_COMPUTER_CMD_H
#define _INIT_COMPUTER_CMD_H

#include "Common.h"
#include "Command.h"


class ViewModel;

class InitComputerCmd: public Command
{
private:
    ViewModel& m_viewmodel;
public:
	InitComputerCmd(ViewModel& viewmodel);
	~InitComputerCmd();
    virtual void execute();
};

#endif
