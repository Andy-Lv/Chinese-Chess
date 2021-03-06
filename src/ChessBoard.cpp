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
    painter.drawLine(QPoint(m_nOffSet + 3 * m_nD, m_nOffSet), QPoint(m_nOffSet + 5 * m_nD, m_nOffSet + 2 * m_nD));
    painter.drawLine(QPoint(m_nOffSet + 3 * m_nD, m_nOffSet + 2 * m_nD), QPoint(m_nOffSet + 5 * m_nD, m_nOffSet));
    painter.drawLine(QPoint(m_nOffSet + 3 * m_nD, m_nOffSet + 7 * m_nD),
                     QPoint(m_nOffSet + 5 * m_nD, m_nOffSet + 9 * m_nD));
    painter.drawLine(QPoint(m_nOffSet + 3 * m_nD, m_nOffSet + 9 * m_nD),
                     QPoint(m_nOffSet + 5 * m_nD, m_nOffSet + 7 * m_nD));

    //用四个矩形确定楚河汉界的汉字位置
    QRect rect1(m_nOffSet + m_nD, m_nOffSet + 4 * m_nD, m_nD, m_nD);
    QRect rect2(m_nOffSet + 2 * m_nD, m_nOffSet + 4 * m_nD, m_nD, m_nD);
    QRect rect3(m_nOffSet + 5 * m_nD, m_nOffSet + 4 * m_nD, m_nD, m_nD);
    QRect rect4(m_nOffSet + 6 * m_nD, m_nOffSet + 4 * m_nD, m_nD, m_nD);

    //在矩形中写字
    painter.setFont(QFont("隶书", m_nR, 800));
    painter.drawText(rect1, "楚", QTextOption(Qt::AlignCenter));
    painter.drawText(rect2, "河", QTextOption(Qt::AlignCenter));
    painter.drawText(rect3, "汉", QTextOption(Qt::AlignCenter));
    painter.drawText(rect4, "界", QTextOption(Qt::AlignCenter));

    //*******************绘画棋子*******************
    for (int i = 0; i < 32; i++)
    {
        drawChessPieces(painter, i);
    }
}

void ChessBoard::drawChessPieces(QPainter &painter, int id)
{
    //如果棋子已经死亡,则不绘画
    if (m_ChessPieces[id].m_bDead)
        return;

    //确定当前棋子的像素坐标
    QPoint temp = center(id);

    //绘制棋子所占的面积矩形
    QRect rect(temp.x() - m_nR, temp.y() - m_nR, m_nD, m_nD);

    if (m_nSelectID == id)
        painter.setBrush(QBrush(QColor(64, 64, 196, 80)));
    else
        painter.setBrush(QBrush(QColor(64, 64, 196, 10)));

    painter.setPen(QColor(0, 0, 0));
    painter.drawEllipse(center(id), m_nR, m_nR);  //绘画圆形
    painter.setFont(QFont("华文行楷", m_nR, 700));

    //设置双方棋子的颜色
    if (id < 16)
    {
        painter.setPen(QColor(0, 0, 0));
    } else
    {
        painter.setPen(QColor(255, 0, 0));
    }

    painter.drawText(rect, m_ChessPieces[id].getnName(), QTextOption(Qt::AlignCenter));  //绘画圆形里面的汉字
}

//使mouseMoveEvent取得的坐标系转换到Painter的坐标系
QPoint ChessBoard::getRealPoint(QPoint pt)
{
    int side = qMin(int((ui->centralwidget->width() - ui->verticalWidget->width()) / 0.9), ui->label->height());
    QPoint ret;

    ret.setX(pt.x() / double(side) * 960.0);
    ret.setY(pt.y() / double(side) * 960.0);

    return ret;
}

