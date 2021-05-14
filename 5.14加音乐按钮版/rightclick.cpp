#include "rightclick.h"
#include "ui_rightclick.h"
#include <QRect>

RightClick::RightClick(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::RightClick)
{
    ui->setupUi(this);
    setGeometry(827,7,570,660);
    hide();
    rrule1 = new rightRule(this);

}

RightClick::~RightClick()
{
    delete ui;
    //delete rrule1;
}

void RightClick::on_rule_clicked()
{
    rrule1->show();
}

void RightClick::on_resign_clicked()
{
    this->close();
    emit resign();
}


void RightClick::on_back_clicked()
{
    this->hide();
}

void RightClick::on_save_clicked()
{
    emit save();
}

void RightClick::on_tryAgain_clicked()
{
    this->close();
    emit tryAgain();
}
