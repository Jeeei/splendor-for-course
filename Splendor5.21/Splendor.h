#pragma once
#include <iostream>
#include <fstream>
#include <QString>
#include <windows.h>
#include <QDebug>
using namespace std;
enum color { Red, Green, Blue, White, Black, Gold };//宝石颜色
enum Manipulation { None, Take, Buy, Retain, SelectNoble };//5个操作暂无动作、拿宝石、买卡、扣卡、选贵族
enum TableStatus{Selecting,Playing,Counting,Setting,Ending};//选择、游戏进行、结算、设置页面
class Card //发展卡类
{
    friend class Player;
    friend class Table;//给予访问权限
    friend ofstream& operator<<(ofstream&, Card&);//储存card信息到文件
    friend ifstream& operator>>(ifstream&, Card&);//从文件中读出信息
public:
    Card();
    Card(QString, color, int*, int);//目前直接传参生成卡片，贵族等
    color GetBonus()const;//返回bonus
    void GetPrice(int*)const;//返回在传入的int*
    int GetRep()const;//返回reputation
    Card* next;

    //显示函数
    QString GetAddress()const{return PicAddr;}//返回图片地址的函数

private:
    QString PicAddr;//图片的地址 "NULL"为未加载图片
    color Bonus;//卡所带宝石颜色（红利）
    int Price[6];//购买发展卡所需宝石的数量/* 用price[color]访问*/
    int Rep;//声望点数
};
class Player;
class Noble//贵族类
{
    friend class Table;
    friend ofstream& operator<<(ofstream&, Noble&);
    friend ifstream& operator>>(ifstream&, Noble&);
public:
    Noble();
    Noble(QString, int rep, int* con);
    int GetRep()const;//显示声望点数
    void GetCondition(int*)const;
    bool CanVisit(Player*);//检查能否访问玩家

    //显示函数
    QString GetAddress()const{return PicAddr;}//返回图片地址的函数

private:
    QString PicAddr;
    int Rep;//声望点数
    int Condition[6];//贵族到访的宝石条件

};

class Player//玩家类，储存玩家的信息
{
    friend class Table;//给予访问权限
    friend ofstream& operator<<(ofstream&, Player&);//存取了所有数据，用于保存进度，初始化时不能直接调用
    friend ifstream& operator>>(ifstream&, Player&);
public:
    Player();
    ~Player();
    //Set函数
    bool Take(int*, int l = 6);//拿宝石 传一个在Table.Take()中认定合法的Diamond[6]
    bool Buy(Card*);//买卡
    void SetReserved(int num, Card* c) {Reserved[num] = c;}
    void AddRep(int r) { Rep += r; }
    bool AlterDiamond(color, int, int);//颜色，符号（+为1，-为-1），个数
    bool NobleCome(Noble*);//贵族到访
    bool SetImg(QString);
    void SetName(QString str){Name = str;}

    //Get函数
    QString GetAddr()const{return PicAddr;}//返回图片地址的函数
    QString GetName()const{return Name;}//返回玩家名字
    int GetRep() { return Rep; }
    void GetDiamonds(int*);//返回宝石
    int GetDiamond(color co) { return Diamonds[co]; }
    int GetBonus(color);//返回玩家拥有的红利数 /*Cards暂时只保存了颜色*/
    Card* GetReserved(int num) {
        if (num < 3 && num >= 0)return Reserved[num];
        else return nullptr;
    }
    void GetDiamond(int*, int length = 6);
    int GetDiamond(int);//增加重载 只返回单个颜色的宝石数

    //show
    void ShowCards(int*, int length = 5);
    void ShowReserved(Card**, int length = 3);//传入为Card的指针数组

    bool CanBuy(Card* card);//检查玩家能否买卡

    bool TakeCanBuy(Card* card,int* takendiamond);

protected:
    QString PicAddr;
    QString Name;
    int Diamonds[6];//玩家拥有的宝石数
    int Rep;//玩家拥有的声望点数
    Noble* Nobles[3];//玩家拥有的贵族卡
    int Cards[5];//玩家拥有的发展卡/*暂时不储存卡片信息只保存不同颜色的数量*/
    Card* Reserved[3];

    int TotalDiamonds()const;//返回玩家拥有全部宝石数

};


class Table
{
    friend ofstream& operator<<(ofstream&, Table&);//存取了所有数据，用于保存进度，初始化时不能直接调用
    friend ifstream& operator>>(ifstream&, Table&);
public:
    Table();
    ~Table();

    bool NewCard(int level, int num);//翻开新的卡
    bool CreateCard();//洗牌(Init里面调用）
    bool CreateNoble();//发贵族(Init里面调用）

    //五操作函数 （Can判断操作是否可行并更改缓冲区，Mani执行更改）
    //Can-系列返回1表示可买，错误代码<0,返回1后更改currmani
    void Avail();//判断桌面上当前玩家可购买的卡 以及可以拜访的贵族
    void NoneMani();//取消操作后显示桌面
    int CanTake(color);//点击宝石后调用返回当前宝石是否可拿
    int UnTake(color);//点击暂时选中宝石放回桌面
    bool CanBuy();//点击卡片调用返回当前卡片是否可买
    int CanRetain(int* = nullptr);//点击卡片调用返回当前卡片是否可扣
    int TakeMani();//点击确定后判断当前操作为Take执行
    int BuyMani();//点击确定后判断当前操作为Buy执行
    int RetainMani(int);//点击确定后判断当前操作为Retain执行,int参数为能否拿金币
    int IfNoble();//三操作点击确认后判断是否执行选贵族操作并判断
    void NobleCome(int);//传入被选择的Noble编号,贵族拜访


