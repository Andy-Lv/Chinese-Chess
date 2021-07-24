//
// Created by andy on 2021/7/19.
//

#ifndef CHINESECHESS_SELECTGAMEMODE_H
#define CHINESECHESS_SELECTGAMEMODE_H

#include <QDialog>
#include <QPushButton>

class SelectGameMode:public QDialog
{
    Q_OBJECT
public:
    explicit SelectGameMode(QWidget *parent = 0);
    ~SelectGameMode();

    QPushButton* m_buttons[4];
    int m_nSelect;

public slots:
    void slotClicked();
};

#endif //CHINESECHESS_SELECTGAMEMODE_H


