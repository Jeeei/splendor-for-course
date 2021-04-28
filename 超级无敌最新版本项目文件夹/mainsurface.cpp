#include "mainsurface.h"
#include "ui_mainsurface.h"


mainSurface::mainSurface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainSurface)
{
    ui->setupUi(this);
    gameSurface = NULL;
}

mainSurface::~mainSurface()
{
    delete ui;
}

void mainSurface::on_start_button_clicked()
{
    this->close();
    gameSurface = new gameInterface;
    gameSurface->show();
}

void mainSurface::on_rule_button_clicked()
{
    r = new Rule;
    r->show();
}
