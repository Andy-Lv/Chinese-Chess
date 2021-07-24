//
// Created by andy on 2021/7/24.
//

#ifndef CHINESECHESS_CHESSSTEP_H
#define CHINESECHESS_CHESSSTEP_H

#include <QObject>

class ChessStep : public QObject
{
    Q_OBJECT
public:
    explicit ChessStep(QObject *parent = 0);
    ~ChessStep();

    int m_nMoveID;   //移动棋子ID
    int m_nKillID;   //将要被击杀的棋子ID
    int m_nRowFrom;  //原位置的行
    int m_nColFrom;  //原位置的列
    int m_nRowTo;    //目的位置的行
    int m_nnColTo;   //目的位置的列
};

#endif //CHINESECHESS_CHESSSTEP_H
