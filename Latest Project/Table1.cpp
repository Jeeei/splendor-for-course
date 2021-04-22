#include "Splendor.h"
using namespace std;

//���������
Table::Table()
{
	for (int i = 0; i < 3; i++)//��ͷ������뵽����
		CardHead[i] = NULL;
	for (int i = 0; i < 3; i++)//��ʼ�����Ϸ�չ������
		for (int j = 0; j < 4; j++)
			OpenCard[i][j] = NULL;
	for (int i = 0; i < 5; i++)//��ʼ�����忨����
		Nobles[i] = NULL;
	for (int i = 0; i < 4; i++)//��ʼ�����ָ��
		Players[i] = NULL;
	Rubbish = NULL;
}
Table::~Table()
{
	for (int i = 0; i < 4; i++)//ɾ�����
	{
		if (Players[i] != NULL)
		{
			delete Players[i];
			Players[i] = NULL;
		}
	}
	for (int i = 0; i < 3; i++)//ɾ�����Ϸ�չ��
		for (int j = 0; j < 4; j++)
		{
			if (OpenCard[i][j] != NULL)
				delete OpenCard[i][j];
		}
	for (int i = 0; i < 3; i++)//ɾ�����忨
		delete Nobles[i];
}
void Table::Avail()
{
	for (int level = 0;level < 3;level++)//^����Ż���Ӧ�����ֲ�������
	{
		for (int num = 0;num < 4;num++)
		{
			Card* p = OpenCard[level][num];//��ȡ��ǰ��ָ��
			int NeededGold = 0;//��Ҫ�Ľ��
			//^ö�������Զ��������/����
			for (int i = 0;i < 5;i++)
			{
				if (int r = p->Price[i] - CurrPlayer->Diamonds[i] > 0)//���ñ�ʯ����
				{
					NeededGold += r;
				}
			}
			if (NeededGold > CurrPlayer->Diamonds[Gold])//�������
				continue;
			AvailCard[level][num] = 1;//����
		}
	}
}

void Table::NoneMani()
{
	AlterMani(None);
	CurrCard[0] = CurrCard[1] = -1;
	for (int i = 0;i < 6;i++)
		TakenDiamond[i] = -1;
}

int Table::CanTake(color co)
{
	if (Diamonds[co] == 0)
		return -1;//ERROR1: This Color ISN'T EXISTED on table!
    int pDiaNum = CurrPlayer->TotalDiamonds();//player�ı�ʯ����Ŀ
	if (pDiaNum + 1 > 10)
		return -2;//ERROR2: Player's diamonds FULL!
    int cDiaNum = ShowTakenDiamond();//�Ѿ��õ�
	if (pDiaNum + cDiaNum + 1 > 10)
		return -3;//ERROR3: Taken will cause OVERFLOW!
	//ERROR2&3��������2ֱ�Ӳ�������Take״̬��3�ɽ���Take״̬����������������
	if (cDiaNum + 1 > 3)
		return -4;//ERROR4: Taken is OVERFLOW!
	if (TakenDiamond[co] != 0)
	{
		if (Diamonds[co] < 4)
			return -5;//ERROR3: 2 same color CAN'T taken while surplus under 4!
		if (cDiaNum - TakenDiamond[co])//����������ɫ
			return -6;//ERROR6: 3 DIFFERENT or 2 SAME color!
	}
	TakenDiamond[co]++;
	return 1;
}

int Table::UnTake(color co)
{
	TakenDiamond[co]--;
	return 1;
}

int Table::CanBuy(int level, int num)
{
	if (AvailCard[level][num])
		return 1;
	return 0;
}

int Table::CanRetain(int level, int num)
{
	for (int i = 0;i < 3;i++)
	{
		if (CurrPlayer->Reserved[i] == NULL)
			return 1;
	}
	return 0;
}

int Table::TakeMani()
{
	for (int i = 0;i < 6;i++)
	{
		CurrPlayer->Diamonds[i] += TakenDiamond[i];	
    }
    ClearTakenDiamond();
	return 1;
}

