#include "Splendor.h"
using namespace std;
Player::Player()
{
	for (int i = 0; i < 5; i++)
	{
		Nobles[i] = NULL;
	}
	for (int i = 0; i < 3; i++)
	{
		Reserved[i] = NULL;
	}
}
Player::~Player()
{

}
void Player::GetDiamonds(int*p)//���ر�ʯ
{
	for (int i = 0;i < 6;i++)
	{
		p[i] = Diamonds[i];
	}
}
void Player::GetBonus(int*p)//�������ӵ�еĺ�����
{
	for (int i = 0;i < 6;i++)
	{
		p[i] = Cards[i];
	}
}
int Player::TotalDiamonds()const//�������ӵ��ȫ����ʯ��
{
	int sum = 0;
	for (int i = 0; i < 6; i++)
		sum += Diamonds[i];
	return sum;
}
bool Player::Take(int* diamond, int l)//�ñ�ʯ ��һ����Table.Take()���϶��Ϸ���Diamond[6]
{
	for (int i = 0; i < l; i++)
		Diamonds[i] += *(diamond + i);
	return true;
}
bool Player::CanBuy(Card* card)//�������ܷ���
{
	int gold = Diamonds[Gold];
	int* price = new int[6];
	card->GetPrice(price);
	for (int i = 0; i < 5; i++)//�����ɫ
	{
		if (Cards[i] >= price[i])//���ñ�ʯ�������
			continue;
		else if (Diamonds[i] + Cards[i] >= price[i])//���ûƽ�������
			continue;
		else if (Diamonds[i] + Cards[i] + gold >= price[i])//Ҫ�ûƽ�������
			gold -= price[i] - (Diamonds[i] + Cards[i]);
		else return false;
		if (gold < 0)  //���𰡸�
			return false;
	}
	return true;
}
bool Player::Buy(Card* card)//�����
{
	int* price = new int[6];
	card->GetPrice(price);
	for (int i = 0; i < 5; i++)
	{
		if (Cards[i] >= price[i])//���ñ�ʯ�������
			continue;
		else if (Diamonds[i] + Cards[i] >= price[i])//���ûƽ�������
			Diamonds[i] -= price[i] - Cards[i];
		else if (Diamonds[i] + Cards[i] + Diamonds[Gold] >= price[i])//Ҫ�ûƽ�������
			Diamonds[Gold] -= price[i] - (Diamonds[i] + Cards[i]);
	}
	Cards[card->GetBonus()]++;
	Rep += card->GetRep();
	return true;
}
bool Player::CanReserve()const//�������ܷ�ۿ�
{
	for (int i = 0; i < 3; i++)
	{
		if (Reserved[i] == NULL)
			return true;
	}
	return false;
}
bool Player::Reserve(Card* card, bool goldleft)//��ҿۿ�
{
	for (int i = 0; i < 3; i++)
	{
		if (Reserved[i] != NULL)
		{
			Reserved[i] = card;
			if (TotalDiamonds() < 10 && goldleft)//�ж�����ܷ��ûƽ�
			{
				Diamonds[Gold]++;
				return true;
			}
			return false;
		}
	}
	
}
int Player::NobleCome(Noble* noble)//���嵽��
{
	for (int i = 0; i < 3; i++)
	{
		if (Nobles[i] == NULL)
		{
			Nobles[i] = noble;
			Rep += noble->GetRep();//������������
			break;
		}
	}
}