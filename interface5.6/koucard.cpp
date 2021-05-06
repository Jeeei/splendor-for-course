#include "koucard.h"
#include "ui_koucard.h"

kouCard::kouCard(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::kouCard)
{
    ui->setupUi(this);
    setGeometry(1000,220,270,350);
    ui->Gold->hide();
    hide();
}

kouCard::~kouCard()
{
    delete ui;
}

void kouCard::showCard(QString cardimg)
{
    ui->ShowCard->setStyleSheet("border-radius:15px;"+cardimg);
}

void kouCard::showGold()
{
    ui->Gold->show();
}

void kouCard::closeEvent(QCloseEvent *)
{
    ui->Gold->hide();
}

void kouCard::on_toolButton_clicked()
{
    close();
    emit Retain();
}

void kouCard::on_ShowCard_clicked()
{
    hide();
}
