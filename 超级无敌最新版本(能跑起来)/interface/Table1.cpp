#include "Splendor.h"
#include <ctime>
#include <QDebug>
using namespace std;

//五操作函数
Table::Table()
{
    for (int i = 0; i < 3; i++)//卡头仍需接入到链表
        CardHead[i] = nullptr;
    for (int i = 0; i < 3; i++)//初始化场上发展卡数组
        for (int j = 0; j < 4; j++)
        {
            OpenCard[i][j] = nullptr;
            AvailCard[i][j] = 0;
        }
    for (int i = 0; i < 5; i++)//初始化贵族卡数组
    {
        Nobles[i] = nullptr;
        AvailNoble[i] = 0;
    }
    for (int i = 0; i < 4; i++)//初始化玩家指针
    {
        Players[i] = nullptr;
        sPlayerImg[i] = "NULL";
    }
    for(int i = 0; i < 6; i++)
    {
        Diamonds[i] = 0;
        TakenDiamond[i] = 0;
    }
    sPlayerNum = 2;//玩家人数为2
    SetCurrCard(-1,-1);
    AlterMani(None);
    SetCurrNoble(-1);
    CurrPlayer = nullptr;
    Status = Selecting;
    //qDebug()<<"Table created."<<endl;
}
Table::~Table()
{
    //qDebug()<<"Table deleted."<<endl;
    for (int i = 0; i < 4; i++)//删除玩家
    {
        if (Players[i] != nullptr)
        {
            delete Players[i];
            Players[i] = nullptr;
        }
    }
    for (int i = 0; i < 3; i++)//删除场上发展卡
        for (int j = 0; j < 4; j++)
        {
            if (OpenCard[i][j] != nullptr)
                delete OpenCard[i][j];
        }
    for (int i = 0; i < 3; i++)//删除贵族卡
    {
        if(Nobles[i] != nullptr)
        {
            delete Nobles[i];
            Nobles[i] = nullptr;
        }
    }
    for (int i = 0; i < 3; i++)//删除生成的卡链表
    {
        Card* temp;
        while(CardHead[i] != nullptr)
        {
            //qDebug()<<"deleting"<<CardHead[i]->Rep<<" "<<CardHead[i]->Bonus<<" "<<CardHead[i];
            temp = CardHead[i];
            CardHead[i] = CardHead[i]-> next;
            delete temp;
        }
    }
}

bool Table::Start()
{
    PlayerNum = sPlayerNum;//确定玩家人数 //sPlayer在构造函数初始化为2
    for(int i = 0;i < PlayerNum;i++)
    {
        Players[i] = new Player;
    }
    CurrPlayer = Players[0];//先手更改

//    for (int i = 0;i<PlayerNum;i++)
//    {
//     Players[i]->SetImg(sPlayerImg[i]);
//    }
    //Players[0]->SetImg("border-image:url(:/images/bbb.png)");//强制给玩家设置头像
    //Players[1]->SetImg("border-image:url(:/images/black.PNG)");
    Init();
    return true;
}

bool Table::Init()
{
    for(int i = 0; i < 6; i++)//初始化宝石数
    {
        Diamonds[i] = 5;
    }
    CreateCard();//生成卡链表
    AlterStatus(Playing);
    //CreateNoble();

    //先有卡再有Avail
    Avail();//初始化AvailCard数组和AvailNoble数组
    return true;
}

QString Table::GetPlayerImg(int playernum)
{
    if(playernum < 1 || playernum > sPlayerNum)
        return "NULL";
    return sPlayerImg[playernum - 1];
}

void Table::Avail()//判断桌面上当前玩家可购买的卡 以及可以拜访的贵族
{
    for (int level = 0;level < 3;level++)//^如果优化不应当出现不明数字
    {
        for (int num = 0; num < 4; num++)
        {
            Card* p = OpenCard[level][num];//获取当前卡指针
            if(CurrPlayer->CanBuy(p))
                AvailCard[level][num] = 1;//可买
            else AvailCard[level][num] = 0;//不可买
        }
    }
//    for (int i = 0; i < 5; i++)//遍历贵族卡数组
//    {
//        if(Nobles[i]->CanVisit(CurrPlayer))
//            AvailNoble[i] = 1;
//        else AvailNoble[i] = 0;
//    }
}

void Table::NoneMani()
{
    AlterMani(None);
    CurrCard[0] = CurrCard[1] = -1;
    for (int i = 0;i < 6;i++)
        TakenDiamond[i] = -1;
}

