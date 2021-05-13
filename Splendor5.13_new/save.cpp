#include "Splendor.h"
#include <QDebug>
using namespace std;


ofstream& operator<<(ofstream& fout, Card& c)
{
    QByteArray ba = c.PicAddr.toLatin1();
    char *addr = ba.data();
//    qDebug()<<"Card addr write: "<<addr;
    fout.write(addr, 55);
    fout.write(reinterpret_cast<char*>(&c.Rep), sizeof(c.Rep));
    fout.write(reinterpret_cast<char*>(&c.Bonus), sizeof(c.Bonus));
    for(int i = 0;i < 5; i++)
    {
        fout.write(reinterpret_cast<char*>(&c.Price[i]), sizeof(c.Price[i]));
    }
    return fout;
}

ifstream& operator>>(ifstream& fin, Card& c)
{
    char addr[55];
    fin.read(addr, 55);
    c.PicAddr = QString(QLatin1String(addr));
    qDebug()<<"Card addr read: "<<c.PicAddr;
    fin.read(reinterpret_cast<char*>(&c.Rep), sizeof(c.Rep));
    fin.read(reinterpret_cast<char*>(&c.Bonus), sizeof(c.Bonus));
    for(int i = 0;i < 5; i++)
    {
        fin.read(reinterpret_cast<char*>(&c.Price[i]), sizeof(c.Price[i]));
    }
    return fin;
}

ofstream& operator<<(ofstream& fout, Noble& n)
{
    QByteArray ba = n.PicAddr.toLatin1();
    char *addr = ba.data();
//    qDebug()<<"Noble addr write: "<<addr;
    fout.write(addr, 55);
    fout.write(reinterpret_cast<char*>(&n.Rep), sizeof(n.Rep));
    for(int i = 0;i < 5; i++)
    {
        fout.write(reinterpret_cast<char*>(&n.Condition[i]), sizeof(n.Condition[i]));
    }
    return fout;
}
ifstream& operator>>(ifstream& fin, Noble& n)
{
    char addr[55];
    fin.read(addr, 55);
    n.PicAddr = QString(QLatin1String(addr));
//    qDebug()<<"Noble addr read: "<<addr;
    fin.read(reinterpret_cast<char*>(&n.Rep), sizeof(n.Rep));
    for(int i = 0;i < 5; i++)
    {
        fin.read(reinterpret_cast<char*>(&n.Condition[i]), sizeof(n.Condition[i]));
    }
    return fin;
}

ofstream& operator<<(ofstream& fout, Player& p)
{
    bool ifnull = 0;
    QByteArray ba = p.PicAddr.toLatin1();
    char *addr = ba.data();
//    qDebug()<<"Player addr write: "<<addr;
    fout.write(addr, 55);
    fout.write(reinterpret_cast<char*>(&p.Rep), sizeof(p.Rep));
    for(int i = 0;i < 5; i++)
    {
        fout.write(reinterpret_cast<char*>(&p.Cards[i]), sizeof(p.Cards[i]));
    }
    for(int i = 0;i < 3; i++)
    {
        ifnull = 0;
        if(p.Nobles[i] != nullptr)
        {
            ifnull = 1;
            fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull为1 该位置贵族卡不为空
            fout << *p.Nobles[i];
        }
        else
        {
            fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull为0 该位置贵族卡为空
        }
    }
    for(int i = 0;i < 6; i++)
    {
        fout.write(reinterpret_cast<char*>(&p.Diamonds[i]), sizeof(p.Diamonds[i]));
    }
    for(int i = 0;i < 3; i++)
    {
        ifnull = 0;
        if(p.Reserved[i] != nullptr)
        {
            ifnull = 1;
            fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull为1 该位置卡不为空
            fout << *p.Reserved[i];
        }
        else
        {
            fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull为0 该位置卡为空
        }
    }
    return fout;
}
ifstream& operator>>(ifstream& fin, Player& p)
{
    bool ifnull = 1;
    char addr[55];
    fin.read(addr, 55);
    p.PicAddr = QString(QLatin1String(addr));
    fin.read(reinterpret_cast<char*>(&p.Rep), sizeof(p.Rep));
    for(int i = 0;i < 5; i++)
    {
        fin.read(reinterpret_cast<char*>(&p.Cards[i]), sizeof(p.Cards[i]));
    }
    for(int i = 0;i < 3; i++)
    {
        fin.read(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));
        if(ifnull)//ifnull为1 该位置贵族卡不为空
        {
            p.Nobles[i] = new Noble;
            fin >> *p.Nobles[i];
        }
        else continue;//ifnull为0 该位置贵族卡为空
    }
    for(int i = 0;i < 6; i++)
    {
        fin.read(reinterpret_cast<char*>(&p.Diamonds[i]), sizeof(p.Diamonds[i]));
    }
    for(int i = 0;i < 3; i++)
    {
        fin.read(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));
        if(ifnull)//ifnull为1 该位置卡不为空
        {
            p.Reserved[i] = new Card;
            fin >> *p.Reserved[i];
        }
        else continue;//ifnull为0 该位置卡为空
    }
    return fin;
}

