#include "pickcoin.h"
#include "ui_pickcoin.h"

pickCoin::pickCoin(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::pickCoin)
{
    ui->setupUi(this);
}

pickCoin::~pickCoin()
{
    delete ui;
}

void pickCoin::showCoin1()
{
    ui->coin1->setStyleSheet("border-image:url(:/images/black.PNG);border-radius:55px");
}

void pickCoin::on_coin1_clicked()
{
    ui->coin1->setStyleSheet("border-radius:55px;background-color: rgba(255, 255, 254, 50);");
    this->close();
}

void pickCoin::on_OK_clicked()
{
    this->close();
}
