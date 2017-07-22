#ifndef CHOOSE_H
#define CHOOSE_H

#include "Common.h"
#include "Command/Command.h"
#include "Command/InitPlayerCmd.h"
#include "Command/MouseMoveCmd.h"
#include "Command/MouseClickCmd.h"
#include "Command/RegretCmd.h"
#include "Command/InitComputerCmd.h"
#include "Command/SetModeCmd.h"

namespace Ui {
class Choose;
}

class Choose : public QDialog
{
    Q_OBJECT

public:
    explicit Choose(QWidget *parent = 0);
    ~Choose();
    void setInitPlayerCmd(shared_ptr<Command>& cmd)
    {
        sp_InitPlayer_cmd = cmd;
    }
    void setCommandParam(shared_ptr<CommandParam>& par)
    {
        sp_Param = par;
    }

private slots:
    void on_choblcak_clicked();

    void on_chowhite_clicked();

private:
    Ui::Choose *ui;
    shared_ptr<Command> sp_InitPlayer_cmd;
    shared_ptr<CommandParam> sp_Param;
};

#endif // CHOOSE_H
