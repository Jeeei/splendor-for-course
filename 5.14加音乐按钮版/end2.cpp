#include "end2.h"
#include "ui_end2.h"

END2::END2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::END2)
{
    ui->setupUi(this);
}

END2::~END2()
{
    delete ui;
}

void END2::showNo1(QString PlayerImg)
{
    ui->no1->setStyleSheet(PlayerImg);
}

void END2::showNo2(QString PlayerImg)
{
    ui->no2->setStyleSheet(PlayerImg);
}

void END2::showScore(int score)
{
    ui->score->setText(QString::number(score));
}

void END2::on_back_clicked()
{
    close();
    emit end();
}
