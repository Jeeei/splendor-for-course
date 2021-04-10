#include "gameinterface.h"
#include "ui_gameinterface.h"
#include <iostream>
#include <QtGlobal>
using namespace std;

gameInterface::gameInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameInterface)
{
    ui->setupUi(this);

    //ui->card1_1->setStyleSheet("border-image:url(:/images/card/blue-high/1.png)");
    //ui->card2_1->setStyleSheet("border-image:url(:/images/card/yellow_middle/1.png)");
    //ui->card2_1->setStyleSheet("border-image:url(:/images/card/green_low/1.png)");

    dialog = new Dialog(this);//购买窗口
    dialog->setModal(false);
    connect(dialog, SIGNAL(DialogPurchase()), SLOT(DialogPurchaseSlot()));// 把子窗口的信号连接到父窗口
    connect(dialog,SIGNAL(DialogCancel()),SLOT(DialogCancelSlot()));
}

gameInterface::~gameInterface()
{
    delete ui;
}

void gameInterface::DialogPurchaseSlot()
{
    // 父窗口用于接收子窗口信号的slot
    dialog->close();
    ui->card1_1->setStyleSheet("border-image:url(:/images/card/blue-high/5.png)");
}
void gameInterface:: DialogCancelSlot()
{
    dialog->close();
}

void gameInterface::on_gold_num_textChanged()
{
    //金币数目函数
}

void gameInterface::on_black_num_textChanged()
{
    //黑币数目函数
}

void gameInterface::on_red_num_textChanged()
{
    //红币数目函数
}



void gameInterface::on_green_num_textChanged()
{
    //绿币数目函数
}

void gameInterface::on_blue_num_textChanged()
{
    //蓝币数目函数
}

void gameInterface::on_white_num_textChanged()
{
    //白币数目函数
}

void gameInterface::on_card1_1_clicked()
{
    //background-color: rgba(255, 255, 224, 10%)；//半透明的样式表代码
    //卡1的点击回馈
    dialog->show();

    //ui->card1_1->setStyleSheet("border-image:url(:/images/card/blue-high/5.png)");
}

void gameInterface::on_card1_2_clicked(bool checked)
{
    //卡2的点击回馈
}

void gameInterface::on_card1_3_clicked(bool checked)
{
    //卡3的点击回馈
}


void gameInterface::on_card1_4_clicked()
{
    //卡4的点击回馈
}

void gameInterface::on_card2_1_clicked(bool checked)
{
    //卡5的点击回馈
    ui->card2_1->setStyleSheet("border-image:url(:/images/card/yellow-middle/5.png)");
}

void gameInterface::on_card2_2_clicked(bool checked)
{
    //卡6的点击回馈
}

void gameInterface::on_card2_3_clicked(bool checked)
{
    //卡7的点击回馈
}


void gameInterface::on_card2_4_clicked(bool checked)
{
    //卡8的点击回馈
}

void gameInterface::on_card3_1_clicked(bool checked)
{
    //卡9的点击回馈
    ui->card3_1->setStyleSheet("border-image:url(:/images/card/green-low/5.png)");
}

void gameInterface::on_card3_2_clicked(bool checked)
{
    //卡10的点击回馈
}

void gameInterface::on_card3_3_clicked(bool checked)
{
    //卡11的点击回馈
}

void gameInterface::on_card3_4_clicked(bool checked)
{
    //卡12的点击回馈
}
