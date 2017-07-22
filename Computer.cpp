#include "Model.h"

Computer::~Computer()
{
	_deleteChessBoard(_chessBoard);
}

Computer::Computer(int** chessBoard, Color color, int level)
{
	// ��ʼ��_chessBoard
	_chessBoard = new int*[8];
	for (int i = 0; i < 8; i++)
	{
		_chessBoard[i] = new int[8];
		for (int j = 0; j < 8; j++)
			_chessBoard[i][j] = chessBoard[i][j];
	}
	_color = color;
	_level = level;

	if (level == 0 || level==1)	{ _iter1 = 1; _iter2 = 1; }
	else if (level == 2)	{ _iter1 = 2; _iter2 = 1; }
	else if (level == 3)	{ _iter1 = 3; _iter2 = 1; }

	_initWeight(level);
}

Computer::Computer(int** chessBoard, int iter1, int iter2, Color color, int level)
{
	// ��ʼ��_chessBoard
	_chessBoard = new int*[8];
	for (int i = 0; i < 8; i++)
	{
		_chessBoard[i] = new int[8];
		for (int j = 0; j < 8; j++)
			_chessBoard[i][j] = chessBoard[i][j];
	}
	_color = color;
	_level = level;

	_iter1 = iter1;
	_iter2 = iter2;

	_initWeight(level);
}

void Computer::_initWeight(int level)
{
	if (level == 3 || level == 2)
	{
		// ��ʼ��Ȩ�ؾ���
		for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if ((i == 0 || i == 7) && (j == 0 || j == 7))		// 4����
				_weight[i][j] = 1000;
			else if (i == 0 || i == 7 || j == 0 || j == 7)		// 4����
				_weight[i][j] = 100;
			else if (i >= 2 && i <= 5 && j >= 2 && j <= 5)		// �м�����4*4
				_weight[i][j] = 10;
			else if ((i != 1 && i != 6) || (j != 1 && j != 6))	// 4���α�
				_weight[i][j] = 1;
			else if ((i == 1 || i == 6) && (j == 1 || j == 6))	// 4���ν�
				_weight[i][j] = -100;
		}
	}
	else if (level == 1)
	{
		// ��ʼ��Ȩ�ؾ���
		for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if ((i == 0 || i == 7) && (j == 0 || j == 7))		// 4����
				_weight[i][j] = 4;
			else if ((i == 0 || i == 7) && (j == 1 || j == 6) || (i == 1 || i == 6) && (j == 0 || j == 7))	// 4���ǵĸ���
				_weight[i][j] = -1;
			else if (i == 0 || i == 7 || j == 0 || j == 7)		// 4����
				_weight[i][j] = 3;
			else if (i >= 2 && i <= 5 && j >= 2 && j <= 5)		// �м�����4*4
				_weight[i][j] = 2;
			else if ((i != 1 && i != 6) || (j != 1 && j != 6))	// 4���α�
				_weight[i][j] = 1;
			else if ((i == 1 || i == 6) && (j == 1 || j == 6))	// 4���ν�
				_weight[i][j] = -2;
		}
	}
	else if (level == 0)
	{
		for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			_weight[i][j] = 1;
	}
}

void Computer::setChessBoard(int** chessBoard, Color color)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			_chessBoard[i][j] = chessBoard[i][j];
	}
	_color = color;
}

Point Computer::exec()
{
	int score = _myScore(_chessBoard);
	int nextScore;
	Point chessPoint = exec1(nextScore);

	//int** nextBoard;
	//nextBoard = _rollChess(_chessBoard, chessPoint);
	return chessPoint;
}

