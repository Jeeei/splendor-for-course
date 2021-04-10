#pragma once
#include <iostream>
#include<fstream>
enum color { Red, Green, Blue, White, Black, Gold };//宝石颜色
using namespace std;
class Card //发展卡类
{
	friend class Player;
	friend class Table;//给予访问权限(好像不需要，能读就行）
public:
	Card();
	Card(color, int*, int);//目前直接传参生成卡片，贵族等
	color GetBonus()const;//返回bonus 
	void GetPrice(int*)const;//返回在传入的int*
	int GetRep()const;//返回reputation
	Card* next = NULL;
private:
	color Bonus;//卡所带宝石颜色（红利）
	int Price[6];//购买发展卡所需宝石的数量/* 用price[color]访问*/
	int Rep;//声望点数
	fstream& operator<<(Card&);//文件存储时初始化时初始化和储存信息
	fstream& operator>>(Card&);
};

class Noble//贵族类  
{
public:
	Noble();
	Noble(int rep, int* con);
	int GetRep()const;//显示声望点数
	void GetCondition(int*)const;
	bool CanVisit(Player*);//检查能否访问玩家
private:
	int Rep;//声望点数
	int Condition[6];//贵族到访的宝石条件
	//指向图片的指针
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
	int NobleCome(Noble*);//贵族到访
	void GetDiamonds(int*);//返回宝石  
	void GetBonus(int*);//返回玩家拥有的红利数 /*Cards暂时只保存了颜色*/
	bool CanBuy(Card* card);//检查玩家能否买卡
	bool CanReserve()const;//检查玩家能否扣卡

protected:
	int Diamonds[6];//玩家拥有的宝石数
	int Rep = 0;//玩家拥有的声望点数
	Noble* Nobles[5];//玩家拥有的贵族卡
	int Cards[6];//玩家拥有的发展卡/*暂时不储存卡片信息只保存不同颜色的数量*/
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
	bool Take(Player*);//调用相应玩家的相应函数,记录拿的次数和规则检查
	bool Buy(Player*, int, int);//买场上翻开的卡,接口,需接收界面返回的卡的二维数组坐标,调用相应玩家的Buy()
	bool Buy(Player*, int);//买自己扣留的卡,接口,需接收界面返回的已扣留卡的数组坐标,调用相应玩家的Buy()
	bool Reserve(Player*, int, int);//接口,需接收界面返回的卡的二维数组坐标,调用相应玩家的相应函数
	bool CreateCard(int, int);//生成发展卡,lv和coord为二维数组坐标

	int Operate(Player*);//加入operate函数作为接口,接收玩家的操作，调用不同的函数或者结束回合
	int ChooseNoble(Player*, int*);//选择贵族到访
	int ShowDiamonds();//显示场上剩余宝石，界面输出接口
private:
	Card* CardHead[3];//未翻开的卡 /*见注释1
	Card* OpenCard[3][4];//翻开的卡 
	Noble* Nobles[5];//使用的贵族
	int Diamonds[6];//桌面上的宝石剩余
	Player* Players[4];//玩家
};

/*注释1：每生成一个Card或者Noble就创建一个指向其的指针，当Table或Player拥有
Card或Noble时，用其指针数组中的指针指向该Card或者Noble，保证一个Card或者Noble
同时只有一个指针指向它
注释2：实参首字母大写，形参全小写

先把啥搞出来：
除Table以外类的成员函数和Table.Init() Table.Start()
目前直接传参初始化卡片，贵族，桌面，文件流来得及就补

*/







