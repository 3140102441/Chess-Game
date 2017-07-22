#include "MouseMoveCmd.h"
#include "ViewModel.h"

using namespace std;

MouseMoveCmd::MouseMoveCmd(ViewModel& viewmodel): m_viewmodel(viewmodel){}

MouseMoveCmd::~MouseMoveCmd(){}

void MouseMoveCmd::execute()
{
	m_viewmodel.MouseMove();
}