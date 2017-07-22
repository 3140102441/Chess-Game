#ifndef _MOUSE_MOVE_CMD_H
#define _MOUSE_MOVE_CMD_H

#include "Common.h"
#include "Command.h"

class ViewModel;

class MouseMoveCmd: public Command
{
private:
	ViewModel& m_viewmodel;
public:
	MouseMoveCmd(ViewModel& viewmodel);
	~MouseMoveCmd();
	virtual void execute();
};

#endif
