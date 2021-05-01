#include "Splendor.h"
#include <ctime>
#include <QDebug>
using namespace std;

//���������
Table::Table()
{
    for (int i = 0; i < 3; i++)//��ͷ������뵽����
        CardHead[i] = nullptr;
    for (int i = 0; i < 3; i++)//��ʼ�����Ϸ�չ������
        for (int j = 0; j < 4; j++)
        {
            OpenCard[i][j] = nullptr;
            AvailCard[i][j] = 0;
        }
    for (int i = 0; i < 5; i++)//��ʼ�����忨����
    {
        Nobles[i] = nullptr;
        AvailNoble[i] = 0;
    }
    for (int i = 0; i < 4; i++)//��ʼ�����ָ��
    {
        Players[i] = nullptr;
        sPlayerImg[i] = "NULL";
    }
    for(int i = 0; i < 6; i++)
    {
        Diamonds[i] = 0;
        TakenDiamond[i] = 0;
    }
    sPlayerNum = 2;//�������Ϊ2
    SetCurrCard(-1,-1);
    AlterMani(None);
    SetCurrNoble(-1);
    CurrPlayer = nullptr;
    Status = Selecting;
    //qDebug()<<"Table created."<<endl;
}
Table::~Table()
{
    //qDebug()<<"Table deleted."<<endl;
    for (int i = 0; i < 4; i++)//ɾ�����
    {
        if (Players[i] != nullptr)
        {
            delete Players[i];
            Players[i] = nullptr;
        }
    }
    for (int i = 0; i < 3; i++)//ɾ�����Ϸ�չ��
        for (int j = 0; j < 4; j++)
        {
            if (OpenCard[i][j] != nullptr)
                delete OpenCard[i][j];
        }
    for (int i = 0; i < 3; i++)//ɾ�����忨
    {
        if(Nobles[i] != nullptr)
        {
            delete Nobles[i];
            Nobles[i] = nullptr;
        }
    }
    for (int i = 0; i < 3; i++)//ɾ�����ɵĿ�����
    {
        Card* temp;
        while(CardHead[i] != nullptr)
        {
            //qDebug()<<"deleting"<<CardHead[i]->Rep<<" "<<CardHead[i]->Bonus<<" "<<CardHead[i];
            temp = CardHead[i];
            CardHead[i] = CardHead[i]-> next;
            delete temp;
        }
    }
}

bool Table::Start()
{
    PlayerNum = sPlayerNum;//ȷ��������� //sPlayer�ڹ��캯����ʼ��Ϊ2
    for(int i = 0;i < PlayerNum;i++)
    {
        Players[i] = new Player;
    }
    CurrPlayer = Players[0];//���ָ���

//    for (int i = 0;i<PlayerNum;i++)
//    {
//     Players[i]->SetImg(sPlayerImg[i]);
//    }
    //Players[0]->SetImg("border-image:url(:/images/bbb.png)");//ǿ�Ƹ��������ͷ��
    //Players[1]->SetImg("border-image:url(:/images/black.PNG)");
    Init();
    return true;
}

bool Table::Init()
{
    for(int i = 0; i < 6; i++)//��ʼ����ʯ��
    {
        Diamonds[i] = 5;
    }
    CreateCard();//���ɿ�����
    AlterStatus(Playing);
    //CreateNoble();

    //���п�����Avail
    Avail();//��ʼ��AvailCard�����AvailNoble����
    return true;
}

QString Table::GetPlayerImg(int playernum)
{
    if(playernum < 1 || playernum > sPlayerNum)
        return "NULL";
    return sPlayerImg[playernum - 1];
}

