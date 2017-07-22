#ifndef VIEW_H
#define VIEW_H

#include "Common.h"
#include "Command/Command.h"
#include "Command/InitPlayerCmd.h"
#include "Command/MouseMoveCmd.h"
#include "Command/MouseClickCmd.h"
#include "Command/RegretCmd.h"
#include "Command/InitComputerCmd.h"
#include "Command/SetModeCmd.h"

namespace Ui {
class View;
}

class View : public QDialog
{
    Q_OBJECT

public:
    explicit View(QDialog *parent = 0);
    ~View();
    int final;
    int flag;
    void DisUnreal(int x, int y, int color);
    void DisReal(int x, int y, int color);
    void DisFlip(int x, int y, int color);
    void DisEmpty(int x, int y);
    void DisRoll(Point step,vector<Point> Roll);
	void SetPlayer(int player, int color);
    void PlayerChange();
    void DisTwinkle(int x, int y, int color);
    void GameWin(int player);
    void CannotRegret(int player);
    void SetPlayerColor(int player,int color);
    void disNumber(int player,int num);
    void setMouseMoveCmd(shared_ptr<Command>& cmd)
    {
        sp_MouseMove_cmd = cmd;
    }
    void setMouseClickCmd(shared_ptr<Command>& cmd)
    {
        sp_MouseClick_cmd = cmd;
    }
    void setRegretCmd(shared_ptr<Command>& cmd)
    {
        sp_Regret_cmd = cmd;
    }
    void setInitPlayerCmd(shared_ptr<Command>& cmd)
    {
        sp_InitPlayer_cmd = cmd;
    }
    void setCommandParam(shared_ptr<CommandParam>& par)
    {
        sp_Param = par;
    }

    void newConnect(); //连接服务器
    void sendMessage(int point_x ,int point_y);


protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);

public slots:

    void readMessage();  //接收数据

private slots:

    void on_defeat_clicked();

    void on_regret_clicked();

    void on_begin_clicked();

    void on_return0_clicked();

    void displayError(QAbstractSocket::SocketError);  //显示错误


private:
    Ui::View *ui;
    int playerNum;
    int end;
    void DisChess(int x,int y,QString str);
    shared_ptr<Command> sp_MouseMove_cmd;
    shared_ptr<Command> sp_MouseClick_cmd;
    shared_ptr<Command> sp_Regret_cmd;
    shared_ptr<Command> sp_InitPlayer_cmd;
    shared_ptr<CommandParam> sp_Param;

    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;

    QString message;  //存放从服务器接收到的字符串
    quint16 blockSize;  //存放文件的大小信息


};

#endif // WIDGET_H
