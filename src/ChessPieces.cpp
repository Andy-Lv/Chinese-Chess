//
// Created by andy on 2021/7/21.
//

#include "ChessPieces.h"

//定义棋子位置结构体tPos

struct POS
{
    int t_nRow;
    int t_nCol;
    ChessPieces::m_emTYPE t_emType;
};

//定义基础的16棋子[预定作为上方使用,黑棋使用]
POS tPos[16]= {
        {0, 0, ChessPieces::CHE},//车
        {0, 1, ChessPieces::MA},//马
        {0, 2, ChessPieces::XIANG},//象
        {0, 3, ChessPieces::SHI},//士
        {0, 4, ChessPieces::JIANG},//将
        {0, 5, ChessPieces::SHI},//士
        {0, 6, ChessPieces::XIANG},//象
        {0, 7, ChessPieces::MA},//马
        {0, 8, ChessPieces::CHE},//车

        {2, 1, ChessPieces::PAO},//炮
        {2, 7, ChessPieces::PAO},//炮
        {3, 0, ChessPieces::BING},//兵
        {3, 2, ChessPieces::BING},//兵
        {3, 4, ChessPieces::BING},//兵
        {3, 6, ChessPieces::BING},//兵
        {3, 8, ChessPieces::BING}//兵
};

ChessPieces::ChessPieces()
{
}

ChessPieces::~ChessPieces()
{
}

//初始化,对每个棋子进行检验判断而后赋值
void ChessPieces::init(int id)
{
    if(id<16)
    {
        //黑方棋子
        m_nRow=tPos[id].t_nRow;
        m_nCol = tPos[id].t_nCol;
        m_emType = tPos[id].t_emType;
        m_bRed = false;
    }
    else
    {
        //红方棋子
        m_nRow = 9-tPos[id-16].t_nRow;
        m_nCol = 8-tPos[id-16].t_nCol;
        m_emType = tPos[id-16].t_emType;
        m_bRed = true;
    }

    //是否死亡
    m_bDead = false;
}

QString ChessPieces::getnName()
{
    //enum m_emTYPE{JIANG, SHI, XIANG, MA, CHE, PAO, BING};
    switch(m_emType)
    {
        case CHE:
            return "车";
        case MA:
            return "马";
        case PAO:
            return "炮";
        case BING:
            return "兵";
        case JIANG:
            return "将";
        case SHI:
            return "士";
        case XIANG:
            return "相";
        default:
            return "显示出错";
    }
}