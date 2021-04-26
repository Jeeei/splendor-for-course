<<<<<<< HEAD:splendor_w/Table1.cpp
#include "Splendor.h"
using namespace std;

//Îå²Ù×÷º¯Êı
Table::Table()
{
	for (int i = 0; i < 3; i++)//¿¨Í·ÈÔĞè½ÓÈëµ½Á´±í
		CardHead[i] = NULL;
	for (int i = 0; i < 3; i++)//³õÊ¼»¯³¡ÉÏ·¢Õ¹¿¨Êı×é
		for (int j = 0; j < 4; j++)
        {
            OpenCard[i][j] = NULL;
            AvailCard[i][j] = 0;
        }
	for (int i = 0; i < 5; i++)//³õÊ¼»¯¹ó×å¿¨Êı×é
    {
        Nobles[i] = NULL;
        AvailNoble[i] = 0;
    }
	for (int i = 0; i < 4; i++)//³õÊ¼»¯Íæ¼ÒÖ¸Õë
    {
        Players[i] = NULL;
        sPlayerImg[i] = "NULL";
    }
    for(int i = 0; i < 6; i++)
    {
        Diamonds[i] = 0;
        TakenDiamond[i] = 0;
    }
    sPlayerNum=2;
    CurrCard[0]=CurrCard[1]=-1;
    CurrMani=None;
    CurrNoble=-1;
    CurrPlayer=NULL;
}
Table::~Table()
{
	for (int i = 0; i < 4; i++)//É¾³ıÍæ¼Ò
	{
		if (Players[i] != NULL)
		{
			delete Players[i];
			Players[i] = NULL;
		}
	}
	for (int i = 0; i < 3; i++)//É¾³ı³¡ÉÏ·¢Õ¹¿¨
		for (int j = 0; j < 4; j++)
		{
			if (OpenCard[i][j] != NULL)
				delete OpenCard[i][j];
		}
	for (int i = 0; i < 3; i++)//É¾³ı¹ó×å¿¨
		delete Nobles[i];
}

QString Table::GetPlayerImg(int playernum)
{
    if(playernum<1 || playernum > sPlayerNum)
        return "NULL";
    return sPlayerImg[playernum - 1]
}

