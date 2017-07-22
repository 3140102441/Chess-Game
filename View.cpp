#include "View.h"
#include "ui_View.h"

View::View(QDialog *parent) :
    QDialog (parent),
    ui(new Ui::View),
    playerNum(0),
    end(0),
    final(0),
    flag(0)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    ui->cannot->hide();
    ui->cannotreg0->hide();
    ui->cannotreg1->hide();
    ui->win0->hide();
    ui->win1->hide();
    ui->changePlayer->hide();
    ui->begin->hide();
    ui->return0->hide();
    ui->chess00->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess01->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess02->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess03->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess04->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess05->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess06->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess07->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess10->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess11->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess12->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess13->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess14->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess15->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess16->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess17->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess20->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess21->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess22->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess23->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess24->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess25->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess26->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess27->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess30->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess31->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess32->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess33->setStyleSheet(QStringLiteral("border-image: url(:/image/image/chesswhite.png);"));
    ui->chess34->setStyleSheet(QStringLiteral("border-image: url(:/image/image/chessblack.png);"));
    ui->chess35->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess36->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess37->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess40->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess41->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess42->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess43->setStyleSheet(QStringLiteral("border-image: url(:/image/image/chessblack.png);"));
    ui->chess44->setStyleSheet(QStringLiteral("border-image: url(:/image/image/chesswhite.png);"));
    ui->chess45->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess46->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess47->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess50->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess51->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess52->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess53->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess54->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess55->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess56->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess57->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess60->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess61->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess62->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess63->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess64->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess65->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess66->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess67->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess70->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess71->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess72->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess73->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess74->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess75->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess76->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));
    ui->chess77->setStyleSheet(QStringLiteral("border-image: url(:/image/image/empty.png);"));

    tcpServer = new QTcpServer(this);

    if(!tcpServer->listen(QHostAddress::AnyIPv4,6666))
    {  //监听本地主机的6666端口，如果出错就输出错误信息，并关闭

        qDebug() << tcpServer->errorString();

        close();

    }

    //connect(tcpServer,SIGNAL(newConnection()),this,SLOT(sendMessage()));

    //连接信号和相应槽函数

    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));

    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
                  this,SLOT(displayError(QAbstractSocket::SocketError)));
}

void View::newConnect()
{

    blockSize = 0; //初始化其为0

    if(flag == 0)
    {
        tcpSocket->abort(); //取消已有的连接
        tcpSocket->connectToHost("10.189.250.71",6666);
        QEventLoop eventloop;
        QTimer::singleShot(3600, &eventloop, SLOT(quit()));
        eventloop.exec();
        tcpSocket->abort();
        tcpSocket->connectToHost("10.189.250.71",6666);
    }
    else if(flag == 1)
    {
        tcpSocket->abort(); //取消已有的连接
        tcpSocket->connectToHost(message,6666);
    }


    //连接到主机，这里从界面获取主机地址和端口号

}

