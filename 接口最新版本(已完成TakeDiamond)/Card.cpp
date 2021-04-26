#include "Splendor.h"
using namespace std;
Card::Card()//初始化发展卡，三种等级的发展卡
{
    //用文件输入，待完善



    //Card[0][0]的属性:
//    int p[5];p[Red]=7;color bon = Black;int r = 7;
//    Bonus = bon;//初始化红利属性
//	for (int i = 0; i < 5; i++)
//	{
//		Price[i] = *(p + i);//初始化购买条件
//	}
//	Rep = r;//初始化声望点数
//    AddressToPic = "border-image:url(:/images/card/blue-high/1.png)";
    //以上测试
}

Card::Card(color bonus, int* price, int rep)
{

    Bonus = bonus;//初始化红利属性
	for (int i = 0; i < 5; i++)
	{
		Price[i] = *(price + i);//初始化购买条件
	}
	Rep = rep;//初始化声望点数
    //AddressToPic = "border-image:url(:/images/card/blue-high/1.png)";
}
int Card::GetRep()const//返回卡片的声望点数
{
    return Rep;
}

//QString Card::GetAddress() const
//{
//    return AddressToPic;
//}
color Card::GetBonus()const//返回卡片的红利种类
{
	return Bonus;
}
void Card::GetPrice(int* p)const//返回Price的指针
{
	for (int i = 0;i < 6;i++)
	{
		p[i] = Price[i];
	}
}
