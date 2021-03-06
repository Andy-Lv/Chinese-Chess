//
// Created by andy on 2021/7/20.
//

#ifndef CHINESECHESS_CHESSBOARD_H
#define CHINESECHESS_CHESSBOARD_H

#include <QMainWindow>
#include <QFrame>
#include "ChessPieces.h"
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QtGlobal>
#include "AboutAuthor.h"
#include "ui_ChessBoard.h"

namespace Ui_Chess {
    class ChessBoard;
}

class ChessBoard : public QMainWindow
{
Q_OBJECT

public:
    explicit ChessBoard(QWidget *parent = 0);

    ~ChessBoard();

    bool isDead(int id);//判断是否死亡
    int getStoneId(int row, int col);//确定每一个位置上棋子的id

    // 车、炮的功能辅助函数   判断两个点是否在一个直线上面,且返回直线之间的棋子个数
    int getStoneCountAtLine(int row1, int col1, int row2, int col2);

    void whoWin();  //谁胜谁负

    bool isChecked(QPoint pt, int &row, int &col);   //是否选中该枚棋子。pt为输入参数; row， col为输出参数

    QPoint getRealPoint(QPoint pt);  // 使mouseMoveEvent取得的坐标同Painter的坐标一致

public:
    QPoint center(int row, int col);         //象棋的棋盘的坐标转换成界面坐标
    QPoint center(int id);

    virtual void paintEvent(QPaintEvent *);      //绘画棋盘
    void drawChessPieces(QPainter &painter, int id);  //绘画单个具体的棋子

    virtual void mousePressEvent(QMouseEvent *);    //鼠标点击事件
    virtual void clickPieces(int checkedID, int &row, int &col);

    //象棋移动的规则[将  士  象  马  车  炮  兵]
    bool canMove(int moveId, int killId, int row, int col);

    bool canMoveJIANG(int moveId, int killId, int row, int col);

    bool canMoveSHI(int moveId, int killId, int row, int col);

    bool canMoveXIANG(int moveId, int killId, int row, int col);

    bool canMoveMA(int moveId, int killId, int row, int col);

    bool canMoveCHE(int moveId, int killId, int row, int col);

    bool canMovePAO(int moveId, int killId, int row, int col);

    bool canMoveBING(int moveId, int killId, int row, int col);

    void init();

    ChessPieces m_ChessPieces[32];  //所有棋子
    int m_nR;          //棋子半径
    int m_nOffSet;     //距离界面的边距
    int m_nD;          //间距为50px
    int m_nSelectID;   //选中棋子[-1:选棋子 || 非-1:走棋子]
    int m_nCheckedID;    //将要被击杀的棋子ID
    bool m_bIsRed;     //是否是红棋
    bool m_bIsTcpServer;
    bool m_bIsOver; //是否已经游戏结束

private slots:

    void updateTime();

    void on_pushButton_start_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_about_clicked();

    void on_pushButton_restart_clicked();

private:
    Ui_Chess::ChessBoard *ui;

    QTimer *m_timer;      //定时器 每秒更新时间
    QTime *m_timeRecord;  //记录时间
    bool m_bIsStart;        //记录是否已经开始计时
    AboutAuthor *m_pAbout;

};

#endif //CHINESECHESS_CHESSBOARD_H