void View::readMessage()
{
    if(flag == 0)
    {
        flag = 1;

        QDataStream in(tcpSocket);

        in.setVersion(QDataStream::Qt_4_6);

        //设置数据流版本，这里要和服务器端相同

        if(blockSize==0) //如果是刚开始接收数据

        {

            //判断接收的数据是否有两字节，也就是文件的大小信息

            //如果有则保存到blockSize变量中，没有则返回，继续接收数据

            if(tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;

            in >> blockSize;

        }

        if(tcpSocket->bytesAvailable() < blockSize) return;

        //如果没有得到全部的数据，则返回，继续接收数据

        in >> message;

        QChar _flag = message[message.size()-1];

        if(_flag == '0')
        {
            sp_Param->setPlayer(0);
            sp_Param->setColor(1);
            sp_Param->setOrder(0);
            sp_InitPlayer_cmd->execute();
            sp_Param->setPlayer(1);
            sp_Param->setColor(2);
            sp_Param->setOrder(0);
            sp_InitPlayer_cmd->execute();
        }
        else if(_flag == '1')
        {
            sp_Param->setPlayer(0);
            sp_Param->setColor(2);
            sp_Param->setOrder(1);
            sp_InitPlayer_cmd->execute();
            sp_Param->setPlayer(1);
            sp_Param->setColor(1);
            sp_Param->setOrder(1);
            sp_InitPlayer_cmd->execute();
        }

        message = message.left(message.size()-2);

        //将接收到的数据存放到变量中
        qDebug()<<message<<endl;

        newConnect();

        //显示接收到的数据
    }
    else if(flag == 1)
    {
        QDataStream in(tcpSocket);

        in.setVersion(QDataStream::Qt_4_6);

        //设置数据流版本，这里要和服务器端相同

        if(blockSize==0) //如果是刚开始接收数据

        {

            //判断接收的数据是否有两字节，也就是文件的大小信息

            //如果有则保存到blockSize变量中，没有则返回，继续接收数据

            if(tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;

            in >> blockSize;

        }

        if(tcpSocket->bytesAvailable() < blockSize) return;

        //如果没有得到全部的数据，则返回，继续接收数据

        in >> message;

        QString str_x = message.section('#',0,0);
        QString str_y = message.section('#',1,1);
        sp_Param->setX(str_x.toInt());
        sp_Param->setY(str_y.toInt());
        sp_Param->setPlayer(playerNum);
        sp_MouseClick_cmd->execute();
    }

}


void View::displayError(QAbstractSocket::SocketError)
{
    qDebug() << tcpSocket->errorString(); //输出错误信息
}




void View::sendMessage(int point_x,int point_y)
{
    QByteArray block; //用于暂存我们要发送的数据

    QDataStream out(&block,QIODevice::WriteOnly);

    //使用数据流写入数据

    out.setVersion(QDataStream::Qt_4_6);

    //设置数据流的版本，客户端和服务器端使用的版本要相同

    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();

    QByteArray array;

    array =(QString::number(point_x)+"#"+QString::number(point_y)).toLatin1();

    char *x = array.data();

    out<<(quint16) 0;

    out<<tr(x);

    out.device()->seek(0);

    out<<(quint16) (block.size() - sizeof(quint16));


        //我们获取已经建立的连接的子套接字

    //connect(clientConnection,SIGNAL(disconnected()),clientConnection,SLOT(deleteLater()));

    clientConnection->write(block);

    //clientConnection->disconnectFromHost();


        //发送数据成功后，显示提示

}

View::~View()
{
    delete ui;
}

void View::DisChess(int x,int y, QString str)
{
    if(x == 0 && y == 0)
        ui->chess00->setStyleSheet(str);
    else if(x == 1&& y == 0)
        ui->chess01->setStyleSheet(str);
    else if(x == 2&& y == 0)
        ui->chess02->setStyleSheet(str);
    else if(x == 3&& y == 0)
        ui->chess03->setStyleSheet(str);
    else if(x == 4&& y == 0)
        ui->chess04->setStyleSheet(str);
    else if(x == 5&& y == 0)
        ui->chess05->setStyleSheet(str);
    else if(x == 6&& y == 0)
        ui->chess06->setStyleSheet(str);
    else if(x == 7&& y == 0)
        ui->chess07->setStyleSheet(str);
    else if(x == 0&& y == 1)
        ui->chess10->setStyleSheet(str);
    else if(x == 1&& y == 1)
        ui->chess11->setStyleSheet(str);
    else if(x == 2&& y == 1)
        ui->chess12->setStyleSheet(str);
    else if(x == 3&& y == 1)
        ui->chess13->setStyleSheet(str);
    else if(x == 4&& y == 1)
        ui->chess14->setStyleSheet(str);
    else if(x == 5&& y == 1)
        ui->chess15->setStyleSheet(str);
    else if(x == 6&& y == 1)
        ui->chess16->setStyleSheet(str);
    else if(x == 7&& y == 1)
        ui->chess17->setStyleSheet(str);
    else if(x == 0&& y == 2)
        ui->chess20->setStyleSheet(str);
    else if(x == 1&& y == 2)
        ui->chess21->setStyleSheet(str);
    else if(x == 2&& y == 2)
        ui->chess22->setStyleSheet(str);
    else if(x == 3&& y == 2)
        ui->chess23->setStyleSheet(str);
    else if(x == 4&& y == 2)
        ui->chess24->setStyleSheet(str);
    else if(x == 5&& y == 2)
        ui->chess25->setStyleSheet(str);
    else if(x == 6&& y == 2)
        ui->chess26->setStyleSheet(str);
    else if(x == 7&& y == 2)
        ui->chess27->setStyleSheet(str);
    else if(x == 0&& y == 3)
        ui->chess30->setStyleSheet(str);
    else if(x == 1&& y == 3)
        ui->chess31->setStyleSheet(str);
    else if(x == 2&& y == 3)
        ui->chess32->setStyleSheet(str);
    else if(x == 3&& y == 3)
        ui->chess33->setStyleSheet(str);
    else if(x == 4&& y == 3)
        ui->chess34->setStyleSheet(str);
    else if(x == 5&& y == 3)
        ui->chess35->setStyleSheet(str);
    else if(x == 6&& y == 3)
        ui->chess36->setStyleSheet(str);
    else if(x == 7&& y == 3)
        ui->chess37->setStyleSheet(str);
    else if(x == 0&& y == 4)
        ui->chess40->setStyleSheet(str);
    else if(x == 1&& y == 4)
        ui->chess41->setStyleSheet(str);
    else if(x == 2&& y == 4)
        ui->chess42->setStyleSheet(str);
    else if(x == 3&& y == 4)
        ui->chess43->setStyleSheet(str);
    else if(x == 4&& y == 4)
        ui->chess44->setStyleSheet(str);
    else if(x == 5&& y == 4)
        ui->chess45->setStyleSheet(str);
    else if(x == 6&& y == 4)
        ui->chess46->setStyleSheet(str);
    else if(x == 7&& y == 4)
        ui->chess47->setStyleSheet(str);
    else if(x == 0&& y == 5)
        ui->chess50->setStyleSheet(str);
    else if(x == 1&& y == 5)
        ui->chess51->setStyleSheet(str);
    else if(x == 2&& y == 5)
        ui->chess52->setStyleSheet(str);
    else if(x == 3&& y == 5)
        ui->chess53->setStyleSheet(str);
    else if(x == 4&& y == 5)
        ui->chess54->setStyleSheet(str);
    else if(x == 5&& y == 5)
        ui->chess55->setStyleSheet(str);
    else if(x == 6&& y == 5)
        ui->chess56->setStyleSheet(str);
    else if(x == 7&& y == 5)
        ui->chess57->setStyleSheet(str);
    else if(x == 0&& y == 6)
        ui->chess60->setStyleSheet(str);
    else if(x == 1&& y == 6)
        ui->chess61->setStyleSheet(str);
    else if(x == 2&& y == 6)
        ui->chess62->setStyleSheet(str);
    else if(x == 3&& y == 6)
        ui->chess63->setStyleSheet(str);
    else if(x == 4&& y == 6)
        ui->chess64->setStyleSheet(str);
    else if(x == 5&& y == 6)
        ui->chess65->setStyleSheet(str);
    else if(x == 6&& y == 6)
        ui->chess66->setStyleSheet(str);
    else if(x == 7&& y == 6)
        ui->chess67->setStyleSheet(str);
    else if(x == 0&& y == 7)
        ui->chess70->setStyleSheet(str);
    else if(x == 1&& y == 7)
        ui->chess71->setStyleSheet(str);
    else if(x == 2&& y == 7)
        ui->chess72->setStyleSheet(str);
    else if(x == 3&& y == 7)
        ui->chess73->setStyleSheet(str);
    else if(x == 4&& y == 7)
        ui->chess74->setStyleSheet(str);
    else if(x == 5&& y == 7)
        ui->chess75->setStyleSheet(str);
    else if(x == 6&& y == 7)
        ui->chess76->setStyleSheet(str);
    else if(x == 7&& y == 7)
        ui->chess77->setStyleSheet(str);
}

void View::DisUnreal(int x, int y, int color)
{
    if(end == 0)
    {
        QString str;

        if(color == 1)
            str = "border-image: url(:/image/image/chessblackh.png);";
        else if(color == 2)
            str = "border-image: url(:/image/image/chesswhiteh.png);";
        else
            str = "border-image: url(:/image/image/empty.png);";
        DisChess(x,y,str);
    }
}

void View::DisReal(int x, int y, int color)
{
    if(end == 0)
    {
        QString str;
        if(color == 1)
            str = "border-image: url(:/image/image/chessblack.png);";
        else if(color == 2)
            str = "border-image: url(:/image/image/chesswhite.png);";
        else
            str = "border-image: url(:/image/image/empty.png);";

        DisChess(x,y,str);
    }
}

void View::DisFlip(int x, int y, int color)
{
    if(end == 0)
    {
        QString str;
        QEventLoop eventloop;
        if(color == 1)
        {
            str = "border-image: url(:/image/image/chesswhite1.png);";
            DisChess(x,y,str);
            QTimer::singleShot(50, &eventloop, SLOT(quit()));
            eventloop.exec();
            str = "border-image: url(:/image/image/empty.png);";
            DisChess(x,y,str);
            QTimer::singleShot(50, &eventloop, SLOT(quit()));
            eventloop.exec();
            str = "border-image: url(:/image/image/chessblack1.png);";
            DisChess(x,y,str);
            QTimer::singleShot(50, &eventloop, SLOT(quit()));
            eventloop.exec();
            str = "border-image: url(:/image/image/chessblack.png);";
            DisChess(x,y,str);
            QTimer::singleShot(50, &eventloop, SLOT(quit()));
            eventloop.exec();
        }
        else if(color == 2)
        {
            str = "border-image: url(:/image/image/chessblack1.png);";
            DisChess(x,y,str);
            QTimer::singleShot(50, &eventloop, SLOT(quit()));
            eventloop.exec();
            str = "border-image: url(:/image/image/empty.png);";
            DisChess(x,y,str);
            QTimer::singleShot(50, &eventloop, SLOT(quit()));
            eventloop.exec();
            str = "border-image: url(:/image/image/chesswhite1.png);";
            DisChess(x,y,str);
            QTimer::singleShot(50, &eventloop, SLOT(quit()));
            eventloop.exec();
            str = "border-image: url(:/image/image/chesswhite.png);";
            DisChess(x,y,str);
            QTimer::singleShot(50, &eventloop, SLOT(quit()));
            eventloop.exec();
        }
        else
        {
            str = "border-image: url(:/image/image/empty.png);";
            DisChess(x,y,str);
        }
    }
}

void View::DisEmpty(int x, int y)
{
    if(end == 0)
    {
        QString str;

        str = "border-image: url(:/image/image/empty.png);";

        DisChess(x,y,str);
    }
}

void View::DisRoll(Point step,vector<Point> Roll)
{
    if(end == 0)
    {
        DisReal(step.x,step.y,step.color);
        QEventLoop eventloop;
        QTimer::singleShot(200, &eventloop, SLOT(quit()));
        eventloop.exec();
        auto beg = Roll.begin(),end = Roll.end();
        for(;beg != end;beg++)
        {
            if(beg->x == step.x && beg->y == step.y) continue;
            DisFlip(beg->x,beg->y,beg->color);
        }
        QTimer::singleShot(800, &eventloop, SLOT(quit()));
        eventloop.exec();
    }
}

void View::PlayerChange()
{
    if(end == 0)
    {
        ui->changePlayer->show();
        QEventLoop eventloop;
        QTimer::singleShot(1500, &eventloop, SLOT(quit()));
        eventloop.exec();
        ui->changePlayer->hide();
    }
}

void View::SetPlayer(int player, int color)
{
    if(end == 0)
    {
        playerNum = player;
        if (color==2)
            ui->now->setStyleSheet("border-image: url(:/image/image/chesswhite.png);");
        else if (color==1)
            ui->now->setStyleSheet("border-image: url(:/image/image/chessblack.png);");
    }
}

void View::DisTwinkle(int x, int y, int color)
{

    if(end == 0)
    {
        ui->cannot->show();
        QEventLoop eventloop;
        QTimer::singleShot(1200, &eventloop, SLOT(quit()));
        eventloop.exec();
        ui->cannot->hide();
    }
}

void View::GameWin(int player)
{
    if(end == 0)
    {
        end = 1;
        ui->begin->show();
        ui->return0->show();
        if(player == 0)
            ui->win0->show();
        else
            ui->win1->show();
    }

}

void View::CannotRegret(int player)
{
    if(end == 0)
    {
        if(player == 0)
        {
            ui->cannotreg0->show();
            QEventLoop eventloop;
            QTimer::singleShot(1200, &eventloop, SLOT(quit()));
            eventloop.exec();
            ui->cannotreg0->hide();
        }
        else
        {
            ui->cannotreg1->show();
            QEventLoop eventloop;
            QTimer::singleShot(1200, &eventloop, SLOT(quit()));
            eventloop.exec();
            ui->cannotreg1->hide();
        }
    }
}

void View::SetPlayerColor(int player,int color)
{
    if(end == 0)
    {
        if(player == 0&& color == 1)
            ui->player0che->setStyleSheet(QStringLiteral("border-image: url(:/image/image/chessblack.png);"));
        else if(player == 0&& color == 2)
            ui->player0che->setStyleSheet(QStringLiteral("border-image: url(:/image/image/chesswhite.png);"));
        else if(player == 1&& color == 1)
            ui->player1che->setStyleSheet(QStringLiteral("border-image: url(:/image/image/chessblack.png);"));
        else if(player == 1&& color == 2)
            ui->player1che->setStyleSheet(QStringLiteral("border-image: url(:/image/image/chesswhite.png);"));
    }
}

void View::disNumber(int player,int num)
{
    QString str;
    QFont ft;
    ft.setPointSize(14);
    ft.setBold(true);
    str = QString::number(num);
    if(player == 0)
    {
        ui->num0->setFont(ft);
        ui->num0->setText(str);
    }
    else if(player == 1)
    {
        ui->num1->setFont(ft);
        ui->num1->setText(str);
    }
}

void View::on_defeat_clicked()
{
    if(end == 0)
    {
        end = 1;
        ui->begin->show();
        ui->return0->show();
        if(playerNum == 0)
            ui->win1->show();
        else
            ui->win0->show();
    }
}

void View::on_regret_clicked()
{
    if(end == 0)
    {
        sp_Param->setPlayer(playerNum);
        sp_Regret_cmd->execute();
    }
}



void View::mouseMoveEvent(QMouseEvent* event)
{
    if(end == 0)
    {
        QPoint pos;
        pos = event->pos();
        sp_Param->setX(pos.x());
        sp_Param->setY(pos.y());
        sp_Param->setPlayer(playerNum);
        sp_MouseMove_cmd->execute();
    }
}

void View::mousePressEvent(QMouseEvent* event)
{
    if(end == 0)
    {
        if(event->button() == Qt::LeftButton)
        {
            QPoint pos;
            pos = event->pos();
            sp_Param->setX(pos.x());
            sp_Param->setY(pos.y());
            sp_Param->setPlayer(playerNum);
            sp_MouseClick_cmd->execute();

        }
    }
}

void View::on_begin_clicked()
{
    if(end == 1)
    {
        final = 1;
        accept();
    }
}

void View::on_return0_clicked()
{
    if(end == 1)
    {
        final = 2;
        accept();
    }
}

