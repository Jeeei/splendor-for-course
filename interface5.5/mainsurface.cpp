#include "mainsurface.h"
#include "ui_mainsurface.h"
#include <QDebug>

mainSurface::mainSurface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainSurface)
{
    ui->setupUi(this);
    setWindowTitle("Splendor MainSurface");
    setFixedSize(1400,800);

    connect(gameSurface,&gameInterface::gameInterfaceResign,this,&mainSurface::MainSurfaceResignSlot);

    gameSurface = nullptr;
    r = nullptr;
}

mainSurface::~mainSurface()
{
    //qDebug()<<"MainSurface deleted."<<endl;
    if(gameSurface != nullptr)
        delete gameSurface;
    if(r != nullptr)
        delete r;
    delete ui;
}

void mainSurface::on_start_button_clicked()
{
    gameSurface = new gameInterface(this);
    gameSurface->show();
}

void mainSurface::on_rule_button_clicked()
{
    r = new Rule;
    r->show();
}

void mainSurface::MainSurfaceResignSlot()
{
    if(gameSurface != nullptr)
    {
        delete gameSurface;
        gameSurface = nullptr;
    }
}