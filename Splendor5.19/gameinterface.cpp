#include "gameinterface.h"
#include "ui_gameinterface.h"
#include <iostream>
#include <QtGlobal>
#include <QDebug>
#include <cstdlib>

using namespace std;

gameInterface::gameInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameInterface)
{
    ui->setupUi(this);
    setWindowTitle("Splendor");
    //qDebug()<<"gameinterface created."<<endl;

    //后端Table
    table = new Table;

    PickCard = new pickCard(this);//买卡窗口
    PickCoin = new pickCoin(this);//拿宝石窗口
    opp1 = new opponent_have(this);//显示对手信息窗口
    end1 = nullptr;//结算窗口
    end2 = nullptr;//并列结算窗口
    kcard = new kouCard(this);//扣卡窗口
    rclick = new RightClick(this);//菜单窗口

    ChooseSurface = new chooseSurface(this);//选择玩家界面
    WContinue = new whetherContinue(this);//继续游戏弹框

    //选择界面信号连接
    connect(ChooseSurface,SIGNAL(Start()),this,SLOT(StartSlot()));
    connect(ChooseSurface,SIGNAL(add()),this,SLOT(AddSlot()));
    connect(ChooseSurface,SIGNAL(subtract()),this,SLOT(SubtractSlot()));
    connect(ChooseSurface,SIGNAL(image1()),this,SLOT(Img1Change()));
    connect(ChooseSurface,SIGNAL(image2()),this,SLOT(Img2Change()));
    connect(ChooseSurface,SIGNAL(image3()),this,SLOT(Img3Change()));
    connect(ChooseSurface,SIGNAL(image4()),this,SLOT(Img4Change()));

    connect(ChooseSurface,SIGNAL(name1(QString)),this,SLOT(name1Slot(QString)));
    connect(ChooseSurface,SIGNAL(name2(QString)),this,SLOT(name2Slot(QString)));

    //继续游戏信号连接
    connect(WContinue,&whetherContinue::gameContinue,this,&gameInterface::gameContinueSlot);
    connect(WContinue,&whetherContinue::gameNew,this,&gameInterface::gameNewSlot);

    //背景音乐
    bsound = new QSound(":/music/BackgroundMusic.wav",this);
    ui->musicC->setStyleSheet("border:none;border-image: url(:/images/continueMusic.png);border-radius:30px");

    for(int i = 0;i < 3;i++)//贵族选择窗口
    {
        rpeople[i] = new richPeople(this);
        //选择贵族窗口信号连接
        connect(rpeople[i],SIGNAL(richScoreSignal(int)),this,SLOT(ChooseNobleSlot(int)));
    }

    //购买卡片的窗口信号连接
    connect(PickCard, SIGNAL(Purchase()), SLOT(PickCard_PurchaseSlot()));
    connect(PickCard, SIGNAL(PickCardCancel()), SLOT(PickCard_CancelSlot()));

    //拿宝石的窗口信号连接
    connect(PickCoin,SIGNAL(Pick_OK()),SLOT(PICK_OKSlot()));
    connect(PickCoin,SIGNAL(Pick_Close()),SLOT(PICK_CancelSlot()));
    connect(PickCoin,SIGNAL(Pick_UnTake(color)),SLOT(PICK_UnTake(color)));

    //扣卡窗口信号连接
    connect(kcard,SIGNAL(Retain()),SLOT(RetainSlot()));

    //菜单信号连接
    connect(rclick,&RightClick::resign,this,&gameInterface::gameInterfaceResignSlot);
    connect(rclick,&RightClick::save,this,&gameInterface::SaveSlot);
    connect(rclick,&RightClick::tryAgain,this,&gameInterface::TryAgainSlot);

    if(table->IfSaved())
    {
        WContinue->setGeometry(275,255,850,290);
        WContinue->show();
    }
    else
    {
        ChooseSurface->show();
    }
}

gameInterface::~gameInterface()
{
    qDebug()<<"gameinterface deleted."<<endl;
    if(ui != nullptr)
    {
        delete ui;
        ui = nullptr;
    }
    if(table != nullptr)
    {
        delete table;
        table = nullptr;
    }
    if(bsound != nullptr)
    {
        bsound->stop();
        delete bsound;
        bsound = nullptr;
    }
}

