//ViewModel.cpp
#include "ViewModel.h"

void ViewModel::SetMode()
{
    int Mode = m_sp_param->getMode();
    this->mode = Mode;
}

void ViewModel::InitPlayer()
{
    int player = m_sp_param->getPlayer();
    int color = m_sp_param->getColor();
    int order = m_sp_param->getOrder();

    if (mode == 0)
    {
        pplayer[player]._color = color;
        m_sp_view->SetPlayer(0, pplayer[0]._color);
        m_sp_view->SetPlayerColor(player, color);
    }
    else if (mode == 2)
    {
        pplayer[0]._color = 1;
        pplayer[1]._color = 2;
        this->order = order;
        m_sp_view->SetPlayer(0, pplayer[0]._color);
        m_sp_view->SetPlayerColor(0, 1);
        m_sp_view->SetPlayerColor(1, 2);
    }
    else;
}

void ViewModel::InitComputer()
{
    int level = m_sp_param->getLevel();
    this->level = level;
}

void ViewModel::MouseMove()
{
    if (fflag == 1 && order == 0)
    {
        int x = m_sp_param->getX();
        int y = m_sp_param->getY();
        int x0 = (x - 125) / 30;
        int y0 = (y - 125) / 30;
        int player = m_sp_param->getPlayer();

        if (mode == 1 && player != 0) return;

        m_sp_view->DisEmpty(store.x, store.y);

        if (ChessStack[ChessStack.size() - 1].Chess[x0][y0] == 0)
        {
            bool IfOk;
            IfOk = IfPosOk(x, y);

            if (1 == IfOk)
            {
                m_sp_view->DisUnreal(x0, y0, pplayer[player]._color);
            }
            else;

            store.x = x0;
            store.y = y0;
        }
        else;
    }
    else;
}

void ViewModel::MouseClick()
{
    int flag;
    int x = m_sp_param->getX();
    int y = m_sp_param->getY();
    int x0 = x; int y0 = y;
    x = (x - 125) / 30;
    y = (y - 125) / 30;
    int player = m_sp_param->getPlayer();

    fflag = 0;
    if (mode == 0) flag = DeterStep(x, y, player);
    else if (mode == 1)
    {
        flag = DeterStep(x, y, player);
        if (1 == flag);
        else
        {
            Point ComStep = m_sp_model->_computer(pplayer[1]._color, level, ChessStack[ChessStack.size() - 1]);
            DeterStep(ComStep.x, ComStep.y, 1);

        }
    }
    else if (mode == 2)
    {
        if (order == 0)
        {
            m_sp_view->sendMessage(x0, y0);
            flag = DeterStep(x, y, player);
            order = 1;
            m_sp_view->readMessage();
        }
        else if (order == 1)
        {
            flag = DeterStep(x, y, player);
            order = 0;
        }
        else;
    }
    else;
    fflag = 1;
}

void ViewModel::Regret()
{
    int player = m_sp_param->getPlayer();



    if (pplayer[player]._regretnum > 0 && ChessStack.size() > 2)
    {
        vector<Point> temp;
        ChessBoard tmp = ChessStack[ChessStack.size() - 1];
        ChessStack.pop_back();
        RecStack.pop_back();
        while (RecStack[RecStack.size() - 1] != player)
        {
            ChessStack.pop_back();
            RecStack.pop_back();
        }
        pplayer[0]._chessnum = m_sp_model->PlayerChess(pplayer[0]._color, ChessStack[ChessStack.size() - 1]);
        m_sp_view->disNumber(0 ,pplayer[0]._chessnum);
        pplayer[1]._chessnum = m_sp_model->PlayerChess(pplayer[1]._color, ChessStack[ChessStack.size() - 1]);
        m_sp_view->disNumber(1 ,pplayer[1]._chessnum);
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {
                if (ChessStack[ChessStack.size() - 1].Chess[i][j] != tmp.Chess[i][j])
                {
                    Point point_temp;
                    point_temp.x = i;
                    point_temp.y = j;
                    point_temp.color = ChessStack[ChessStack.size() - 1].Chess[i][j];
                    temp.push_back(point_temp);
                }
                else;
            }
        StepTmp.x = -1;
        StepTmp.y = -1;
        m_sp_view->DisRoll(StepTmp, temp);
        m_sp_view->SetPlayer(player, pplayer[player]._color);
        pplayer[player]._regretnum--;
    }
    else if (pplayer[player]._regretnum == 0 && ChessStack.size() > 1) m_sp_view->CannotRegret(player);
    else;
}