void Table::Avail()//�ж������ϵ�ǰ��ҿɹ���Ŀ� �Լ����԰ݷõĹ���
{
    for (int level = 0;level < 3;level++)//^����Ż���Ӧ�����ֲ�������
    {
        for (int num = 0; num < 4; num++)
        {
            Card* p = OpenCard[level][num];//��ȡ��ǰ��ָ��
            if(CurrPlayer->CanBuy(p))
                AvailCard[level][num] = 1;//����
            else AvailCard[level][num] = 0;//������
        }
    }
//    for (int i = 0; i < 5; i++)//�������忨����
//    {
//        if(Nobles[i]->CanVisit(CurrPlayer))
//            AvailNoble[i] = 1;
//        else AvailNoble[i] = 0;
//    }
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
    int cDiaNum = 0;//�Ѿ��õ�
    for (int i = 0;i < 6;i++)
        cDiaNum += TakenDiamond[i];
    //qDebug()<<"Taken num:"<<cDiaNum<<endl;
    if (pDiaNum + cDiaNum + 1 > 10)
        return -3;//ERROR3: Taken will cause OVERFLOW!
    //ERROR2&3��������2ֱ�Ӳ�������Take״̬��3�ɽ���Take״̬����������������
    if (cDiaNum + 1 > 3)
        return -4;//ERROR4: Taken is OVERFLOW!
    if (TakenDiamond[co] != 0)
    {
        if (Diamonds[co] < 3)
            return -5;//ERROR5: 2 same color CAN'T taken while surplus under 4!
        if (cDiaNum - TakenDiamond[co] || TakenDiamond[co] >= 2)
            return -6;//ERROR6: 3 DIFFERENT or 2 SAME color!
    }
    for(int i = 0;i < 6;i++)
    {
        if((i != co)&&TakenDiamond[i]>=2)//����������ɫ
            return -7;//ERROR7: 2 SAME color and 1 different color!
    }
    //qDebug()<<"taken add from table.";
    TakenDiamond[co]++;
    Diamonds[co]--;
    return 1;
}

int Table::UnTake(color co)
{
    if(TakenDiamond[co] > 0)
    {
        //qDebug()<<"taken minus from table.";
        TakenDiamond[co]--;
        Diamonds[co]++;
        return true;
    }
    else return false;
}

bool Table::CanBuy()
{
    return AvailCard[CurrCard[0]][CurrCard[1]];
}

int Table::CanRetain(int level, int num)
{
    if(level < 0 || level > 2 || num < 0 || num > 3)
        return -1;//���Ϸ���λ��
    if (OpenCard[level][num] == nullptr)
        return -2;//û����
    for (int i = 0;i < 3;i++)
    {
        if (CurrPlayer->Reserved[i] == nullptr)
            return 1;
    }
    return 0;
}

int Table::TakeMani()
{
    for (int i = 0;i < 6;i++)
    {
        CurrPlayer->Diamonds[i] += TakenDiamond[i];
        TakenDiamond[i] = 0;
    }
    return 1;
}

int Table::BuyMani()//����������²ŵ���
{
    Card* c = OpenCard[CurrCard[0]][CurrCard[1]];//��ȡ��ǰ��ָ��
    CurrPlayer->Buy(c);
    for (int i = 0; i < 5; i++)//����ʯ��table
    {
        if (CurrPlayer->Cards[i] >= c->Price[i])//���ñ�ʯ�������
            continue;
        else if (Diamonds[i] + CurrPlayer->Cards[i] >= c->Price[i])//���ûƽ�������
            Diamonds[i] += c->Price[i] - CurrPlayer->Cards[i];
        else if (Diamonds[i] + CurrPlayer->Cards[i] + Diamonds[Gold] >= c->Price[i])//Ҫ�ûƽ�������
            Diamonds[Gold] += c->Price[i] - (Diamonds[i] + CurrPlayer->Cards[i]);
    }
    if (CurrCard[1] < 4)//Ϊ����Ŀ�
        NewCard(CurrCard[0], CurrCard[1]);//������Ŀ�
    else
        CurrPlayer->SetReserved(CurrCard[0], nullptr);
    return 1;
}

int Table::RetainMani()
{
    Card* c = OpenCard[CurrCard[0]][CurrCard[1]];//��ȡ��ǰ��ָ��
    int i;
    for (i = 0;i < 3;i++)
    {
        if(CurrPlayer->GetReserved(i) == nullptr)
        {
            CurrPlayer->SetReserved(i, c);//����
            break;
        }
    }
    if (i >= 3)
        return -1;//ERROR1:û�пյĲ�
    if (CurrCard[1] < 4)//Ϊ����Ŀ�
        NewCard(CurrCard[0], CurrCard[1]);
    else
        return -2;//ERROR2:�����Ĳ�Ϊ����Ŀ�
    return 1;
}

int Table::IfNoble()//�ж��Ƿ���Ҫѡ�����
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        if(AvailNoble[i])
            count++;
    }
    if(count > 1)//��Ҫѡ��
        return 1;
    else if(count == 1)//����Ҫѡ,ֱ�Ӱݷ�
        return 0;
    else return -1;//û��ѡ,��
}