void gameInterface::PickCard_PurchaseSlot()
{
    // 父窗口用于接收子窗口信号的slot
    if(table->CanBuy())//买得起当前卡片
    {
        int level,num;
        table->GetCurrCard(&level,&num);
        CardUsed(2 - level,num);
    }//买不起啊干
    textChanged();//重新显示信息
}

void gameInterface:: PickCard_CancelSlot()
{
    if(table->GetMani() != SelectNoble)
        table->AlterMani(None);
    textChanged();//重新显示信息
}

void gameInterface::PICK_OKSlot()
{
    table->TakeMani();
    table->Avail();
    if(table->IfNoble() > 0)
    {
        table->AlterMani(SelectNoble);
        ChooseNoble();
    }
    else
    {
        QTimer::singleShot(1000,this,&gameInterface::Next);
        textChanged();
        this->setEnabled(false);
    }
}

void gameInterface::PICK_CancelSlot()
{
    if(table->GetMani() != SelectNoble)
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
    int re_num;
    int canRetain = table->CanRetain(&re_num);
    if(canRetain >= 0)
    {
        int level,num;
        table->GetCurrCard(&level,&num);
        CardUsed(2 - level,num,re_num);
        table->RetainMani(canRetain);
    }
}

void gameInterface::SaveSlot()
{
    table->Save();
}

void gameInterface::StartSlot()
{
    table->Start();//做相应的初始化
    table->SaveBeginning();//保存开始信息
    bsound->play();
    bsound->setLoops(-1);//循环次数，-1代表一致循环
    textInit();//显示信息也初始化
    this->show();
    textChanged();
}

void gameInterface::AddSlot()
{
    //增加玩家人数按钮
    //暂时不更改玩家人数
}

void gameInterface::SubtractSlot()
{
    //减少玩家人数按钮
    //暂时不更改玩家人数
}

void gameInterface::Img1Change()
{
    //点击第一个玩家头像，更改玩家头像

}

void gameInterface::Img2Change()
{
    //点击第二个玩家头像，更改玩家头像

}

void gameInterface::Img3Change()
{
    //点击第三个玩家头像，更改玩家头像
    //暂时不更改玩家人数

}

void gameInterface::Img4Change()
{
    //点击第四个玩家头像，更改玩家头像
    //暂时不更改玩家人数

}

void gameInterface::EndSlot()
{
    close();
    emit gameInterfaceEnd();
}

void gameInterface::ChooseNobleSlot(int num)
{
    table->NobleCome(num);
    for(int i = 0;i < 3;i++)
        rpeople[i]->close();
    QTimer::singleShot(1000,this,&gameInterface::Next);
    this->setEnabled(false);
    textChanged();
}

void gameInterface::gameInterfaceResignSlot()
{
//    qDebug()<<"gameinterface resign.";
    close();
    emit gameInterfaceResign();
}

void gameInterface::TryAgainSlot()
{
    delete table;
    table = new Table;
    table->TryAgain();
    bsound->play();
    bsound->setLoops(-1);//循环次数，-1代表一致循环
    textInit();//显示信息也初始化
    this->show();
    textChanged();
}

void gameInterface::gameContinueSlot()
{
    table->Load();
    bsound->play();
    bsound->setLoops(-1);//循环次数，-1代表一致循环
    textInit();//显示信息也初始化
    this->show();
    textChanged();
}

