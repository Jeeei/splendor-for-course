#include "pickcard.h"
#include "ui_pickcard.h"

pickCard::pickCard(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::pickCard)
{
    ui->setupUi(this);
}

pickCard::~pickCard()
{
    delete ui;
}

void pickCard::showCard()
{
    ui->cardShow->setStyleSheet("border-radius:55px;border-image:url(:/images/card/blue-high/1.png)");
}

void pickCard::on_cardShow_clicked()
{
    ui->cardShow->setStyleSheet("border-radius:55px;background-color: rgba(255, 255, 254, 50)");
    this->close();
}



void pickCard::on_purchase_clicked()
{
    this->close();
}
