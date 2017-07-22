#ifndef _Module_H
#define _Module_H

#include "Common.h"
#include "Command/Command.h"
#include "Command/InitPlayerCmd.h"
#include "Command/MouseMoveCmd.h"
#include "Command/MouseClickCmd.h"
#include "Command/RegretCmd.h"
#include "Command/InitComputerCmd.h"
#include "Command/SetModeCmd.h"

class Model{

public:
	vector<Point> _computeChessAvl(int color,ChessBoard _gameChess);      //返回能下棋的位置向量                                   
	Point  _computer(int color,int level, ChessBoard _gameChess);         //人工智能下棋                                    //人工智能下棋
	ChessBoard RollChess(Point point, ChessBoard _gameChess);             //实现翻转
	int PlayerChess(int color, ChessBoard _gameChess);
};

enum Color { EMPTY = 0, BLACK = 1, WHITE = 2 };
class Computer
{
private:
	Color _color;
	int** _chessBoard;
	int _weight[8][8];
	int _level;

	int _iter1;
	int _iter2;

	Color swapColor() { Color color = _color == BLACK ? WHITE : BLACK; return color; }
	void _initWeight(int level);
	int _myScore(int** chessBoard);
	int** _rollChess(int** oldChessBoard, Point point);
	bool _Checkflop(int** chessBoard, Point point, int state);
	void _deleteChessBoard(int** chessBoard);

	vector<Point> _chessAvl(int** chessBoard, Color color);
	Point exec1(int& score);
	void exec2(int& score);

public:
	Computer(int** chessBoard, Color color, int level);
	Computer(int** chessBoard, int iter1, int iter2, Color color, int level);
	~Computer();
	void setChessBoard(int** chessBoard, Color color);
	Point exec();
};


#endif
