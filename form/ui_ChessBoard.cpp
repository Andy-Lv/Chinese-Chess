/********************************************************************************
** Form generated from reading UI file 'ChessBoard.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSBOARD_H
#define UI_CHESSBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChessBoard
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLCDNumber *lcdNumber;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_start;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_reset;
    QPushButton *pushButton_restart;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_about;
    QMenuBar *menubar;

    void setupUi(QMainWindow *ChessBoard)
    {
        if (ChessBoard->objectName().isEmpty())
            ChessBoard->setObjectName(QString::fromUtf8("ChessBoard"));
        ChessBoard->resize(1156, 940);
        centralwidget = new QWidget(ChessBoard);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setScaledContents(false);

        horizontalLayout->addWidget(label);

        verticalWidget = new QWidget(centralwidget);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(verticalWidget->sizePolicy().hasHeightForWidth());
        verticalWidget->setSizePolicy(sizePolicy1);
        verticalWidget->setStyleSheet(QString::fromUtf8("#verticalWidget{\n"
"border-image: url(:/images/b.jpg);\n"
"}"));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(30, 20, 30, 50);
        label_2 = new QLabel(verticalWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(18);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        lcdNumber = new QLCDNumber(verticalWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy2);
        lcdNumber->setMinimumSize(QSize(0, 83));

        verticalLayout->addWidget(lcdNumber);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        pushButton_start = new QPushButton(verticalWidget);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_start->sizePolicy().hasHeightForWidth());
        pushButton_start->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(pushButton_start);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_reset = new QPushButton(verticalWidget);
        pushButton_reset->setObjectName(QString::fromUtf8("pushButton_reset"));
        sizePolicy3.setHeightForWidth(pushButton_reset->sizePolicy().hasHeightForWidth());
        pushButton_reset->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(pushButton_reset);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton_restart = new QPushButton(verticalWidget);
        pushButton_restart->setObjectName(QString::fromUtf8("pushButton_restart"));

        verticalLayout->addWidget(pushButton_restart);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_about = new QPushButton(verticalWidget);
        pushButton_about->setObjectName(QString::fromUtf8("pushButton_about"));
        sizePolicy3.setHeightForWidth(pushButton_about->sizePolicy().hasHeightForWidth());
        pushButton_about->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(pushButton_about);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addWidget(verticalWidget);

        horizontalLayout->setStretch(0, 11);
        horizontalLayout->setStretch(1, 3);
        ChessBoard->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChessBoard);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1156, 22));
        ChessBoard->setMenuBar(menubar);

        retranslateUi(ChessBoard);

        QMetaObject::connectSlotsByName(ChessBoard);
    } // setupUi

    void retranslateUi(QMainWindow *ChessBoard)
    {
        ChessBoard->setWindowTitle(QCoreApplication::translate("ChessBoard", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("ChessBoard", "\345\257\271\346\210\230\350\256\241\346\227\266\357\274\232", nullptr));
        pushButton_start->setText(QCoreApplication::translate("ChessBoard", "\345\274\200\345\247\213", nullptr));
        pushButton_reset->setText(QCoreApplication::translate("ChessBoard", "\351\207\215\347\275\256", nullptr));
        pushButton_restart->setText(QCoreApplication::translate("ChessBoard", "\351\207\215\346\226\260\346\270\270\346\210\217", nullptr));
        pushButton_about->setText(QCoreApplication::translate("ChessBoard", "\345\205\263\344\272\216\344\275\234\350\200\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChessBoard: public Ui_ChessBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSBOARD_H
