#include "Splendor.h"
using namespace std;
Card::Card()//��ʼ����չ�������ֵȼ��ķ�չ��
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

