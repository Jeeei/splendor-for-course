#include "Splendor.h"
using namespace std;
Card::Card()//��ʼ����չ�������ֵȼ��ķ�չ��
{
	//���ļ������ʼ����Ƭ��Ϣ
}
Card::Card(color bonus, int* price, int rep)
{
	Bonus = bonus;//��ʼ����������
	for (int i = 0; i < 5; i++)
	{
		Price[i] = *(price + i);//��ʼ����������
	}
	Rep = rep;//��ʼ����������
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
	for (int i = 0; i < 6; i++)
	{
		p[i] = Price[i];
	}
}