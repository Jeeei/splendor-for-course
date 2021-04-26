#include "gameinterface.h"
#include "ui_gameinterface.h"
#include "mainsurface.h"
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
    //dialog->setModal(true);
    dialog2=new Dialog2(this);//拿币窗口

    connect(dialog, SIGNAL(DialogPurchase()), SLOT(DialogPurchaseSlot()));// 把子窗口的信号连接到父窗口
    connect(dialog,SIGNAL(DialogCancel()),SLOT(DialogCancelSlot()));

    connect(dialog2,SIGNAL(dialog2OK()),SLOT(dialog2OKSlot()));

}

gameInterface::~gameInterface()
{
    delete ui;
}

void gameInterface::DialogPurchaseSlot()
{
    // 父窗口用于接收子窗口信号的slot
    action=1;
    dialog->close();
    ui->card1_1->setStyleSheet("border-image:url(:/images/card/blue-high/5.png)");
    QString have_string="0";
    ui->red_have->setFontPointSize(qreal(24));
    ui->red_have->setTextColor(QColor(255,255,255));
    ui->red_have->setText("0");
    ui->red_num->setFontPointSize(qreal(14));
    ui->red_num->setTextColor(QColor(255,255,255));
    ui->red_num->setText("7");
    ui->gradePeople1->setFontPointSize(qreal(14));
    ui->gradePeople1->setTextColor(QColor(255,255,255));
    ui->gradePeople1->setText("4");
}

void gameInterface:: DialogCancelSlot()
{
    dialog->close();
}
void gameInterface::dialog2OKSlot()
{
    action=0;
    dialog2->close();
    ui->black_have->setFontPointSize(qreal(24));
    ui->black_have->setTextColor(QColor(255,255,255));
    ui->black_have->setText("1");
    ui->red_have->setFontPointSize(qreal(24));
    ui->red_have->setTextColor(QColor(255,255,255));
    ui->red_have->setText("1");
    ui->green_have->setFontPointSize(qreal(24));
    ui->green_have->setTextColor(QColor(255,255,255));
    ui->green_have->setText("1");
    ui->black_num->setFontPointSize(qreal(14));
    ui->black_num->setTextColor(QColor(255,255,255));
    ui->black_num->setText("4");
    ui->green_num->setFontPointSize(qreal(14));
    ui->green_num->setTextColor(QColor(255,255,255));
    ui->green_num->setText("4");
    ui->red_num->setFontPointSize(qreal(14));
    ui->red_num->setTextColor(QColor(255,255,255));
    ui->red_num->setText("6");
}

void gameInterface::on_toolButton_clicked()
{
    //"我要拿币"
    dialog2->show();
    dialog2->setWindowFlags(dialog2->windowFlags() | Qt::WindowStaysOnTopHint);
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
    color=1;
    dialog->exec();
    dialog->showImageChanged(color);
}

void gameInterface::on_card1_2_clicked(bool checked)
{
    //卡2的点击回馈
    dialog->show();
    dialog->showImageChanged(color);
}

void gameInterface::on_card1_3_clicked(bool checked)
{
    //卡3的点击回馈
    dialog->show();
}


void gameInterface::on_card1_4_clicked()
{
    //卡4的点击回馈
    dialog->show();
}

void gameInterface::on_card2_1_clicked(bool checked)
{
    //卡5的点击回馈
    color=2;
    dialog->show();
    dialog->showImageChanged(color);
    ui->card2_1->setStyleSheet("border-image:url(:/images/card/yellow-middle/5.png)");
}

void gameInterface::on_card2_2_clicked(bool checked)
{
    //卡6的点击回馈
    dialog->show();
}

void gameInterface::on_card2_3_clicked(bool checked)
{
    //卡7的点击回馈
    dialog->show();
}


void gameInterface::on_card2_4_clicked(bool checked)
{
    //卡8的点击回馈
    dialog->show();
}

void gameInterface::on_card3_1_clicked(bool checked)
{
    //卡9的点击回馈
    color=3;
    dialog->show();
    ui->card3_1->setStyleSheet("border-image:url(:/images/card/green-low/5.png)");
}

void gameInterface::on_card3_2_clicked(bool checked)
{
    //卡10的点击回馈
    dialog->show();
}

void gameInterface::on_card3_3_clicked(bool checked)
{
    //卡11的点击回馈
    dialog->show();
}

void gameInterface::on_card3_4_clicked(bool checked)
{
    //卡12的点击回馈
    dialog->show();
}


void gameInterface::on_selectBlack_clicked()
{
    //点击黑币
    dialog2->showBlack();
}

void gameInterface::on_selectRed_clicked()
{
    //点击红币
    dialog2->showRed();
}



void gameInterface::on_selectGreen_clicked()
{
    //点击绿币
    dialog2->showGreen();
}


void gameInterface::on_white_have_textChanged()
{

}

void gameInterface::on_green_have_textChanged()
{

}

void gameInterface::on_red_have_textChanged()
{

}

void gameInterface::on_black_have_textChanged()
{

}


void gameInterface::on_re_clicked()
{

}
