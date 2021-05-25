#include "Splendor.h"
using namespace std;
Card::Card()//初始化发展卡，三种等级的发展卡
{
    //default set
    PicAddr = "background-color:rgba(255,255,255,80)";
    Bonus = Red;
    for(int i = 0;i < 6; i++)
    {
        Price[i] = 0;
    }
    Rep = 0;
    next = nullptr;
}

Card::Card(QString s, color bonus, int* price, int rep)
{
    PicAddr = s;
    Bonus = bonus;//初始化红利属性
    for (int i = 0; i < 5; i++)
    {
        Price[i] = *(price + i);//初始化购买条件
    }
    Rep = rep;//初始化声望点数
    next = nullptr;
}
int Card::GetRep()const//返回卡片的声望点数
{
    return Rep;
}

color Card::GetBonus()const//返回卡片的红利种类
{
    return Bonus;
}
void Card::GetPrice(int* p)const//返回Price的指针
{
    for (int i = 0;i < 5;i++)
    {
        p[i] = Price[i];
    }
}