Point Computer::exec1(int& score)												// ��������
{
	vector<Point> pointAvailable = _chessAvl(_chessBoard, _color);				// ȷ�����ߵĵ�
	if (_iter1 > 0 && !pointAvailable.empty())
	{
		if (_iter1 % 2 == 1)													// ��Ϊ������ʱ
		{
			int maxScore = -100000;
			Point maxPoint;
			for (int i = 0; i < pointAvailable.size(); i++)
			{
				int** tempBoard = _rollChess(_chessBoard, pointAvailable[i]);	// �����������ߵĵ�
				Computer nextChess(tempBoard, _iter1 - 1, _iter2, swapColor(), _level);
				nextChess.exec1(score);											// ֱ�ӵ��������������������ߵĵ㣬������·�֧��������
				//cout << pointAvailable[i].x << " " << pointAvailable[i].y << " " << pointAvailable[i].color << " " << score << endl;
				if (score > maxScore)
				{
					maxScore = score;											// �����н����ȡ������
					maxPoint = pointAvailable[i];
				}
				_deleteChessBoard(tempBoard);
			}
			score = maxScore;
			return maxPoint;
		}
		else																	// ��Ϊ�Է���ʱ
		{
			int minScore = 100000;
			Point minPoint;
			for (int i = 0; i < pointAvailable.size(); i++)
			{
				int** tempBoard = _rollChess(_chessBoard, pointAvailable[i]);	// �����������ߵĵ�
				Computer nextChess(tempBoard, _iter1 - 1, _iter2, swapColor(), _level);
				nextChess.exec1(score);											// ֱ�ӵ��������������������ߵĵ㣬������·�֧����С����
				//cout << pointAvailable[i].x << " " << pointAvailable[i].y << " " << pointAvailable[i].color << " " << score << endl;
				if (score < minScore)
				{
					minScore = score;											// �����н����ȡ��С����
					minPoint = pointAvailable[i];
				}
				_deleteChessBoard(tempBoard);
			}
			score = minScore;
			return minPoint;
		}
	}
	else
	{
		exec2(score);
	}
}

void Computer::exec2(int& score)												// �����С����
{
	vector<Point> pointAvailable = _chessAvl(_chessBoard, _color);				// ȷ�����ߵĵ�
	if (_iter2 > 0 && !pointAvailable.empty())
	{
		int** nextBoard;
		int maxScore = -20000;
		Point maxPoint;
		for (int i = 0; i < pointAvailable.size(); i++)
		{
			int** tempBoard = _rollChess(_chessBoard, pointAvailable[i]);	// �����������ߵĵ�
			int score = _myScore(tempBoard);								// �õ�����
			if (score>maxScore)
			{
				maxScore = score;											// ȡ���ķ����Ͷ�Ӧ�ĵ�
				maxPoint = pointAvailable[i];
			}
			_deleteChessBoard(tempBoard);
		}
		nextBoard = _rollChess(_chessBoard, maxPoint);						// ����������Ӧ�ĵ�
		Computer nextChess(nextBoard, _iter1, _iter2 - 1, swapColor(), _level);
		nextChess.exec2(score);													// �����˹���_iter2��
		_deleteChessBoard(nextBoard);
	}
	else
	{
		score = _myScore(_chessBoard);											// ���һ���������շ���
	}
}

int Computer::_myScore(int** chessBoard)
{
	int score = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (chessBoard[i][j] == _color)
				score += _weight[i][j];
			else if (chessBoard[i][j] == swapColor())
				score -= _weight[i][j];
		}
	}
	return score;
}

vector<Point> Computer::_chessAvl(int** chessBoard, Color color)
{
	Point temp;
	vector <Point> chessAvl;
	chessAvl.clear();
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (chessBoard[i][j] != 0) continue;
			temp.x = i;
			temp.y = j;
			temp.color = color;
			for (int state = 0; state < 8; state++)
			{
				if (_Checkflop(chessBoard, temp, state))
				{
					chessAvl.push_back(temp);
					break;
				}
			}
		}
	}
	return chessAvl;
}

