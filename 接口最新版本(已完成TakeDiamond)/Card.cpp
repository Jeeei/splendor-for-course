#include "Splendor.h"
using namespace std;
Card::Card()//初始化发展卡，三种等级的发展卡
{
    //default set
    PicAddr = "NULL";
    Bonus = Red;
    for(int i=0;i<6;i++)
    {
        Price[i]=0;
    }
    Rep =0;



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

Card::Card(QString s, color bonus, int* price, int rep)
{
    PicAddr = s;
    Bonus = bonus;//初始化红利属性
	for (int i = 0; i < 5; i++)
	{
		Price[i] = *(price + i);//初始化购买条件
	}
    Rep = rep;//初始化声望点数
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
	for (int i = 0;i < 6;i++)
	{
		p[i] = Price[i];
	}
}

ofstream& operator<<(ofstream& fout, Card& c)
{
    fout.write(reinterpret_cast<char*>(&c.PicAddr), sizeof(c.PicAddr));
    fout.write(reinterpret_cast<char*>(&c.Rep), sizeof(c.Rep));
    fout.write(reinterpret_cast<char*>(&c.Bonus), sizeof(c.Bonus));
    fout.write(reinterpret_cast<char*>(&c.Price), sizeof(c.Price));
    fout.write(reinterpret_cast<char*>(&c.next), sizeof(c.next));
    return fout;
}
ifstream& operator>>(ifstream& fin, Card& c)
{
    fin.read(reinterpret_cast<char*>(&c.PicAddr), sizeof(c.PicAddr));
    fin.read(reinterpret_cast<char*>(&c.Rep), sizeof(c.Rep));
    fin.read(reinterpret_cast<char*>(&c.Bonus), sizeof(c.Bonus));
    fin.read(reinterpret_cast<char*>(&c.Price), sizeof(c.Price));
    fin.read(reinterpret_cast<char*>(&c.next), sizeof(c.next));
    return fin;
}
