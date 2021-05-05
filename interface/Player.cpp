#include "Splendor.h"
#include <QDebug>
using namespace std;
Player::Player()
{
    PicAddr = "background-color: rgba(255, 255, 254, 50);border:2px solid rgb(247, 228, 16);border-radius:45px;";
    Rep = 0;
    for (int i = 0; i < 6; i++)
    {
        Diamonds[i] = 0;
    }
    for (int i = 0; i < 5; i++)
    {
        Nobles[i] = nullptr;
        Cards[i] = 0;
    }
    for (int i = 0; i < 3; i++)
    {
        Reserved[i] = nullptr;
    }
    no = 0;
}
Player::~Player()
{
    for (int i = 0; i < 3; i++)
    {
        if (Reserved[i] != nullptr)
            delete Reserved[i];
    }
}
void Player::GetDiamonds(int*p)//返回宝石
{
    for (int i = 0;i < 6;i++)
    {
        p[i] = Diamonds[i];
    }
}
int Player::GetBonus(color co)//返回玩家拥有的红利数
{
    return Cards[co];
}
int Player::TotalDiamonds()const//返回玩家拥有全部宝石数
{
    int sum = 0;
    for (int i = 0; i < 6; i++)
        sum += Diamonds[i];
    return sum;
}
bool Player::Take(int* diamond, int l)//拿宝石 传一个在Table.Take()中认定合法的Diamond[6]
{
    for (int i = 0; i < l; i++)
        Diamonds[i] += *(diamond + i);
    return true;
}

bool Player::CanBuy(Card* card)//检查玩家能否买卡
{
    if(card != nullptr)
    {
        int gold = Diamonds[Gold];
        int* price = new int[5];
        card->GetPrice(price);
        for (int i = 0; i < 5; i++)//五个颜色
        {
            if (Cards[i] >= price[i])//不用宝石就买得起
                continue;
            else if (Diamonds[i] + Cards[i] >= price[i])//不用黄金就买得起
                continue;
            else if (Diamonds[i] + Cards[i] + gold >= price[i])//要用黄金才买得起
                gold -= price[i] - (Diamonds[i] + Cards[i]);
            else return false;
            if (gold < 0)  //买不起啊干
                return false;
        }
        return true;
    }
    else return false;
}

bool Player::Buy(Card* card)//玩家买卡
{
    int* price = new int[5];
    card->GetPrice(price);
    for (int i = 0; i < 5; i++)
    {
        if (Cards[i] >= price[i])//不用宝石就买得起
            continue;
        else if (Diamonds[i] + Cards[i] >= price[i])//不用黄金就买得起
            Diamonds[i] -= price[i] - Cards[i];
        else if (Diamonds[i] + Cards[i] + Diamonds[Gold] >= price[i])//要用黄金才买得起
        {
            Diamonds[Gold] -= price[i] - (Diamonds[i] + Cards[i]);
            Diamonds[i] = 0;
        }
    }
    Cards[card->GetBonus()]++;
    AddRep(card->GetRep());
    delete []price;
    return true;
}

bool Player::CanReserve()const//检查玩家能否扣卡
{
    for (int i = 0; i < 3; i++)
    {
        if (Reserved[i] == NULL)
            return true;
    }
    return false;
}

bool Player::Reserve(Card* card, bool goldleft)//玩家扣卡
{
    for (int i = 0; i < 3; i++)
    {
        if (Reserved[i] == nullptr)
        {
            Reserved[i] = card;
            if (TotalDiamonds() < 10 && goldleft)//判断玩家能否拿黄金
            {
                Diamonds[Gold]++;
                return true;
            }
            else return false;
        }
    }
    return false;
}

bool Player::NobleCome(Noble* noble)//贵族到访
{
    for (int i = 0; i < 3; i++)
    {
        if (Nobles[i] == nullptr)
        {
            Nobles[i] = noble;
            Rep += noble->GetRep();//增加声望点数
            return true;
        }
    }
    return false;
}


bool Player::AlterDiamond(color co, int nota, int num)
{
    int n = Diamonds[co] + nota * num;
    if ( n >= 0)//不能为负
    {
        Diamonds[co] = n;
        return 1;
    }
    return 0;
}

int Player::GetDiamond(int co)
{
    if(co >= 0 && co < 6)
    {
        return Diamonds[co];
    }
    else return -1;
}

void Player::GetDiamond(int* d, int length)
{
    for (int i = 0;i < length;i++)
        d[i] = Diamonds[i];
}

void Player::ShowCards(int* c, int length)
{
    for (int i = 0;i < length;i++)
        c[i] = Cards[i];
}

void Player::ShowReserved(Card** r, int length)
{
    for (int i = 0;i < length;i++)
        r[i] = Reserved[i];
}

bool Player::SetImg(QString s)
{
    PicAddr = s;
    return true;
}
