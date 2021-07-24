//
// Created by andy on 2021/7/21.
//

#ifndef CHINESECHESS_ABOUTAUTHOR_H
#define CHINESECHESS_ABOUTAUTHOR_H

#include <QDialog>
#include <QFont>
#include "ui_AboutAuthor.h"


//namespace Ui {
//    class AboutAuthor;
//}

class AboutAuthor : public QDialog
{
    Q_OBJECT

public:
    explicit AboutAuthor(QWidget *parent = 0);
    ~AboutAuthor();

private:
    Ui::AboutAuthor *ui;
};

#endif //CHINESECHESS_ABOUTAUTHOR_H