int Table::BuyMani()
{
	Card* c = OpenCard[CurrCard[0]][CurrCard[1]];//��ȡ��ǰ��ָ��
	int NeededGold = 0;//��Ҫ�Ľ��
	//^ö�������Զ��������/����
	for (int i = 0;i < 5;i++)
	{
		if (int r = c->Price[i] - CurrPlayer->GetDiamond(color(i)) > 0)//���ñ�ʯ����
		{
			NeededGold += r;
			CurrPlayer->AlterDiamond(color(i), -1, c->Price[i]);//����ʯ
			//CurrPlayer->Diamonds[i] -= c->Price[i];//�����Ǿ�����������
		}
	}
	if (NeededGold > CurrPlayer->GetDiamond(Gold))
		return -1;//ERROR1:���Ϊ��,���˲��Ϸ��Ŀ�
	CurrPlayer->AlterDiamond(Gold, -1, NeededGold);//�����		
	CurrPlayer->AddRep(c->GetRep());//��������
	CurrPlayer->Cards[c->GetBonus()]++;//���ӿ����Ժ��Ϊ��¼��Ƭ����
	if (CurrCard[1] < 4)//Ϊ����Ŀ�
		NewCard(CurrCard[0], CurrCard[1]);
	else
		CurrPlayer->SetReserved(CurrCard[0], NULL);
	AddRubbish(c);//�ռ�ָ��
	return 1;
}
/*
����ʱ���ӵ�еı�ʯ����û���ȥ
�����ı�ʯ������������ ��û���ӻ�ȥ
*/
int Table::RetainMani()
{
	Card* c = OpenCard[CurrCard[0]][CurrCard[1]];//��ȡ��ǰ��ָ��
	int i;
	for (i = 0;i < 3;i++)
	{
		if(CurrPlayer->GetReserved(i)==NULL)
			CurrPlayer->SetReserved(i, c);//����
		break;
	}
	if (i >= 3)
		return -1;//ERROR1:û�пյĲ�
	if (CurrCard[1] < 4)//Ϊ����Ŀ�
		NewCard(CurrCard[0], CurrCard[1]);
	else
		return -2;//ERROR2:�����Ĳ�Ϊ����Ŀ�
	return 1;
}

bool Table::IfNoble()//��ûд
{

}

void Table::NobleCome(int)//��ûд
{

}


//չʾ����
void Table::ShowCards(Card*** c, int level, int num)
{
	for (int i = 0;i < level;i++)
	{
		for (int j = 0;j < num;j++)
		{
			c[i][j] = OpenCard[i][j];
		}
    }
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
void Table::ShowNobles(Noble** n, int length)
{
	for (int i = 0;i < length;i++)
	{
		n[i] = Nobles[i];
	}
}

void Table::AvailCardInfo(int** c, int level, int num)
{
	for (int i = 0;i < level;i++)
	{
		for (int j = 0;j < num;j++)
		{
			c[i][j] = AvailCard[i][j];
		}
	}
}

void Table::AvailNobleInfo(int* n, int length)
{
	for (int i = 0;i < length;i++)
	{
		n[i] = AvailNoble[i];
	}
}

void Table::TakenDiamondInfo(int* d, int length)
{
	for (int i = 0;i < length;i++)
		d[i] = -1;//Ϊ��
	for (int i = 0;i < length;i++)//�ñ�ʯ�������
	{
		for (int j = 0;j < 6;j++)//��ɫ
		{
			if (TakenDiamond[j] == 1)
			{
				d[i] = j;
				break;
			}
			if (TakenDiamond[j] == 2)
			{
				d[i] = d[i + 1] = j;
				return;
			}
		}
	}
}

Card* Table::CurrCardInfo()
{
	if (CurrCard[1] == 4)//Ϊ�Լ��۵Ŀ�
	{
		return CurrPlayer->GetReserved(CurrCard[0]);
	}
	return OpenCard[CurrCard[0]][CurrCard[1]];
}

Noble* Table::CurrNobleInfo()
{
    return Nobles[CurrNoble];
}

int Table::ShowDiamonds(int co)
{
    return Diamonds[co];
}

int Table::ShowPlayerDiamonds(int color)
{
    return CurrPlayer->ShowDiamond(color);
}

int Table::ShowTakenDiamond() const
{
    int cDiaNum = 0;//�Ѿ��õ�
    for (int i = 0;i < 6;i++)
        cDiaNum += TakenDiamond[i];
    return cDiaNum;
}

void Table::ClearTakenDiamond()
{
    for(int i=0;i<6;i++)
    {
        TakenDiamond[i]=0;
    }
}