int Table::CanTake(color co)
{
    if (Diamonds[co] == 0)
        return -1;//ERROR1: This Color ISN'T EXISTED on table!
    int pDiaNum = CurrPlayer->TotalDiamonds();//player的宝石总数目
    if (pDiaNum + 1 > 10)
        return -2;//ERROR2: Player's diamonds FULL!
    int cDiaNum = 0;//已经拿的
    for (int i = 0;i < 6;i++)
        cDiaNum += TakenDiamond[i];
    //qDebug()<<"Taken num:"<<cDiaNum<<endl;
    if (pDiaNum + cDiaNum + 1 > 10)
        return -3;//ERROR3: Taken will cause OVERFLOW!
    //ERROR2&3区别在于2直接不给进入Take状态，3可进入Take状态但是所拿数量限制
    if (cDiaNum + 1 > 3)
        return -4;//ERROR4: Taken is OVERFLOW!
    if (TakenDiamond[co] != 0)
    {
        if (Diamonds[co] < 3)
            return -5;//ERROR5: 2 same color CAN'T taken while surplus under 4!
        if (cDiaNum - TakenDiamond[co] || TakenDiamond[co] >= 2)
            return -6;//ERROR6: 3 DIFFERENT or 2 SAME color!
    }
    for(int i = 0;i < 6;i++)
    {
        if((i != co)&&TakenDiamond[i]>=2)//拿了其他颜色
            return -7;//ERROR7: 2 SAME color and 1 different color!
    }
    //qDebug()<<"taken add from table.";
    TakenDiamond[co]++;
    Diamonds[co]--;
    return 1;
}

int Table::UnTake(color co)
{
    if(TakenDiamond[co] > 0)
    {
        //qDebug()<<"taken minus from table.";
        TakenDiamond[co]--;
        Diamonds[co]++;
        return true;
    }
    else return false;
}

bool Table::CanBuy()
{
    return AvailCard[CurrCard[0]][CurrCard[1]];
}

int Table::CanRetain(int level, int num)
{
    if(level < 0 || level > 2 || num < 0 || num > 3)
        return -1;//不合法的位置
    if (OpenCard[level][num] == nullptr)
        return -2;//没牌了
    for (int i = 0;i < 3;i++)
    {
        if (CurrPlayer->Reserved[i] == nullptr)
            return 1;
    }
    return 0;
}

int Table::TakeMani()
{
    for (int i = 0;i < 6;i++)
    {
        CurrPlayer->Diamonds[i] += TakenDiamond[i];
        TakenDiamond[i] = 0;
    }
    return 1;
}

int Table::BuyMani()//买得起的情况下才调用
{
    Card* c = OpenCard[CurrCard[0]][CurrCard[1]];//获取当前卡指针
    CurrPlayer->Buy(c);
    for (int i = 0; i < 5; i++)//还宝石给table
    {
        if (CurrPlayer->Cards[i] >= c->Price[i])//不用宝石就买得起
            continue;
        else if (Diamonds[i] + CurrPlayer->Cards[i] >= c->Price[i])//不用黄金就买得起
            Diamonds[i] += c->Price[i] - CurrPlayer->Cards[i];
        else if (Diamonds[i] + CurrPlayer->Cards[i] + Diamonds[Gold] >= c->Price[i])//要用黄金才买得起
            Diamonds[Gold] += c->Price[i] - (Diamonds[i] + CurrPlayer->Cards[i]);
    }
    if (CurrCard[1] < 4)//为桌面的卡
        NewCard(CurrCard[0], CurrCard[1]);//补桌面的卡
    else
        CurrPlayer->SetReserved(CurrCard[0], nullptr);
    return 1;
}

int Table::RetainMani()
{
    Card* c = OpenCard[CurrCard[0]][CurrCard[1]];//获取当前卡指针
    int i;
    for (i = 0;i < 3;i++)
    {
        if(CurrPlayer->GetReserved(i) == nullptr)
        {
            CurrPlayer->SetReserved(i, c);//保留
            break;
        }
    }
    if (i >= 3)
        return -1;//ERROR1:没有空的槽
    if (CurrCard[1] < 4)//为桌面的卡
        NewCard(CurrCard[0], CurrCard[1]);
    else
        return -2;//ERROR2:保留的不为桌面的卡
    return 1;
}

int Table::IfNoble()//判断是否需要选择贵族
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        if(AvailNoble[i])
            count++;
    }
    if(count > 1)//需要选择
        return 1;
    else if(count == 1)//不需要选,直接拜访
        return 0;
    else return -1;//没得选,爬
}

void Table::NobleCome(int num)//贵族拜访
{
    if(num >= 0 && num <= 4)
        if(AvailNoble[num])
            CurrPlayer->NobleCome(Nobles[num]);
}

