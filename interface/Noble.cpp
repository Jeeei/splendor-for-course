#include "Splendor.h"
using namespace std;
Noble::Noble()
{
    PicAddr = "NULL";
    Rep=0;
    for(int i=0;i<6;i++)
        Condition[i]=0;
}
Noble::Noble(QString s, int rep, int* con)
{
    PicAddr = s;
    Rep = rep;
    for (int i = 0; i < 5; i++)
        Condition[i] = *(con + i);
}
int Noble::GetRep()const//显示声望点数
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

bool Noble::CanVisit(Player* player)//检查能否访问玩家
{
    for (int i = 0; i < 5; i++)
    {
        if (player->GetBonus(color(i)) < Condition[i])
            return false;
    }
    return true;
}

