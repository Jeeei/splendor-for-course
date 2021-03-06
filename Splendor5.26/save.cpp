#include "Splendor.h"
#include <QDebug>
#include <QTextCodec>
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
    //qDebug()<<"Card addr read: "<<c.PicAddr;
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
    fout.write(addr, 55);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QByteArray ba1 = p.Name.toLocal8Bit();
    char *addr1 = ba1.data();
    fout.write(addr1, 20);
    //qDebug()<<addr1;

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
            fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull???1 ???????????????????????????
            fout << *p.Nobles[i];
        }
        else
        {
            fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull???0 ????????????????????????
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
            fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull???1 ?????????????????????
            fout << *p.Reserved[i];
        }
        else
        {
            fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull???0 ??????????????????
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
    //qDebug()<<p.PicAddr;

    char addr1[20];
    fin.read(addr1, 20);
    p.Name = QString::fromLocal8Bit(addr1);
    //qDebug()<<p.Name;

    fin.read(reinterpret_cast<char*>(&p.Rep), sizeof(p.Rep));
    for(int i = 0;i < 5; i++)
    {
        fin.read(reinterpret_cast<char*>(&p.Cards[i]), sizeof(p.Cards[i]));
    }
    for(int i = 0;i < 3; i++)
    {
        fin.read(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));
        if(ifnull)//ifnull???1 ???????????????????????????
        {
            p.Nobles[i] = new Noble;
            fin >> *p.Nobles[i];
        }
        else continue;//ifnull???0 ????????????????????????
    }
    for(int i = 0;i < 6; i++)
    {
        fin.read(reinterpret_cast<char*>(&p.Diamonds[i]), sizeof(p.Diamonds[i]));
    }
    for(int i = 0;i < 3; i++)
    {
        fin.read(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));
        if(ifnull)//ifnull???1 ?????????????????????
        {
            p.Reserved[i] = new Card;
            fin >> *p.Reserved[i];
        }
        else continue;//ifnull???0 ??????????????????
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
            fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull???1 ??????????????????
            fout << *c;
            c = c->next;
        }
        ifnull = 0;
        fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull???0 ??????????????????
    }
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            if(p.OpenCard[i][j] != nullptr)
            {
                ifnull = 1;
                fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull???1 ??????????????????
                fout << *p.OpenCard[i][j];
            }
            else
            {
                ifnull = 0;
                fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull???0 ???????????????
            }
        }
    }
    for(int i = 0;i < 3;i++)
    {
        ifnull = 0;
        if(p.Nobles[i] != nullptr)
        {
            ifnull = 1;
            fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull???1 ???????????????????????????
            fout << *p.Nobles[i];
        }
        else fout.write(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));//ifnull???0 ????????????????????????
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
            fout.write(reinterpret_cast<char*>(&i), sizeof(i));//??????CurrPlayer????????????
        }
    }
    fout.write(reinterpret_cast<char*>(&p.CurrMani), sizeof(p.CurrMani));
    //????????????????????????????????????????????????
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
        while(ifnull)//ifnull???1 ??????????????????
        {
            c->next = new Card;
            c = c->next;
            fin >> *c;
            qDebug()<<"Cardhead "<<i<<": "<<c;
            fin.read(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));
        }
        c = nullptr;//ifnull???0 ??????????????????
    }
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            fin.read(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));
            if(ifnull)//ifnull???1 ?????????????????????
            {
                p.OpenCard[i][j] = new Card;
                fin >> *p.OpenCard[i][j];
            }
            else continue;//ifnull???0 ??????????????????
        }
    }
    for(int i = 0;i < 3;i++)
    {
        fin.read(reinterpret_cast<char*>(&ifnull), sizeof(ifnull));
        if(ifnull)//ifnull???1 ???????????????????????????
        {
            p.Nobles[i] = new Noble;
            fin >> *p.Nobles[i];
        }
        else continue;//ifnull???0 ????????????????????????
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
    fin.read(reinterpret_cast<char*>(&i), sizeof(i));//??????CurrPlayer????????????
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
    //??????????????????????????? ????????????????????????????????????
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
    //?????????????????????????????????????????????????????????????????????
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

bool Table::TryAgain()//??????????????????
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
        return -1;//ERROR 1:??????????????????
    ifstream c("Saved.dat", ios::in | ios::binary);
    if(!c.is_open())
        return false;
    c>>*this;
    c.close();
    DeleteFileA("Saved.dat");//??????????????? Deletefile()????????????????????????A/W
    return true;
}
