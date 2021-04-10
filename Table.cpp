#include "Splendor.h"
using namespace std;

Table::Table()
{
	//接开始游戏菜单
	for (int i = 0; i < 3; i++)//卡头仍需接入到链表
		CardHead[i] = NULL;
	for (int i = 0; i < 3; i++)//初始化场上发展卡数组
		for (int j = 0; j < 4; j++)
			OpenCard[i][j] = NULL;
	for (int i = 0; i < 5; i++)//初始化贵族卡数组
		Nobles[i] = NULL;
	for (int i = 0; i < 4; i++)//初始化玩家指针
		Players[i] = NULL;
}
Table::~Table()
{
	for (int i = 0; i < 4; i++)//删除玩家
	{
		if (Players[i] != NULL)
			delete Players[i];
	}
	for (int i = 0; i < 3; i++)//删除场上发展卡
		for (int j = 0; j < 4; j++)
		{
			if (OpenCard[i][j] != NULL)
				delete OpenCard[i][j];
		}
	for (int i = 0; i < 3; i++)//删除贵族卡
		delete Nobles[i];
}
bool Table::Start()//与用户交互初始化 先生成2个Players并调用Init 后续补充其他选项
{
	Players[0] = new Player;
	Players[1] = new Player;
	if (Init())
	{
		int result = Round();//调用Round进行游戏,并检测游戏结果
		if (result)//检查是否正常结束游戏
			return true;
		else return false;
	}
}
bool Table::Init()//初始化函数，包括宝石数，发展卡，贵族卡的初始化
{
	for (int i = 0; i < 6; i++)//初始化宝石数
		Diamonds[i] = 5;
	for (int i = 0; i < 3; i++)//初始化发展卡
		for (int j = 0; j < 4; j++)
		{
			if (OpenCard[i][j] == NULL)
				CreateCard(i, j);
		}
	for (int i = 0; i < 3; i++)
	{
		if (Nobles[i] == NULL)
			Nobles[i] = new Noble;
	}
	return true;
}
bool Table::CreateCard(int lv, int pos)//生成发展卡,lv和coord为二维数组坐标
{
	if (lv > 0 && lv < 3 && pos > 0 && pos < 4)//检查坐标有效
	{
		OpenCard[lv][pos] = new Card;
		return true;
	}
	else return false;
}
int Table::Operate(Player* player)//加入operate函数作为接口,接收玩家的操作，调用不同的函数或者结束回合
{
	//接口，显示界面

	//应有选择菜单
	/*Take(Players[i]);
	Buy(Players[i]);
	Reserve(Players[i]);
	以及结束回合的选项*/

}
bool Table::Take(Player* player)//调用相应玩家的相应函数,记录拿的次数和规则检查
{
	//接口,接收所选择的宝石颜色以及数量,保证按规则取
	int diamond[6] = { 0 };//储存要取的宝石
	//player->TotalDiamonds()表示玩家拥有的宝石数
	player->Take(diamond);
	return true;
	//可以增加取消选项return false;
}
bool Table::Buy(Player* player, int lv, int pos)//买场上翻开的卡,接口,需接收界面返回的卡的二维数组坐标,调用相应玩家的Buy()
{
	if (player->CanBuy(OpenCard[lv][pos]))//如果他可以买
	{
		player->Buy(OpenCard[lv][pos]);//那就买
		delete OpenCard[lv][pos];
		CreateCard(lv, pos);
		return true;
	}
	else
	{
		//需要输出买不起的提示
		return false;
	}
}
bool Table::Buy(Player* player, int order)//买自己扣留的卡,接口,需接收界面返回的已扣留卡的数组坐标,调用相应玩家的Buy()
{
	if (player->CanBuy(player->Reserved[order]))//如果他可以买
	{
		player->Buy(player->Reserved[order]);//那就买
		delete player->Reserved[order];
		player->Reserved[order] = NULL;
		return true;
	}
	else
	{
		//需要输出买不起的提示
		return false;
	}
}
bool Table::Reserve(Player* player, int lv, int pos)//接口,需接收界面返回的卡的二维数组坐标,调用相应玩家的相应函数
{
	if (player->CanReserve())//检查是否能够扣留卡
	{
		bool GoldLeft = 0;
		if (Diamonds[Gold] > 0)
			GoldLeft = 1;
		if (player->Reserve(OpenCard[lv][pos], GoldLeft))//扣卡
			Diamonds[Gold]--;
		OpenCard[lv][pos] = NULL;
		CreateCard(lv, pos);//在该位置生成发展卡
		return true;
	}
	else
	{
		//需要输出扣留卡已满的提示
		return false;
	}
}
int Table::ChooseNoble(Player* player, int* canvisit)//选择贵族到访
{
	//接口,接收最终选择的贵族卡的顺序,并把order作为返回值
	while (*canvisit != 0)//非零内容表示数组中可以选择的贵族位置
	{
		//表示这个贵族可选

		//若选择,则return (*canvisit);即这个贵族的位置
	}
}
int Table::Round()//回合进行函数，对每个玩家调用Operate()，并在之后进行相应判断操作
{
	int end = 0;//表示游戏是否达到结束条件
	while (!end)
	{
		for (int i = 0; i < 2; i++)//玩家人数
		{

			Operate(Players[i]);
			//判断贵族
			int count = 0;//记录可以到访的贵族数
			int CanVisit[3] = { 0 };//储存可选择贵族的位置
			for (int j = 0; j < 3; j++)
			{
				if (Nobles[j]->CanVisit(Players[i]))
				{
					CanVisit[count] = j;//把贵族的位置信息存到数组中
					count++;
				}
			}
			if (count >= 2)//可以选择贵族
				Players[i]->NobleCome(Nobles[ChooseNoble(Players[i], CanVisit)]);
			else //只有一个贵族,不能选择
			{
				for (int j = 0; j < 3; j++)
				{
					if (Nobles[j]->CanVisit(Players[i]))
					{
						Players[i]->NobleCome(Nobles[j]);
						break;
					}
				}
			}
			if (Players[i]->Rep >= 15)
				end = 1;
		}
		//结算
	}
	return 1;//正常结束
}
