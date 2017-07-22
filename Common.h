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

class Point{                   //�����ϵ�����λ�ýṹ
public:
	int x;
	int y;
	int color;                 //1����ڣ�2�����
	~Point(){
		x = 0;
		y = 0;
		color = 0;
	}
};

class Player              //�����Ϣ��
{
public:
	string _id;          //�˻�
	string _password;    //����
	int _color;			 // 1����ڣ�2�����
	int  _time;          //ʣ��ʱ��
	int _chessnum;       //���µ�������
	int _regretnum;      //������� 
	 

    Player(int color = 1,string id = "",string password = ""){     //���캯��
		_id = id;
		_password = password;
		_color = color;
		_time = 120;
		_chessnum = 2;
		_regretnum = 3;
	}
};

class ChessBoard{                     //������
public:
	int Chess[8][8];                  //�ö�ά���鱣��������Ϣ
	int ChessLeftNum;                 //ʣ�����������

	ChessBoard(){                     //���캯��
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
