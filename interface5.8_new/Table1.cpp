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
        sPlayers[i] = nullptr;
        sPlayersPic[i] = i; //ͷ������Ϊ�ʼ�ĸ�
    }
    for(int i = 0; i < 6; i++)
    {
        Diamonds[i] = 0;
        TakenDiamond[i] = 0;
    }
    AlterStatus(Selecting);
    sPlayerNum = 2;//�������Ϊ2
    SetCurrCard(-1,-1);
    AlterMani(None);
    SetCurrNoble(-1);
    CurrPlayer = nullptr;
    RandomFirst = true;
    FirstPlayer = 1;
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
            delete sPlayers[i];
            sPlayers[i] = nullptr;
        }
    }
    for (int i = 0; i < 3; i++)//ɾ�����Ϸ�չ��
        for (int j = 0; j < 4; j++)
        {
            if (OpenCard[i][j] != nullptr)
            {
                delete OpenCard[i][j];
                OpenCard[i][j] = nullptr;
            }
        }
    for (int i = 0; i < 5; i++)//ɾ�����忨
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
    AlterStatus(Selecting);
    PlayerNum = sPlayerNum;//ȷ��������� //sPlayer�ڹ��캯����ʼ��Ϊ2
    for (int i=0;i<PlayerNum;i++)
    {
        sPlayers[i]->SetImg(GetPlayerPic(i));//д��ͷ�������Ѿ�д��
    }
    for(int i = 0;i < PlayerNum;i++)
    {
        if(Players[i] == nullptr)
            Players[i] = new Player;
    }
    for(int no = 1;no <= PlayerNum;no++)//��������player���������
    {
        if(no>=GetFirst())
            Players[no-GetFirst()]=sPlayers[no-1];
        else
            Players[no-GetFirst()+sPlayerNum]=sPlayers[no-1];
    }
    CurrPlayer = Players[0];//���ָ���
    Init();
    return true;
}

bool Table::Init()
{
    for(int i = 0; i < 6; i++)//��ʼ����ʯ��
    {
        Diamonds[i] = 5;
    }
    CreateCard();//���ɷ�չ������
    CreateNoble();//���ɹ��忨����

    //���п�����Avail
    Avail();//��ʼ��AvailCard�����AvailNoble����
    AlterStatus(Playing);
    return true;
}

bool Table::AlterPlayerNum(int a)
{
    int num = sPlayerNum+a;
    if(num<2||num>4)
        return false;
    PlayerNum = num;
    AlterIfRandom();
    AlterIfRandom();//����˳�����
    return true;
}

//"background-color:rgba(255,255,255,80)"
QString Table::GetPlayerPic(int no)
{
    if(no>sPlayerNum)
        return "background-color:rgba(255,255,255,80)";
    QString pic = "border-image:url(:images/role/1.png";
    pic[30]=sPlayersPic[no];//��ͼƬ·���ַ�����ͼƬ����λ�õ��ַ��ĳ��������ͼƬ���(0-9)
    return pic;
}

void Table::AlterPlayerPic(int no)
{
    int sno = (sPlayersPic[no]+1)%10;
    while(1)
    {
        int i=0;
        for(i=0;i<sPlayerNum;i++)
        {
            if(sno==sPlayersPic[i])
                break;
        }
        if(i==sPlayerNum)
        {
            sPlayersPic[no] = sno;
            return;
        }
        sno = (sno+1)%10;
    }
}

void Table::AlterIfRandom()
{
    IfRandom = !IfRandom;
    if(!IfRandom)
        FirstPlayer=1;
    else {
        srand(time(0));
        FirstPlayer = rand()%PlayerNum+1;
    }
}

