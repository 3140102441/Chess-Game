#include "choose.h"
#include "ui_choose.h"


Choose::Choose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Choose)
{
    ui->setupUi(this);
}

Choose::~Choose()
{
    delete ui;
}

void Choose::on_choblcak_clicked()
{
    sp_Param->setPlayer(0);
    sp_Param->setColor(1);
    sp_InitPlayer_cmd->execute();
    sp_Param->setPlayer(1);
    sp_Param->setColor(2);
    sp_InitPlayer_cmd->execute();
    this->close();
    accept();

}

void Choose::on_chowhite_clicked()
{
    sp_Param->setPlayer(0);
    sp_Param->setColor(2);
    sp_InitPlayer_cmd->execute();
    sp_Param->setPlayer(1);
    sp_Param->setColor(1);
    sp_InitPlayer_cmd->execute();
    this->close();
    accept();
}