//鼠标点击事件
void ChessBoard::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() != Qt::LeftButton || ev->type() != QEvent::Type::MouseButtonPress)
    {
        //只响应鼠标左键的单击操作 防止游戏结束重复弹框
        return;
    }

    QPoint pt = ev->pos();
    pt = getRealPoint(pt);

    //将pt转化成棋盘的像行列值
    //判断这个行列值上面有没有棋子
    int row, col;

    //点击棋盘外面就不做处理
    if (!isChecked(pt, row, col))
        return;

    //判断游戏是否结束
    if (m_bIsOver)
    {
        QMessageBox message(QMessageBox::Information, "提示", "本局已结束，请重新开始.");
        message.setIconPixmap(QPixmap(":/images/win.jpg"));
        message.setFont(QFont("华文行楷", 16, QFont::Bold));
        message.exec();
        return;
    }

    //判断是哪一个棋子被选中，根据ID（这里的局部i）来记录下来
    int i;
    m_nCheckedID = -1;

    for (i = 0; i <= 31; ++i)
    {
        if (m_ChessPieces[i].m_nRow == row && m_ChessPieces[i].m_nCol == col && m_ChessPieces[i].m_bDead == false)
            break;
    }

    if (0 <= i && i < 32)
        m_nCheckedID = i;  //选中的棋子的ID

    clickPieces(m_nCheckedID, row, col);

    update();
    whoWin();
}

void ChessBoard::clickPieces(int checkedID, int &row, int &col)
{
    m_nCheckedID = checkedID;

    if (m_nSelectID == -1)//选中棋子
    {
        if (m_nCheckedID != -1)
        {
            if (m_bIsRed == m_ChessPieces[m_nCheckedID].m_bRed)
            {
                m_nSelectID = m_nCheckedID;
            }
        }
    } else//走棋子
    {
        if (canMove(m_nSelectID, m_nCheckedID, row, col))
        {
            //m_nSelectID为第一次点击选中的棋子，
            //m_nCheckedID为第二次点击||被杀的棋子ID，准备选中棋子下子的地方
            m_ChessPieces[m_nSelectID].m_nRow = row;
            m_ChessPieces[m_nSelectID].m_nCol = col;
            if (m_nCheckedID != -1)
                m_ChessPieces[m_nCheckedID].m_bDead = true;

            m_nSelectID = -1;
            m_bIsRed = !m_bIsRed;
        }
    }
}

//总的移动规则，选中准备下的棋子，被杀的棋子， 准备移动到的目的行列值
bool ChessBoard::canMove(int moveId, int killId, int row, int col)
{
    //1.确定是选择其它棋子还是走棋
    //2.是否需要使用到canMoveXXX()来做限制
    //3.罗列出所有情况，和需要的得到的结果值 ==>  然后进行中间的逻辑层判断※不要受到别人的代码框架的束缚※
    if (m_ChessPieces[moveId].m_bRed == m_ChessPieces[killId].m_bRed)  //选择其它棋子，返回false
    {
        if (killId == -1)  //其中有一个特殊情况，黑+m_ChessPieces[-1].m_bRed ==> 也需要判断能否
        {
            switch (m_ChessPieces[moveId].m_emType)
            {
                case ChessPieces::JIANG:
                    return canMoveJIANG(moveId, killId, row, col);
                case ChessPieces::SHI:
                    return canMoveSHI(moveId, killId, row, col);
                case ChessPieces::XIANG:
                    return canMoveXIANG(moveId, killId, row, col);
                case ChessPieces::MA:
                    return canMoveMA(moveId, killId, row, col);
                case ChessPieces::CHE:
                    return canMoveCHE(moveId, killId, row, col);
                case ChessPieces::PAO:
                    return canMovePAO(moveId, killId, row, col);
                case ChessPieces::BING:
                    return canMoveBING(moveId, killId, row, col);
            }

        }
        m_nSelectID = killId;

        return false;
    } else  //选择其走棋，返回true
    {
        switch (m_ChessPieces[moveId].m_emType)
        {
            case ChessPieces::JIANG:
                return canMoveJIANG(moveId, killId, row, col);
            case ChessPieces::SHI:
                return canMoveSHI(moveId, killId, row, col);
            case ChessPieces::XIANG:
                return canMoveXIANG(moveId, killId, row, col);
            case ChessPieces::MA:
                return canMoveMA(moveId, killId, row, col);
            case ChessPieces::CHE:
                return canMoveCHE(moveId, killId, row, col);
            case ChessPieces::PAO:
                return canMovePAO(moveId, killId, row, col);
            case ChessPieces::BING:
                return canMoveBING(moveId, killId, row, col);
        }
        return true;
    }
}

