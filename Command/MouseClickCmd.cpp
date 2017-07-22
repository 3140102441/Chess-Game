#include "MouseClickCmd.h"
#include "ViewModel.h"

using namespace std;

MouseClickCmd::MouseClickCmd(ViewModel& viewmodel): m_viewmodel(viewmodel){}

MouseClickCmd::~MouseClickCmd(){}

void MouseClickCmd::execute()
{
	m_viewmodel.MouseClick();
}