void gameInterface::gameNewSlot()
{
    ChooseSurface->show();
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
    ui->card1_1->setStyleSheet("border-radius:15px;"+table->CardImg(2,0));
    ui->card1_2->setStyleSheet("border-radius:15px;"+table->CardImg(2,1));
    ui->card1_3->setStyleSheet("border-radius:15px;"+table->CardImg(2,2));
    ui->card1_4->setStyleSheet("border-radius:15px;"+table->CardImg(2,3));
    ui->card2_1->setStyleSheet("border-radius:15px;"+table->CardImg(1,0));
    ui->card2_2->setStyleSheet("border-radius:15px;"+table->CardImg(1,1));
    ui->card2_3->setStyleSheet("border-radius:15px;"+table->CardImg(1,2));
    ui->card2_4->setStyleSheet("border-radius:15px;"+table->CardImg(1,3));
    ui->card3_1->setStyleSheet("border-radius:15px;"+table->CardImg(0,0));
    ui->card3_2->setStyleSheet("border-radius:15px;"+table->CardImg(0,1));
    ui->card3_3->setStyleSheet("border-radius:15px;"+table->CardImg(0,2));
    ui->card3_4->setStyleSheet("border-radius:15px;"+table->CardImg(0,3));
    //显示贵族卡片信息
    ui->noble1->setStyleSheet("border-radius:18px;"+table->NobleImg(0));
    ui->noble2->setStyleSheet("border-radius:18px;"+table->NobleImg(1));
    ui->noble3->setStyleSheet("border-radius:18px;"+table->NobleImg(2));
    //如果拿了币可买卡片高亮
    ui->yellowLight1_1->setVisible(table->AvailTakenCardInfo(2,0));
    ui->yellowLight1_2->setVisible(table->AvailTakenCardInfo(2,1));
    ui->yellowLight1_3->setVisible(table->AvailTakenCardInfo(2,2));
    ui->yellowLight1_4->setVisible(table->AvailTakenCardInfo(2,3));
    ui->yellowLight2_1->setVisible(table->AvailTakenCardInfo(1,0));
    ui->yellowLight2_2->setVisible(table->AvailTakenCardInfo(1,1));
    ui->yellowLight2_3->setVisible(table->AvailTakenCardInfo(1,2));
    ui->yellowLight2_4->setVisible(table->AvailTakenCardInfo(1,3));
    ui->yellowLight3_1->setVisible(table->AvailTakenCardInfo(0,0));
    ui->yellowLight3_2->setVisible(table->AvailTakenCardInfo(0,1));
    ui->yellowLight3_3->setVisible(table->AvailTakenCardInfo(0,2));
    ui->yellowLight3_4->setVisible(table->AvailTakenCardInfo(0,3));
    ui->yellowLight4_1->setVisible(table->AvailTakenCardInfo(0,4));
    ui->yellowLight4_2->setVisible(table->AvailTakenCardInfo(1,4));
    ui->yellowLight4_3->setVisible(table->AvailTakenCardInfo(2,4));
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
    ui->highlight4_1->setVisible(table->AvailCardInfo(0,4));
    ui->highlight4_2->setVisible(table->AvailCardInfo(1,4));
    ui->highlight4_3->setVisible(table->AvailCardInfo(2,4));
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
    this->setEnabled(true);
    //回合真正结束
    if(table->Next())//玩家头像信息切换
    {
        //轮到对手时
        ui->oppo_turn->setVisible(true);
        ui->oppo_turn_2->setVisible(true);
        ui->name1->setGeometry(0,170,161,41);
        ui->name2->setGeometry(10,755,161,41);
    }
    else
    {
        //轮到自己
        ui->oppo_turn->setVisible(false);
        ui->oppo_turn_2->setVisible(false);
        ui->name2->setGeometry(0,170,161,41);
        ui->name1->setGeometry(10,755,161,41);
    }
    if(table->GetStatus() == Ending)//游戏结束
    {
        Player* no1 = nullptr,*no2 = nullptr;
        int num1 = 0,num2 = 0;
        table->GetCount(&no1,&no2,&num1,&num2);
        if(num1 == 1)//一个第一
        {
            end1 = new END1(this);
            //信号连接
            connect(end1,&END1::end,this,&gameInterface::EndSlot);

            end1->showNo1("border:2px solid rgb(247, 228, 16);border-radius:45px;"+no1->GetAddr());
            end1->showNo2("border:2px solid rgb(247, 228, 16);border-radius:45px;"+no2->GetAddr());
            end1->showScore1(no1->GetRep());
            end1->showScore2(no2->GetRep());
            end1->show();
        }
        else //并列第一
        {
            end2 = new END2(this);
            //信号连接
            connect(end2,&END2::end,this,&gameInterface::EndSlot);

            end2->showNo1("border:2px solid rgb(247, 228, 16);border-radius:45px;"+no1->GetAddr());
            end2->showNo2("border:2px solid rgb(247, 228, 16);border-radius:45px;"+(no1 + num1 - 1)->GetAddr());
            end2->showScore(no1->GetRep());
            end2->show();
        }
    }
    textChanged();
}