bool ChessBoard::canMoveJIANG(int moveId, int killId, int row, int col)
{
    if (m_ChessPieces[moveId].m_bRed) //红 将
    {
        if (row < 7 || col < 3 || col > 5) return false;
    } else  //黑 将
    {

        if (row > 2 || col < 3 || col > 5) return false;
    }

    int dr = m_ChessPieces[moveId].m_nRow - row;
    int dc = m_ChessPieces[moveId].m_nCol - col;
    int d = abs(dr) * 10 + abs(dc);
    if (d == 1 || d == 10)
        return true;

    return false;
}

bool ChessBoard::canMoveSHI(int moveId, int killId, int row, int col)
{
    if (m_ChessPieces[moveId].m_bRed) //红 士
    {
        if (row < 7 || col < 3 || col > 5) return false;
    } else  //黑 士
    {

        if (row > 2 || col < 3 || col > 5) return false;
    }

    int dr = m_ChessPieces[moveId].m_nRow - row;
    int dc = m_ChessPieces[moveId].m_nCol - col;
    int d = abs(dr) * 10 + abs(dc);
    if (d == 11)
        return true;

    return false;
}

bool ChessBoard::canMoveXIANG(int moveId, int killId, int row, int col)
{
    if (m_ChessPieces[moveId].m_bRed) //红
    {
        if (row < 5) return false;
    } else  //黑
    {

        if (row > 4) return false;
    }

    int dr = m_ChessPieces[moveId].m_nRow - row;
    int dc = m_ChessPieces[moveId].m_nCol - col;
    int d = abs(dr) * 10 + abs(dc);

    int dr2 = (m_ChessPieces[moveId].m_nRow + row) / 2;
    int dc2 = (m_ChessPieces[moveId].m_nCol + col) / 2;

    //象眼被堵，就不能够调，就会有i属于0~31，返回false
    int i = 0;
    for (i = 0; i <= 31; i++)
    {
        if (m_ChessPieces[i].m_nRow == dr2 && m_ChessPieces[i].m_nCol == dc2 && m_ChessPieces[i].m_bDead == false)
            break;
    }

    if (0 <= i && i <= 31)
        return false;

    if (d == 22)
        return true;

    return false;
}

bool ChessBoard::canMoveMA(int moveId, int killId, int row, int col)
{
    int dr = m_ChessPieces[moveId].m_nRow - row;
    int dc = m_ChessPieces[moveId].m_nCol - col;
    int d = abs(dr) * 10 + abs(dc);

    int dr2 = (m_ChessPieces[moveId].m_nRow + row) / 2;
    int dc2 = (m_ChessPieces[moveId].m_nCol + col) / 2;

    // 蹩脚马
    if (abs(dr) == 2 && abs(dc) == 1)
    {
        int i = 0;
        if (row < m_ChessPieces[moveId].m_nRow)
        {
            for (i = 0; i <= 31; i++)
            {
                if (m_ChessPieces[i].m_nRow == (m_ChessPieces[moveId].m_nRow - 1) &&
                    m_ChessPieces[i].m_nCol == m_ChessPieces[moveId].m_nCol && m_ChessPieces[i].m_bDead == false)
                    break;
            }
        } else
        {
            for (i = 0; i <= 31; i++)
            {
                if (m_ChessPieces[i].m_nRow == (m_ChessPieces[moveId].m_nRow + 1) &&
                    m_ChessPieces[i].m_nCol == m_ChessPieces[moveId].m_nCol && m_ChessPieces[i].m_bDead == false)
                    break;
            }
        }

        if (0 <= i && i <= 31)
            return false;
    }

    if (abs(dr) == 1 && abs(dc) == 2)
    {
        int i = 0;
        if (col < m_ChessPieces[moveId].m_nCol)
        {

            for (i = 0; i <= 31; i++)
            {
                if (m_ChessPieces[i].m_nRow == m_ChessPieces[moveId].m_nRow &&
                    m_ChessPieces[i].m_nCol == (m_ChessPieces[moveId].m_nCol - 1) && m_ChessPieces[i].m_bDead == false)
                    break;
            }
        } else
        {
            for (i = 0; i <= 31; i++)
            {
                if (m_ChessPieces[i].m_nRow == m_ChessPieces[moveId].m_nRow &&
                    m_ChessPieces[i].m_nCol == (m_ChessPieces[moveId].m_nCol + 1) && m_ChessPieces[i].m_bDead == false)
                    break;
            }
        }

        if (0 <= i && i <= 31)
            return false;

    }

    if (d == 12 || d == 21)
        return true;

    return false;
}

