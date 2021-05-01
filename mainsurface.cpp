#include "mainsurface.h"
#include "ui_mainsurface.h"
#include "rule.h"


mainSurface::mainSurface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainSurface)
{
    ui->setupUi(this);
}

mainSurface::~mainSurface()
{
    delete ui;
}

void mainSurface::on_start_button_clicked()
{
    this->close();
    gameInterface *gameSurface=new gameInterface;
    gameSurface->show();

}

void mainSurface::on_rule_button_clicked()
{
    Rule *r=new Rule();
    r->show();
}
