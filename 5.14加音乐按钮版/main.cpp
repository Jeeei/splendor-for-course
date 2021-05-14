#include "gameinterface.h"
#include "mainsurface.h"
#include "Table1.cpp"
#include "Noble.cpp"
#include "Player.cpp"
#include "Card.cpp"
#include "save.cpp"
#include <QApplication>
#include <QWidget>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainSurface w;
    w.show();
    return a.exec();
}

