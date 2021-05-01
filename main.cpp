#include "gameinterface.h"
#include "mainsurface.h"
#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainSurface *w=new mainSurface;
    w->setFixedSize(1400,800);
    w->show();

    return a.exec();
}