void Table::Avail()
{
	for (int level = 0;level < 3;level++)//^Èç¹ûÓÅ»¯²»Ó¦µ±³öÏÖ²»Ã÷Êı×Ö
	{
		for (int num = 0;num < 4;num++)
		{
			Card* p = OpenCard[level][num];//»ñÈ¡µ±Ç°¿¨Ö¸Õë
			int NeededGold = 0;//ĞèÒªµÄ½ğ±Ò
			//^Ã¶¾ÙÀàĞÍ×Ô¶¨ÒåÔËËã·û/º¯Êı
			for (int i = 0;i < 5;i++)
			{
				if (int r = p->Price[i] - CurrPlayer->Diamonds[i] > 0)//½öÓÃ±¦Ê¯Âò²»Æğ
				{
					NeededGold += r;
				}
			}
			if (NeededGold > CurrPlayer->Diamonds[Gold])//ÕæµÄÂò²»Æğ
				continue;
			AvailCard[level][num] = 1;//¿ÉÂò
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
    int pDiaNum = CurrPlayer->TotalDiamonds();//playerµÄ±¦Ê¯×ÜÊıÄ¿
	if (pDiaNum + 1 > 10)
		return -2;//ERROR2: Player's diamonds FULL!
    int cDiaNum = ShowTakenDiamond();//ÒÑ¾­ÄÃµÄ
	if (pDiaNum + cDiaNum + 1 > 10)
		return -3;//ERROR3: Taken will cause OVERFLOW!
	//ERROR2&3Çø±ğÔÚÓÚ2Ö±½Ó²»¸ø½øÈëTake×´Ì¬£¬3¿É½øÈëTake×´Ì¬µ«ÊÇËùÄÃÊıÁ¿ÏŞÖÆ
	if (cDiaNum + 1 > 3)
		return -4;//ERROR4: Taken is OVERFLOW!
	if (TakenDiamond[co] != 0)
	{
		if (Diamonds[co] < 4)
			return -5;//ERROR3: 2 same color CAN'T taken while surplus under 4!
		if (cDiaNum - TakenDiamond[co])//ÄÃÁËÆäËûÑÕÉ«
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
    if(level < 0 || level > 2 || num < 0 || num > 3)
        return -1;//²»ºÏ·¨µÄÎ»ÖÃ
    if (OpenCard[level][num] == NULL)
        return -2;//Ã»ÅÆÁË
	if (AvailCard[level][num])
		return 1;
	return 0;
}

int Table::CanRetain(int level, int num)
{
    if(level < 0 || level > 2 || num < 0 || num > 3)
        return -1;//²»ºÏ·¨µÄÎ»ÖÃ
    if (OpenCard[level][num] == NULL)
        return -2;//Ã»ÅÆÁË
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
	Card* c = OpenCard[CurrCard[0]][CurrCard[1]];//»ñÈ¡µ±Ç°¿¨Ö¸Õë
	int NeededGold = 0;//ĞèÒªµÄ½ğ±Ò
	//^Ã¶¾ÙÀàĞÍ×Ô¶¨ÒåÔËËã·û/º¯Êı
	for (int i = 0;i < 5;i++)
	{
		if (int r = c->Price[i] - CurrPlayer->GetDiamond(color(i)) > 0)//½öÓÃ±¦Ê¯Âò²»Æğ
		{
			NeededGold += r;
			CurrPlayer->AlterDiamond(color(i), -1, c->Price[i]);//¼õ±¦Ê¯
			//CurrPlayer->Diamonds[i] -= c->Price[i];//ÉÏÃæÄÇ¾ä³öÎÊÌâÓÃÕâ¸ö
		}
	}
	if (NeededGold > CurrPlayer->GetDiamond(Gold))
		return -1;//ERROR1:½ğ±ÒÎª¸º,ÂòÁË²»ºÏ·¨µÄ¿¨
	CurrPlayer->AlterDiamond(Gold, -1, NeededGold);//¼õ½ğ±Ò		
	CurrPlayer->AddRep(c->GetRep());//Ôö¼ÓÉùÍû
	CurrPlayer->Cards[c->GetBonus()]++;//Ôö¼Ó¿¨£¬ÒÔºó¸ÄÎª¼ÇÂ¼¿¨Æ¬ÄÚÈİ
	if (CurrCard[1] < 4)//Îª×ÀÃæµÄ¿¨
        NewCard(CurrCard[0], CurrCard[1]);//²¹×ÀÃæµÄ¿¨
	else
		CurrPlayer->SetReserved(CurrCard[0], NULL);
	return 1;
}
/*
¹ºÂòÊ±Íæ¼ÒÓµÓĞµÄ±¦Ê¯ºìÀûÃ»Ëã½øÈ¥
¼õµôµÄ±¦Ê¯Èç¹û×îºó·¢ÏÖÂò²»Æğ ÓÖÃ»·¨¼Ó»ØÈ¥
*/
int Table::RetainMani()
{
	Card* c = OpenCard[CurrCard[0]][CurrCard[1]];//»ñÈ¡µ±Ç°¿¨Ö¸Õë
	int i;
	for (i = 0;i < 3;i++)
	{
		if(CurrPlayer->GetReserved(i)==NULL)
        {
            CurrPlayer->SetReserved(i, c);//±£Áô
            break;
        }
	}
	if (i >= 3)
		return -1;//ERROR1:Ã»ÓĞ¿ÕµÄ²Û
    NewCard(CurrCard[0], CurrCard[1]);
	return 1;
}

bool Table::IfNoble()//»¹Ã»Ğ´
{

}

void Table::NobleCome(int)//»¹Ã»Ğ´
{

}


//Õ¹Ê¾º¯Êı

bool Table::CreateCard(int lv, int pos)//Éú³É·¢Õ¹¿¨,lvºÍcoordÎª¶şÎ¬Êı×é×ø±ê
{
    if (lv > 0 && lv < 3 && pos > 0 && pos < 4)//¼ì²é×ø±êÓĞĞ§
    {
        OpenCard[lv][pos] = new Card;
        return true;
    }
    else return false;
}

//2.table
QString Table::CardImg(int level, int num)
{
    if(OpenCard[level][num]!=NULL)
        return OpenCard[level][num]->GetAddress();
    return "\0";
}
QString Table::NobleImg(int num)
{
    if(Nobles[num] != NULL)
        return Nobles[num]->GetAddress();
    return "\0";
}
QString Table::PlayerImg(int num)
{
    if(Players[num] != NULL)
        return Players[num]->GetAddress();
    return "\0";
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
		d[i] = -1;//Îª¿Õ
	for (int i = 0;i < length;i++)//ÄÃ±¦Ê¯×î¶àÈı¸ö
	{
		for (int j = 0;j < 6;j++)//ÑÕÉ«
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
	if (CurrCard[1] == 4)//Îª×Ô¼º¿ÛµÄ¿¨
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

int Table::ShowPlayerDiamonds(int color, int p)
{
    if(p == -1)
        return CurrPlayer->ShowDiamond(color);
    return Players[p]->ShowDiamond(color);
}

int Table::ShowRep(int p)
{
    if(p == -1)
        return CurrPlayer->ShowRep();
    return Players[p]->ShowRep();
}

int Table::ShowTakenDiamond() const
{
    int cDiaNum = 0;//ÒÑ¾­ÄÃµÄ
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
=======
#include "Splendor.h"
using namespace std;

//Îå²Ù×÷º¯Êı
Table::Table()
{
	for (int i = 0; i < 3; i++)//¿¨Í·ÈÔĞè½ÓÈëµ½Á´±í
		CardHead[i] = NULL;
	for (int i = 0; i < 3; i++)//³õÊ¼»¯³¡ÉÏ·¢Õ¹¿¨Êı×é
		for (int j = 0; j < 4; j++)
			OpenCard[i][j] = NULL;
	for (int i = 0; i < 5; i++)//³õÊ¼»¯¹ó×å¿¨Êı×é
		Nobles[i] = NULL;
	for (int i = 0; i < 4; i++)//³õÊ¼»¯Íæ¼ÒÖ¸Õë
		Players[i] = NULL;
	Rubbish = NULL;
}
Table::~Table()
{
	for (int i = 0; i < 4; i++)//É¾³ıÍæ¼Ò
	{
		if (Players[i] != NULL)
		{
			delete Players[i];
			Players[i] = NULL;
		}
	}
	for (int i = 0; i < 3; i++)//É¾³ı³¡ÉÏ·¢Õ¹¿¨
		for (int j = 0; j < 4; j++)
		{
			if (OpenCard[i][j] != NULL)
				delete OpenCard[i][j];
		}
	for (int i = 0; i < 3; i++)//É¾³ı¹ó×å¿¨
		delete Nobles[i];
}
void Table::Avail()
{
	for (int level = 0;level < 3;level++)//^Èç¹ûÓÅ»¯²»Ó¦µ±³öÏÖ²»Ã÷Êı×Ö
	{
		for (int num = 0;num < 4;num++)
		{
			Card* p = OpenCard[level][num];//»ñÈ¡µ±Ç°¿¨Ö¸Õë
			int NeededGold = 0;//ĞèÒªµÄ½ğ±Ò
			//^Ã¶¾ÙÀàĞÍ×Ô¶¨ÒåÔËËã·û/º¯Êı
			for (int i = 0;i < 5;i++)
			{
				if (int r = p->Price[i] - CurrPlayer->Diamonds[i] > 0)//½öÓÃ±¦Ê¯Âò²»Æğ
				{
					NeededGold += r;
				}
			}
			if (NeededGold > CurrPlayer->Diamonds[Gold])//ÕæµÄÂò²»Æğ
				continue;
			AvailCard[level][num] = 1;//¿ÉÂò
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
    int pDiaNum = CurrPlayer->TotalDiamonds();//playerµÄ±¦Ê¯×ÜÊıÄ¿
	if (pDiaNum + 1 > 10)
		return -2;//ERROR2: Player's diamonds FULL!
    int cDiaNum = 0;//ÒÑ¾­ÄÃµÄ
    for (int i = 0;i < 6;i++)
        cDiaNum += TakenDiamond[i];
	if (pDiaNum + cDiaNum + 1 > 10)
		return -3;//ERROR3: Taken will cause OVERFLOW!
	//ERROR2&3Çø±ğÔÚÓÚ2Ö±½Ó²»¸ø½øÈëTake×´Ì¬£¬3¿É½øÈëTake×´Ì¬µ«ÊÇËùÄÃÊıÁ¿ÏŞÖÆ
	if (cDiaNum + 1 > 3)
		return -4;//ERROR4: Taken is OVERFLOW!
	if (TakenDiamond[co] != 0)
	{
		if (Diamonds[co] < 4)
			return -5;//ERROR3: 2 same color CAN'T taken while surplus under 4!
		if (cDiaNum - TakenDiamond[co])//ÄÃÁËÆäËûÑÕÉ«
			return -6;//ERROR6: 3 DIFFERENT or 2 SAME color!
	}
	TakenDiamond[co]++;
    return 1;
}

bool Table::CancelTake(color co)
{
    if(TakenDiamond[co]!=0)
    {
        TakenDiamond[co]--;
        return true;
    }
    else return false;
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
	Card* c = OpenCard[CurrCard[0]][CurrCard[1]];//»ñÈ¡µ±Ç°¿¨Ö¸Õë
	int NeededGold = 0;//ĞèÒªµÄ½ğ±Ò
	//^Ã¶¾ÙÀàĞÍ×Ô¶¨ÒåÔËËã·û/º¯Êı
	for (int i = 0;i < 5;i++)
	{
		if (int r = c->Price[i] - CurrPlayer->GetDiamond(color(i)) > 0)//½öÓÃ±¦Ê¯Âò²»Æğ
		{
			NeededGold += r;
			CurrPlayer->AlterDiamond(color(i), -1, c->Price[i]);//¼õ±¦Ê¯
			//CurrPlayer->Diamonds[i] -= c->Price[i];//ÉÏÃæÄÇ¾ä³öÎÊÌâÓÃÕâ¸ö
		}
	}
	if (NeededGold > CurrPlayer->GetDiamond(Gold))
		return -1;//ERROR1:½ğ±ÒÎª¸º,ÂòÁË²»ºÏ·¨µÄ¿¨
	CurrPlayer->AlterDiamond(Gold, -1, NeededGold);//¼õ½ğ±Ò		
	CurrPlayer->AddRep(c->GetRep());//Ôö¼ÓÉùÍû
	CurrPlayer->Cards[c->GetBonus()]++;//Ôö¼Ó¿¨£¬ÒÔºó¸ÄÎª¼ÇÂ¼¿¨Æ¬ÄÚÈİ
	if (CurrCard[1] < 4)//Îª×ÀÃæµÄ¿¨
		NewCard(CurrCard[0], CurrCard[1]);
	else
		CurrPlayer->SetReserved(CurrCard[0], NULL);
	AddRubbish(c);//ÊÕ¼¯Ö¸Õë
	return 1;
}
/*
¹ºÂòÊ±Íæ¼ÒÓµÓĞµÄ±¦Ê¯ºìÀûÃ»Ëã½øÈ¥
¼õµôµÄ±¦Ê¯Èç¹û×îºó·¢ÏÖÂò²»Æğ ÓÖÃ»·¨¼Ó»ØÈ¥
*/
int Table::RetainMani()
{
	Card* c = OpenCard[CurrCard[0]][CurrCard[1]];//»ñÈ¡µ±Ç°¿¨Ö¸Õë
	int i;
	for (i = 0;i < 3;i++)
	{
		if(CurrPlayer->GetReserved(i)==NULL)
			CurrPlayer->SetReserved(i, c);//±£Áô
		break;
	}
	if (i >= 3)
		return -1;//ERROR1:Ã»ÓĞ¿ÕµÄ²Û
	if (CurrCard[1] < 4)//Îª×ÀÃæµÄ¿¨
		NewCard(CurrCard[0], CurrCard[1]);
	else
		return -2;//ERROR2:±£ÁôµÄ²»Îª×ÀÃæµÄ¿¨
	return 1;
}

bool Table::IfNoble()//»¹Ã»Ğ´
{

}

void Table::NobleCome(int)//»¹Ã»Ğ´
{

}


//Õ¹Ê¾º¯Êı
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


bool Table::CreateCard(int lv, int pos)//Éú³É·¢Õ¹¿¨,lvºÍcoordÎª¶şÎ¬Êı×é×ø±ê
{
    if (lv > 0 && lv < 3 && pos > 0 && pos < 4)//¼ì²é×ø±êÓĞĞ§
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
		d[i] = -1;//Îª¿Õ
	for (int i = 0;i < length;i++)//ÄÃ±¦Ê¯×î¶àÈı¸ö
	{
		for (int j = 0;j < 6;j++)//ÑÕÉ«
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
	if (CurrCard[1] == 4)//Îª×Ô¼º¿ÛµÄ¿¨
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

void Table::ClearTakenDiamond()
{
    for(int i=0;i<6;i++)
    {
        TakenDiamond[i]=0;
    }
}
>>>>>>> remotes/origin/main:æ¥å£æœ€æ–°ç‰ˆæœ¬(å·²å®ŒæˆTakeDiamond)/Table1.cpp
