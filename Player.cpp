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
void Player::GetDiamonds(int*p)//返回宝石
{
	for (int i = 0;i < 6;i++)
	{
		p[i] = Diamonds[i];
	}
}
void Player::GetBonus(int*p)//返回玩家拥有的红利数
{
	for (int i = 0;i < 6;i++)
	{
		p[i] = Cards[i];
	}
}
int Player::TotalDiamonds()const//返回玩家拥有全部宝石数
{
	int sum = 0;
	for (int i = 0; i < 6; i++)
		sum += Diamonds[i];
	return sum;
}
bool Player::Take(int* diamond, int l)//拿宝石 传一个在Table.Take()中认定合法的Diamond[6]
{
	for (int i = 0; i < l; i++)
		Diamonds[i] += *(diamond + i);
	return true;
}
bool Player::CanBuy(Card* card)//检查玩家能否买卡
{
	int gold = Diamonds[Gold];
	int* price = new int[6];
	card->GetPrice(price);
	for (int i = 0; i < 5; i++)//五个颜色
	{
		if (Cards[i] >= price[i])//不用宝石就买得起
			continue;
		else if (Diamonds[i] + Cards[i] >= price[i])//不用黄金就买得起
			continue;
		else if (Diamonds[i] + Cards[i] + gold >= price[i])//要用黄金才买得起
			gold -= price[i] - (Diamonds[i] + Cards[i]);
		else return false;
		if (gold < 0)  //买不起啊干
			return false;
	}
	return true;
}
bool Player::Buy(Card* card)//玩家买卡
{
	int* price = new int[6];
	card->GetPrice(price);
	for (int i = 0; i < 5; i++)
	{
		if (Cards[i] >= price[i])//不用宝石就买得起
			continue;
		else if (Diamonds[i] + Cards[i] >= price[i])//不用黄金就买得起
			Diamonds[i] -= price[i] - Cards[i];
		else if (Diamonds[i] + Cards[i] + Diamonds[Gold] >= price[i])//要用黄金才买得起
			Diamonds[Gold] -= price[i] - (Diamonds[i] + Cards[i]);
	}
	Cards[card->GetBonus()]++;
	Rep += card->GetRep();
	return true;
}
bool Player::CanReserve()const//检查玩家能否扣卡
{
	for (int i = 0; i < 3; i++)
	{
		if (Reserved[i] == NULL)
			return true;
	}
	return false;
}
bool Player::Reserve(Card* card, bool goldleft)//玩家扣卡
{
	for (int i = 0; i < 3; i++)
	{
		if (Reserved[i] != NULL)
		{
			Reserved[i] = card;
			if (TotalDiamonds() < 10 && goldleft)//判断玩家能否拿黄金
			{
				Diamonds[Gold]++;
				return true;
			}
			return false;
		}
	}
	
}
int Player::NobleCome(Noble* noble)//贵族到访
{
	for (int i = 0; i < 3; i++)
	{
		if (Nobles[i] == NULL)
		{
			Nobles[i] = noble;
			Rep += noble->GetRep();//增加声望点数
			break;
		}
	}
}