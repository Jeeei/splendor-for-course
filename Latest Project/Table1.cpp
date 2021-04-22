#include "Splendor.h"
using namespace std;

//五操作函数
Table::Table()
{
	for (int i = 0; i < 3; i++)//卡头仍需接入到链表
		CardHead[i] = NULL;
	for (int i = 0; i < 3; i++)//初始化场上发展卡数组
		for (int j = 0; j < 4; j++)
			OpenCard[i][j] = NULL;
	for (int i = 0; i < 5; i++)//初始化贵族卡数组
		Nobles[i] = NULL;
	for (int i = 0; i < 4; i++)//初始化玩家指针
		Players[i] = NULL;
	Rubbish = NULL;
}
Table::~Table()
{
	for (int i = 0; i < 4; i++)//删除玩家
	{
		if (Players[i] != NULL)
		{
			delete Players[i];
			Players[i] = NULL;
		}
	}
	for (int i = 0; i < 3; i++)//删除场上发展卡
		for (int j = 0; j < 4; j++)
		{
			if (OpenCard[i][j] != NULL)
				delete OpenCard[i][j];
		}
	for (int i = 0; i < 3; i++)//删除贵族卡
		delete Nobles[i];
}
void Table::Avail()
{
	for (int level = 0;level < 3;level++)//^如果优化不应当出现不明数字
	{
		for (int num = 0;num < 4;num++)
		{
			Card* p = OpenCard[level][num];//获取当前卡指针
			int NeededGold = 0;//需要的金币
			//^枚举类型自定义运算符/函数
			for (int i = 0;i < 5;i++)
			{
				if (int r = p->Price[i] - CurrPlayer->Diamonds[i] > 0)//仅用宝石买不起
				{
					NeededGold += r;
				}
			}
			if (NeededGold > CurrPlayer->Diamonds[Gold])//真的买不起
				continue;
			AvailCard[level][num] = 1;//可买
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
    int pDiaNum = CurrPlayer->TotalDiamonds();//player的宝石总数目
	if (pDiaNum + 1 > 10)
		return -2;//ERROR2: Player's diamonds FULL!
    int cDiaNum = ShowTakenDiamond();//已经拿的
	if (pDiaNum + cDiaNum + 1 > 10)
		return -3;//ERROR3: Taken will cause OVERFLOW!
	//ERROR2&3区别在于2直接不给进入Take状态，3可进入Take状态但是所拿数量限制
	if (cDiaNum + 1 > 3)
		return -4;//ERROR4: Taken is OVERFLOW!
	if (TakenDiamond[co] != 0)
	{
		if (Diamonds[co] < 4)
			return -5;//ERROR3: 2 same color CAN'T taken while surplus under 4!
		if (cDiaNum - TakenDiamond[co])//拿了其他颜色
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
	Card* c = OpenCard[CurrCard[0]][CurrCard[1]];//获取当前卡指针
	int NeededGold = 0;//需要的金币
	//^枚举类型自定义运算符/函数
	for (int i = 0;i < 5;i++)
	{
		if (int r = c->Price[i] - CurrPlayer->GetDiamond(color(i)) > 0)//仅用宝石买不起
		{
			NeededGold += r;
			CurrPlayer->AlterDiamond(color(i), -1, c->Price[i]);//减宝石
			//CurrPlayer->Diamonds[i] -= c->Price[i];//上面那句出问题用这个
		}
	}
	if (NeededGold > CurrPlayer->GetDiamond(Gold))
		return -1;//ERROR1:金币为负,买了不合法的卡
	CurrPlayer->AlterDiamond(Gold, -1, NeededGold);//减金币		
	CurrPlayer->AddRep(c->GetRep());//增加声望
	CurrPlayer->Cards[c->GetBonus()]++;//增加卡，以后改为记录卡片内容
	if (CurrCard[1] < 4)//为桌面的卡
		NewCard(CurrCard[0], CurrCard[1]);
	else
		CurrPlayer->SetReserved(CurrCard[0], NULL);
	AddRubbish(c);//收集指针
	return 1;
}
/*
购买时玩家拥有的宝石红利没算进去
减掉的宝石如果最后发现买不起 又没法加回去
*/
int Table::RetainMani()
{
	Card* c = OpenCard[CurrCard[0]][CurrCard[1]];//获取当前卡指针
	int i;
	for (i = 0;i < 3;i++)
	{
		if(CurrPlayer->GetReserved(i)==NULL)
			CurrPlayer->SetReserved(i, c);//保留
		break;
	}
	if (i >= 3)
		return -1;//ERROR1:没有空的槽
	if (CurrCard[1] < 4)//为桌面的卡
		NewCard(CurrCard[0], CurrCard[1]);
	else
		return -2;//ERROR2:保留的不为桌面的卡
	return 1;
}

bool Table::IfNoble()//还没写
{

}

void Table::NobleCome(int)//还没写
{

}


//展示函数
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


bool Table::CreateCard(int lv, int pos)//生成发展卡,lv和coord为二维数组坐标
{
    if (lv > 0 && lv < 3 && pos > 0 && pos < 4)//检查坐标有效
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
		d[i] = -1;//为空
	for (int i = 0;i < length;i++)//拿宝石最多三个
	{
		for (int j = 0;j < 6;j++)//颜色
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
	if (CurrCard[1] == 4)//为自己扣的卡
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
    int cDiaNum = 0;//已经拿的
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
