#include "Splendor.h"
using namespace std;
Card::Card()//��ʼ����չ�������ֵȼ��ķ�չ��
{
    //���ļ����룬������



    //Card[0][0]������:
//    int p[5];p[Red]=7;color bon = Black;int r = 7;
//    Bonus = bon;//��ʼ����������
//	for (int i = 0; i < 5; i++)
//	{
//		Price[i] = *(p + i);//��ʼ����������
//	}
//	Rep = r;//��ʼ����������
//    AddressToPic = "border-image:url(:/images/card/blue-high/1.png)";
    //���ϲ���
}

Card::Card(color bonus, int* price, int rep)
{

    Bonus = bonus;//��ʼ����������
	for (int i = 0; i < 5; i++)
	{
		Price[i] = *(price + i);//��ʼ����������
	}
	Rep = rep;//��ʼ����������
    //AddressToPic = "border-image:url(:/images/card/blue-high/1.png)";
}
int Card::GetRep()const//���ؿ�Ƭ����������
{
    return Rep;
}

//QString Card::GetAddress() const
//{
//    return AddressToPic;
//}
color Card::GetBonus()const//���ؿ�Ƭ�ĺ�������
{
	return Bonus;
}
void Card::GetPrice(int* p)const//����Price��ָ��
{
	for (int i = 0;i < 6;i++)
	{
		p[i] = Price[i];
	}
}
