#include "Splendor.h"
using namespace std;

Table::Table()
{
	//�ӿ�ʼ��Ϸ�˵�
	for (int i = 0; i < 3; i++)
		CardHead[i] = NULL;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			OpenCard[i][j] = NULL;
	for (int i = 0; i < 5; i++)
		Nobles[i] = NULL;
	for (int i = 0; i < 4; i++)
		Players[i] = NULL;
}
//ȱ��~Table()
bool Table::Start()//���û�������ʼ�� ������2��Players������Init ������������ѡ��
{
	Players[0] = new Player;
	Players[1] = new Player;
	if (Init())
	{
		int result = Round();//����Round������Ϸ,�������Ϸ���
		if (result)//����Ƿ�����������Ϸ
		{
			delete Players[0];
			delete Players[1];
			for (int i = 0; i < 3; i++)
				delete Nobles[i];
			return true;
		}
		else return false;
	}
}
bool Table::Init()//��ʼ��������������ʯ������չ�������忨�ĳ�ʼ��
{
	for (int i = 0; i < 6; i++)//��ʼ����ʯ��
		Diamonds[i] = 5;
	for (int i = 0; i < 3; i++)//��ʼ����չ��
		for (int j = 0; j < 4; j++)
		{
			if (OpenCard[i][j] == NULL)
				CreateCard(i, j);
		}
	for (int i = 0; i < 3; i++)
	{
		if (Nobles[i] == NULL)
			Nobles[i] = new Noble;
	}
	return true;
}
bool Table::CreateCard(int lv, int pos)//���ɷ�չ��,lv��coordΪ��ά��������
{
	if (lv > 0 && lv < 3 && pos > 0 && pos < 4)//���������Ч
	{
		OpenCard[lv][pos] = new Card;
		return true;
	}
	else return false;
}
int Table::Operate(Player* player)//����operate������Ϊ�ӿ�,������ҵĲ��������ò�ͬ�ĺ������߽����غ�
{
	//�ӿڣ���ʾ����

	//Ӧ��ѡ��˵�
	/*Take(Players[i]);
	Buy(Players[i]);
	Reserve(Players[i]);
	�Լ������غϵ�ѡ��*/

}
bool Table::Take(Player* player)//������Ӧ��ҵ���Ӧ����,��¼�õĴ����͹�����
{
	//�ӿ�,������ѡ��ı�ʯ��ɫ�Լ�����,��֤������ȡ
	int diamond[6] = { 0 };//����Ҫȡ�ı�ʯ
	//player->TotalDiamonds()��ʾ���ӵ�еı�ʯ��
	player->Take(diamond);
	return true;
	//��������ȡ��ѡ��return false;
}
bool Table::Buy(Player* player, int lv, int pos)//���Ϸ����Ŀ�,�ӿ�,����ս��淵�صĿ��Ķ�ά��������,������Ӧ��ҵ�Buy()
{
	if (player->CanBuy(OpenCard[lv][pos]))//�����������
	{
		player->Buy(OpenCard[lv][pos]);//�Ǿ���
		delete OpenCard[lv][pos];
		CreateCard(lv, pos);
		return true;
	}
	else
	{
		//��Ҫ����������ʾ
		return false;
	}
}
bool Table::Buy(Player* player, int order)//���Լ������Ŀ�,�ӿ�,����ս��淵�ص��ѿ���������������,������Ӧ��ҵ�Buy()
{
	if (player->CanBuy(player->Reserved[order]))//�����������
	{
		player->Buy(player->Reserved[order]);//�Ǿ���
		delete player->Reserved[order];
		player->Reserved[order] = NULL;
		return true;
	}
	else
	{
		//��Ҫ����������ʾ
		return false;
	}
}
bool Table::Reserve(Player* player, int lv, int pos)//�ӿ�,����ս��淵�صĿ��Ķ�ά��������,������Ӧ��ҵ���Ӧ����
{
	if (player->CanReserve())//����Ƿ��ܹ�������
	{
		bool GoldLeft = 0;
		if (Diamonds[Gold] > 0)
			GoldLeft = 1;
		if (player->Reserve(OpenCard[lv][pos], GoldLeft))//�ۿ�
			Diamonds[Gold]--;
		OpenCard[lv][pos] = NULL;
		CreateCard(lv, pos);//�ڸ�λ�����ɷ�չ��
		return true;
	}
	else
	{
		//��Ҫ�����������������ʾ
		return false;
	}
}
int Table::ChooseNoble(Player* player, int* canvisit)//ѡ����嵽��
{
	//�ӿ�,��������ѡ��Ĺ��忨��˳��,����order��Ϊ����ֵ
	while (*canvisit != 0)//�������ݱ�ʾ�����п���ѡ��Ĺ���λ��
	{
		//��ʾ��������ѡ

		//��ѡ��,��return (*canvisit);����������λ��
	}
}
int Table::Round()//�غϽ��к�������ÿ����ҵ���Operate()������֮�������Ӧ�жϲ���
{
	int end = 0;//��ʾ��Ϸ�Ƿ�ﵽ��������
	while (!end)
	{
		for (int i = 0; i < 2; i++)//�������
		{

			Operate(Players[i]);
			//�жϹ���
			int count = 0;//��¼���Ե��õĹ�����
			int CanVisit[3] = { 0 };//�����ѡ������λ��
			for (int j = 0; j < 3; j++)
			{
				if (Nobles[j]->CanVisit(Players[i]))
				{
					CanVisit[count] = j;//�ѹ����λ����Ϣ�浽������
					count++;
				}
			}
			if (count >= 2)//����ѡ�����
				Players[i]->NobleCome(Nobles[ChooseNoble(Players[i], CanVisit)]);
			else //ֻ��һ������,����ѡ��
			{
				for (int j = 0; j < 3; j++)
				{
					if (Nobles[j]->CanVisit(Players[i]))
					{
						Players[i]->NobleCome(Nobles[j]);
						break;
					}
				}
			}
			if (Players[i]->Rep >= 15)
				end = 1;
		}
		//����
	}
	return 1;//��������
}