    //展示函数，获取当前状态后，查询绘图所需信息
    //需要获取的信息为数组的需要传入一个数组指针获得，其余由返回值获得
    //1.Mani相关函数
    int Next();//当前玩家操作全部结束后调用刷新信息*
    Manipulation GetMani() { return CurrMani; }//获取当前状态以获取信息绘图
    void AlterMani(Manipulation m) { CurrMani = m; }//*是否更改操作由返回值决定

    //2.获得table上显示的数据
    //diamond的image不储存在这，除非把它升级成个struct
    QString CardImg(int level, int num);//如果不存在返回半透明
    QString ReserveImg(int num);//返回当前玩家扣的卡的图片地址
    QString NobleImg(int num);
    QString PlayerImg(int num);
    int ShowDiamonds(int co);//显示场上剩余宝石,co：颜色
    int ShowPlayerDiamonds(color co, int player = -1);//显示玩家拥有宝石，（co:颜色，player：玩家相对顺序，默认当前player)
    int ShowPlayerBonus(color co, int player = -1);//显示玩家拥有宝石，（co:颜色，player：玩家相对顺序，默认当前player)
    int ShowRep(int player = -1); //显示玩家声望(player：玩家相对顺序，默认当前player)

    //3.卡/贵族可买高亮
    int AvailCardInfo(int level, int num){return AvailCard[level][num];}//返回第[level][num]是否avail //从0开始
    int AvailNobleInfo(int num){return AvailNoble[num];}//返回第[num]是否avail //从0开始
    void AvailCardInfo(int**, int level = 3, int num = 4);//获取当前可买卡信息
    void AvailNobleInfo(int*, int length = 5);//获取当前可拿贵族信息

    int AvailTakenCardInfo(int level, int num);

    //4.Take操作数据
    void TakenDiamondInfo(int*, int length = 3);//获取当前拿取的金币或宝石，返回int数组用color(int)转换为颜色，-1为空 //没用到

    //5.Retain&Buy
    void SetCurrCard(int,int);
    Card* CurrCardInfo();//获取当前将要拿或扣卡的
    void GetCurrCard(int*,int*);

    //7.初始化
    int GetPlayerNum(){return sPlayerNum;}
    bool AlterPlayerNum(int);//参数传入+1/-1表明数量增减 !增减后先手改变
    QString GetPlayerPic(int no);//注意先判断Player是否存在
    void AlterPlayerPic(int no);//将第no（1-4）个player的头像切换为下一个（注意不能重复）
    QString GetPlayerName(int no){return Players[no - 1]->Name;}//名字重复更改
    void AlterPlayerName(int no, QString str){sPlayers[no - 1]->SetName(str);}
    bool GetIfRandom(){return IfRandom;}//只有当非随机时显示顺序
    void AlterIfRandom();//被改为随机后生成次序，改为设定后玩家1为先手
    int GetFirst(){return FirstPlayer;}
    void AlterFirst(int no){FirstPlayer = no;}//将第no（1-4）个player设为先手

    void NewSelect();//准备初始化
    bool Start();//与用户交互初始化 先生成2个Players并调用Init 后续补充其他选项
    bool Init();//与用户无关初始化 可被Start()调用 生成固定的Cards和Nobles链表

    //8.status相关函数
    void AlterStatus(TableStatus t){Status = t;}
    TableStatus GetStatus(){return Status;}
    bool IfCount();//返回判断是否有玩家到达15分
    bool IfCurrCount();//返回当前玩家是否到达15分
    bool GetCount(Player**,Player**,int* num1,int* num2);
        //传入第一名和第二名的Player指针数组Player*[4]，num1,num2表示数组最终长度
        //使用Player->GetAddr/Rep/No()获取玩家结算信息

    //9.保存与重新读取
    bool IfSaved();//返回是否有保存文件
    bool Save();//保存当前进度
    bool SaveBeginning();//保存游戏初始信息
    bool TryAgain();//重新开始
    bool Load();//加载保存进度

    //未归类函数
    void ClearTakenDiamond();//重置已经拿了的宝石数组

private:
    //桌面拥有的东西
    Card* CardHead[3];//未翻开的卡 /*见注释1
    Card* OpenCard[3][4];//翻开的卡
    Noble* Nobles[5];//使用的贵族
    int Diamonds[6];//桌面上的宝石剩余
    Player* Players[4];//玩家
    int PlayerNum;//玩家人数

    //初始化临时变量 //还没接起来先不管
    int sPlayerNum;//目前选择的玩家人数
    Player* sPlayers[4];//临时玩家
    int sPlayersPic[4];//四个玩家目前图片编号(0-9)存放玩家头像的文件名Role.dat
    bool IfRandom;//玩家顺序是否随机
    int FirstPlayer;//玩家编号为1-4、

    //游戏过程临时变量
    TableStatus Status;//当前页面
    Player* CurrPlayer;//当前玩家
    Manipulation CurrMani;//当前操作
    int AvailNoble[5];//当前玩家可获取的贵族
    int CurrCard[2];//-1表示未选中
        //当前正在购买或者扣的卡的序号（0-2，0-3）为桌面的卡，（x，4）为自己扣卡的第x+1张
    int AvailCard[3][5];//玩家可购买的卡，1为可以，0为不可
    int TakenDiamond[6];//标记每个宝石被拿的数量
};
