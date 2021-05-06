#include "pickcard.h"
#include "ui_pickcard.h"

pickCard::pickCard(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::pickCard)
{
    ui->setupUi(this);
    setGeometry(600,160,270,350);
    hide();
}

pickCard::~pickCard()
{
    delete ui;
}

void pickCard::showCard(QString s)//显示贴图
{
    ui->cardShow->setStyleSheet(s);
}

void pickCard::on_cardShow_clicked()
{
    ui->cardShow->setStyleSheet("border-radius:55px;background-color: rgba(255, 255, 254, 50)");
    this->close();
}

void pickCard::closeEvent(QCloseEvent *)
{
    emit PickCardCancel();
}
