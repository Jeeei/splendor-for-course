#include "Splendor.h"
using namespace std;
bool Table::Start()
{
    CurrPlayer=Players[0];//先手更改
    PlayerNum = sPlayerNum;//确定玩家人数 //sPlayer在构造函数初始化为2
    for (int i = 0;i<PlayerNum;i++)
    {
     Players[i]->SetImg(sPlayerImg[i]);
    }
    Players[0]->SetImg(":/img/images/bbb.png");//强制给玩家设置头像
    Players[1]->SetImg(":/img/images/black.PNG");
    return true;
}

bool Table::Init()
{
    CreateCard();
    CreateNoble();
}

int Table::Round()
{
    for(int i=0;i<PlayerNum;i++)//切换下一个玩家
    {
        if(CurrPlayer = Players[i])
        {
            CurrPlayer=Players[(i+1)%PlayerNum];
        }
    }
    AlterMani(None);
}

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

}
bool Table::CreateNoble()
{

}
