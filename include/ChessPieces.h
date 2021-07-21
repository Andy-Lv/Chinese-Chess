//
// Created by andy on 2021/7/21.
//

#ifndef CHINESECHESS_CHESSPIECES_H
#define CHINESECHESS_CHESSPIECES_H

#include <QString>

class ChessPieces
{
public:
    ChessPieces();

    ~ChessPieces();

    void init(int id);//初始化

    QString getnName();//棋子对应的汉字

    enum m_emTYPE
    {
        JIANG, SHI, XIANG, MA, CHE, PAO, BING
    };

    int m_nRow;   //行
    int m_nCol;   //列
    int m_nID;    //ID号
    bool m_bDead;  //死亡状态
    bool m_bRed;   //是否是红方
    m_emTYPE m_emType;  //具体哪一个棋子
};


#endif //CHINESECHESS_CHESSPIECES_H