bool ViewModel::IfPosOk(int x, int y)
{
    if (x >= 365 || x <= 125 || y >= 365 || y <= 125) return 0;
    return 1;
}

int ViewModel::IfGameOver(ChessBoard Current)
{
    int Pos0, Pos1;
    Pos0 = m_sp_model->_computeChessAvl(pplayer[0]._color, Current).size();
    Pos1 = m_sp_model->_computeChessAvl(pplayer[1]._color, Current).size();

    if (0 != Pos0 || 0 != Pos1) return 0;

    if (pplayer[0]._chessnum > pplayer[1]._chessnum) return 1;
    else return 2;
}

bool ViewModel::IfStep(int x, int y, vector<Point> OkPos)
{
    for (int i = 0; i < OkPos.size(); i++)
    {
        if (OkPos[i].x == x && OkPos[i].y == y) return 1;
    }
    return 0;
}

int ViewModel::DeterStep(int x, int y, int player)
{
    int flag = 0;

    StepTmp.x = x;
    StepTmp.y = y;
    StepTmp.color = pplayer[player]._color;

    vector<Point> OkPos;
    OkPos = m_sp_model->_computeChessAvl(pplayer[player]._color, ChessStack[ChessStack.size() - 1]);

    if (0 != OkPos.size())
    {
        bool If = IfStep(x, y, OkPos);
        if (1 == If)
        {
            vector<Point> temp;
            Point point;

            point.x = x;
            point.y = y;
            point.color = pplayer[player]._color;
            ChessStack.push_back(m_sp_model->RollChess(point, ChessStack[ChessStack.size() - 1]));
            pplayer[0]._chessnum = m_sp_model->PlayerChess(pplayer[0]._color, ChessStack[ChessStack.size() - 1]);
            m_sp_view->disNumber(0,  pplayer[0]._chessnum);
            pplayer[1]._chessnum = m_sp_model->PlayerChess(pplayer[1]._color, ChessStack[ChessStack.size() - 1]);
            m_sp_view->disNumber(1,  pplayer[1]._chessnum);
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                {
                    if (ChessStack[ChessStack.size() - 2].Chess[i][j] != ChessStack[ChessStack.size() - 1].Chess[i][j])
                    {
                        Point point_temp;
                        point_temp.x = i;
                        point_temp.y = j;
                        point_temp.color = ChessStack[ChessStack.size() - 1].Chess[i][j];
                        temp.push_back(point_temp);
                    }
                    else;
                }
            store.x = -1;
            store.y = -1;
            m_sp_view->DisRoll(StepTmp, temp);

            if (IfGameOver(ChessStack[ChessStack.size() - 1]) == 1)
            {
                m_sp_view->GameWin(0);
            }
            else if (IfGameOver(ChessStack[ChessStack.size() - 1]) == 2)
            {
                m_sp_view->GameWin(1);
            }
            else
            {
                if (player == 0)
                {
                    player = 1;
                    m_sp_view->SetPlayer(1, pplayer[player]._color);
                }
                else
                {
                    player = 0;
                    m_sp_view->SetPlayer(0, pplayer[player]._color);
                }
            }

            vector<Point> OkPosNext = m_sp_model->_computeChessAvl(pplayer[player]._color, ChessStack[ChessStack.size() - 1]);
            if (OkPosNext.size() == 0)
            {
                flag = 1;
                RecStack.push_back(!player);
                if (player == 0)
                {
                    player = 1;
                    m_sp_view->SetPlayer(1, pplayer[player]._color);
                }
                else
                {
                    player = 0;
                    m_sp_view->SetPlayer(0, pplayer[player]._color);
                }
                m_sp_view->PlayerChange();
            }
            else RecStack.push_back(player);
        }
        else
        {
            m_sp_view->DisTwinkle(x, y, pplayer[player]._color);
            flag = 1;
        }
    }
    else;

    return flag;
}