bool ChessBoard::canMoveCHE(int moveId, int killId, int row, int col)
{
    int ret = getStoneCountAtLine(m_ChessPieces[moveId].m_nRow, m_ChessPieces[moveId].m_nCol, row, col);
    if(ret == 0)
        return true;

    return false;
}

bool ChessBoard::canMovePAO(int moveId, int killId, int row, int col)
{
    int ret = getStoneCountAtLine(row, col, m_ChessPieces[moveId].m_nRow, m_ChessPieces[moveId].m_nCol);
    if(killId != -1)
    {
        if(ret == 1)
            return true;
    }
    else
    {
        if(ret == 0)
            return true;
    }
    return false;
}

bool ChessBoard::canMoveBING(int moveId, int killId, int row, int col)
{
    int dr = m_ChessPieces[moveId].m_nRow - row;
    int dc = m_ChessPieces[moveId].m_nCol - col;
    int d = abs(dr)*10 + abs(dc);
    if(d != 1 && d != 10) return false;


    if(m_ChessPieces[moveId].m_bRed) //红 兵
    {
        if(row >  m_ChessPieces[moveId].m_nRow) return false;
        if(m_ChessPieces[moveId].m_nRow == 5 || m_ChessPieces[moveId].m_nRow == 6)
        {
            if(col == m_ChessPieces[moveId].m_nCol && row == (m_ChessPieces[moveId].m_nRow-1))
                return true;
        }
        else
        {
            if((col == m_ChessPieces[moveId].m_nCol && row <= 4) || (row == m_ChessPieces[moveId].m_nRow && abs(col-m_ChessPieces[moveId].m_nCol)==1))
                return true;
        }

        return false;
    }
    else  //黑 兵
    {
        if(row <  m_ChessPieces[moveId].m_nRow) return false;
        if(m_ChessPieces[moveId].m_nRow == 3 || m_ChessPieces[moveId].m_nRow == 4)
        {
            if(col == m_ChessPieces[moveId].m_nCol && row == (m_ChessPieces[moveId].m_nRow+1))
                return true;
        }
        else
        {
            if((col == m_ChessPieces[moveId].m_nCol && row >= 5) || (row == m_ChessPieces[moveId].m_nRow && abs(col-m_ChessPieces[moveId].m_nCol)==1))
                return true;
        }

        return false;
    }

    return true;
}

//刷新时间
void ChessBoard::updateTime()
{
    *m_timeRecord = m_timeRecord->addSecs(1);
    ui->lcdNumber->display(m_timeRecord->toString("hh:mm:ss"));

    if(m_bIsStart == false)
    {
        ui->pushButton_start->setText("开始");
    }
    else if(m_bIsStart == true)
    {
        ui->pushButton_start->setText("暂停");
    }
}

void ChessBoard::on_pushButton_start_clicked()
{
    if(!m_bIsStart) //尚未开始 开始计时
    {
        m_timer->start(1000);
        ui->pushButton_start->setText("暂停");
    }
    else //已经开始，暂停
    {
        m_timer->stop();
        ui->pushButton_start->setText("继续");
    }
    m_bIsStart = !m_bIsStart;
}

void ChessBoard::on_pushButton_reset_clicked()
{
    m_timer->stop();    //计时器停止
    m_timeRecord->setHMS(0,0,0); //时间设为0
    ui->lcdNumber->display(m_timeRecord->toString("hh:mm:ss")); //显示00:00:00
    m_bIsStart = false;
    ui->pushButton_start->setText("开始");
    ui->pushButton_start->setEnabled(true);
}

void ChessBoard::on_pushButton_about_clicked()
{
    m_pAbout->setWindowTitle("关于作者");
    m_pAbout->show();

}

void ChessBoard::on_pushButton_restart_clicked()
{
    init();
    on_pushButton_reset_clicked();
    update();
}