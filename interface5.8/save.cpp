#include "Splendor.h"

using namespace std;


ofstream& operator<<(ofstream& fout, Card& c)
{
    fout.write(reinterpret_cast<char*>(&c.PicAddr), sizeof(c.PicAddr));
    fout.write(reinterpret_cast<char*>(&c.Rep), sizeof(c.Rep));
    fout.write(reinterpret_cast<char*>(&c.Bonus), sizeof(c.Bonus));
    fout.write(reinterpret_cast<char*>(&c.Price), sizeof(c.Price));
    fout.write(reinterpret_cast<char*>(&c.next), sizeof(c.next));
    return fout;
}
ifstream& operator>>(ifstream& fin, Card& c)
{
    fin.read(reinterpret_cast<char*>(&c.PicAddr), sizeof(c.PicAddr));
    fin.read(reinterpret_cast<char*>(&c.Rep), sizeof(c.Rep));
    fin.read(reinterpret_cast<char*>(&c.Bonus), sizeof(c.Bonus));
    fin.read(reinterpret_cast<char*>(&c.Price), sizeof(c.Price));
    fin.read(reinterpret_cast<char*>(&c.next), sizeof(c.next));
    return fin;
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

ofstream& operator<<(ofstream& fout, Player& p)
{
    fout.write(reinterpret_cast<char*>(&p.PicAddr), sizeof(p.PicAddr));
    fout.write(reinterpret_cast<char*>(&p.Rep), sizeof(p.Rep));
    fout.write(reinterpret_cast<char*>(&p.Cards), sizeof(p.Cards));
    fout.write(reinterpret_cast<char*>(&p.Nobles), sizeof(p.Nobles));
    fout.write(reinterpret_cast<char*>(&p.Diamonds), sizeof(p.Diamonds));
    fout.write(reinterpret_cast<char*>(&p.Reserved), sizeof(p.Reserved));
    fout.write(reinterpret_cast<char*>(&p.no), sizeof(p.no));
    return fout;
}
ifstream& operator>>(ifstream& fin, Player& p)
{
    fin.read(reinterpret_cast<char*>(&p.PicAddr), sizeof(p.PicAddr));
    fin.read(reinterpret_cast<char*>(&p.Rep), sizeof(p.Rep));
    fin.read(reinterpret_cast<char*>(&p.Cards), sizeof(p.Cards));
    fin.read(reinterpret_cast<char*>(&p.Nobles), sizeof(p.Nobles));
    fin.read(reinterpret_cast<char*>(&p.Diamonds), sizeof(p.Diamonds));
    fin.read(reinterpret_cast<char*>(&p.Reserved), sizeof(p.Reserved));
    fin.read(reinterpret_cast<char*>(&p.no), sizeof(p.no));
    return fin;
}

ofstream& operator<<(ofstream& fout, Table& p)
{
    fout.write(reinterpret_cast<char*>(&p.CardHead), sizeof(p.CardHead));
    fout.write(reinterpret_cast<char*>(&p.OpenCard), sizeof(p.OpenCard));
    fout.write(reinterpret_cast<char*>(&p.Nobles), sizeof(p.Nobles));
    fout.write(reinterpret_cast<char*>(&p.Diamonds), sizeof(p.Diamonds));
    fout.write(reinterpret_cast<char*>(&p.Players), sizeof(p.Players));
    fout.write(reinterpret_cast<char*>(&p.PlayerNum), sizeof(p.PlayerNum));
    fout.write(reinterpret_cast<char*>(&p.Status), sizeof(p.Status));
    fout.write(reinterpret_cast<char*>(&p.CurrPlayer), sizeof(p.CurrPlayer));
    fout.write(reinterpret_cast<char*>(&p.CurrMani), sizeof(p.CurrMani));
    fout.write(reinterpret_cast<char*>(&p.CurrNoble), sizeof(p.CurrNoble));
    fout.write(reinterpret_cast<char*>(&p.AvailNoble), sizeof(p.AvailNoble));
    fout.write(reinterpret_cast<char*>(&p.CurrCard), sizeof(p.CurrCard));
    fout.write(reinterpret_cast<char*>(&p.AvailCard), sizeof(p.AvailCard));
    fout.write(reinterpret_cast<char*>(&p.TakenDiamond), sizeof(p.TakenDiamond));
    return fout;
}
ifstream& operator>>(ifstream& fin, Table& p)
{
    fin.read(reinterpret_cast<char*>(&p.CardHead), sizeof(p.CardHead));
    fin.read(reinterpret_cast<char*>(&p.OpenCard), sizeof(p.OpenCard));
    fin.read(reinterpret_cast<char*>(&p.Nobles), sizeof(p.Nobles));
    fin.read(reinterpret_cast<char*>(&p.Diamonds), sizeof(p.Diamonds));
    fin.read(reinterpret_cast<char*>(&p.Players), sizeof(p.Players));
    fin.read(reinterpret_cast<char*>(&p.PlayerNum), sizeof(p.PlayerNum));
    fin.read(reinterpret_cast<char*>(&p.Status), sizeof(p.Status));
    fin.read(reinterpret_cast<char*>(&p.CurrPlayer), sizeof(p.CurrPlayer));
    fin.read(reinterpret_cast<char*>(&p.CurrMani), sizeof(p.CurrMani));
    fin.read(reinterpret_cast<char*>(&p.CurrNoble), sizeof(p.CurrNoble));
    fin.read(reinterpret_cast<char*>(&p.AvailNoble), sizeof(p.AvailNoble));
    fin.read(reinterpret_cast<char*>(&p.CurrCard), sizeof(p.CurrCard));
    fin.read(reinterpret_cast<char*>(&p.AvailCard), sizeof(p.AvailCard));
    fin.read(reinterpret_cast<char*>(&p.TakenDiamond), sizeof(p.TakenDiamond));
    return fin;
}

bool Table::IfSaved()
{
    //只读模式打开文件， 如果文件不存在，不会创建
    ifstream c("Saved.dat", ios::in | ios::binary);
    if(!c.is_open())
        return false;
    c.close();
    return true;
}

bool Table::Save()
{
    //只写模式打开文件，如果文件不存在，可以创建文件
    ofstream c("Saved.dat", ios::out | ios::binary | ios::trunc);
    c<<*this;
    c.close();
    return true;
}

bool Table::Load()
{
    if(!IfSaved())
        return -1;//ERROR 1:没有保存文件
    ifstream c("Saved.dat", ios::in | ios::binary);
    c>>*this;
    c.close();
    DeleteFileA("Saved.dat");//加载后清掉 Deletefile()由字符集决定选择A/W
    return true;
}
