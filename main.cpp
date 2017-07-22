#include "View.h"
#include "ViewModel.h"
#include "choose.h"
#include "Model.h"
#include "Common.h"
#include "mainview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    shared_ptr<View> sp_View;
    shared_ptr<ViewModel> sp_ViewModel;
    shared_ptr<Model> sp_Model;
    shared_ptr<Choose> sp_Choose;
    shared_ptr<MainView> sp_MainView;

    sp_View = make_shared<View>();
    sp_ViewModel = make_shared<ViewModel>();
    sp_Model = make_shared<Model>();
    sp_Choose = make_shared<Choose>();
    sp_MainView = make_shared<MainView>();

    sp_View->setMouseMoveCmd(sp_ViewModel->getMouseMoveCmd());
    sp_View->setMouseClickCmd(sp_ViewModel->getMouseClickCmd());
    sp_View->setRegretCmd(sp_ViewModel->getRegretCmd());
    sp_View->setCommandParam(sp_ViewModel->getCommandParam());
    sp_Choose->setInitPlayerCmd(sp_ViewModel->getInitPlayerCmd());
    sp_Choose->setCommandParam(sp_ViewModel->getCommandParam());
    sp_MainView->setSetModeCmd(sp_ViewModel->getGetModeCmd());
    sp_MainView->setInitComputerCmd(sp_ViewModel->getInitComputerCmd());
    sp_MainView->setCommandParam(sp_ViewModel->getCommandParam());
    sp_ViewModel->setModel(sp_Model);
    sp_ViewModel->setView(sp_View);
    sp_ViewModel->setChoose(sp_Choose);

    while(sp_MainView->exec() == QDialog::Accepted)
    {           
        if(sp_MainView->mode == 0 || sp_MainView->mode == 1 || sp_MainView->mode == 2)
        {
            if(sp_MainView->mode == 2)
            {
                 sp_View->newConnect();
                 while(sp_View->exec() == QDialog::Accepted && sp_View->final == 1)
                 {
                     sp_View = make_shared<View>();
                     sp_ViewModel = make_shared<ViewModel>();
                     sp_Model = make_shared<Model>();
                     sp_Choose = make_shared<Choose>();
                     sp_MainView = make_shared<MainView>();

                     sp_View->setMouseMoveCmd(sp_ViewModel->getMouseMoveCmd());
                     sp_View->setMouseClickCmd(sp_ViewModel->getMouseClickCmd());
                     sp_View->setRegretCmd(sp_ViewModel->getRegretCmd());
                     sp_View->setInitPlayerCmd(sp_ViewModel->getInitPlayerCmd());
                     sp_View->setCommandParam(sp_ViewModel->getCommandParam());
                     sp_Choose->setInitPlayerCmd(sp_ViewModel->getInitPlayerCmd());
                     sp_Choose->setCommandParam(sp_ViewModel->getCommandParam());
                     sp_MainView->setSetModeCmd(sp_ViewModel->getGetModeCmd());
                     sp_MainView->setInitComputerCmd(sp_ViewModel->getInitComputerCmd());
                     sp_MainView->setCommandParam(sp_ViewModel->getCommandParam());
                     sp_ViewModel->setModel(sp_Model);
                     sp_ViewModel->setView(sp_View);
                     sp_ViewModel->setChoose(sp_Choose);
                     continue;
                 }
                 if(sp_View->final == 2)
                 {
                     sp_View = make_shared<View>();
                     sp_ViewModel = make_shared<ViewModel>();
                     sp_Model = make_shared<Model>();
                     sp_Choose = make_shared<Choose>();
                     sp_MainView = make_shared<MainView>();

                     sp_View->setMouseMoveCmd(sp_ViewModel->getMouseMoveCmd());
                     sp_View->setMouseClickCmd(sp_ViewModel->getMouseClickCmd());
                     sp_View->setRegretCmd(sp_ViewModel->getRegretCmd());
                     sp_View->setCommandParam(sp_ViewModel->getCommandParam());
                     sp_Choose->setInitPlayerCmd(sp_ViewModel->getInitPlayerCmd());
                     sp_Choose->setCommandParam(sp_ViewModel->getCommandParam());
                     sp_MainView->setSetModeCmd(sp_ViewModel->getGetModeCmd());
                     sp_MainView->setInitComputerCmd(sp_ViewModel->getInitComputerCmd());
                     sp_MainView->setCommandParam(sp_ViewModel->getCommandParam());
                     sp_ViewModel->setModel(sp_Model);
                     sp_ViewModel->setView(sp_View);
                     sp_ViewModel->setChoose(sp_Choose);
                 }

            }
            else
            {
                while(sp_Choose->exec() == QDialog::Accepted)
                {

                    if(sp_View->exec() == QDialog::Accepted && sp_View->final == 1)
                    {
                        sp_View = make_shared<View>();
                        sp_ViewModel = make_shared<ViewModel>();
                        sp_Model = make_shared<Model>();
                        sp_Choose = make_shared<Choose>();
                        sp_MainView = make_shared<MainView>();

                        sp_View->setMouseMoveCmd(sp_ViewModel->getMouseMoveCmd());
                        sp_View->setMouseClickCmd(sp_ViewModel->getMouseClickCmd());
                        sp_View->setRegretCmd(sp_ViewModel->getRegretCmd());
                        sp_View->setCommandParam(sp_ViewModel->getCommandParam());
                        sp_Choose->setInitPlayerCmd(sp_ViewModel->getInitPlayerCmd());
                        sp_Choose->setCommandParam(sp_ViewModel->getCommandParam());
                        sp_MainView->setSetModeCmd(sp_ViewModel->getGetModeCmd());
                        sp_MainView->setInitComputerCmd(sp_ViewModel->getInitComputerCmd());
                        sp_MainView->setCommandParam(sp_ViewModel->getCommandParam());
                        sp_ViewModel->setModel(sp_Model);
                        sp_ViewModel->setView(sp_View);
                        sp_ViewModel->setChoose(sp_Choose);
                        continue;
                    }
                    else if(sp_View->final == 2)
                    {
                        sp_View = make_shared<View>();
                        sp_ViewModel = make_shared<ViewModel>();
                        sp_Model = make_shared<Model>();
                        sp_Choose = make_shared<Choose>();
                        sp_MainView = make_shared<MainView>();

                        sp_View->setMouseMoveCmd(sp_ViewModel->getMouseMoveCmd());
                        sp_View->setMouseClickCmd(sp_ViewModel->getMouseClickCmd());
                        sp_View->setRegretCmd(sp_ViewModel->getRegretCmd());
                        sp_View->setCommandParam(sp_ViewModel->getCommandParam());
                        sp_Choose->setInitPlayerCmd(sp_ViewModel->getInitPlayerCmd());
                        sp_Choose->setCommandParam(sp_ViewModel->getCommandParam());
                        sp_MainView->setSetModeCmd(sp_ViewModel->getGetModeCmd());
                        sp_MainView->setInitComputerCmd(sp_ViewModel->getInitComputerCmd());
                        sp_MainView->setCommandParam(sp_ViewModel->getCommandParam());
                        sp_ViewModel->setModel(sp_Model);
                        sp_ViewModel->setView(sp_View);
                        sp_ViewModel->setChoose(sp_Choose);

                        break;
                    }
                    return a.exec();
                }
            }
        }
        else if(sp_MainView->mode == 3)
            return 0;

    }

}