void Table::Next()//操作完成,回合结束,切换下一个玩家
{
//    //检查是否有贵族拜访
//    switch(IfNoble())
//    {
//    case 1:
//        //选择贵族啊
//        break;
//    case 0:
//        for (int i = 0; i < 5; i++)
//        {
//            if(AvailNoble[i])
//            {
//                NobleCome(i);//直接拜访,也许需要动画什么的
//                break;
//            }
//        }
//        break;
//    case -1://没得选
//    default:
//        break;
//    }
//    //回合真正结束
    for(int i=0; i < PlayerNum; i++)//切换下一个玩家
    {
        if(CurrPlayer == Players[i])
        {
            CurrPlayer = Players[(i+1)%PlayerNum];
            break;
        }
    }
    Avail();//重置AvailCard数组和AvailNoble数组
    ClearTakenDiamond();//重置已拿宝石数组
    SetCurrCard(-1,-1);//设置选中卡片为空
    SetCurrNoble(-1);//设置选中贵族为空
    AlterMani(None);//无操作状态
}

//2.table
QString Table::CardImg(int level, int num)
{
    if(OpenCard[level][num] != nullptr && level >= 0 && level <= 2 && num >= 0 && num <= 3)
        return OpenCard[level][num]->GetAddress();
    return "\0";
}

QString Table::NobleImg(int num)
{
    if(Nobles[num] != nullptr && num >= 0 && num <= 4)
        return Nobles[num]->GetAddress();
    return "\0";
}

QString Table::PlayerImg(int num)
{
    if(Players[num] != nullptr && num >= 0 && num <= 3)
        return Players[num]->GetAddress();
    return "\0";
}


void Table::AvailCardInfo(int** c, int level, int num)
{
    for (int i = 0;i < level;i++)
    {
        for (int j = 0;j < num;j++)
        {
            c[i][j] = AvailCard[i][j];
        }
    }
}

void Table::AvailNobleInfo(int* n, int length)
{
    for (int i = 0; i < length; i++)
    {
        n[i] = AvailNoble[i];
    }
}

void Table::TakenDiamondInfo(int* d, int length)
{
    for (int i = 0;i < length;i++)
        d[i] = -1;//为空
    for (int i = 0;i < length;i++)//拿宝石最多三个
    {
        for (int j = 0;j < 6;j++)//颜色
        {
            if (TakenDiamond[j] == 1)
            {
                d[i] = j;
                break;
            }
            if (TakenDiamond[j] == 2)
            {
                d[i] = d[i + 1] = j;
                return;
            }
        }
    }
}

Card* Table::CurrCardInfo()
{
    if (CurrCard[1] == 4)//为自己扣的卡
    {
        return CurrPlayer->GetReserved(CurrCard[0]);
    }
    return OpenCard[CurrCard[0]][CurrCard[1]];
}

void Table::SetCurrNoble(int num)
{
    CurrNoble = num;
}

Noble* Table::CurrNobleInfo()
{
    return Nobles[CurrNoble];
}

int Table::ShowDiamonds(int co)
{
    return Diamonds[co];
}

int Table::ShowPlayerDiamonds(int color, int player)
{
    if(player == -1)
        return CurrPlayer->ShowDiamond(color);
    else return Players[player]->ShowDiamond(color);
}

int Table::ShowRep(int player)
{
    if(player == -1)
        return CurrPlayer->ShowRep();
    return Players[player]->ShowRep();
}

void Table::ClearTakenDiamond()
{
    for(int i = 0; i < 6;i++)
    {
        if(TakenDiamond[i]>0)
        {
            Diamonds[i] += TakenDiamond[i];
            TakenDiamond[i] = 0;
        }
    }
}

void Table::SetCurrCard(int level, int num)
{
    CurrCard[0] = level;
    CurrCard[1] = num;
}

//int Table::Round()
//{
//    for(int i=0;i<PlayerNum;i++)//切换下一个玩家
//    {
//        if(CurrPlayer == Players[i])
//        {
//            CurrPlayer = Players[(i+1)%PlayerNum];
//        }
//    }
//    AlterMani(None);
//    return 1;
//}

