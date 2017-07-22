#include "InitComputerCmd.h"
#include "ViewModel.h"

using namespace std;

InitComputerCmd::InitComputerCmd(ViewModel& viewmodel): m_viewmodel(viewmodel){}

InitComputerCmd::~InitComputerCmd(){}

void InitComputerCmd::execute()
{
	m_viewmodel.InitComputer();
}