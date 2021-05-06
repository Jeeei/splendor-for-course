#include "gameinterface.h"
#include "ui_gameinterface.h"
#include <iostream>
#include <QtGlobal>
#include <QDebug>

using namespace std;

gameInterface::gameInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameInterface)
{
    ui->setupUi(this);
    setWindowTitle("Splendor");
    //qDebug()<<"gameinterface created."<<endl;

    PickCard = new pickCard(this);//买卡窗口
    PickCoin = new pickCoin(this);//拿宝石窗口
    opp1 = new opponent_have(this);//显示对手信息窗口
    end1 = nullptr;//结算窗口
    end2 = nullptr;//并列结算窗口
    kcard = new kouCard(this);//扣卡窗口
    rclick = new RightClick(this);


    //背景音乐
    bsound = new QSound(":/music/BackgroundMusic.wav",this);
    bsound->play();
    bsound->setLoops(-1);//循环次数，-1代表一致循环


    //购买卡片的窗口信号连接
    connect(PickCard, SIGNAL(Purchase()), SLOT(PickCard_PurchaseSlot()));
    connect(PickCard, SIGNAL(PickCardCancel()), SLOT(PickCard_CancelSlot()));

    //拿宝石的窗口信号连接
    connect(PickCoin,SIGNAL(Pick_OK()),SLOT(PICK_OKSlot()));
    connect(PickCoin,SIGNAL(Pick_Close()),SLOT(PICK_CancelSlot()));
    connect(PickCoin,SIGNAL(Pick_UnTake(color)),SLOT(PICK_UnTake(color)));

    //扣卡窗口信号连接
    connect(kcard,SIGNAL(Retain()),SLOT(RetainSlot()));

    //回主界面信号连接
    connect(rclick,&RightClick::resign,this,&gameInterface::gameInterfaceResignSlot);

    //后端Table的初始化
    table = new Table;
    table -> Start();//做相应的初始化
    textInit();//显示信息也初始化
    textChanged();
}

gameInterface::~gameInterface()
{
    qDebug()<<"gameinterface deleted."<<endl;
    delete ui;
    delete table;
    delete PickCard;
    delete PickCoin;
    delete opp1;
    delete rclick;
    delete kcard;
    bsound->stop();
    delete bsound;
    if(end1 != nullptr)
    {
        delete end1;
        end1 = nullptr;
    }
    if(end2 != nullptr)
    {
        delete end2;
        end2 = nullptr;
    }
}

