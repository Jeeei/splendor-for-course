#include "dialog.h"
#include "ui_dialog.h"
#include <QObject>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->purchase, SIGNAL(clicked()), SLOT(ClickedPurchase()));
    connect(ui->cancel,SIGNAL(clicked()),SLOT(ClickedCancel()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showImageChanged(int i)
{
    switch(i)
    {
    case 1:
        ui->label->setStyleSheet("border-image:url(:/images/card/blue-high/1.png)");//第一行卡片
        break;
    case 2:
        ui->label->setStyleSheet("border-image:url(:/images/card/yellow-middle/1.png)");//第二行卡片
        break;
    case 3:
        ui->label->setStyleSheet("border-image:url(:/images/card/green-low/1.png)");//第三行卡片
        break;
    }
}
