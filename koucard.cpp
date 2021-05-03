#include "koucard.h"
#include "ui_koucard.h"

kouCard::kouCard(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::kouCard)
{
    ui->setupUi(this);
}

kouCard::~kouCard()
{
    delete ui;
}

void kouCard::showKouCard()
{
    ui->cardShow->setStyleSheet("border-radius:15px;border-image:url(:/images/card/yellow-middle/1.png)");
}

void kouCard::on_toolButton_clicked()
{
    this->close();
    emit IsKou();
}

void kouCard::on_cardShow_clicked()
{
    this->hide();
}
