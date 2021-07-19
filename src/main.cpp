//
// Created by andy on 2021/7/19.
//

/***
 *      ┌─┐       ┌─┐ + +
 *   ┌──┘ ┴───────┘ ┴──┐++
 *   │                 │
 *   │       ───       │++ + + +
 *   ███████───███████ │+
 *   │                 │+
 *   │       ─┴─       │
 *   │                 │
 *   └───┐         ┌───┘
 *       │         │
 *       │         │   + +
 *       │         │
 *       │         └──────────────┐
 *       │                        │
 *       │                        ├─┐
 *       │                        ┌─┘
 *       │                        │
 *       └─┐  ┐  ┌───────┬──┐  ┌──┘  + + + +
 *         │ ─┤ ─┤       │ ─┤ ─┤
 *         └──┴──┘       └──┴──┘  + + + +
 *                神兽保佑
 *               代码无BUG!
 */

#include <QApplication>

#include "SelectGameMode.h"
#include "ChooseMainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SelectGameMode dlg;
    dlg.setWindowTitle("选择游戏方式");
    dlg.setFixedSize(200,120);
    dlg.setWindowIcon(QIcon("../images/chess.svg"));


    if(dlg.exec() != QDialog::Accepted)
        return 0;


    return a.exec();
}