bool Computer::_Checkflop(int** chessBoard, Point point, int state)
{
	int x = point.x;
	int y = point.y;

	switch (state)
	{
	case 0:
		x++;
		while (x < 8)
		{
			if (chessBoard[x][y] == EMPTY) break;
			else if ((x == point.x + 1) && chessBoard[x][y] == _color) break;
			else if (chessBoard[x][y] == swapColor()) { x++; continue; }
			else if (chessBoard[x][y] == _color) return true;
		}
		break;
	case 1:
		x++; y--;
		while (x < 8 && y >= 0)
		{
			if (chessBoard[x][y] == 0) break;
			else if ((x == point.x + 1) && (y == point.y - 1) && chessBoard[x][y] == _color) break;
			else if (chessBoard[x][y] == swapColor()) { x++; y--; continue; }
			else if (chessBoard[x][y] == _color) return true;
		}
		break;
	case 2:
		y--;
		while (y >= 0)
		{
			if (chessBoard[x][y] == 0) break;
			else if ((y == point.y - 1) && chessBoard[x][y] == _color) break;
			else if (chessBoard[x][y] == swapColor()) { y--; continue; }
			else if (chessBoard[x][y] == _color) return true;
		}
		break;
	case 3:
		x--; y--;
		while (x >= 0 && y >= 0)
		{
			if (chessBoard[x][y] == 0) break;
			else if ((x == point.x - 1) && (y == point.y - 1) && chessBoard[x][y] == _color) break;
			else if (chessBoard[x][y] == swapColor()) { x--; y--; continue; }
			else if (chessBoard[x][y] == _color) return true;
		}
		break;
	case 4:
		x--;
		while (x >= 0)
		{
			if (chessBoard[x][y] == 0) break;
			else if ((x == point.x - 1) && chessBoard[x][y] == _color) break;
			else if (chessBoard[x][y] == swapColor()){ x--; continue; }
			else if (chessBoard[x][y] == _color) return true;
		}
		break;
	case 5:
		x--; y++;
		while (x >= 0 && y < 8)
		{
			if (chessBoard[x][y] == 0) break;
			else if ((x == point.x - 1) && (y == point.y + 1) && chessBoard[x][y] == _color) break;
			else if (chessBoard[x][y] == swapColor()) { x--; y++; continue; }
			else if (chessBoard[x][y] == _color) return true;
		}
		break;
	case 6:
		y++;
		while (y < 8)
		{
			if (chessBoard[x][y] == 0) break;
			else if ((y == point.y + 1) && chessBoard[x][y] == _color) break;
			else if (chessBoard[x][y] == swapColor()) { y++; continue; }
			else if (chessBoard[x][y] == _color) return true;
		}
		break;
	case 7:
		x++; y++;
		while (x < 8 && y < 8)
		{
			if (chessBoard[x][y] == 0) break;
			else if ((x == point.x + 1) && (y == point.y + 1) && chessBoard[x][y] == _color) break;
			else if (chessBoard[x][y] == swapColor()) { x++; y++; continue; }
			else if (chessBoard[x][y] == _color) return true;
		}
		break;
	}
	return false;
}

int** Computer::_rollChess(int** oldChessBoard, Point point)
{
	int** chessBoard = new int*[8];
	for (int i = 0; i < 8; i++)
	{
		chessBoard[i] = new int[8];
		for (int j = 0; j < 8; j++)
			chessBoard[i][j] = oldChessBoard[i][j];
	}

	int x = point.x;
	int y = point.y;
	chessBoard[x][y] = point.color;
	for (int state = 0; state < 8; state++)
	{
		if (_Checkflop(chessBoard, point, state))
		{
			x = point.x;
			y = point.y;
			switch (state)
			{
			case 0:
				x++;
				while (x < 8 && chessBoard[x][y] == swapColor())
				{
					chessBoard[x][y] = point.color;
					x++;
				}
				break;
			case 1:
				x++; y--;
				while (x < 8 && y >= 0 && chessBoard[x][y] == swapColor())
				{
					chessBoard[x][y] = point.color;
					x++; y--;
				}
				break;
			case 2:
				y--;
				while (y >= 0 && chessBoard[x][y] == swapColor())
				{
					chessBoard[x][y] = point.color;
					y--;
				}
				break;
			case 3:
				x--; y--;
				while (x >= 0 && y >= 0 && chessBoard[x][y] == swapColor())
				{
					chessBoard[x][y] = point.color;
					x--; y--;
				}
				break;
			case 4:
				x--;
				while (x >= 0 && chessBoard[x][y] == swapColor())
				{
					chessBoard[x][y] = point.color;
					x--;
				}
				break;
			case 5:
				x--; y++;
				while (x >= 0 && y < 8 && chessBoard[x][y] == swapColor())
				{
					chessBoard[x][y] = point.color;
					x--; y++;
				}
				break;
			case 6:
				y++;
				while (y < 8 && chessBoard[x][y] == swapColor())
				{
					chessBoard[x][y] = point.color;
					y++;
				}
				break;
			case 7:
				x++; y++;
				while (x < 8 && y < 8 && chessBoard[x][y] == swapColor())
				{
					chessBoard[x][y] = point.color;
					x++; y++;
				}
				break;
			}
		}
	}
	return chessBoard;
}

void Computer::_deleteChessBoard(int** chessBoard)
{
	for (int i = 0; i < 8; i++)
		delete[] chessBoard[i];
	delete[] chessBoard;
}
