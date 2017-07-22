#ifndef _Common_H
#define _Common_H

#include <QDialog>
#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QApplication>
#include <vector>
#include <QTimer>
#include <QEventLoop>
#include <QDebug>
#include <QtNetwork/QtNetwork>
using namespace std;

class Point{                   //棋盘上的棋子位置结构
public:
	int x;
	int y;
	int color;                 //1代表黑，2代表白
	~Point(){
		x = 0;
		y = 0;
		color = 0;
	}
};

class Player              //玩家信息类
{
public:
	string _id;          //账户
	string _password;    //密码
	int _color;			 // 1代表黑，2代表白
	int  _time;          //剩余时间
	int _chessnum;       //所下的棋子数
	int _regretnum;      //悔棋次数 
	 

    Player(int color = 1,string id = "",string password = ""){     //构造函数
		_id = id;
		_password = password;
		_color = color;
		_time = 120;
		_chessnum = 2;
		_regretnum = 3;
	}
};

class ChessBoard{                     //棋盘类
public:
	int Chess[8][8];                  //用二维数组保存棋盘信息
	int ChessLeftNum;                 //剩余可下棋子数

	ChessBoard(){                     //构造函数
		ChessLeftNum = 60;
		memset(Chess, 0, sizeof(Chess));
		Chess[3][3] = 2;
		Chess[4][3] = 1;
		Chess[3][4] = 1;
		Chess[4][4] = 2;
	}
};

class CommandParam{
public:
   CommandParam():x(0),y(0),color(0),player(0),mode(0),level(0){}
   ~CommandParam(){}
   void setX(const int& x) {this->x = x;}
   void setY(const int& y) {this->y = y;}
   void setColor(const int& color) {this->color = color;}
   void setPlayer(const int& player){this->player = player;}
   void setMode(const int& mode){this->mode = mode;}
   void setLevel(const int& level){this->level = level;}
   void setOrder(const int& order){this->order = order;}
   int getX(){return x;}
   int getY(){return y;}
   int getColor(){return color;}
   int getPlayer(){return player;}
   int getMode(){return mode;}
   int getLevel(){return level;}
   int getOrder(){return order;}
private:
   int x;
   int y;
   int color;
   int player;
   int mode;
   int level;
   int order;
};

#endif
