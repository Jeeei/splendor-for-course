#include "Splendor.h"
using namespace std;
Noble::Noble()
{
	//empty
}
Noble::Noble(int rep, int* con)
{
	Rep = rep;
	for (int i = 0; i < 5; i++)
		Condition[i] = *(con + i);
}
int Noble::GetRep()const//��ʾ��������
{
	return Rep;
}

void Noble::GetCondition(int* p)const
{
	for (int i = 0;i < 6;i++)
	{
		p[i] = Condition[i];
	}
}

bool Noble::CanVisit(Player* player)//����ܷ�������
{
	int* p = new int[6];
	player->GetBonus(p);
	for (int i = 0; i < 5; i++)
	{
		if (p[i] < Condition[i])
			return false;
	}
	return true;
}