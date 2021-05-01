#include "Splendor.h"
using namespace std;
Card::Card()//��ʼ����չ�������ֵȼ��ķ�չ��
{
    //default set
    PicAddr = "NULL";
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
    Bonus = bonus;//��ʼ����������
    for (int i = 0; i < 5; i++)
    {
        Price[i] = *(price + i);//��ʼ����������
    }
    Rep = rep;//��ʼ����������
    next = nullptr;
}
int Card::GetRep()const//���ؿ�Ƭ����������
{
    return Rep;
}

color Card::GetBonus()const//���ؿ�Ƭ�ĺ�������
{
    return Bonus;
}
void Card::GetPrice(int* p)const//����Price��ָ��
{
    for (int i = 0;i < 5;i++)
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
    //fout.write(reinterpret_cast<char*>(&c.next), sizeof(c.next));
    return fout;
}
ifstream& operator>>(ifstream& fin, Card& c)
{
    fin.read(reinterpret_cast<char*>(&c.PicAddr), sizeof(c.PicAddr));
    fin.read(reinterpret_cast<char*>(&c.Rep), sizeof(c.Rep));
    fin.read(reinterpret_cast<char*>(&c.Bonus), sizeof(c.Bonus));
    fin.read(reinterpret_cast<char*>(&c.Price), sizeof(c.Price));
    //fin.read(reinterpret_cast<char*>(&c.next), sizeof(c.next));
    return fin;
}