ofstream& operator<<(ofstream& fout, Table& p)
{
    bool ifnull = 0;
    for(int i = 0;i < 3;i++)
    {
        Card* c = p.CardHead[i];
        while(c != nullptr)
        {
            ifnull = 1;
            fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull为1 未到链表尾部
            fout << *c;
            c = c->next;
        }
        ifnull = 0;
        fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull为0 到达链表尾部
    }
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            if(p.OpenCard[i][j] != nullptr)
            {
                ifnull = 1;
                fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull为1 该位置不为空
                fout << *p.OpenCard[i][j];
            }
            else
            {
                ifnull = 0;
                fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull为0 该位置为空
            }
        }
    }
    for(int i = 0;i < 3;i++)
    {
        ifnull = 0;
        if(p.Nobles[i] != nullptr)
        {
            ifnull = 1;
            fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull为1 该位置贵族卡不为空
            fout << *p.Nobles[i];
        }
        else fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull为0 该位置贵族卡为空
    }
    ifnull = 0;
    for(int i = 0;i < 6; i++)
    {
        fout.write(reinterpret_cast<char*>(&p.Diamonds[i]), sizeof(p.Diamonds[i]));
    }
    fout.write(reinterpret_cast<char*>(&p.PlayerNum), sizeof(p.PlayerNum));
    for(int i = 0;i < p.PlayerNum; i++)
    {
        fout << *p.Players[i];
    }
    fout.write(reinterpret_cast<char*>(&p.Status), sizeof(p.Status));
    for(int i = 0; i < p.PlayerNum; i++)
    {
        if(p.CurrPlayer == p.Players[i])
        {
            fout.write(reinterpret_cast<char*>(&i), sizeof(i));//储存CurrPlayer位置信息
        }
    }
    fout.write(reinterpret_cast<char*>(&p.CurrMani), sizeof(p.CurrMani));
    //不需要，加载的时候重新算一遍就行
//    fout.write(reinterpret_cast<char*>(&p.AvailCard), sizeof(p.AvailCard));
//    fout.write(reinterpret_cast<char*>(&p.AvailNoble), sizeof(p.AvailNoble));
    for(int i = 0;i < 5; i++)
    {
        fout.write(reinterpret_cast<char*>(&p.TakenDiamond[i]), sizeof(p.TakenDiamond[i]));
    }
    return fout;
}
ifstream& operator>>(ifstream& fin, Table& p)
{
    bool ifnull = 1;
    for(int i = 0;i < 3;i++)
    {
        fin.read(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));
        Card *c = new Card;
        if(!ifnull)
        {
            delete c;
            c = nullptr;
        }
        p.CardHead[i] = c;
        fin >> *c;
        fin.read(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));
        while(ifnull)//ifnull为1 未到链表尾部
        {
            c->next = new Card;
            c = c->next;
            fin >> *c;
            qDebug()<<"Cardhead "<<i<<": "<<c;
            fin.read(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));
        }
        c = nullptr;//ifnull为0 到达链表尾部
    }
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            fin.read(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));
            if(ifnull)//ifnull为1 该位置卡不为空
            {
                p.OpenCard[i][j] = new Card;
                fin >> *p.OpenCard[i][j];
            }
            else continue;//ifnull为0 该位置卡为空
        }
    }
    for(int i = 0;i < 3;i++)
    {
        fin.read(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));
        if(ifnull)//ifnull为1 该位置贵族卡不为空
        {
            p.Nobles[i] = new Noble;
            fin >> *p.Nobles[i];
        }
        else continue;//ifnull为0 该位置贵族卡为空
    }
    for(int i = 0;i < 6; i++)
    {
        fin.read(reinterpret_cast<char*>(&p.Diamonds[i]), sizeof(p.Diamonds[i]));
    }
    fin.read(reinterpret_cast<char*>(&p.PlayerNum), sizeof(p.PlayerNum));
    for(int i = 0;i < p.PlayerNum; i++)
    {
        p.Players[i] = new Player;
        fin >> *p.Players[i];
    }
    fin.read(reinterpret_cast<char*>(&p.Status), sizeof(p.Status));
    int i = 0;
    fin.read(reinterpret_cast<char*>(&i), sizeof(i));//读取CurrPlayer位置信息
    p.CurrPlayer = p.Players[i];
    fin.read(reinterpret_cast<char*>(&p.CurrMani), sizeof(p.CurrMani));
    for(int i = 0;i < 5; i++)
    {
        fin.read(reinterpret_cast<char*>(&p.TakenDiamond[i]), sizeof(p.TakenDiamond[i]));
    }
    p.Avail();
    return fin;
}

bool Table::IfSaved()
{
    //只读模式打开文件， 如果文件不存在，不会创建
    ifstream c("Saved.dat", ios::in | ios::binary);
    if(!c.is_open())
        return false;
    else
    {
        c.close();
        return true;
    }
}

bool Table::Save()
{
    //只写模式打开文件，如果文件不存在，可以创建文件
    ofstream c("Saved.dat", ios::out | ios::binary | ios::trunc);
    c<<*this;
    c.close();
    return true;
}

bool Table::SaveBeginning()
{
    ofstream c("Saved1.dat", ios::out | ios::binary | ios::trunc);
    c<<*this;
    c.close();
    return true;
}

bool Table::TryAgain()//重开这局游戏
{
    ifstream c("Saved1.dat", ios::in | ios::binary);
    if(!c.is_open())
        return false;
    c>>*this;
    c.close();
    return true;
}

bool Table::Load()
{
    if(!IfSaved())
        return -1;//ERROR 1:没有保存文件
    ifstream c("Saved.dat", ios::in | ios::binary);
    if(!c.is_open())
        return false;
    c>>*this;
    c.close();
    DeleteFileA("Saved.dat");//加载后清掉 Deletefile()由字符集决定选择A/W
    return true;
}
