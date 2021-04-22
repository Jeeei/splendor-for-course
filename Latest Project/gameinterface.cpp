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
    dialog2 = new Dialog2(this);//拿币窗口

    //购买卡片的窗口信号连接
    connect(dialog, SIGNAL(DialogPurchase()), SLOT(DialogPurchaseSlot()));// 把子窗口的信号连接到父窗口
    connect(dialog,SIGNAL(DialogCancel()),SLOT(DialogCancelSlot()));
    //拿宝石的窗口信号连接
    connect(dialog2,SIGNAL(dialog2OK()),SLOT(dialog2OKSlot()));
    connect(dialog2,&Dialog2::dialog2close,this,&gameInterface::dialog2CancelSlot);//这也是连接信号的写法
    //后端Table的初始化
    table = new Table;
    table->Start();//做相应的初始化
    textInit();//显示信息也初始化

}

gameInterface::~gameInterface()
{
    delete ui;
    delete table;
}

void gameInterface::DialogPurchaseSlot()
{
    // 父窗口用于接收子窗口信号的slot
    table->AlterMani(None);
    dialog->close();
    //ui->card3_1->setStyleSheet(table->CardAddress(2,0)); //测试代码
    ui->card1_1->setStyleSheet("border-image:url(:/images/card/blue-high/5.png)");
    QString have_string="0";

    textChanged();
}

void gameInterface:: DialogCancelSlot()
{
    table->AlterMani(None);
    dialog->close();
}
void gameInterface::dialog2OKSlot()
{
    table->AlterMani(None);
    table->TakeMani();

    dialog2->close();//关闭窗口
    textChanged();//重新显示信息
}

void gameInterface::dialog2CancelSlot()
{
    table->AlterMani(None);
    table->ClearTakenDiamond();//重置宝石
}

void gameInterface::on_toolButton_clicked()
{
    //"我要拿币"
    table->AlterMani(Take);
    dialog2->OpenStatus();
    dialog2->show();
    dialog2->setWindowFlags(dialog2->windowFlags() | Qt::WindowStaysOnTopHint);
}
void gameInterface::textChanged()
{
    //显示玩家拥有宝石
    on_white_have_textChanged();
    on_blue_have_textChanged();
    on_green_have_textChanged();
    on_red_have_textChanged();
    on_black_have_textChanged();
    on_gold_have_textChanged();
    //显示场上宝石
    on_red_num_textChanged();
    on_blue_num_textChanged();
    on_green_num_textChanged();
    on_white_num_textChanged();
    on_black_num_textChanged();
    on_gold_num_textChanged();
    //两个角色要切换显示
    ui->gradePeople1->setText((QString)table->ShowRep());
}
void gameInterface::textInit()
{
    //显示信息设置初始化
    //场上宝石数量信息
    ui->gold_num->setFontPointSize(qreal(14));
    ui->gold_num->setTextColor(QColor(255,255,255));
    ui->black_num->setFontPointSize(qreal(14));
    ui->black_num->setTextColor(QColor(255,255,255));
    ui->red_num->setFontPointSize(qreal(14));
    ui->red_num->setTextColor(QColor(255,255,255));
    ui->green_num->setFontPointSize(qreal(14));
    ui->green_num->setTextColor(QColor(255,255,255));
    ui->blue_num->setFontPointSize(qreal(14));
    ui->blue_num->setTextColor(QColor(255,255,255));
    ui->white_num->setFontPointSize(qreal(14));
    ui->white_num->setTextColor(QColor(255,255,255));
    //玩家声望信息
    ui->gradePeople1->setFontPointSize(qreal(14));
    ui->gradePeople1->setTextColor(QColor(255,255,255));
    //玩家拥有宝石数量信息
    ui->red_have->setFontPointSize(qreal(24));
    ui->red_have->setTextColor(QColor(255,255,255));
    ui->green_have->setFontPointSize(qreal(24));
    ui->green_have->setTextColor(QColor(255,255,255));
    ui->black_have->setFontPointSize(qreal(24));
    ui->black_have->setTextColor(QColor(255,255,255));
    ui->blue_nave->setFontPointSize(qreal(24));
    ui->blue_nave->setTextColor(QColor(255,255,255));
    ui->white_have->setFontPointSize(qreal(24));
    ui->white_have->setTextColor(QColor(255,255,255));
    ui->gold_have->setFontPointSize(qreal(24));
    ui->gold_have->setTextColor(QColor(255,255,255));
}
void gameInterface::on_gold_num_textChanged()
{
    //金币数目函数
    ui->gold_num->setText((QString)table->ShowDiamonds(Gold));
}
void gameInterface::on_black_num_textChanged()
{
    //黑币数目函数
    ui->black_num->setText((QString)table->ShowDiamonds(Black));
}
void gameInterface::on_red_num_textChanged()
{
    //红币数目函数
    ui->red_num->setText((QString)table->ShowDiamonds(Red));
}
void gameInterface::on_green_num_textChanged()
{
    //绿币数目函数
    ui->green_num->setText((QString)table->ShowDiamonds(Green));
}
void gameInterface::on_blue_num_textChanged()
{
    //蓝币数目函数
    ui->blue_num->setText((QString)table->ShowDiamonds(Blue));
}
void gameInterface::on_white_num_textChanged()
{
    //白币数目函数
    ui->white_num->setText((QString)table->ShowDiamonds(White));
}

