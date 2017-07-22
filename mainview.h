#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "Common.h"
#include "Command/Command.h"
#include "Command/InitPlayerCmd.h"
#include "Command/MouseMoveCmd.h"
#include "Command/MouseClickCmd.h"
#include "Command/RegretCmd.h"
#include "Command/InitComputerCmd.h"
#include "Command/SetModeCmd.h"

namespace Ui {
class MainView;
}

class MainView : public QDialog
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();
    int mode;
    void setSetModeCmd(shared_ptr<Command>& cmd)
    {
        sp_SetMode_cmd = cmd;
    }
    void setInitComputerCmd(shared_ptr<Command>& cmd)
    {
        sp_InitComputer_cmd = cmd;
    }
    void setCommandParam(shared_ptr<CommandParam>& par)
    {
        sp_Param = par;
    }

private slots:
    void on_mode0_clicked();

    void on_mode1_clicked();

    void on_mode2_clicked();

    void on_exit_clicked();

    void on_level0_clicked();

    void on_level1_clicked();

    void on_level2_clicked();

    void on_level3_clicked();

private:
    Ui::MainView *ui;
    shared_ptr<Command> sp_SetMode_cmd;
    shared_ptr<Command> sp_InitComputer_cmd;
    shared_ptr<CommandParam> sp_Param;

};

#endif // MAINVIEW_H
