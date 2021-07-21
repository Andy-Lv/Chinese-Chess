//
// Created by andy on 2021/7/21.
//

#include "AboutAuthor.h"
#include "ui_AboutAuthor.h"
#include <QIcon>

AboutAuthor::AboutAuthor(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::AboutAuthor)
{
    this->setWindowIcon(QIcon(":/images/chess.svg"));
    ui->setupUi(this);
}

AboutAuthor::~AboutAuthor()
{
    delete ui;
}
