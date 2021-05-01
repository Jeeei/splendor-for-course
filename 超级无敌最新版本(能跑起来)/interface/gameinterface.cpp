#include "gameinterface.h"
#include "ui_gameinterface.h"
#include <iostream>
#include <QtGlobal>
#include <QDebug>
#include <QSound>
using namespace std;

gameInterface::gameInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameInterface)
{
    ui->setupUi(this);
    setWindowTitle("Splendor");
    //qDebug()<<"gameinterface created."<<endl;
    //ui->card1_1->setStyleSheet("border-image:url(:/images/card/blue-high/1.png)");
    //ui->card2_1->setStyleSheet("border-image:url(:/images/card/yellow_middle/1.png)");
    //ui->card2_1->setStyleSheet("border-image:url(:/images/card/green_low/1.png)");

    PickCard = new pickCard(this);//买卡窗口
    PickCoin = new pickCoin(this);//拿宝石窗口

    //背景音乐
    QSound *bsound = new QSound(":/music/BackgroundMusic.wav",this);
    bsound->play();
    bsound->setLoops(-1);//循环次数，-1代表一致循环


    //购买卡片的窗口信号连接
    connect(PickCard, SIGNAL(Purchase()), SLOT(PickCard_PurchaseSlot()));
    connect(PickCard, SIGNAL(PickCardCancel()), SLOT(PickCard_CancelSlot()));

    //拿宝石的窗口信号连接
    connect(PickCoin,SIGNAL(Pick_OK()),SLOT(PICK_OKSlot()));
    connect(PickCoin,SIGNAL(Pick_Close()),SLOT(PICK_CancelSlot()));
    connect(PickCoin,SIGNAL(Pick_UnTake(color)),SLOT(PICK_UnTake(color)));

    //后端Table的初始化
    table = new Table;
    table->Start();//做相应的初始化
    textInit();//显示信息也初始化
    textChanged();
}

gameInterface::~gameInterface()
{
    //qDebug()<<"gameinterface deleted."<<endl;
    delete ui;
    delete table;
    delete PickCard;
    delete PickCoin;
}

void gameInterface::PickCard_PurchaseSlot()
{
    // 父窗口用于接收子窗口信号的slot
    if(table->CanBuy())//买得起当前卡片
    {
        table->BuyMani();
        table->SetCurrCard(-1,-1);
        table->Next();
    }//买不起啊干
    table->AlterMani(None);
    textChanged();//重新显示信息
}

void gameInterface:: PickCard_CancelSlot()
{
    table->AlterMani(None);
    textChanged();//重新显示信息
}

void gameInterface::PICK_OKSlot()
{
    table->TakeMani();
    table->AlterMani(None);
//    textChanged();//重新显示信息
    table->Next();
    textChanged();//重新显示信息

}

void gameInterface::PICK_CancelSlot()
{
    table->AlterMani(None);
    table->ClearTakenDiamond();//重置宝石
    textChanged();//重新显示信息
}

void gameInterface::PICK_UnTake(enum color co)
{
    table->UnTake(co);
    textChanged();//重新显示信息
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
    ui->gradePeople1->setText(QString::number(table->ShowRep()));
    ui->gradePeople2->setText(QString::number(table->ShowRep(1)));
    //显示卡片信息
    ui->card1_1->setStyleSheet(table->CardImg(2,0));
    ui->card1_2->setStyleSheet(table->CardImg(2,1));
    ui->card1_3->setStyleSheet(table->CardImg(2,2));
    ui->card1_4->setStyleSheet(table->CardImg(2,3));
    ui->card2_1->setStyleSheet(table->CardImg(1,0));
    ui->card2_2->setStyleSheet(table->CardImg(1,1));
    ui->card2_3->setStyleSheet(table->CardImg(1,2));
    ui->card2_4->setStyleSheet(table->CardImg(1,3));
    ui->card3_1->setStyleSheet(table->CardImg(0,0));
    ui->card3_2->setStyleSheet(table->CardImg(0,1));
    ui->card3_3->setStyleSheet(table->CardImg(0,2));
    ui->card3_4->setStyleSheet(table->CardImg(0,3));
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
    ui->gradePeople1->setFontPointSize(qreal(16));
    ui->gradePeople1->setTextColor(QColor(255,255,255));
    ui->gradePeople2->setFontPointSize(qreal(16));
    ui->gradePeople2->setTextColor(QColor(255,255,255));
    //玩家拥有宝石数量信息
    ui->red_have->setFontPointSize(qreal(24));
    ui->red_have->setTextColor(QColor(255,255,255));
    ui->green_have->setFontPointSize(qreal(24));
    ui->green_have->setTextColor(QColor(255,255,255));
    ui->black_have->setFontPointSize(qreal(24));
    ui->black_have->setTextColor(QColor(255,255,255));
    ui->blue_have->setFontPointSize(qreal(24));
    ui->blue_have->setTextColor(QColor(255,255,255));
    ui->white_have->setFontPointSize(qreal(24));
    ui->white_have->setTextColor(QColor(255,255,255));
    ui->gold_have->setFontPointSize(qreal(24));
    ui->gold_have->setTextColor(QColor(255,255,255));
}
void gameInterface::on_gold_num_textChanged()
{
    //金币数目函数
    ui->gold_num->setText(QString::number(table->ShowDiamonds((int)Gold)));
}
void gameInterface::on_black_num_textChanged()
{
    //黑币数目函数
    ui->black_num->setText(QString::number(table->ShowDiamonds((int)Black)));
}
void gameInterface::on_red_num_textChanged()
{
    //红币数目函数
    ui->red_num->setText(QString::number(table->ShowDiamonds((int)Red)));
}
void gameInterface::on_green_num_textChanged()
{
    //绿币数目函数
    ui->green_num->setText(QString::number(table->ShowDiamonds((int)Green)));
}
void gameInterface::on_blue_num_textChanged()
{
    //蓝币数目函数
    ui->blue_num->setText(QString::number(table->ShowDiamonds((int)Blue)));
}
void gameInterface::on_white_num_textChanged()
{
    //白币数目函数
    ui->white_num->setText(QString::number(table->ShowDiamonds((int)White)));
}

