#include "Model.h"

bool Checkflop(int srcMat[][8], Point point);
int  Checkflopstate(int srcMat[][8], Point point, int state);

//test
/*int main(){
	Model model;
	Point temp;
	ChessBoard a;
	vector<Point> temp1;
	int i, j;
	temp.x = 4;
	temp.y = 5;
	temp.color = 1;
	model._flop(temp);
	temp.x = 5;
	temp.y = 5;
	temp.color = 2;
	model._flop(temp);
	temp.x = 5;
	temp.y = 4;
	temp.color = 1;
	model._flop(temp);
	temp.x = 5;
	temp.y = 3;
	temp.color = 2;
	model._flop(temp);
	temp.x = 2;
	temp.y = 2;
	temp.color = 1;
	model._flop(temp);
	temp.x = 2;
	temp.y = 5;
	temp.color = 2;
	model._flop(temp);
	temp.x = 6;
	temp.y = 3;
	temp.color = 1;
	model._flop(temp);
	temp.x = 5;
	temp.y = 2;
	temp.color = 2;
	model._flop(temp);
	model._computeChessAvl(2);
	temp1 = model.ShowHist();
	for (i = 0; i < temp1.size(); i++){
		cout << temp1[i].x << " " << temp1[i].y << " "<< temp1[i].color << endl;
	}
	/*a = model.ShowChess();
	for (i = 0; i < 8; i++){
		for (j = 0; j < 8; j++){
			cout << a.Chess[j][i] << " ";
		}
		cout << endl;
	}
	return 0;
}*/

vector<Point> Model::_computeChessAvl(int color,ChessBoard _gameChess)
{
	int i, j;
	Point temp;
	vector <Point> _chessAvl;
	_chessAvl.clear();
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++){
			if (_gameChess.Chess[i][j] != 0)
				continue;
			temp.x = i;
			temp.y = j;
			temp.color = color;
			if (Checkflop(_gameChess.Chess, temp)){
				_chessAvl.push_back(temp);
			}
		}
	return _chessAvl;
}

ChessBoard Model::RollChess(Point point, ChessBoard _gameChess){
	int state = 0;
	int flag;
	int x = point.x;
	int y = point.y;
	_gameChess.Chess[x][y] = point.color;
	while (state < 8){
        flag = Checkflopstate(_gameChess.Chess, point, state);
        if (flag != -1){
			switch (flag){
			case 0:
				x = point.x;
				y = point.y;
				x++;
				while (x < 8 && _gameChess.Chess[x][y] == 3 - point.color){
					_gameChess.Chess[x][y] = point.color;
					x++;
				}
				break;
			case 1:
				x = point.x;
				y = point.y;
				x++;
				y--;
				while (x < 8 && y >= 0 && _gameChess.Chess[x][y] == 3 - point.color){
					_gameChess.Chess[x][y] = point.color;
					x++;
					y--;
				}
				break;
			case 2:
				x = point.x;
				y = point.y;
				y--;
				while (y >= 0 && _gameChess.Chess[x][y] == 3 - point.color){
					_gameChess.Chess[x][y] = point.color;
					y--;
				}
				break;
			case 3:
				x = point.x;
				y = point.y;
				x--;
				y--;
				while (x >= 0 && y >= 0 && _gameChess.Chess[x][y] == 3 - point.color){
					_gameChess.Chess[x][y] = point.color;
					x--;
					y--;
				}
				break;
			case 4:
				x = point.x;
				y = point.y;
				x--;
				while (x >= 0 && _gameChess.Chess[x][y] == 3 - point.color){
					_gameChess.Chess[x][y] = point.color;
					x--;
				}
				break;
			case 5:
				x = point.x;
				y = point.y;
				x--;
				y++;
				while (x >= 0 && y < 8 && _gameChess.Chess[x][y] == 3 - point.color){
					_gameChess.Chess[x][y] = point.color;
					x--;
					y++;
				}
				break;
			case 6:
				x = point.x;
				y = point.y;
				y++;
				while (y < 8 && _gameChess.Chess[x][y] == 3 - point.color){
					_gameChess.Chess[x][y] = point.color;
					y++;
				}
				break;
			case 7:
				x = point.x;
				y = point.y;
				x++;
				y++;
				while (x < 8 && y < 8 && _gameChess.Chess[x][y] == 3 - point.color){
					_gameChess.Chess[x][y] = point.color;
					x++;
					y++;
				}
				break;
			}
		}
		state++;
	}
	return _gameChess;
}

