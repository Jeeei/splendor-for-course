#pragma once
#include <iostream>
#include <fstream>
#include <QString>
enum color { Red, Green, Blue, White, Black, Gold };//宝石颜色
enum Manipulation { None, Take, Buy, Retain, SelectNoble };//5个操作暂无动作、拿宝石、买卡、扣卡、选贵族using namespace std;
class Card //发展卡类
{
	friend class Player;
	friend class Table;//给予访问权限
public:
	Card();
	Card(color, int*, int);//目前直接传参生成卡片，贵族等
	color GetBonus()const;//返回bonus 
	void GetPrice(int*)const;//返回在传入的int*
	int GetRep()const;//返回reputation
	Card* next = NULL;

	//显示函数
    //QString GetAddress()const;//返回图片地址的函数

private:
	//QImage//图片地址
	color Bonus;//卡所带宝石颜色（红利）
	int Price[6];//购买发展卡所需宝石的数量/* 用price[color]访问*/
	int Rep;//声望点数
    //QString AddressToPic;//图片的地址
    //fstream& operator<<(Card&);//文件存储时初始化时初始化和储存信息
    //fstream& operator>>(Card&);
};
class Player;
class Noble//贵族类  
{
public:
	Noble();
	Noble(int rep, int* con);
	int GetRep()const;//显示声望点数
	void GetCondition(int*)const;
	bool CanVisit(Player*);//检查能否访问玩家

	//显示函数
	//一个返回QImage的函数
private:
	//QImage//图片地址
	int Rep;//声望点数
	int Condition[6];//贵族到访的宝石条件
	
};

class Player//玩家类，储存玩家的信息
{
	friend class Table;//给予访问权限
public:
	Player();
	~Player();
	bool Take(int*, int l = 6);//拿宝石 传一个在Table.Take()中认定合法的Diamond[6]
	bool Buy(Card*);//买卡 
	bool Reserve(Card*, bool);//扣卡,bool参数表示场上是否有黄金剩余,返回player宝石是否可拿
	bool NobleCome(Noble*);//贵族到访
	void GetDiamonds(int*);//返回宝石  
	void GetBonus(int*);//返回玩家拥有的红利数 /*Cards暂时只保存了颜色*/
	bool CanBuy(Card* card);//检查玩家能否买卡
	bool CanReserve()const;//检查玩家能否扣卡

	int GetDiamond(color co) { return Diamonds[co]; }
	Card* GetReserved(int num) {
		if (num < 3)return Reserved[num];
		else return NULL;
	}
	void SetReserved(int num, Card* c) {Reserved[num] = c;}
	void AddRep(int r) { Rep += r; }
	bool AlterDiamond(color, int, int);//颜色，符号（+为1，-为-1），个数
	
	//展示函数
	int ShowRep() { return Rep; }
	void ShowDiamond(int*, int length = 6);
    int ShowDiamond(int);//增加重载 只返回单个颜色的宝石数
	void ShowCards(int*, int length = 5);
	void ShowReserved(Card**, int length = 3);//传入为Card的指针数组

protected:
	int Diamonds[6];//玩家拥有的宝石数
	int Rep;//玩家拥有的声望点数
	Noble* Nobles[5];//玩家拥有的贵族卡
	int Cards[5];//玩家拥有的发展卡/*暂时不储存卡片信息只保存不同颜色的数量*/
	Card* Reserved[3];
	int TotalDiamonds()const;//返回玩家拥有全部宝石数

};


class Table
{
public:
	Table();
	~Table();
	bool Start();//与用户交互初始化 先生成2个Players并调用Init 后续补充其他选项
	bool Init();//与用户无关初始化 可被Start()调用 生成固定的Cards和Nobles链表
	int Round();//回合进行函数，对每个玩家调用Operate()，并在之后进行相应判断操作

	void NewCard(int level, int num);//翻开新的卡
	void AddRubbish(Card*);//废弃的卡指针(被买走了）

