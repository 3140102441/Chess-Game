#include "SetModeCmd.h"
#include "ViewModel.h"

using namespace std;

SetModeCmd::SetModeCmd(ViewModel& viewmodel): m_viewmodel(viewmodel){}

SetModeCmd::~SetModeCmd(){}

void SetModeCmd::execute()
{
	m_viewmodel.SetMode();
}