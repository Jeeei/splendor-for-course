#include "end1.h"
#include "ui_end1.h"

END1::END1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::END1)
{
    ui->setupUi(this);
}

END1::~END1()
{
    delete ui;
}

void END1::showNo1(QString PlayerImg)
{
    ui->no1->setStyleSheet(PlayerImg);
}

void END1::showNo2(QString PlayerImg)
{
    ui->no2->setStyleSheet(PlayerImg);
}

