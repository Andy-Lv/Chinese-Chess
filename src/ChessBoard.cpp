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
    m_timer = new QTimer;//初始化计时器
    m_timeRecord = new QTime(0, 0, 0);//初始化时间
    m_bIsStart = false;//初始为还未计时

    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateTime()));

    m_pAbout = new AboutAuthor();

    this->setWindowIcon(QIcon(":/images/chess.svg"));
    ui->setupUi(this);

}

ChessBoard::~ChessBoard()
{
    delete ui;
}

void ChessBoard::init()
{
    for (int i = 0; i < 32; ++i)
    {
        m_ChessPieces[i].init(i);
    }

    m_nSelectID = -1;
    m_nCheckedID = -1;
    m_bIsTcpServer = true;
    m_bIsRed = true;
    m_bIsOver = false;
}

//判断是否死亡
bool ChessBoard::isDead(int id)
{
    if (id == -1)
        return true;

    return m_ChessPieces[id].m_bDead;
}

//确定每一个位置上棋子的id
int ChessBoard::getStoneId(int row, int col)
{
    for (int i = 0; i < 32; ++i)
    {
        if (m_ChessPieces[i].m_nRow == row && m_ChessPieces[i].m_nCol == col && !isDead(i))
            return i;
    }
    return -1;
}

// 车、炮的功能辅助函数   判断两个点是否在一个直线上面,且返回直线之间的棋子个数
int ChessBoard::getStoneCountAtLine(int row1, int col1, int row2, int col2)
{
    //不在同一行或者列
    if (row1 != row2 && col1 != col2)
        return -1;
    //在同一个位置
    if (row1 == row2 && col1 == col2)
        return -1;

    //两个棋子中间的棋子个数
    int ret = 0;

    //行相同
    if (row1 == row2)
    {
        int min = col1 < col2 ? col1 : col2;
        int max = col1 < col2 ? col2 : col1;

        for (int col = min + 1; col < max; ++col)
        {
            if (getStoneId(row1, col) != -1)
                ret++;
        }
    } else
    {
        int min = row1 < row2 ? row1 : row2;
        int max = row1 < row2 ? row2 : row1;
        for (int row = min + 1; row < max; ++row)
        {
            if (getStoneId(row, col1) != -1)
                ret++;
        }
    }

    return ret;
}

//谁胜谁负
void ChessBoard::whoWin()
{
    //将被杀
    if (m_ChessPieces[4].m_bDead == true && m_ChessPieces[20].m_bDead == false)
    {
        m_bIsOver = true;

        //游戏结束,停止计时,计时控制按钮不可再用,直到用户重新启动游戏
        if (m_bIsStart)
        {
            m_timer->stop();
            m_bIsStart = false;
        }

        //计时开始按钮失效
        ui->pushButton_start->setEnabled(false);

        QMessageBox message(QMessageBox::Information, "提示", "本局结束,红方胜利");
        message.setIconPixmap(QPixmap("../images/win.jpg"));
        message.setFont(QFont("华文行楷", 16, QFont::Bold));
        message.exec();

    }

    //帅被杀
    if (m_ChessPieces[4].m_bDead == false && m_ChessPieces[20].m_bDead == true)
    {
        m_bIsOver = true;

        //游戏结束,停止计时,计时控制按钮不可再用,直到用户重新启动游戏
        if (m_bIsStart)
        {
            m_timer->stop();
            m_bIsStart = false;
        }

        //计时开始按钮失效
        ui->pushButton_start->setEnabled(false);

        QMessageBox message(QMessageBox::Information, "提示", "本局结束,黑方胜利");
        message.setIconPixmap(QPixmap("../images/win.jpg"));
        message.setFont(QFont("华文行楷", 16, QFont::Bold));
        message.exec();

    }
}

//是否选中该枚棋子。pt为输入参数; row， col为输出参数
bool ChessBoard::isChecked(QPoint pt, int &row, int &col)
{
    //只要鼠标点击在棋子的半径之内,都算作选中该棋子
    for (int row = 0; row <= 9; ++row)
    {
        for (int col = 0; col <= 8; ++col)
        {
            QPoint temp = center(row, col);
            int x = temp.x() - pt.x();
            int y = temp.y() - pt.y();

            if (x * x + y * y < m_nR * m_nR)
                return true;
        }
    }

    return false;
}

//象棋的棋盘的坐标转换成界面坐标
QPoint ChessBoard::center(int row, int col)
{
    QPoint rePoint;

    //rx和ry是得到横纵坐标的引用
    rePoint.ry() = row * m_nD + m_nOffSet;
    rePoint.rx() = col * m_nD + m_nOffSet;

    return rePoint;
}

