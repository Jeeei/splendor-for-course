#include "gameinterface.h"
#include "mainsurface.h"
#include "Table1.cpp"
#include "Noble.cpp"
#include "Player.cpp"
#include "Card.cpp"
#include <QApplication>
#include <QWidget>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainSurface w;
    w.setFixedSize(1293,765);
    w.show();
    //qDebug()<<"PicAddr: ";
    return a.exec();
}