void Table::Avail()//�ж������ϵ�ǰ��ҿɹ���Ŀ� �Լ����԰ݷõĹ���
{
    for (int level = 0;level < 3;level++)//^����Ż���Ӧ�����ֲ�������
    {
        for (int num = 0; num < 5; num++)
        {
            if(num < 4)//�����ϵĿ�
            {
                Card* c = OpenCard[level][num];//��ȡ��ǰ��ָ��
                if(CurrPlayer->CanBuy(c))
                    AvailCard[level][num] = 1;//����
                else AvailCard[level][num] = 0;//������
            }
            else//�۵Ŀ�
            {
                AvailCard[level][num] = CurrPlayer->CanBuy(CurrPlayer->Reserved[level]);
            }
        }
    }
    for (int i = 0; i < 3; i++)//�������忨����
    {
        if(Nobles[i] != nullptr)
        {
            if(Nobles[i]->CanVisit(CurrPlayer))
                AvailNoble[i] = 1;
            else AvailNoble[i] = 0;
        }
        else AvailNoble[i] = 0;
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
    int cDiaNum = 0;//�Ѿ��õ�
    for (int i = 0;i < 6;i++)
        cDiaNum += TakenDiamond[i];
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
    TakenDiamond[co]++;
    Diamonds[co]--;
    return 1;
}

int Table::UnTake(color co)
{
    if(TakenDiamond[co] > 0)
    {
        TakenDiamond[co]--;
        Diamonds[co]++;
        return true;
    }
    else return false;
}

bool Table::CanBuy()
{
    if(CurrCard[0] < 3 && CurrCard[0] >= 0 && CurrCard[1] <= 4 && CurrCard[1] >= 0)
        return AvailCard[CurrCard[0]][CurrCard[1]];
    else return false;
}

int Table::CanRetain()
{
    if (CurrCard[0] < 3 && CurrCard[0] >= 0 && CurrCard[1] < 4 && CurrCard[1] >= 0)//Ϊ����Ŀ�
    {
        if (OpenCard[CurrCard[0]][CurrCard[1]] == nullptr)
            return -1;//û����
        for (int i = 0;i < 3;i++)
        {
            if (CurrPlayer->Reserved[i] == nullptr)
            {    if(CurrPlayer->TotalDiamonds()<10 && Diamonds[Gold]>0)
                {
                    return 1;//�����ý��
                }
                else
                {
                    return 0;//�����ý��
                }
            }
        }
        return -2;//���ܿۿ�
    }
    else return -3;//�۵Ĳ�������Ŀ�
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
    if(CurrCard[0] < 3 && CurrCard[0] >= 0 && CurrCard[1] <= 4 && CurrCard[1] >= 0)//�Ϸ��Ŀ�Ƭ
    {
        int card[5] = {0},playerDia[6] = {0};
        for (int i = 0; i < 6; i++)//���������֮ǰ�Ŀ�Ƭ����������ұ�ʯ��
        {
            if(i != 5)
                card[i] = CurrPlayer->Cards[i];
            playerDia[i] = CurrPlayer->GetDiamond(color(i));
        }
        if (CurrCard[1] < 4)//Ϊ����Ŀ�
        {
            Card* c = OpenCard[CurrCard[0]][CurrCard[1]];//��ȡ��ǰ��ָ��
            if(c != nullptr)
            {
                CurrPlayer->Buy(c);
                for (int i = 0; i < 5; i++)//����ʯ��table
                {
                    if (card[i] >= c->Price[i])//���ñ�ʯ�������
                        continue;
                    else if (playerDia[i] + card[i] >= c->Price[i])//���ûƽ�������
                        Diamonds[i] += c->Price[i] - card[i];
                    else if (playerDia[i] + card[i] + playerDia[Gold] >= c->Price[i])//Ҫ�ûƽ�������
                    {
                        Diamonds[Gold] += c->Price[i] - (playerDia[i] + card[i]);
                        Diamonds[i] += playerDia[i];
                    }
                }
                return NewCard(CurrCard[0], CurrCard[1]);//������Ŀ�������ֵΪ0��1����ʾ���޳ɹ����ɿ�Ƭ
            }
        }
        else //����˵Ŀ�
        {
            Card* c = CurrPlayer->Reserved[CurrCard[0]];
            if(c != nullptr)
            {
                CurrPlayer->Buy(c);
                for (int i = 0; i < 5; i++)//����ʯ��table
                {
                    if (card[i] >= c->Price[i])//���ñ�ʯ�������
                        continue;
                    else if (playerDia[i] + card[i] >= c->Price[i])//���ûƽ�������
                        Diamonds[i] += c->Price[i] - card[i];
                    else if (playerDia[i] + card[i] + playerDia[Gold] >= c->Price[i])//Ҫ�ûƽ�������
                    {
                        Diamonds[Gold] += c->Price[i] - (playerDia[i] + card[i]);
                        Diamonds[i] += playerDia[i];
                    }
                }
                delete c;
                CurrPlayer->SetReserved(CurrCard[0], nullptr);
                return -1;
            }
            else return -3;//û�п�Ƭ
        }
    }
    return -2;//��Ƭ���Ϸ�
}

int Table::RetainMani(int canRetain)//��CanRetain()����һ��ʹ��
{
    if(canRetain >= 0)//���Կۿ�
    {
        Card* c = OpenCard[CurrCard[0]][CurrCard[1]];//��ȡ��ǰ��ָ��
        int i;
        for (i = 0;i < 3;i++)
        {
            if(CurrPlayer->GetReserved(i) == nullptr)
            {
                CurrPlayer->SetReserved(i, c);//����
                if(canRetain)//�����ûƽ�
                {
                    Diamonds[Gold]--;
                    CurrPlayer->AlterDiamond(Gold,1,1);
                }
                NewCard(CurrCard[0], CurrCard[1]);
                return 1;
            }
        }
        return -2;
    }
    else return canRetain;//�������
}

int Table::IfNoble()//�ж��Ƿ���Ҫѡ�����
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        if(AvailNoble[i])
            count++;
    }
    if(count > 0)//���Է���
        return count;
    else return -1;//û��ѡ,��
}