void gameInterface::PickCard_PurchaseSlot()
{
    // 父窗口用于接收子窗口信号的slot
    if(table->CanBuy())//买得起当前卡片
    {
        table->BuyMani();
        Next();
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
    Next();
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

void gameInterface::RetainSlot()
{
    int canRetain = table->CanRetain();
    if(canRetain >= 0)
    {
        table->RetainMani(canRetain);
        Next();
    }
}

void gameInterface::gameInterfaceResignSlot()
{
    qDebug()<<"gameinterface resign.";
    close();
    emit gameInterfaceResign();
}

void gameInterface::textChanged()
{
    //显示玩家信息
    people1_textChanged();
    people2_textChanged();
    //显示场上宝石
    on_red_num_textChanged();
    on_blue_num_textChanged();
    on_green_num_textChanged();
    on_white_num_textChanged();
    on_black_num_textChanged();
    on_gold_num_textChanged();
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
    //可买卡片高亮
    ui->highlight1_1->setVisible(table->AvailCardInfo(2,0));
    ui->highlight1_2->setVisible(table->AvailCardInfo(2,1));
    ui->highlight1_3->setVisible(table->AvailCardInfo(2,2));
    ui->highlight1_4->setVisible(table->AvailCardInfo(2,3));
    ui->highlight2_1->setVisible(table->AvailCardInfo(1,0));
    ui->highlight2_2->setVisible(table->AvailCardInfo(1,1));
    ui->highlight2_3->setVisible(table->AvailCardInfo(1,2));
    ui->highlight2_4->setVisible(table->AvailCardInfo(1,3));
    ui->highlight3_1->setVisible(table->AvailCardInfo(0,0));
    ui->highlight3_2->setVisible(table->AvailCardInfo(0,1));
    ui->highlight3_3->setVisible(table->AvailCardInfo(0,2));
    ui->highlight3_4->setVisible(table->AvailCardInfo(0,3));
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
    ui->gradePeople1->setFontPointSize(qreal(20));
    ui->gradePeople1->setTextColor(QColor(255,255,255));
    ui->gradePeople2->setFontPointSize(qreal(20));
    ui->gradePeople2->setTextColor(QColor(255,255,255));
    //玩家头像切换
    ui->oppo_turn->setVisible(false);
    ui->oppo_turn_2->setVisible(false);
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
    //玩家拥有卡片红利信息
    ui->red_card->setFontPointSize(qreal(16));
    ui->red_card->setAlignment( Qt::AlignHCenter );
    ui->green_card->setFontPointSize(qreal(16));
    ui->green_card->setAlignment( Qt::AlignHCenter );
    ui->blue_card->setFontPointSize(qreal(16));
    ui->blue_card->setAlignment( Qt::AlignHCenter );
    ui->white_card->setFontPointSize(qreal(16));
    ui->white_card->setAlignment( Qt::AlignHCenter );
    ui->black_card->setFontPointSize(qreal(16));
    ui->black_card->setAlignment( Qt::AlignHCenter );
}

void gameInterface::Next()
{
    if(PickCard->isVisible())
        PickCard->hide();
    if(PickCoin->isVisible())
        PickCoin->close();
    if(kcard->isVisible())
        kcard->close();
    if(table->Next())//玩家头像信息切换
    {
        //轮到对手时
        ui->oppo_turn->setVisible(true);
        ui->oppo_turn_2->setVisible(true);
    }
    else
    {
        //轮到自己
        ui->oppo_turn->setVisible(false);
        ui->oppo_turn_2->setVisible(false);
    }
    if(table->GetStatus() == Ending)//游戏结束
    {
        Player* no1 = nullptr,*no2 = nullptr;
        int num1 = 0,num2 = 0;
        table->GetCount(&no1,&no2,&num1,&num2);
        if(num1 == 1)//一个第一
        {
            end1 = new END1(this);
            end1->showNo1("border:2px solid rgb(247, 228, 16);border-radius:45px;"+no1->GetAddr());
            end1->showNo2("border:2px solid rgb(247, 228, 16);border-radius:45px;"+no2->GetAddr());
            end1->show();
        }
        else //并列第一
        {
            end2 = new END2(this);
            end2->showNo1("border:2px solid rgb(247, 228, 16);border-radius:45px;"+no1->GetAddr());
            end2->showNo2("border:2px solid rgb(247, 228, 16);border-radius:45px;"+(no1 + num1 - 1)->GetAddr());
            end2->show();
        }
    }
    textChanged();
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
    if(table->CanBuy())//买得起显示买卡窗口
    {
        PickCard->show();
        PickCard->showCard(table->CardImg(2 - level,num));
    }
    else//买不起显示扣卡窗口
    {
        if(table->CanRetain() >= 0&&table->CardImg(2 - level,num) != "background-color:rgba(255,255,255,80);bordor-radius:55px;")//卡片不为空
        {
            kcard->showCard(table->CardImg(2 - level,num));
            if(table->CanRetain() == 1)//可以拿金币
                kcard->showGold();
            kcard->show();
        }
    }
}

void gameInterface::people1_textChanged()
{
    //显示声望
    ui->gradePeople1->setText(QString::number(table->ShowRep()));
    //显示当前玩家拥有的宝石数
    ui->red_have->setText(QString::number(table->ShowPlayerDiamonds(Red)));
    ui->green_have->setText(QString::number(table->ShowPlayerDiamonds(Green)));
    ui->blue_have->setText(QString::number(table->ShowPlayerDiamonds(Blue)));
    ui->white_have->setText(QString::number(table->ShowPlayerDiamonds(White)));
    ui->black_have->setText(QString::number(table->ShowPlayerDiamonds(Black)));
    ui->gold_have->setText(QString::number(table->ShowPlayerDiamonds(Gold)));
    //显示玩家拥有卡片
    ui->red_card->setText(QString::number(table->ShowPlayerBonus(Red)));
    ui->green_card->setText(QString::number(table->ShowPlayerBonus(Green)));
    ui->blue_card->setText(QString::number(table->ShowPlayerBonus(Blue)));
    ui->white_card->setText(QString::number(table->ShowPlayerBonus(White)));
    ui->black_card->setText(QString::number(table->ShowPlayerBonus(Black)));
    //显示玩家所扣的卡
    ui->reserved1->setStyleSheet("border-radius:18px;"+table->ReserveImg(0));
    ui->reserved2->setStyleSheet("border-radius:18px;"+table->ReserveImg(1));
    ui->reserved3->setStyleSheet("border-radius:18px;"+table->ReserveImg(2));
}

void gameInterface::people2_textChanged()
{
    //显示声望
    ui->gradePeople2->setText(QString::number(table->ShowRep(1)));
    //显示玩家2拥有的宝石数
    opp1->showRed(table->ShowPlayerDiamonds(Red,1));
    opp1->showGreen(table->ShowPlayerDiamonds(Green,1));
    opp1->showBlue(table->ShowPlayerDiamonds(Blue,1));
    opp1->showWhite(table->ShowPlayerDiamonds(White,1));
    opp1->showBlack(table->ShowPlayerDiamonds(Black,1));
    opp1->showGold(table->ShowPlayerDiamonds(Gold,1));
    //显示玩家2拥有的卡片红利
    opp1->showRedCard(table->ShowPlayerBonus(Red,1));
    opp1->showGreenCard(table->ShowPlayerBonus(Green,1));
    opp1->showBlueCard(table->ShowPlayerBonus(Blue,1));
    opp1->showWhiteCard(table->ShowPlayerBonus(White,1));
    opp1->showBlackCard(table->ShowPlayerBonus(Black,1));

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

void gameInterface::on_changeMan_clicked()
{
    Next();
}

void gameInterface::on_oppo1_clicked()
{
    opp1->show();
}

void gameInterface::on_reserved1_clicked()
{
    table->SetCurrCard(0,4);
    if(table->CanBuy() && table->ReserveImg(0) != "background-color: rgba(255, 255, 255, 80);border-radius:18px;border:2px solid rgb(176, 176, 87);")
    {
        PickCard->show();
        PickCard->showCard(table->ReserveImg(0));
    }

}

void gameInterface::on_reserved2_clicked()
{
    table->SetCurrCard(1,4);
    if(table->CanBuy() && table->ReserveImg(1) != "background-color: rgba(255, 255, 255, 80);border-radius:18px;border:2px solid rgb(176, 176, 87);")
    {
        PickCard->show();
        PickCard->showCard(table->ReserveImg(1));
    }
}

void gameInterface::on_reserved3_clicked()
{
    table->SetCurrCard(2,4);
    if(table->CanBuy() && table->ReserveImg(2) != "background-color: rgba(255, 255, 255, 80);border-radius:18px;border:2px solid rgb(176, 176, 87);")
    {
        PickCard->show();
        PickCard->showCard(table->ReserveImg(2));
    }
}

void gameInterface::on_re_clicked()
{
    rclick->show();
}
