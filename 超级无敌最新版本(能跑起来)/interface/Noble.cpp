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
    int* p = new int[6];
    player->GetBonus(p);
    for (int i = 0; i < 5; i++)
    {
        if (p[i] < Condition[i])
            return false;
    }
    return true;
}


ofstream& operator<<(ofstream& fout, Noble& n)
{
     fout.write(reinterpret_cast<char*>(&n.PicAddr), sizeof(n.PicAddr));
     fout.write(reinterpret_cast<char*>(&n.Rep), sizeof(n.Rep));
     fout.write(reinterpret_cast<char*>(&n.Condition), sizeof(n.Condition));
     return fout;
}
ifstream& operator>>(ifstream& fin, Noble& n)
{
    fin.read(reinterpret_cast<char*>(&n.PicAddr), sizeof(n.PicAddr));
    fin.read(reinterpret_cast<char*>(&n.Rep), sizeof(n.Rep));
    fin.read(reinterpret_cast<char*>(&n.Condition), sizeof(n.Condition));
    return fin;
}
