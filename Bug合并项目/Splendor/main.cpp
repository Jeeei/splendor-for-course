#include "gameinterface.h"
#include <QApplication>
#include <QWidget>
#include "Card.cpp"
#include "Noble.cpp"
#include "Player.cpp"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    gameInterface w;
    w.setFixedSize(1293,765);
    w.show();
    return a.exec();
}