void gameInterface::AnyCardClicked(int level, int num)
{
    table->SetCurrCard(2 - level,num);
    PickCard->show();
    PickCard->showCard(table->CardImg(2 - level,num));
}

void gameInterface::on_card1_1_clicked()
{
    //background-color: rgba(255, 255, 224, 10%)；//半透明的样式表代码
    //卡1的点击回馈
    AnyCardClicked(0,0);
}

void gameInterface::on_card1_2_clicked()
{
    //卡2的点击回馈
    AnyCardClicked(0,1);
}

void gameInterface::on_card1_3_clicked()
{
    //卡3的点击回馈
    AnyCardClicked(0,2);
}

void gameInterface::on_card1_4_clicked()
{
    //卡4的点击回馈
    AnyCardClicked(0,3);
}

void gameInterface::on_card2_1_clicked()
{
    //卡5的点击回馈
    AnyCardClicked(1,0);
}

void gameInterface::on_card2_2_clicked()
{
    //卡6的点击回馈
    AnyCardClicked(1,1);
}

void gameInterface::on_card2_3_clicked()
{
    //卡7的点击回馈
    AnyCardClicked(1,2);
}

void gameInterface::on_card2_4_clicked()
{
    //卡8的点击回馈
    AnyCardClicked(1,3);
}

void gameInterface::on_card3_1_clicked()
{
    //卡9的点击回馈
    AnyCardClicked(2,0);
}

void gameInterface::on_card3_2_clicked()
{
    //卡10的点击回馈
    AnyCardClicked(2,1);
}

void gameInterface::on_card3_3_clicked()
{
    //卡11的点击回馈
    AnyCardClicked(2,2);
}

void gameInterface::on_card3_4_clicked()
{
    //卡12的点击回馈
    AnyCardClicked(2,3);
}


void gameInterface::AnyDiamondClicked(enum color co)
{
    //qDebug() <<"table return: "<< a << endl;
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
        //拿了两个以上同颜色
        break;
    case -7:
        //拿了两个同颜色和一个其他颜色
        break;
    case 1:
        //符合规则
        table->AlterMani(Take);
        PickCoin->show();
        PickCoin->selectDiamond(co);//包含显示函数
        break;
    default:
        break;
    }
    //qDebug()<<"text changed!";
    textChanged();
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
    ui->white_have->setText(QString::number(table->ShowPlayerDiamonds(White)));
    //qDebug()<<(QString::number(table->ShowPlayerDiamonds(White)));
}
void gameInterface::on_blue_have_textChanged()
{
    ui->blue_have->setText(QString::number(table->ShowPlayerDiamonds(Blue)));
}
void gameInterface::on_green_have_textChanged()
{
    ui->green_have->setText(QString::number(table->ShowPlayerDiamonds(Green)));
}
void gameInterface::on_red_have_textChanged()
{
    ui->red_have->setText(QString::number(table->ShowPlayerDiamonds(Red)));
}
void gameInterface::on_black_have_textChanged()
{
    ui->black_have->setText(QString::number(table->ShowPlayerDiamonds(Black)));
}
void gameInterface::on_gold_have_textChanged()
{
    ui->gold_have->setText(QString::number(table->ShowPlayerDiamonds(Gold)));
}


void gameInterface::on_toolButton_triggered(QAction *arg1)
{

}


void gameInterface::on_changeMan_clicked()
{
    table->Next();
    textChanged();
}