void gameInterface::on_card1_1_clicked()
{
    //background-color: rgba(255, 255, 224, 10%)；//半透明的样式表代码
    //卡1的点击回馈
    color=1;
    dialog->show();
    dialog->showImageChanged();
}

void gameInterface::on_card1_2_clicked(bool checked)
{
    //卡2的点击回馈
    dialog->show();
    dialog->showImageChanged();
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
    dialog->showImageChanged();
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


void gameInterface::AnyDiamondClicked(enum color co)
{
    if(dialog2->getStatus())//如果买宝石窗口开启
    {
        switch(table->CanTake(co))
        {
        case -1:
            //场上已经没有该宝石
            break;
        case -2:
            //宝石满10个
            break;
        case -3:
            //加上已拿宝石满10个
            break;
        case -4:
            //拿超过了三个
            break;
        case -5:
            //场上该颜色宝石少于4个，不能拿两个
            break;
        case -6:
            //拿了两个同颜色的
            break;
        case 1:
             //符合规则
             dialog2->selectDiamond(table->ShowTakenDiamond(),co);
             switch (co)
             {
             case Black:
                 dialog2->showBlack();
                 break;
             case Red:
                 dialog2->showRed();
                 break;
             case Blue:
                 dialog2->showBlue();
                 break;
             case Green:
                 dialog2->showGreen();
                 break;
             case White:
                 dialog2->showWhite();
                 break;
             default:
                 break;
             }
             break;
        default:
             break;
        }
    }
}

void gameInterface::on_selectBlack_clicked()
{
    //点击黑币
    AnyDiamondClicked(Black);
}
void gameInterface::on_selectRed_clicked()
{
    //点击红币
    AnyDiamondClicked(Red);
}
void gameInterface::on_selectGreen_clicked()
{
    //点击绿币
    AnyDiamondClicked(Green);
}
void gameInterface::on_selectBlue_clicked()
{
    //点击蓝币
    AnyDiamondClicked(Blue);
}
void gameInterface::on_selectWhite_clicked()
{
    //点击白币
    AnyDiamondClicked(White);
}



void gameInterface::on_white_have_textChanged()
{
    ui->white_have->setText((QString)table->ShowPlayerDiamonds(White));
}
void gameInterface::on_blue_have_textChanged()
{
    ui->blue_nave->setText((QString)table->ShowPlayerDiamonds(Blue));
}
void gameInterface::on_green_have_textChanged()
{
    ui->green_have->setText((QString)table->ShowPlayerDiamonds(Green));
}
void gameInterface::on_red_have_textChanged()
{
    ui->red_have->setText((QString)table->ShowPlayerDiamonds(Red));
}
void gameInterface::on_black_have_textChanged()
{
    ui->black_have->setText((QString)table->ShowPlayerDiamonds(Black));
}
void gameInterface::on_gold_have_textChanged()
{
    ui->gold_have->setText((QString)table->ShowPlayerDiamonds(Gold));
}


void gameInterface::on_toolButton_triggered(QAction *arg1)
{

}