//重载:坐标转换
QPoint ChessBoard::center(int id)
{
    return center(m_ChessPieces[id].m_nRow, m_ChessPieces[id].m_nCol);
}

//绘画棋盘
void ChessBoard::paintEvent(QPaintEvent *)
{
    //创建画家
    QPainter painter(this);

    int side = qMin(int((ui->centralwidget->width() - ui->verticalWidget->width()) / 0.9), ui->label->height());

    //设置刻度
    painter.scale(side / 960.0, side / 960.0);

    m_nOffSet = 60;  //距离界面的边距
    m_nD = 90; //间距为50px
    m_nR = m_nD / 2;  //棋子半径为d/2

    //*******************绘画棋盘*******************
    //绘画10条横线
    for (int i = 0; i <= 9; ++i)
    {
        painter.drawLine(QPoint(m_nOffSet, m_nOffSet + i * m_nD), QPoint(m_nOffSet + 8 * m_nD, m_nOffSet + i * m_nD));
    }

    //绘画9条竖线
    for (int i = 0; i <= 8; i++)
    {
        if (i == 0 || i == 8)
        {
            painter.drawLine(QPoint(m_nOffSet + i * m_nD, m_nOffSet),
                             QPoint(m_nOffSet + i * m_nD, m_nOffSet + 9 * m_nD));
        } else
        {
            painter.drawLine(QPoint(m_nOffSet + i * m_nD, m_nOffSet),
                             QPoint(m_nOffSet + i * m_nD, m_nOffSet + 4 * m_nD));
            painter.drawLine(QPoint(m_nOffSet + i * m_nD, m_nOffSet + 5 * m_nD),
                             QPoint(m_nOffSet + i * m_nD, m_nOffSet + 9 * m_nD));
        }
    }

    //绘画4条斜线
    painter.drawLine(QPoint(m_nOffSet+3*m_nD, m_nOffSet), QPoint(m_nOffSet+5*m_nD, m_nOffSet+2*m_nD));
    painter.drawLine(QPoint(m_nOffSet+3*m_nD, m_nOffSet+2*m_nD), QPoint(m_nOffSet+5*m_nD, m_nOffSet));
    painter.drawLine(QPoint(m_nOffSet+3*m_nD, m_nOffSet+7*m_nD), QPoint(m_nOffSet+5*m_nD, m_nOffSet+9*m_nD));
    painter.drawLine(QPoint(m_nOffSet+3*m_nD, m_nOffSet+9*m_nD), QPoint(m_nOffSet+5*m_nD, m_nOffSet+7*m_nD));

    //用四个矩形确定楚河汉界的汉字位置
    QRect rect1(m_nOffSet+m_nD,   m_nOffSet+4*m_nD, m_nD, m_nD);
    QRect rect2(m_nOffSet+2*m_nD, m_nOffSet+4*m_nD, m_nD, m_nD);
    QRect rect3(m_nOffSet+5*m_nD, m_nOffSet+4*m_nD, m_nD, m_nD);
    QRect rect4(m_nOffSet+6*m_nD, m_nOffSet+4*m_nD, m_nD, m_nD);

    //在矩形中写字
    painter.setFont(QFont("隶书", m_nR, 800));
    painter.drawText(rect1, "楚", QTextOption(Qt::AlignCenter));
    painter.drawText(rect2, "河", QTextOption(Qt::AlignCenter));
    painter.drawText(rect3, "汉", QTextOption(Qt::AlignCenter));
    painter.drawText(rect4, "界", QTextOption(Qt::AlignCenter));

    //*******************绘画棋子*******************
    for(int i = 0; i < 32; i++)
    {
        drawChessPieces(painter, i);
    }
}

void ChessBoard::drawChessPieces(QPainter &painter, int id)
{
    //如果棋子已经死亡,则不绘画
    if(m_ChessPieces[id].m_bDead)
        return;

    //确定当前棋子的像素坐标
    QPoint temp=center(id);

    //绘制棋子所占的面积矩形
    QRect rect(temp.x()-m_nR, temp.y()-m_nR, m_nD, m_nD);

    if(m_nSelectID == id)
        painter.setBrush(QBrush(QColor(64,64,196, 80)));
    else
        painter.setBrush(QBrush(QColor(64,64,196, 10)));

    painter.setPen(QColor(0, 0, 0));
    painter.drawEllipse(center(id), m_nR, m_nR);  //绘画圆形
    painter.setFont(QFont("华文行楷", m_nR, 700));

    //设置双方棋子的颜色
    if(id < 16)
    {
        painter.setPen(QColor(0, 0, 0));
    }
    else
    {
        painter.setPen(QColor(255, 0, 0));
    }

    painter.drawText(rect, m_ChessPieces[id].getnName(), QTextOption(Qt::AlignCenter));  //绘画圆形里面的汉字
}