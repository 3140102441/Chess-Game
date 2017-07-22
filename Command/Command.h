#ifndef _COMMAND_H
#define _COMMAND_H

#include "Common.h"

using namespace std;

class Command 
{
public:
	    Command(){}
	    virtual ~Command(){}
        virtual void execute() = 0;
};

#endif
