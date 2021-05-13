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
    //ui->no1->setStyleSheet(PlayerImg);
    ui->no1->setStyleSheet("border-image:url(:/images/role/3.jpg);border-radius:15px");
}

void END1::showNo2(QString PlayerImg)
{
    //ui->no2->setStyleSheet(PlayerImg);
    ui->no2->setStyleSheet("border-image:url(:/images/role/5.jpg);border-radius:15px");
}

void END1::showScore1(int score)
{
    //ui->score1->setText(QString::number(score));
}

void END1::showScore2(int score)
{
    //ui->score2->setText(QString::number(score));
}

void END1::on_back_clicked()
{
    close();
    emit end();
}
