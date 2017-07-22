#ifndef _INIT_PLAYER_CMD_H
#define _INIT_PLAYER_CMD_H

#include "Common.h"
#include "Command.h"


class ViewModel;

class InitPlayerCmd: public Command
{
private:
    ViewModel& m_viewmodel;
public:
	InitPlayerCmd(ViewModel& viewmodel);
	~InitPlayerCmd();
    virtual void execute();
};

#endif