int Model::PlayerChess(int color, ChessBoard _gameChess){
	int i, j, res=0;
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++){
			if (_gameChess.Chess[i][j] == color)
				res++;
		}
	return res;
}

Point  Model::_computer(int color,int level, ChessBoard _gameChess)
{
	ChessBoard tempChess;
	int **p = new int*[8];
	for (int i = 0; i < 8; i++)
	{
		p[i] = new int[8];
		for (int j = 0; j < 8; j++)
			p[i][j] = _gameChess.Chess[i][j];
	}
	Color temp;
	if (color == 0)
		temp = EMPTY;
	else if (color == 1)
		temp = BLACK;
	else
		temp = WHITE;
	Computer c(p,  temp, level);
	Point temppoint = c.exec();
	for (int i = 0; i < 8; i++)
		delete[]p[i];
	delete p;
	return temppoint;
}

bool Checkflop(int srcMat[][8], Point point){
	int state = 0;
	int x = point.x;
	int y = point.y;
	while (state < 8){
		if (Checkflopstate(srcMat, point, state) != -1)
			return true;
		else
			state++;
	}
	return false;
}


int  Checkflopstate(int srcMat[][8],Point point,int state){
	    int x = point.x;
	    int y = point.y;
		switch (state){
		case 0:
			x++;
			while (x < 8){
				if (srcMat[x][y] == 0)
					break;
				if ((x == point.x + 1) && srcMat[x][y] == point.color)
					break;
				if (srcMat[x][y] == 3 - point.color){
					x++; 
					continue;
				}
				if (srcMat[x][y] == point.color)
					return state;
			}
			state++;
			break;
		case 1:
			x++;
			y--;
			while (x < 8 && y >= 0){
				if (srcMat[x][y] == 0)
					break;
				if ((x == point.x + 1) && (y == point.y - 1) && srcMat[x][y] == point.color)
					break;
				if (srcMat[x][y] == 3 - point.color){
					x++;
					y--;
					continue;
				}
				if (srcMat[x][y] == point.color)
					return state;
			}
			state++;
			break;
		case 2:
			y--;
			while (y >= 0){
				if (srcMat[x][y] == 0)
					break;
				if ((y == point.y - 1) && srcMat[x][y] == point.color)
					break;
				if (srcMat[x][y] == 3 - point.color){
					y--;
					continue;
				}
				if (srcMat[x][y] == point.color)
					return state;
			}
			state++;
			break;
		case 3:
			x--;
			y--;
			while (x >= 0 && y >= 0){
				if (srcMat[x][y] == 0)
					break;
				if ((x == point.x - 1) && (y == point.y - 1) && srcMat[x][y] == point.color)
					break;
				if (srcMat[x][y] == 3 - point.color){
					x--;
					y--;
					continue;
				}
				if (srcMat[x][y] == point.color)
					return state;
			}
			state++;
			break;
		case 4:
			x--;
			while (x >= 0){
				if (srcMat[x][y] == 0)
					break;
				if ((x == point.x - 1) && srcMat[x][y] == point.color)
					break;
				if (srcMat[x][y] == 3 - point.color){
					x--;
					continue;
				}
				if (srcMat[x][y] == point.color)
					return state;
			}
			state++;
			break;
		case 5:
			x--;
			y++;
			while (x >= 0 && y < 8){
				if (srcMat[x][y] == 0)
					break;
				if ((x == point.x - 1) && (y == point.y + 1) && srcMat[x][y] == point.color)
					break;
				if (srcMat[x][y] == 3 - point.color){
					x--;
					y++;
					continue;
				}
				if (srcMat[x][y] == point.color)
					return state;
			}
			state++;
			break;
		case 6:
			y++;
			while (y < 8){
				if (srcMat[x][y] == 0)
					break;
				if ((y == point.y + 1) && srcMat[x][y] == point.color)
					break;
				if (srcMat[x][y] == 3 - point.color){
					y++;
					continue;
				}
				if (srcMat[x][y] == point.color)
					return state;
			}
			state++;
			break;
		case 7:
			x++;
			y++;
			while (x < 8 && y < 8){
				if (srcMat[x][y] == 0)
					break;
				if ((x == point.x + 1) && (y == point.y + 1) && srcMat[x][y] == point.color)
					break;
				if (srcMat[x][y] == 3 - point.color){
					x++;
					y++;
					continue;
				}
				if (srcMat[x][y] == point.color)
					return state;
			}
			state++;
			break;
		}
	return -1;
}