void gameInterface::ChooseNoble()
{
    if(PickCard->isVisible())
        PickCard->hide();
    if(PickCoin->isVisible())
        PickCoin->close();
    if(kcard->isVisible())
        kcard->close();
    //检查是否有贵族拜访
    int ifnoble = table->IfNoble();
    if(ifnoble > 0)
    {
        int count = 0;
        switch(ifnoble)//选择贵族啊
        {
        case 3:
            rpeople[0]->setGeometry(230,205,310,390);
            rpeople[1]->setGeometry(590,205,310,390);
            rpeople[2]->setGeometry(950,205,310,390);
            for (int i = 0; i < 3; i++)
            {
                if(table->AvailNobleInfo(i))
                {
                    rpeople[count]->setnum(i);
                    rpeople[count]->showRich(table->NobleImg(i));
                    count++;
                }
                rpeople[i]->show();
            }
            break;
        case 2:
            rpeople[0]->setGeometry(315,205,310,390);
            rpeople[1]->setGeometry(680,205,310,390);
            rpeople[0]->show();
            rpeople[1]->show();

            for (int i = 0; i < 3; i++)
            {
                if(table->AvailNobleInfo(i))
                {
                    rpeople[count]->setnum(i);
                    rpeople[count]->showRich(table->NobleImg(i));
                    count++;
                }
            }
            break;
        case 1:
            rpeople[0]->show();
            rpeople[0]->setGeometry(545,205,310,390);
            for (int i = 0; i < 3; i++)
            {
                if(table->AvailNobleInfo(i))
                {
                    rpeople[count]->setnum(i);
                    rpeople[count]->showRich(table->NobleImg(i));
                    count++;
                }
            }
            break;
        default:
            break;
        }
        table->AlterMani(SelectNoble);
    }
}

void gameInterface::NewCard(QAbstractButton *button)
{
    int lv,num;
    table->GetCurrCard(&lv,&num);
    table->NewCard(lv,num);
    textChanged();
    QPropertyAnimation *PA = new QPropertyAnimation(button, "geometry");
    PA->setDuration(500);
    QRect NowPos = button->geometry();
    int y = button->y();
    int height = button->height();
    PA->setStartValue(QRect(230,y,0,height));
    PA->setEndValue(NowPos);
    PA->start();
    this->setEnabled(false);
    connect(PA,&QPropertyAnimation::finished,[=](){
        this->setEnabled(true);
        if(table->IfNoble() > 0)
        {
            table->AlterMani(SelectNoble);
            ChooseNoble();
        }
        else
        {
            Next();
            textChanged();
        }
    });
}

void gameInterface::cardConsume(QAbstractButton *pushbutton, color co, bool ifnew)
{
    QPropertyAnimation *PA = new QPropertyAnimation(pushbutton, "geometry");
    PA->setDuration(1000);
    QRect NowPos = pushbutton->geometry();
    QRect EndPos;
    PA->setStartValue(NowPos);
    switch (co)
    {
    case Red:
        EndPos = ui->red_card->geometry();
        break;
    case Green:
        EndPos = ui->green_card->geometry();
        break;
    case Blue:
        EndPos = ui->blue_card->geometry();
        break;
    case White:
        EndPos = ui->white_card->geometry();
        break;
    case Black:
        EndPos = ui->black_card->geometry();
        break;
    default:
        break;
    }
    PA->setEndValue(EndPos);
    PA->setEasingCurve(QEasingCurve::InOutQuad);
    PA->start();
    this->setEnabled(false);

    connect(PA,&QPropertyAnimation::finished,[=](){
        pushbutton->setGeometry(NowPos);
        this->setEnabled(true);
        table->BuyMani();
        table->Avail();
        if(ifnew)//购买的是桌面上的卡，需要翻开卡片
            NewCard(pushbutton);
        else //不需要翻开卡片
        {
            if(table->IfNoble() > 0)
            {
                table->AlterMani(SelectNoble);
                ChooseNoble();
            }
            else
            {
                Next();
                textChanged();
            }
        }
    });
}

