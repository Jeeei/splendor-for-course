#include "gameinterface.h"
#include "ui_gameinterface.h"
#include "mainsurface.h"
#include <iostream>
#include <QtGlobal>
#include <QSound>
#include <QTableWidget>
using namespace std;

gameInterface::gameInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameInterface)
{
    ui->setupUi(this);

    //背景音乐
    QSound *bsound=new QSound(":/music/背景音乐.wav",this);
    bsound->play();
    bsound->setLoops(-1);//循环次数，-1代表一致循环

    PickCoin=new pickCoin(this);
    PickCoin->setGeometry(1060,680,321,101);
    PickCoin->hide();

    PickCard=new pickCard(this);
    PickCard->setGeometry(600,160,271,351);
    PickCard->hide();

    opp1=new opponent_have(this);
    opp1->setGeometry(0,40,183,151);
    opp1->hide();

    //右弹菜单
    rclick=new RightClick(this);
    rclick->setGeometry(850,30,512,691);
    rclick->hide();

    //轮到自己时，将对手高亮隐藏
    ui->oppo_turn->setVisible(false);//轮到对手时false改成true就行
    ui->oppo_turn_2->setVisible(false);

    //高亮
    ui->highlight1_1->setVisible(false);
    ui->highlight1_2->setVisible(false);
    ui->highlight1_3->setVisible(false);
    ui->highlight1_4->setVisible(false);
    ui->highlight2_1->setVisible(false);
    ui->highlight2_2->setVisible(false);
    ui->highlight2_3->setVisible(false);
    ui->highlight2_4->setVisible(false);
    ui->highlight3_1->setVisible(false);
    ui->highlight3_2->setVisible(false);
    ui->highlight3_3->setVisible(false);
    ui->highlight3_4->setVisible(false);
}

gameInterface::~gameInterface()
{
    delete ui;
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
    //卡1的点击回馈
    PickCard->show();
    PickCard->showCard();
}

void gameInterface::on_card1_2_clicked()
{
    //卡2的点击回馈
    ui->oppo_turn_2->setVisible(true);
    ui->oppo_turn->setVisible(true);//轮到对手时false改成true就行
}

void gameInterface::on_card1_3_clicked()
{
    //卡3的点击回馈
}


void gameInterface::on_card1_4_clicked()
{
    //卡4的点击回馈
}

void gameInterface::on_card2_1_clicked()
{
    //卡5的点击回馈
}

void gameInterface::on_card2_2_clicked()
{
    //卡6的点击回馈
}

void gameInterface::on_card2_3_clicked()
{
    //卡7的点击回馈
}


void gameInterface::on_card2_4_clicked()
{
    //卡8的点击回馈
}

void gameInterface::on_card3_1_clicked()
{
    //卡9的点击回馈
}

void gameInterface::on_card3_2_clicked()
{
    //卡10的点击回馈
}

void gameInterface::on_card3_3_clicked()
{
    //卡11的点击回馈
}

void gameInterface::on_card3_4_clicked()
{
    //卡12的点击回馈
}


void gameInterface::on_selectBlack_clicked()
{
    //点击黑币
    PickCoin->show();
    PickCoin->showCoin1();
}

void gameInterface::on_selectRed_clicked()
{
    //点击红币

}



void gameInterface::on_selectGreen_clicked()
{
    //点击绿币

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
    rclick->show();
    if((rclick->showMainsurface())==true)
    {
        delete this;
    }
}

void gameInterface::on_oppo1_clicked()
{
    opp1->show();
}
