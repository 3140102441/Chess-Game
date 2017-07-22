//ViewModel.h
#ifndef _VIEWMODEL_H
#define _VIEWMODEL_H

#include "Common.h"
#include "Command/Command.h"
#include "Command/InitPlayerCmd.h"
#include "Command/MouseMoveCmd.h"
#include "Command/MouseClickCmd.h"
#include "Command/RegretCmd.h"
#include "Command/InitComputerCmd.h"
#include "Command/SetModeCmd.h"
#include "Model.h"
#include "View.h"
#include "choose.h"

using namespace std;

class ViewModel
{
private:
    shared_ptr<Model> m_sp_model;
    shared_ptr<View> m_sp_view;
    shared_ptr<Choose> m_sp_choose;
    vector<ChessBoard> ChessStack;
    vector<int> RecStack;
    Player pplayer[2];
    Point store;
    int mode; //0:双人 1：人机 2：联网
    int level;
    Point StepTmp; //存储上一次落子需要特殊标记的点
    int fflag;
    int order;

    shared_ptr<Command> m_sp_initplayer_cmd;
    shared_ptr<Command> m_sp_mousemove_cmd;
    shared_ptr<Command> m_sp_mouseclick_cmd;
    shared_ptr<Command> m_sp_regret_cmd;
    shared_ptr<Command> m_sp_initcomputer_cmd;
    shared_ptr<Command> m_sp_setmode_cmd;
    shared_ptr<CommandParam> m_sp_param;


public:
    ViewModel()
    {
        fflag = 1;
        mode = 1; //临时的
        level = 3;
        ChessBoard InitBoard;
        ChessStack.push_back(InitBoard);
        RecStack.push_back(0);
        order = 0;
        m_sp_initplayer_cmd = static_pointer_cast<Command, InitPlayerCmd>(make_shared<InitPlayerCmd>(*this));
        m_sp_mousemove_cmd = static_pointer_cast<Command, MouseMoveCmd>(make_shared<MouseMoveCmd>(*this));
        m_sp_mouseclick_cmd = static_pointer_cast<Command, MouseClickCmd>(make_shared<MouseClickCmd>(*this));
        m_sp_regret_cmd = static_pointer_cast<Command, RegretCmd>(make_shared<RegretCmd>(*this));
        m_sp_initcomputer_cmd = static_pointer_cast<Command, InitComputerCmd>(make_shared<InitComputerCmd>(*this));
        m_sp_setmode_cmd = static_pointer_cast<Command, SetModeCmd>(make_shared<SetModeCmd>(*this));
        m_sp_param = make_shared<CommandParam>();
    }
    ~ViewModel(){}

    shared_ptr<Command>& getInitPlayerCmd()
    {
        return m_sp_initplayer_cmd;
    }
    shared_ptr<Command>& getMouseMoveCmd()
    {
        return m_sp_mousemove_cmd;
    }
    shared_ptr<Command>& getMouseClickCmd()
    {
        return m_sp_mouseclick_cmd;
    }
    shared_ptr<Command>& getRegretCmd()
    {
        return m_sp_regret_cmd;
    }
    shared_ptr<Command>& getGetModeCmd()
    {
        return m_sp_setmode_cmd;
    }
    shared_ptr<Command>& getInitComputerCmd()
    {
        return m_sp_initcomputer_cmd;
    }
    shared_ptr<CommandParam>& getCommandParam()
    {
        return m_sp_param;
    }

    void setModel(shared_ptr<Model>& model)
    {
        m_sp_model = model;
    }
    void setView(shared_ptr<View>& view)
    {
        m_sp_view = view;
    }
    void setChoose(shared_ptr<Choose>& choose)
    {
        m_sp_choose = choose;
    }

    void SetMode();
    void InitPlayer();
    void InitComputer();
    void MouseMove();
    void MouseClick();
    void Regret();

    bool IfPosOk(int x, int y);
    int IfGameOver(ChessBoard Current);
    bool IfStep(int x, int y, vector<Point> OkPos);
    int DeterStep(int x, int y, int player);
};

#endif
