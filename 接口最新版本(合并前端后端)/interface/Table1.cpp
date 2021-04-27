#include "Splendor.h"
using namespace std;

//五操作函数
Table::Table()
{
    for (int i = 0; i < 3; i++)//卡头仍需接入到链表
        CardHead[i] = NULL;
    for (int i = 0; i < 3; i++)//初始化场上发展卡数组
        for (int j = 0; j < 4; j++)
        {
            OpenCard[i][j] = NULL;
            AvailCard[i][j] = 0;
        }
    for (int i = 0; i < 5; i++)//初始化贵族卡数组
    {
        Nobles[i] = NULL;
        AvailNoble[i] = 0;
    }
    for (int i = 0; i < 4; i++)//初始化玩家指针
    {
        Players[i] = NULL;
        sPlayerImg[i] = "NULL";
    }
    for(int i = 0; i < 6; i++)
    {
        Diamonds[i] = 0;
        TakenDiamond[i] = 0;
    }
    sPlayerNum = 2;
    SetCurrCard(-1,-1);
    AlterMani(None);
    CurrNoble = -1;
    CurrPlayer = NULL;
}
Table::~Table()
{
    for (int i = 0; i < 4; i++)//删除玩家
    {
        if (Players[i] != NULL)
        {
            delete Players[i];
            Players[i] = NULL;
        }
    }
    for (int i = 0; i < 3; i++)//删除场上发展卡
        for (int j = 0; j < 4; j++)
        {
            if (OpenCard[i][j] != NULL)
                delete OpenCard[i][j];
        }
    for (int i = 0; i < 3; i++)//删除贵族卡
        delete Nobles[i];
}

bool Table::Start()
{
    CurrPlayer = Players[0];//先手更改
    PlayerNum = sPlayerNum;//确定玩家人数 //sPlayer在构造函数初始化为2
    for (int i = 0;i<PlayerNum;i++)
    {
     Players[i]->SetImg(sPlayerImg[i]);
    }
    Players[0]->SetImg(":/images/bbb.png");//强制给玩家设置头像
    Players[1]->SetImg(":/images/black.PNG");
    Init();
    return true;
}

bool Table::Init()
{
    CreateCard();
    CreateNoble();
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
    for (int i = 0; i < 5; i++)//遍历贵族卡数组
    {
        if(Nobles[i]->CanVisit(CurrPlayer))
            AvailNoble[i] = 1;
        else AvailNoble[i] = 0;
    }
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
    int cDiaNum = ShowTakenDiamond();//已经拿的
    if (pDiaNum + cDiaNum + 1 > 10)
        return -3;//ERROR3: Taken will cause OVERFLOW!
    //ERROR2&3区别在于2直接不给进入Take状态，3可进入Take状态但是所拿数量限制
    if (cDiaNum + 1 > 3)
        return -4;//ERROR4: Taken is OVERFLOW!
    if (TakenDiamond[co] != 0)
    {
        if (Diamonds[co] < 4)
            return -5;//ERROR3: 2 same color CAN'T taken while surplus under 4!
        if (cDiaNum - TakenDiamond[co])//拿了其他颜色
            return -6;//ERROR6: 3 DIFFERENT or 2 SAME color!
    }
    TakenDiamond[co]++;
    return 1;
}

int Table::UnTake(color co)
{
    if(TakenDiamond[co]!=0)
    {
        TakenDiamond[co]--;
        return true;
    }
    else return false;
}

int Table::CanBuy(int level, int num)
{
    if(level < 0 || level > 2 || num < 0 || num > 3)
        return -1;//不合法的位置
    if (OpenCard[level][num] == NULL)
        return -2;//没牌了
    if (AvailCard[level][num])
        return 1;
    return 0;
}

int Table::CanRetain(int level, int num)
{
    if(level < 0 || level > 2 || num < 0 || num > 3)
        return -1;//不合法的位置
    if (OpenCard[level][num] == NULL)
        return -2;//没牌了
    for (int i = 0;i < 3;i++)
    {
        if (CurrPlayer->Reserved[i] == NULL)
            return 1;
    }
    return 0;
}

int Table::TakeMani()
{
    for (int i = 0;i < 6;i++)
    {
        CurrPlayer->Diamonds[i] += TakenDiamond[i];
    }
    ClearTakenDiamond();
    return 1;
}

int Table::BuyMani()
{
    Card* c = OpenCard[CurrCard[0]][CurrCard[1]];//获取当前卡指针
    CurrPlayer->Buy(c);
    if (CurrCard[1] < 4)//为桌面的卡
        NewCard(CurrCard[0], CurrCard[1]);//补桌面的卡
    else
        CurrPlayer->SetReserved(CurrCard[0], NULL);
    return 1;
}

