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

void END1::showNo1Name(QString name)
{
    ui->name1->setText(name);
}

void END1::showNo2Name(QString name)
{
    ui->name2->setText(name);
}

void END1::showScore1(int score)
{
    ui->score1->setText(QString::number(score));
}

void END1::showScore2(int score)
{
    ui->score2->setText(QString::number(score));
}

void END1::on_back_clicked()
{
    close();
    emit end();
}
