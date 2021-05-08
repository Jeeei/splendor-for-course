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


    gameSurface = nullptr;
    r = nullptr;
}

mainSurface::~mainSurface()
{
    //qDebug()<<"MainSurface deleted."<<endl;
//    if(gameSurface != nullptr)
//    {
//        delete gameSurface;
//        gameSurface = nullptr;
//    }
//    if(r != nullptr)
//    {
//        delete r;
//        r = nullptr;
//    }
    delete ui;
}

void mainSurface::on_start_button_clicked()
{
    if(gameSurface == nullptr)
    {
        gameSurface = new gameInterface(this);
        //Resign信号连接
        connect(gameSurface,&gameInterface::gameInterfaceResign,this,&mainSurface::MainSurfaceResignSlot);
        gameSurface->show();
    }
}

void mainSurface::on_rule_button_clicked()
{
    if(r == nullptr)
        r = new Rule;
    r->show();
}

void mainSurface::MainSurfaceResignSlot()
{
//    qDebug()<<"Main resign.";
    if(gameSurface != nullptr)
    {
        gameSurface->deleteLater();
        gameSurface = nullptr;
    }
}
