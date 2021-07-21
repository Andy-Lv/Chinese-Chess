//
// Created by andy on 2021/7/20.
//

#include "ChessBoard.h"
#include "ui_ChessBoard.h"

ChessBoard::ChessBoard(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui_Chess::ChessBoard)
{
    init();

    //记时器部分
    m_timer=new QTimer;//初始化计时器
    m_timeRecord=new QTime(0,0,0);//初始化时间
    m_bIsStart= false;//初始为还未计时

    connect(m_timer, SIGNAL(timeout()),this, SLOT(updateTime()));

    m_pAbout=new AboutAuthor();

    this->setWindowIcon(QIcon(":/images/chess.svg"));
    ui->setupUi(this);

}