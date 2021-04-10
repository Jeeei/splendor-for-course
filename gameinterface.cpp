#include "gameinterface.h"
#include "ui_gameinterface.h"
#include <iostream>
#include <QtGlobal>
#include <cstdlib>
using namespace std;

gameInterface::gameInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameInterface)
{
    ui->setupUi(this);
}

gameInterface::~gameInterface()
{
    delete ui;
}

void gameInterface::ran(QImage card[3][30])
{
    //蓝卡的图片存储
    card[0][0]=QImage(":/card/blue-high/1.png");
    card[0][1]=QImage(":/card/blue-high/2.png");
    card[0][2]=QImage(":/card/blue-high/3.png");
    card[0][3]=QImage(":/card/blue-high/4.png");
    card[0][4]=QImage(":/card/blue-high/5.png");
    //绿卡的图片存储
    //黄卡的图片存储
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
    //ui->card1_1->setStyleSheet("QPushButton{border-image: url(:/card/blue-high/5.png);border:none;color:rgb(255, 255, 255);}");
    //ui->card1_1->setStyleSheet("QPushButton:clicked{border-image: url(:/card/blue-high/5.png);}");
    ui->card1_1->setStyleSheet("border-image:url(:/card/blue-high/5.png)");
    update();
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