void Table::NobleCome(int num)//����ݷ�
{
    if(num >= 0 && num <= 4)
        if(AvailNoble[num])
            CurrPlayer->NobleCome(Nobles[num]);
}

void Table::Next()//�������,�غϽ���,�л���һ�����
{
//    //����Ƿ��й���ݷ�
//    switch(IfNoble())
//    {
//    case 1:
//        //ѡ����尡
//        break;
//    case 0:
//        for (int i = 0; i < 5; i++)
//        {
//            if(AvailNoble[i])
//            {
//                NobleCome(i);//ֱ�Ӱݷ�,Ҳ����Ҫ����ʲô��
//                break;
//            }
//        }
//        break;
//    case -1://û��ѡ
//    default:
//        break;
//    }
//    //�غ���������
    for(int i=0; i < PlayerNum; i++)//�л���һ�����
    {
        if(CurrPlayer == Players[i])
        {
            CurrPlayer = Players[(i+1)%PlayerNum];
            break;
        }
    }
    Avail();//����AvailCard�����AvailNoble����
    ClearTakenDiamond();//�������ñ�ʯ����
    SetCurrCard(-1,-1);//����ѡ�п�ƬΪ��
    SetCurrNoble(-1);//����ѡ�й���Ϊ��
    AlterMani(None);//�޲���״̬
}

//2.table
QString Table::CardImg(int level, int num)
{
    if(OpenCard[level][num] != nullptr && level >= 0 && level <= 2 && num >= 0 && num <= 3)
        return OpenCard[level][num]->GetAddress();
    return "\0";
}

QString Table::NobleImg(int num)
{
    if(Nobles[num] != nullptr && num >= 0 && num <= 4)
        return Nobles[num]->GetAddress();
    return "\0";
}