void gameInterface::cardConsume(QAbstractButton *pushbutton, int num)//num为0-2
{
    if(num>=0&&num<3)
    {
        QPropertyAnimation *PA = new QPropertyAnimation(pushbutton, "geometry");
        PA->setDuration(1000);
        QRect NowPos = pushbutton->geometry();
        QRect EndPos;
        PA->setStartValue(NowPos);
        switch (num)
        {
        case 0:
            EndPos = ui->reserved1->geometry();
            break;
        case 1:
            EndPos = ui->reserved2->geometry();
            break;
        case 2:
            EndPos = ui->reserved3->geometry();
            break;
        default:
            break;
        }
        PA->setEndValue(EndPos);
        PA->setEasingCurve(QEasingCurve::InOutQuad);
        PA->start();
        this->setEnabled(false);

        connect(PA,&QPropertyAnimation::finished,[=](){
            pushbutton->setGeometry(NowPos);
            this->setEnabled(true);
            table->Avail();
            NewCard(pushbutton);
        });
    }
}

void gameInterface::CardUsed(int level, int num)
{
    if(level >= 0 && level <= 2 && num >= 0 && num <= 3)
    {
        if(level == 0 && num == 0)
            cardConsume(ui->card1_1,table->CurrCardInfo()->GetBonus());
        else if(level == 0 && num == 1)
            cardConsume(ui->card1_2,table->CurrCardInfo()->GetBonus());
        else if(level == 0 && num == 2)
            cardConsume(ui->card1_3,table->CurrCardInfo()->GetBonus());
        else if(level == 0 && num == 3)
            cardConsume(ui->card1_4,table->CurrCardInfo()->GetBonus());
        else if(level == 1 && num == 0)
            cardConsume(ui->card2_1,table->CurrCardInfo()->GetBonus());
        else if(level == 1 && num == 1)
            cardConsume(ui->card2_2,table->CurrCardInfo()->GetBonus());
        else if(level == 1 && num == 2)
            cardConsume(ui->card2_3,table->CurrCardInfo()->GetBonus());
        else if(level == 1 && num == 3)
            cardConsume(ui->card2_4,table->CurrCardInfo()->GetBonus());
        else if(level == 2 && num == 0)
            cardConsume(ui->card3_1,table->CurrCardInfo()->GetBonus());
        else if(level == 2 && num == 1)
            cardConsume(ui->card3_2,table->CurrCardInfo()->GetBonus());
        else if(level == 2 && num == 2)
            cardConsume(ui->card3_3,table->CurrCardInfo()->GetBonus());
        else if(level == 2 && num == 3)
            cardConsume(ui->card3_4,table->CurrCardInfo()->GetBonus());
    }
    else if(level >= 0 && level <= 2 && num == 4)
    {
        if(level == 0)
            cardConsume(ui->reserved1,table->CurrCardInfo()->GetBonus(),false);
        else if(level == 1)
            cardConsume(ui->reserved2,table->CurrCardInfo()->GetBonus(),false);
        else cardConsume(ui->reserved3,table->CurrCardInfo()->GetBonus(),false);
    }
}