void Table::NobleCome(int num)//����ݷ�
{
    if(num >= 0 && num < 3)
        if(AvailNoble[num])
        {
            CurrPlayer->NobleCome(Nobles[num]);
            Nobles[num] = nullptr;
        }
}

int Table::Next()//�������,�غϽ���,�л���һ�����
{
    if(IfCurrCount())
        AlterStatus(Counting);
    int num = 0;
    for(int i = 0; i < PlayerNum; i++)//�л���һ�����
    {
        if(CurrPlayer == Players[i])
        {
            if(GetStatus() == Counting)//�������غ�
            {
                if((i + 1) < PlayerNum)//�����л���һ��
                {
                    CurrPlayer = Players[(i+1)];
                    num = i+1;
                    break;
                }
                else //���һλ���
                {
                    AlterStatus(Ending);//������Ϸ
                    return i;
                }
            }
            else//û�н������غ�
            {
                CurrPlayer = Players[(i+1)%PlayerNum];
                num = (i+1)%PlayerNum;
                break;
            }
        }
    }
    Avail();//����AvailCard�����AvailNoble����
    ClearTakenDiamond();//�������ñ�ʯ����
    SetCurrCard(-1,-1);//����ѡ�п�ƬΪ��
    SetCurrNoble(-1);//����ѡ�й���Ϊ��
    AlterMani(None);//�޲���״̬
    return num;
}

//2.table
QString Table::CardImg(int level, int num)
{
    if(OpenCard[level][num] != nullptr && level >= 0 && level <= 2 && num >= 0 && num <= 3)
        return OpenCard[level][num]->GetAddress();
    return "background-color:rgba(255,255,255,80);bordor-radius:55px;";
}

QString Table::ReserveImg(int num)
{
    if(CurrPlayer->GetReserved(num) != nullptr)
        return CurrPlayer->GetReserved(num)->GetAddress();
    else return "background-color: rgba(255, 255, 255, 80);border-radius:18px;border:2px solid rgb(176, 176, 87);";
}

QString Table::NobleImg(int num)
{
    if(Nobles[num] != nullptr && num >= 0 && num < 3)
        return Nobles[num]->GetAddress();
    return "background-color:rgba(255,255,255,80);bordor-radius:15px;";
}

