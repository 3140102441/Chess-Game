#include "InitPlayerCmd.h"
#include "ViewModel.h"

using namespace std;

InitPlayerCmd::InitPlayerCmd(ViewModel& viewmodel): m_viewmodel(viewmodel){}

InitPlayerCmd::~InitPlayerCmd(){}

void InitPlayerCmd::execute()
{
	m_viewmodel.InitPlayer();
}