QString Table::PlayerImg(int num)
{
    if(Players[num] != nullptr && num >= 0 && num <= 3)
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
    for (int i = 0; i < length; i++)
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

void Table::SetCurrNoble(int num)
{
    CurrNoble = num;
}

Noble* Table::CurrNobleInfo()
{
    return Nobles[CurrNoble];
}

int Table::ShowDiamonds(int co)
{
    return Diamonds[co];
}

int Table::ShowPlayerDiamonds(int color, int player)
{
    if(player == -1)
        return CurrPlayer->ShowDiamond(color);
    else return Players[player]->ShowDiamond(color);
}

int Table::ShowRep(int player)
{
    if(player == -1)
        return CurrPlayer->ShowRep();
    return Players[player]->ShowRep();
}

void Table::ClearTakenDiamond()
{
    for(int i = 0; i < 6;i++)
    {
        if(TakenDiamond[i]>0)
        {
            Diamonds[i] += TakenDiamond[i];
            TakenDiamond[i] = 0;
        }
    }
}

void Table::SetCurrCard(int level, int num)
{
    CurrCard[0] = level;
    CurrCard[1] = num;
}

//int Table::Round()
//{
//    for(int i=0;i<PlayerNum;i++)//�л���һ�����
//    {
//        if(CurrPlayer == Players[i])
//        {
//            CurrPlayer = Players[(i+1)%PlayerNum];
//        }
//    }
//    AlterMani(None);
//    return 1;
//}

bool Table::NewCard(int level, int num)
{
    if(level >= 0&&level < 3&&num >= 0&&num < 4)
    {
        OpenCard[level][num] = CardHead[level];
        if(CardHead[level]->next != nullptr)//��һ����Ϊ��
        {
            CardHead[level] = CardHead[level]->next;
            OpenCard[level][num]->next = nullptr;
            //qDebug()<<"Card "<<level<<" "<<num<<"created!"<<endl;
            return true;
        }
        else//û����
        {
        OpenCard[level][num] = nullptr;
        return false;
        }
    }
    else return false;
}
bool Table::CreateCard()
{
    char addr[90][55];
        int bonus[90];
        int price[90], rep[90];
        int num[6] = { 8 };//num[color]
        Card* randHigh[20] = {nullptr}, *randMid[30] = {nullptr},
            *randLow[40] = {nullptr};
        ifstream c("cards.dat", ios::in | ios::binary);
        //qDebug() << c.is_open() << endl;//dat������
        for (int i = 0;i < 90;i++)//20-40-30
        {
            c.read(reinterpret_cast<char*>(&addr[i]), sizeof(addr[i]));
            c.read(reinterpret_cast<char*>(&bonus[i]), sizeof(bonus[i]));
            c.read(reinterpret_cast<char*>(&price[i]), sizeof(price[i]));
            c.read(reinterpret_cast<char*>(&rep[i]), sizeof(rep[i]));
            for (int j = 5;j >= 0;j--)
            {
                num[j] = price[i] % 10;
                price[i] -= num[j];
                price[i] /= 10;
            }
            srand(time(0));
            if(i < 20)//High
            {
                int sit = rand()%20;
                while(randHigh[sit]!=nullptr)
                    sit = rand()%20;
                randHigh[sit] = new Card;
                randHigh[sit]->PicAddr = QString(QLatin1String(addr[i]));//QString(QLatin1String(ch));
                randHigh[sit]->Rep = rep[i];
                randHigh[sit]->Bonus = color(bonus[i]);
                for(int k = 0; k < 6; k++)
                {
                   randHigh[sit]->Price[k] = num[k];
                }
            }
            else if(i < 60)//Low
            {
                int sit = rand()%40;
                while(randLow[sit]!=nullptr)
                    sit = rand()%40;
                randLow[sit] = new Card;
                randLow[sit]->PicAddr = QString(QLatin1String(addr[i]));//QString(QLatin1String(ch));
                randLow[sit]->Rep = rep[i];
                randLow[sit]->Bonus = color(bonus[i]);
                for(int k=0; k<6; k++)
                {
                   randLow[sit]->Price[k] = num[k];
                }
            }
            else//Mid
            {
                int sit = rand()%30;
                while(randMid[sit]!=nullptr)
                    sit = rand()%30;
                randMid[sit] = new Card;
                randMid[sit]->PicAddr = QString(QLatin1String(addr[i]));//QString(QLatin1String(ch));
                randMid[sit]->Rep = rep[i];
                randMid[sit]->Bonus = color(bonus[i]);
                for(int k=0; k<6; k++)
                {
                   randMid[sit]->Price[k] = num[k];
                }
            }
        }
        //����������
        Card* cc1 = CardHead[2] = randHigh[0];
        for (int k = 0; k < 19; k++)
        {
           cc1->next = randHigh[k+1];
           cc1 = cc1->next;
        }
        //qDebug()<<"create 1:"<<cc1->Rep<<" "<<cc1->Bonus<<" "<<cc1;
        cc1->next = nullptr;
        //����������
        Card* cc2 = CardHead[0] = randLow[0];
        for (int k = 0; k < 39; k++)
        {
           cc2->next=randLow[k+1];
           cc2 = cc2->next;
        }
        //qDebug()<<"create 2:"<<cc2->Rep<<" "<<cc2->Bonus<<" "<<cc2;
        cc2->next = nullptr;
        //����������
        Card* cc3 = CardHead[1] = randMid[0];
        for (int k = 0; k < 29; k++)
        {
           cc3->next = randMid[k+1];
           cc3 = cc3->next;
        }
        //qDebug()<<"create 3:"<<cc3->Rep<<" "<<cc3->Bonus<<" "<<cc3;
        cc3->next = nullptr;
        c.close();
        for(int i = 0;i < 3;i++)
        {
            for(int j = 0;j < 4;j++)
                NewCard(i,j);
        }
}
bool Table::CreateNoble()
{

}


bool Table::IfCount()
{
    for (int i=0;i<PlayerNum;i++) {
        if(Players[i]->Rep>=15)
            return true;
    }
    return false;
}

bool Table::IfCurrCount()
{
    if(CurrPlayer->Rep>=15)
        return true;
    return false;
}

bool Table::GetCount(Player **no1, Player **no2, int* num1, int* num2)
{
    if(Status!=Counting)
        return false;
    int highscore=0,No1Num=0,No2Num=0;
    for(int i=0;i<PlayerNum;i++)//��ȡ��߷�
    {
        if(Players[i]->Rep>highscore)
            highscore=Players[i]->Rep;
    }
    for(int i=0;i<PlayerNum;i++)//��������
    {
        if(Players[i]->Rep=highscore)
        {
            no1[No1Num]=Players[i];
            No1Num++;
        }
        else {
            no2[No2Num]=Players[i];
            No2Num++;
        }
    }
    *num1=No1Num;
    *num2=No2Num;
    return true;
}