int Table::RetainMani()
{
    Card* c = OpenCard[CurrCard[0]][CurrCard[1]];//获取当前卡指针
    int i;
    for (i = 0;i < 3;i++)
    {
        if(CurrPlayer->GetReserved(i)==NULL)
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
    //检查是否有贵族拜访
    switch(IfNoble())
    {
    case 1:
        //选择贵族啊
        break;
    case 0:
        for (int i = 0; i < 5; i++)
        {
            if(AvailNoble[i])
            {
                NobleCome(i);//直接拜访,也许需要动画什么的
                break;
            }
        }
        break;
    case -1://没得选
    default:
        break;
    }
    //回合真正结束
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
    if(OpenCard[level][num] != NULL && level >= 0 && level <= 2 && num >= 0 && num <= 3)
        return OpenCard[level][num]->GetAddress();
    return "\0";
}

QString Table::NobleImg(int num)
{
    if(Nobles[num] != NULL && num >= 0 && num <= 4)
        return Nobles[num]->GetAddress();
    return "\0";
}

QString Table::PlayerImg(int num)
{
    if(Players[num] != NULL && num >= 0 && num <= 3)
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
    return Players[player]->ShowDiamond(color);
}

int Table::ShowRep(int player)
{
    if(player == -1)
        return CurrPlayer->ShowRep();
    return Players[player]->ShowRep();
}

int Table::ShowTakenDiamond() const
{
    int cDiaNum = 0;//已经拿的
    for (int i = 0;i < 6;i++)
        cDiaNum += TakenDiamond[i];
    return cDiaNum;
}

void Table::ClearTakenDiamond()
{
    for(int i=0;i<6;i++)
    {
        TakenDiamond[i]=0;
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
    //cardhead[level]->opencard[level][num]
    OpenCard[level][num]=CardHead[level];
    if(CardHead[level]->next != nullptr)//下一个不为空
    {
        CardHead[level]=CardHead[level]->next;
        OpenCard[level][num]->next= nullptr;
        return true;
    }
    else {
        OpenCard[level][num]=nullptr;
        return false;
    }

}
bool Table::CreateCard()
{
    char addr[90][40];
        int bonus[90];
        int price[90], rep[90];
        int num[6] = { 8 };//num[color]
        Card* randHigh[20] = {nullptr}, *randMid[30] = {nullptr},
            *randLow[40] = {nullptr};
        ifstream c("cards.dat", ios::in | ios::binary);
        cout << c.is_open() << endl;//dat读出来
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
            srand(time(NULL));
            if(i < 20)//High
            {
                int sit = rand()%20;
                while(randHigh[sit]!=nullptr)
                    sit = rand()%20;
                randHigh[sit] = new Card;
                randHigh[sit]->PicAddr = QString(QLatin1String(addr[i]));//QString(QLatin1String(ch));
                randHigh[sit]->Rep = rep[i];
                randHigh[sit]->Bonus = color(bonus[i]);
                for(int k=0; k<6; k++)
                {
                   randHigh[sit]->Price[k] = num[k];
                }
                //链表连连看
                Card* cc = CardHead[2] = randHigh[0];
                for (int k=0; k<19; k++)
                {
                   cc->next=randHigh[k+1];
                   cc=cc->next;
                }
            }
            else if(i < 60)//Low
            {
                int sit = rand()%40;
                while(randMid[sit]!=nullptr)
                    sit = rand()%40;
                randMid[sit] = new Card;
                randMid[sit]->PicAddr = QString(QLatin1String(addr[i]));//QString(QLatin1String(ch));
                randMid[sit]->Rep = rep[i];
                randMid[sit]->Bonus = color(bonus[i]);
                for(int k=0; k<6; k++)
                {
                   randMid[sit]->Price[k] = num[k];
                }
                //链表连连看
                Card* cc = CardHead[0] = randMid[0];
                for (int k=0; k<39; k++)
                {
                   cc->next=randMid[k+1];
                   cc=cc->next;
                }
            }
            else//Mid
            {
                int sit = rand()%30;
                while(randLow[sit]!=nullptr)
                    sit = rand()%30;
                randLow[sit] = new Card;
                randLow[sit]->PicAddr = QString(QLatin1String(addr[i]));//QString(QLatin1String(ch));
                randLow[sit]->Rep = rep[i];
                randLow[sit]->Bonus = color(bonus[i]);
                for(int k=0; k<6; k++)
                {
                   randLow[sit]->Price[k] = num[k];
                }
                //链表连连看
                Card* cc = CardHead[1] = randLow[0];
                for (int k=0; k<19; k++)
                {
                   cc->next=randLow[k+1];
                   cc=cc->next;
                }
            }
        }

        c.close();
}
bool Table::CreateNoble()
{

}
