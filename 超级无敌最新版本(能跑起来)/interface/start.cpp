#include "Splendor.h"
using namespace std;
/*
 * 所有的初始化函数写在这里了
 * 所有带""的地方估计都要重整，特别是Player+序号的地方
 * 还差一个Role.dat文件用于储存玩家头像合集
 * 默认了Role.dat为10个QString组成，要改动数量则Get/AlterPlayerPic函数循环判断要改
 */

bool Table::AlterPlayerNum(int a)
{
    if(a==1 && sPlayerNum<4)
    {
        sPlayerNum++;
        sPlayers[sPlayerNum-1]->Name="Player"+(sPlayerNum-1);//不知道可不可以这么用
        AlterPlayerPic(sPlayerNum-1);//保证新加player图片不重复
        return true;
    }
    else if (a==-1 && sPlayerNum>2)
    {
        sPlayerNum--;
        return true;
    }
    return false;
}
QString Table::GetPlayerPic(int no)
{
    ifstream c("Role.dat", ios::in | ios::binary);
    QString pics[10];
//    seekg(sizeof(QString)*(sPlayersPic[no-1]),ios::beg);//表示从文件begin位置开始偏移
//    c>>pics[i];
    for(int i=0;i<10;i++)//采用全部读出来的办法，前文偏移读出还没试过可不可以用
    {
        c>>pics[i];
    }
    if(sPlayersPic[no]<10)//在pic范围内
        return pics[sPlayersPic[no-1]];
    return "NULL";
}
void Table::AlterPlayerPic(int no)//将第no（1-4）个player的头像切换为下一个（注意不能重复）
{
    int next=sPlayersPic[no-1];
    while(true)
    {
        next=(next+1)%10;
        for (int i=0;i<sPlayerNum;i++)
        {
            if(next!=sPlayersPic[i])//不和其他玩家重复
            {
                sPlayersPic[no-1]=next;
                return;
            }
        }
    }
}
void Table::AlterRandom()//被改为随机后生成次序，改为设定后玩家1为先手
{
    RandomFirst=!RandomFirst;
    if(RandomFirst)
    {
        srand(time(0));
        FirstPlayer=rand()%sPlayerNum+1;
    }
    else {
        FirstPlayer=1;
    }
}


void Table::InitSelect()//给玩家初始设置头像名字
{
    for (int i=0;i<4;i++)
    {
        sPlayersPic[i]=i;//初始设置头像
        sPlayers[i]=new Player;
        sPlayers[i]->Name="Player"+('0'+(i+1));//又不知道可不可以这么写
    }
}

bool Table::Start()
{
    PlayerNum = sPlayerNum;//确定玩家人数 //sPlayer在构造函数初始化为2
    for(int i=0;i<sPlayerNum;i++)//确定玩家
    {
        Players[i]=sPlayers[(FirstPlayer-1+i)%sPlayerNum];
        Players[i]->PicAddr=GetPlayerPic(i+1);//将暂存图片序号转为地址后存入
    }
    for(int i=0;i<4;i++)//清除内存
    {
        delete sPlayers[i];
    }
    CurrPlayer = Players[0];

//    for (int i = 0;i<PlayerNum;i++)
//    {
//     Players[i]->SetImg(sPlayerImg[i]);
//    }
    //Players[0]->SetImg("border-image:url(:/images/bbb.png)");//强制给玩家设置头像
    //Players[1]->SetImg("border-image:url(:/images/black.PNG)");
    Init();
    return true;
}

bool Table::Init()
{
    for(int i = 0; i < 6; i++)//初始化宝石数
    {
        Diamonds[i] = 5;
    }
    CreateCard();//生成卡链表
    AlterStatus(Playing);
    //CreateNoble();

    //先有卡再有Avail
    Avail();//初始化AvailCard数组和AvailNoble数组
    return true;
}
