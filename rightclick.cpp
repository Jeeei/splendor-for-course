#include "rightclick.h"
#include "ui_rightclick.h"
#include <QRect>
#include "mainsurface.h"

RightClick::RightClick(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::RightClick)
{
    ui->setupUi(this);

    rrule1=new rightRule(this);
    rrule1->setGeometry(0,0,500,660);
    rrule1->hide();
}

RightClick::~RightClick()
{
    delete ui;
}

void RightClick::on_rule_clicked()
{
    rrule1->show();
}

void RightClick::on_resign_clicked()
{
    mainSurface *msurface=new mainSurface;
    msurface->show();
}

void RightClick::on_toolButton_clicked()
{
    this->hide();
}