QString Table::PlayerImg(int num)
{
    if(Players[num] != nullptr && num >= 0 && num <= 3)
        return Players[num]->GetAddr();
    return "background-color:rgba(255,255,255,50);bordor-radius:55px;";
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

int Table::ShowPlayerDiamonds(color co, int player)
{
    if(player == -1)//��ǰ���
        return CurrPlayer->GetDiamond(co);
    else
    {
        for(int i = 0; i < PlayerNum; i++)//Ѱ����һ�����
        {
            if(CurrPlayer == Players[i])
            {
                return Players[(i+1)%PlayerNum]->GetDiamond(co);
            }
        }
    }
    return -1;
}

int Table::ShowPlayerBonus(color co, int player)
{
    if(player == -1)//��ǰ���
        return CurrPlayer->GetBonus(co);
    else
    {
        for(int i = 0; i < PlayerNum; i++)//Ѱ����һ�����
        {
            if(CurrPlayer == Players[i])
            {
                return Players[(i+1)%PlayerNum]->GetBonus(co);
            }
        }
    }
    return -1;
}

int Table::ShowRep(int player)
{
    if(player == -1)//��ǰ���
        return CurrPlayer->GetRep();
    else
    {
        for(int i = 0; i < PlayerNum; i++)//Ѱ����һ�����
        {
            if(CurrPlayer == Players[i])
            {
                return Players[(i+1)%PlayerNum]->GetRep();
            }
        }
    }
    return -1;
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

bool Table::NewCard(int level, int num)
{
    if(level >= 0&&level < 3&&num >= 0&&num < 4)
    {
        if(CardHead[level] != nullptr)
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
                CardHead[level] = nullptr;
                return true;
            }
        }
        else//��ͷ����
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
    Card* randHigh[20] = {nullptr}, *randMid[30] = {nullptr}, *randLow[40] = {nullptr};
    ifstream c("cards.dat", ios::in | ios::binary);
    bool open = c.is_open();//dat������
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
            while(randHigh[sit] != nullptr)
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
            while(randLow[sit] != nullptr)
                sit = rand()%40;
            randLow[sit] = new Card;
            randLow[sit]->PicAddr = QString(QLatin1String(addr[i]));//QString(QLatin1String(ch));
            randLow[sit]->Rep = rep[i];
            randLow[sit]->Bonus = color(bonus[i]);
            for(int k = 0; k<6; k++)
            {
                randLow[sit]->Price[k] = num[k];
            }
        }
        else//Mid
        {
            int sit = rand()%30;
            while(randMid[sit] != nullptr)
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
        randHigh[k+1] = nullptr;
        cc1 = cc1->next;
    }
    cc1->next = nullptr;
    //����������
    Card* cc2 = CardHead[0] = randLow[0];
    for (int k = 0; k < 39; k++)
    {
        cc2->next = randLow[k+1];
        randLow[k+1] = nullptr;
        cc2 = cc2->next;
    }
    cc2->next = nullptr;
    //����������
    Card* cc3 = CardHead[1] = randMid[0];
    for (int k = 0; k < 29; k++)
    {
        cc3->next = randMid[k+1];
        randMid[k+1] = nullptr;
        cc3 = cc3->next;
    }
    cc3->next = nullptr;
    c.close();
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 4;j++)
            NewCard(i,j);
    }
    return open;
}
bool Table::CreateNoble()
{
    char addr[10][50];
    int price[10];
    int num[6]={8};
    Noble* ns[10] = {nullptr};
    ifstream c("nobles.dat", ios::in | ios::binary);
    bool open = c.is_open();//dat������
    for (int i = 0;i < 10;i++)//20-40-30
    {
        c.read(reinterpret_cast<char*>(&addr[i]), sizeof(addr[i]));
        c.read(reinterpret_cast<char*>(&price[i]), sizeof(price[i]));
        for (int j = 5;j >= 0;j--)
        {
            num[j] = price[i] % 10;
            price[i] -= num[j];
            price[i] /= 10;
        }
        srand(time(0));
        int sit = rand()%10;
        while(ns[sit] != nullptr)
            sit = rand()%10;
        ns[sit] = new Noble;
        ns[sit]->PicAddr = QString(QLatin1String(addr[i]));
        for(int k = 0; k < 6; k++)
        {
           ns[sit]->Condition[k] = num[k];
        }
    }
    for(int i = 0;i < 10;i++)//��������+1������
    {
        if(i < PlayerNum + 1)
            Nobles[i] = ns[i];
        else delete ns[i];
    }
    return open;
}

bool Table::IfCount()
{
    for (int i = 0;i < PlayerNum;i++) {
        if(Players[i]->Rep >= 15)
            return true;
    }
    return false;
}

bool Table::IfCurrCount()
{
    if(CurrPlayer->Rep >= 15)
        return true;
    return false;
}

bool Table::GetCount(Player **no1, Player **no2, int* num1, int* num2)
{
    if(Status != Ending)
        return false;
    int highscore = 0,No1Num = 0,No2Num = 0;
    for(int i = 0;i < PlayerNum;i++)//��ȡ��߷�
    {
        if(Players[i]->GetRep() > highscore)
            highscore = Players[i]->GetRep();
    }
    for(int i = 0;i < PlayerNum;i++)//��������
    {
        if(Players[i]->GetRep() == highscore)
        {
            no1[No1Num] = Players[i];
            No1Num++;
        }
        else {
            no2[No2Num] = Players[i];
            No2Num++;
        }
    }
    *num1 = No1Num;
    *num2 = No2Num;
    return true;
}
