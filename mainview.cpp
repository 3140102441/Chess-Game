#include "mainview.h"
#include "ui_mainview.h"

MainView::MainView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainView),
    mode(0)
{
    ui->setupUi(this);
    ui->level->hide();
}

MainView::~MainView()
{
    delete ui;
}

void MainView::on_mode0_clicked()
{
    mode = 0;
    sp_Param->setMode(0);
    sp_SetMode_cmd->execute();
    this->close();
    accept();
}

void MainView::on_mode1_clicked()
{
    mode = 1;
    sp_Param->setMode(1);
    sp_SetMode_cmd->execute();
    ui->level->show();
}

void MainView::on_mode2_clicked()
{
    mode = 2;
    sp_Param->setMode(2);
    sp_SetMode_cmd->execute();
    this->close();
    accept();
}

void MainView::on_exit_clicked()
{
    mode = 3;
    this->close();
    accept();

}

void MainView::on_level0_clicked()
{
    if(mode == 1)
    {
        sp_Param->setLevel(0);
        sp_InitComputer_cmd->execute();
        this->close();
        accept();
    }
}

void MainView::on_level1_clicked()
{
    if(mode == 1)
    {
        sp_Param->setLevel(1);
        sp_InitComputer_cmd->execute();
        this->close();
        accept();
    }
}

void MainView::on_level2_clicked()
{
    if(mode == 1)
    {
        sp_Param->setLevel(2);
        sp_InitComputer_cmd->execute();
        this->close();
        accept();
    }
}

void MainView::on_level3_clicked()
{
    if(mode == 1)
    {
        sp_Param->setLevel(3);
        sp_InitComputer_cmd->execute();
        this->close();
        accept();
    }
}
