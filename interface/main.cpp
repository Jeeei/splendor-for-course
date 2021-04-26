#include "gameinterface.h"
#include "mainsurface.h"
#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainSurface w;
    w.setFixedSize(1293,765);
    w.show();

    return a.exec();
}
