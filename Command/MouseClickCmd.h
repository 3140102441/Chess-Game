#ifndef _MOUSE_CLICK_CMD_H
#define _MOUSE_CLICK_CMD_H

#include "Common.h"
#include "Command.h"


class ViewModel;

class MouseClickCmd: public Command
{
private:
	ViewModel& m_viewmodel;
public:
	MouseClickCmd(ViewModel& viewmodel);
	~MouseClickCmd();
	virtual void execute();
};

#endif
