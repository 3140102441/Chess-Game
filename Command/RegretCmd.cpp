#include "RegretCmd.h"
#include "ViewModel.h"

using namespace std;

RegretCmd::RegretCmd(ViewModel& viewmodel): m_viewmodel(viewmodel){}

RegretCmd::~RegretCmd(){}

void RegretCmd::execute()
{
	m_viewmodel.Regret();
}