	//五操作函数 
	//Can-系列返回1表示可买，错误代码<0,返回1后更改currmani
	void Avail();//判断桌面上当前玩家可购买的卡
	void NoneMani();//取消操作后显示桌面
	int CanTake(color);//点击宝石后调用返回当前宝石是否可拿
	int UnTake(color);//点击暂时选中宝石放回桌面
	int CanBuy(int, int);//点击卡片调用返回当前卡片是否可买
	int CanRetain(int, int);//点击卡片调用返回当前卡片是否可扣
	int TakeMani();//点击确定后判断当前操作为Take执行
	int BuyMani();//点击确定后判断当前操作为Buy执行
	int RetainMani();//点击确定后判断当前操作为Retain执行
	bool IfNoble();//三操作点击确认后判断是否执行选贵族操作并判断
	void NobleCome(int);//传入被选择的Noble编号


	//展示函数，获取当前状态后，查询绘图所需信息
	//需要获取的信息为数组的需要传入一个数组指针获得，其余由返回值获得
	void Next();//当前玩家操作全部结束后调用刷新信息
	Manipulation GetMani() { return CurrMani; }//获取当前状态以获取信息绘图
	void AlterMani(Manipulation m) { CurrMani = m; }//*是否更改操作由返回值决定

	//后可以将Card和Noble数组改成QIMage
	void ShowCards(Card***, int level = 3, int num = 4);
//    QString CardAddress(int level, int num)
//    {
//        return OpenCard[level][num]->GetAddress();
//    }
	void ShowNobles(Noble**, int length = 5);

	void AvailCardInfo(int**, int level = 3, int num = 4);//获取当前可买卡信息
	void AvailNobleInfo(int*, int length = 5);//获取当前可拿贵族信息

	void TakenDiamondInfo(int*, int length = 3);//获取当前拿取的金币或宝石
	//返回int数组用color(int)转换为颜色，-1为空
	Card* CurrCardInfo();//获取当前将要拿或扣卡的
	Noble* CurrNobleInfo();//IfNoble()=1时调用，获取当前可选的Noble

	//bool Reserve(Player*, int, int);//接口,需接收界面返回的卡的二维数组坐标,调用相应玩家的相应函数
    bool CreateCard(int, int);//生成发展卡,lv和coord为二维数组坐标
	//int ChooseNoble(Player*, int*);//选择贵族到访
    //这个函数要用到显示函数中去
    int ShowDiamonds(int);//显示场上剩余宝石，界面输出接口
    int ShowPlayerDiamonds(int);//显示玩家拥有宝石，接口
    int ShowRep() { return CurrPlayer->ShowRep(); }//显示玩家声望

private:
	//桌面拥有的东西
	Card* CardHead[3];//未翻开的卡 /*见注释1
	Card* OpenCard[3][4];//翻开的卡 
	Card* Rubbish;//废弃的卡指针
	Noble* Nobles[5];//使用的贵族
	int Diamonds[6];//桌面上的宝石剩余
	Player* Players[4];//玩家

	//临时变量
	Player* CurrPlayer;//当前玩家
	Manipulation CurrMani;//当前操作
	int CurrNoble = 0;//玩家选中的贵族 0-4代表桌面上的贵族
	int AvailNoble[5] = { 0 };//当前玩家可获取的贵族
	int CurrCard[2] = { -1 };//-1表示未选中
	//当前正在购买或者扣的卡的序号（0-2，0-3）为桌面的卡，（x，4）为自己扣卡的第x+1张
	int AvailCard[3][4] = { 0 };//玩家可购买的卡，1为可以，0为不可
	int TakenDiamond[6] = { 0 };//标记每个宝石被拿的数量
	};

/*注释1：每生成一个Card或者Noble就创建一个指向其的指针，当Table或Player拥有
Card或Noble时，用其指针数组中的指针指向该Card或者Noble，保证一个Card或者Noble
同时只有一个指针指向它
注释2：实参首字母大写，形参全小写

先把啥搞出来：
除Table以外类的成员函数和Table.Init() Table.Start()
目前直接传参初始化卡片，贵族，桌面，文件流来得及就补

*/







