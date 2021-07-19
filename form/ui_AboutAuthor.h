/********************************************************************************
** Form generated from reading UI file 'AboutAuthor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTAUTHOR_H
#define UI_ABOUTAUTHOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AboutAuthor
{
public:
    QDialogButtonBox *buttonBox;
    QTextBrowser *textBrowser;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *AboutAuthor)
    {
        if (AboutAuthor->objectName().isEmpty())
            AboutAuthor->setObjectName(QString::fromUtf8("AboutAuthor"));
        AboutAuthor->resize(882, 491);
        AboutAuthor->setFocusPolicy(Qt::NoFocus);
        AboutAuthor->setAcceptDrops(false);
        AboutAuthor->setToolTipDuration(0);
        AboutAuthor->setLayoutDirection(Qt::RightToLeft);
        buttonBox = new QDialogButtonBox(AboutAuthor);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(700, 430, 151, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textBrowser = new QTextBrowser(AboutAuthor);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(20, 10, 651, 461));
        textBrowser->setStyleSheet(QString::fromUtf8("background-image: url(:/images/5abc.png);\n"
"font: 9pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        label = new QLabel(AboutAuthor);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(750, 30, 61, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(16);
        label->setFont(font);
        label_2 = new QLabel(AboutAuthor);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(740, 220, 61, 31));
        label_2->setFont(font);
        label_3 = new QLabel(AboutAuthor);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(700, 60, 150, 150));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/WeChat.png")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(AboutAuthor);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(700, 250, 150, 150));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/Alipay.png")));
        label_4->setScaledContents(true);
        label_5 = new QLabel(AboutAuthor);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 0, 882, 491));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/background.jpg")));
        label_5->setScaledContents(true);
        label_5->raise();
        buttonBox->raise();
        textBrowser->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();

        retranslateUi(AboutAuthor);
        QObject::connect(buttonBox, SIGNAL(accepted()), AboutAuthor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AboutAuthor, SLOT(reject()));

        QMetaObject::connectSlotsByName(AboutAuthor);
    } // setupUi

    void retranslateUi(QDialog *AboutAuthor)
    {
        AboutAuthor->setWindowTitle(QCoreApplication::translate("AboutAuthor", "Dialog", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("AboutAuthor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\215\216\346\226\207\346\245\267\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\344\275\234\350\200\205: </span><a href=\"https://xmuli.tech\"><span style=\" font-size:14pt; text-decoration: underline; color:#007af4;\">\345\201\225\350\207\247 | xmuli</span></a></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; "
                        "text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\351\241\271\347\233\256\357\274\232\345\205\263\344\272\216 </span><a href=\"https://github.com/xmuli/chinessChess\"><span style=\" font-size:14pt; text-decoration: underline; color:#007af4;\">ChinessChess</span></a><span style=\" font-size:14pt;\"> \346\255\244\345\274\200\346\272\220\351\241\271\347\233\256 \357\274\214\350\257\264\346\230\216\351\203\275\345\234\250\350\277\231\351\207\214 [\344\270\255\346\226\207 | English] </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\"-qt-pa"
                        "ragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\345\205\266\344\273\226\357\274\232\345\217\257\344\273\245\350\257\267\346\210\221\345\226\235\344\270\200\346\235\257\345\277\253\344\271\220\346\260\264\357\274\214</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\342\200\213       "
                        "      \350\200\214\345\257\271\344\273\223\345\272\223  </span><a href=\"https://github.com/xmuli/chinessChess\"><span style=\" font-size:14pt; text-decoration: underline; color:#007af4;\">ChinessChess</span></a><span style=\" font-size:14pt;\">  \347\232\204 star \345\222\214 fork \346\230\257\347\273\231\346\210\221\347\232\204\346\234\200\345\244\247\351\274\223\345\212\261\357\274\233</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\342\200\213             \345\275\223\347\204\266\346\254\242\350\277\216\344\273\273\344\275\225\344\272\272\346\217\220\344\272\244\345\234\250\346\217\220\344\272\244 pr\357\274\214\345\270\256\345\212\251\344\270\260\345\257\214\345\256\203\357\274\233</span></p>\n"
"<p style=\"-qt-"
                        "paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\342\200\213             \345\257\271\345\272\224\345\274\200\345\217\221\346\225\231\347\250\213\345\222\214\346\272\220\347\240\201\345\267\262\345\274\200\346\272\220\357\274\214\344\276\233\345\244\247\345\256\266\345\255\246\344\271\240\345\217\202\350\200\203\357\274\233</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\342\200\213             \347\203\255\347\210\261\345\274\200\346\272\220\357\274\214"
                        "\347\203\255\347\210\261\347\224\237\345\221\275\357\274\214\347\203\255\347\210\261\347\224\237\346\264\273\357\274\233</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p s"
                        "tyle=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">Telegram: </span><a href=\"https://t.me/xmuli\"><span style=\" font-size:14pt; text-decoration: underline; color:#007af4;\">https://t.me/xmuli</span></a></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">Gmail: xmulitech@gmail.com</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">GitHub: <"
                        "/span><a href=\"https://github.com/xmuli\"><span style=\" font-size:14pt; text-decoration: underline; color:#007af4;\">https://github.com/xmuli</span></a></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">CSDN Bolg: </span><a href=\"https://github.com/xmuli\"><span style=\" font-size:14pt; text-decoration: underline; color:#007af4;\">https://xmuli.blog.csdn.net</span></a></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("AboutAuthor", "\345\276\256    \344\277\241", nullptr));
        label_2->setText(QCoreApplication::translate("AboutAuthor", "\346\224\257\344\273\230\345\256\235", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutAuthor: public Ui_AboutAuthor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTAUTHOR_H