void gameInterface::CardUsed(int level, int num, int re_num)
{
    if(level >= 0 && level <= 2 && num >= 0 && num <= 3 && re_num >= 0 && re_num < 3)
    {
        if(level == 0 && num == 0)
            cardConsume(ui->card1_1,re_num);
        else if(level == 0 && num == 1)
            cardConsume(ui->card1_2,re_num);
        else if(level == 0 && num == 2)
            cardConsume(ui->card1_3,re_num);
        else if(level == 0 && num == 3)
            cardConsume(ui->card1_4,re_num);
        else if(level == 1 && num == 0)
            cardConsume(ui->card2_1,re_num);
        else if(level == 1 && num == 1)
            cardConsume(ui->card2_2,re_num);
        else if(level == 1 && num == 2)
            cardConsume(ui->card2_3,re_num);
        else if(level == 1 && num == 3)
            cardConsume(ui->card2_4,re_num);
        else if(level == 2 && num == 0)
            cardConsume(ui->card3_1,re_num);
        else if(level == 2 && num == 1)
            cardConsume(ui->card3_2,re_num);
        else if(level == 2 && num == 2)
            cardConsume(ui->card3_3,re_num);
        else if(level == 2 && num == 3)
            cardConsume(ui->card3_4,re_num);
    }
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
    if(table->GetMani() != SelectNoble)
    {
        table->SetCurrCard(2 - level,num);
        if(table->CanBuy())//买得起显示买卡窗口
        {
            table->AlterMani(Buy);
            PickCard->show();
            PickCard->showCard(table->CardImg(2 - level,num));
        }
        else//买不起显示扣卡窗口
        {
            if(table->CanRetain() >= 0&&table->CardImg(2 - level,num) != "background-color:rgba(255,255,255,80);bordor-radius:55px;")//卡片不为空
            {
                table->AlterMani(Retain);
                kcard->showCard(table->CardImg(2 - level,num));
                if(table->CanRetain() == 1)//可以拿金币
                    kcard->showGold();
                kcard->show();
            }
        }
    }
}

void gameInterface::people1_textChanged()
{
    //显示声望
    ui->gradePeople1->setText(QString::number(table->ShowRep()));
    ui->name1->setText(table->GetPlayerName(1));
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
    ui->name2->setText(table->GetPlayerName(2));
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
    if(table->GetMani() != SelectNoble)
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
    textChanged();
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

void gameInterface::on_changeMan_clicked()
{
    if(table->GetMani() != SelectNoble)
    {
        table->Avail();
        if(table->IfNoble() > 0)
            ChooseNoble();
        else Next();
    //    {
    //        QTimer::singleShot(1000,this,&gameInterface::Next);
    //    }
    }
}

void gameInterface::on_oppo1_clicked()
{
    opp1->show();
}

void gameInterface::on_reserved1_clicked()
{
    if(table->GetMani() != SelectNoble)
    {
        table->SetCurrCard(0,4);
        if(table->CanBuy() && table->ReserveImg(0) != "background-color: rgba(255, 255, 255, 80);border-radius:18px;border:2px solid rgb(176, 176, 87);")
        {
            PickCard->show();
            PickCard->showCard(table->ReserveImg(0));
        }
    }
}

void gameInterface::on_reserved2_clicked()
{
    if(table->GetMani() != SelectNoble)
    {
        table->SetCurrCard(1,4);
        if(table->CanBuy() && table->ReserveImg(1) != "background-color: rgba(255, 255, 255, 80);border-radius:18px;border:2px solid rgb(176, 176, 87);")
        {
            PickCard->show();
            PickCard->showCard(table->ReserveImg(1));
        }
    }
}

void gameInterface::on_reserved3_clicked()
{
    if(table->GetMani() != SelectNoble)
    {
        table->SetCurrCard(2,4);
        if(table->CanBuy() && table->ReserveImg(2) != "background-color: rgba(255, 255, 255, 80);border-radius:18px;border:2px solid rgb(176, 176, 87);")
        {
            PickCard->show();
            PickCard->showCard(table->ReserveImg(2));
        }
    }
}

void gameInterface::on_re_clicked()
{
    rclick->show();
}

void gameInterface::name1Slot(QString str)
{
    table->AlterPlayerName(1,str);
}

void gameInterface::name2Slot(QString str)
{
    table->AlterPlayerName(2,str);
}
/*
void gameInterface::name3Slot(QString str)
{
    ui->name3->setText(str);
}

void gameInterface::name4Slot(QString str)
{
    ui->name4->setText(str);
}
*/

void gameInterface::on_musicC_clicked()
{
    if(musicW == 1)
    {
        ui->musicC->setStyleSheet("border-image: url(:/images/closeMusic.png);border-radius:30px");
        bsound->stop();
        musicW = 0;
    }
    else
    {
        ui->musicC->setStyleSheet("border-image: url(:/images/continueMusic.png);border-radius:30px");
        bsound->play();
        musicW = 1;
    }
}