bool Table::NewCard(int level, int num)
{
    if(level >= 0&&level < 3&&num >= 0&&num < 4)
    {
        OpenCard[level][num] = CardHead[level];
        if(CardHead[level]->next != nullptr)//下一个不为空
        {
            CardHead[level] = CardHead[level]->next;
            OpenCard[level][num]->next = nullptr;
            //qDebug()<<"Card "<<level<<" "<<num<<"created!"<<endl;
            return true;
        }
        else//没牌了
        {
        OpenCard[level][num] = nullptr;
        return false;
        }
    }
    else return false;
}
bool Table::CreateCard()
{
    char addr[90][55];
        int bonus[90];
        int price[90], rep[90];
        int num[6] = { 8 };//num[color]
        Card* randHigh[20] = {nullptr}, *randMid[30] = {nullptr},
            *randLow[40] = {nullptr};
        ifstream c("cards.dat", ios::in | ios::binary);
        //qDebug() << c.is_open() << endl;//dat读出来
        for (int i = 0;i < 90;i++)//20-40-30
        {
            c.read(reinterpret_cast<char*>(&addr[i]), sizeof(addr[i]));
            c.read(reinterpret_cast<char*>(&bonus[i]), sizeof(bonus[i]));
            c.read(reinterpret_cast<char*>(&price[i]), sizeof(price[i]));
            c.read(reinterpret_cast<char*>(&rep[i]), sizeof(rep[i]));
            for (int j = 5;j >= 0;j--)
            {
                num[j] = price[i] % 10;
                price[i] -= num[j];
                price[i] /= 10;
            }
            srand(time(0));
            if(i < 20)//High
            {
                int sit = rand()%20;
                while(randHigh[sit]!=nullptr)
                    sit = rand()%20;
                randHigh[sit] = new Card;
                randHigh[sit]->PicAddr = QString(QLatin1String(addr[i]));//QString(QLatin1String(ch));
                randHigh[sit]->Rep = rep[i];
                randHigh[sit]->Bonus = color(bonus[i]);
                for(int k = 0; k < 6; k++)
                {
                   randHigh[sit]->Price[k] = num[k];
                }
            }
            else if(i < 60)//Low
            {
                int sit = rand()%40;
                while(randLow[sit]!=nullptr)
                    sit = rand()%40;
                randLow[sit] = new Card;
                randLow[sit]->PicAddr = QString(QLatin1String(addr[i]));//QString(QLatin1String(ch));
                randLow[sit]->Rep = rep[i];
                randLow[sit]->Bonus = color(bonus[i]);
                for(int k=0; k<6; k++)
                {
                   randLow[sit]->Price[k] = num[k];
                }
            }
            else//Mid
            {
                int sit = rand()%30;
                while(randMid[sit]!=nullptr)
                    sit = rand()%30;
                randMid[sit] = new Card;
                randMid[sit]->PicAddr = QString(QLatin1String(addr[i]));//QString(QLatin1String(ch));
                randMid[sit]->Rep = rep[i];
                randMid[sit]->Bonus = color(bonus[i]);
                for(int k=0; k<6; k++)
                {
                   randMid[sit]->Price[k] = num[k];
                }
            }
        }
        //链表连连看
        Card* cc1 = CardHead[2] = randHigh[0];
        for (int k = 0; k < 19; k++)
        {
           cc1->next = randHigh[k+1];
           cc1 = cc1->next;
        }
        //qDebug()<<"create 1:"<<cc1->Rep<<" "<<cc1->Bonus<<" "<<cc1;
        cc1->next = nullptr;
        //链表连连看
        Card* cc2 = CardHead[0] = randLow[0];
        for (int k = 0; k < 39; k++)
        {
           cc2->next=randLow[k+1];
           cc2 = cc2->next;
        }
        //qDebug()<<"create 2:"<<cc2->Rep<<" "<<cc2->Bonus<<" "<<cc2;
        cc2->next = nullptr;
        //链表连连看
        Card* cc3 = CardHead[1] = randMid[0];
        for (int k = 0; k < 29; k++)
        {
           cc3->next = randMid[k+1];
           cc3 = cc3->next;
        }
        //qDebug()<<"create 3:"<<cc3->Rep<<" "<<cc3->Bonus<<" "<<cc3;
        cc3->next = nullptr;
        c.close();
        for(int i = 0;i < 3;i++)
        {
            for(int j = 0;j < 4;j++)
                NewCard(i,j);
        }
}
bool Table::CreateNoble()
{

}


bool Table::IfCount()
{
    for (int i=0;i<PlayerNum;i++) {
        if(Players[i]->Rep>=15)
            return true;
    }
    return false;
}

bool Table::IfCurrCount()
{
    if(CurrPlayer->Rep>=15)
        return true;
    return false;
}

bool Table::GetCount(Player **no1, Player **no2, int* num1, int* num2)
{
    if(Status!=Counting)
        return false;
    int highscore=0,No1Num=0,No2Num=0;
    for(int i=0;i<PlayerNum;i++)//获取最高分
    {
        if(Players[i]->Rep>highscore)
            highscore=Players[i]->Rep;
    }
    for(int i=0;i<PlayerNum;i++)//放入数组
    {
        if(Players[i]->Rep=highscore)
        {
            no1[No1Num]=Players[i];
            No1Num++;
        }
        else {
            no2[No2Num]=Players[i];
            No2Num++;
        }
    }
    *num1=No1Num;
    *num2=No2Num;
    return true;
}
