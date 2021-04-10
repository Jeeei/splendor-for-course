#pragma once
#include <iostream>
#include<fstream>
enum color { Red, Green, Blue, White, Black, Gold };//��ʯ��ɫ
using namespace std;
class Card //��չ����
{
	friend class Player;
	friend class Table;//�������Ȩ��(������Ҫ���ܶ����У�
public:
	Card();
	Card(color, int*, int);//Ŀǰֱ�Ӵ������ɿ�Ƭ�������
	color GetBonus()const;//����bonus 
	void GetPrice(int*)const;//�����ڴ����int*
	int GetRep()const;//����reputation
	Card* next = NULL;
private:
	color Bonus;//��������ʯ��ɫ��������
	int Price[6];//����չ�����豦ʯ������/* ��price[color]����*/
	int Rep;//��������
	fstream& operator<<(Card&);//�ļ��洢ʱ��ʼ��ʱ��ʼ���ʹ�����Ϣ
	fstream& operator>>(Card&);
};

class Noble//������  
{
public:
	Noble();
	Noble(int rep, int* con);
	int GetRep()const;//��ʾ��������
	void GetCondition(int*)const;
	bool CanVisit(Player*);//����ܷ�������
private:
	int Rep;//��������
	int Condition[6];//���嵽�õı�ʯ����
	//ָ��ͼƬ��ָ��
};

class Player//����࣬������ҵ���Ϣ
{
	friend class Table;//�������Ȩ��
public:
	Player();
	~Player();
	bool Take(int*, int l = 6);//�ñ�ʯ ��һ����Table.Take()���϶��Ϸ���Diamond[6]
	bool Buy(Card*);//�� 
	bool Reserve(Card*, bool);//�ۿ�,bool������ʾ�����Ƿ��лƽ�ʣ��,����player��ʯ�Ƿ����
	int NobleCome(Noble*);//���嵽��
	void GetDiamonds(int*);//���ر�ʯ  
	void GetBonus(int*);//�������ӵ�еĺ����� /*Cards��ʱֻ��������ɫ*/
	bool CanBuy(Card* card);//�������ܷ���
	bool CanReserve()const;//�������ܷ�ۿ�

protected:
	int Diamonds[6];//���ӵ�еı�ʯ��
	int Rep = 0;//���ӵ�е���������
	Noble* Nobles[5];//���ӵ�еĹ��忨
	int Cards[6];//���ӵ�еķ�չ��/*��ʱ�����濨Ƭ��Ϣֻ���治ͬ��ɫ������*/
	Card* Reserved[3];
	int TotalDiamonds()const;//�������ӵ��ȫ����ʯ��

};


class Table
{
public:
	Table();
	bool Start();//���û�������ʼ�� ������2��Players������Init ������������ѡ��
	bool Init();//���û��޹س�ʼ�� �ɱ�Start()���� ���ɹ̶���Cards��Nobles����
	int Round();//�غϽ��к�������ÿ����ҵ���Operate()������֮�������Ӧ�жϲ���
	bool Take(Player*);//������Ӧ��ҵ���Ӧ����,��¼�õĴ����͹�����
	bool Buy(Player*, int, int);//���Ϸ����Ŀ�,�ӿ�,����ս��淵�صĿ��Ķ�ά��������,������Ӧ��ҵ�Buy()
	bool Buy(Player*, int);//���Լ������Ŀ�,�ӿ�,����ս��淵�ص��ѿ���������������,������Ӧ��ҵ�Buy()
	bool Reserve(Player*, int, int);//�ӿ�,����ս��淵�صĿ��Ķ�ά��������,������Ӧ��ҵ���Ӧ����
	bool CreateCard(int, int);//���ɷ�չ��,lv��coordΪ��ά��������

	int Operate(Player*);//����operate������Ϊ�ӿ�,������ҵĲ��������ò�ͬ�ĺ������߽����غ�
	int ChooseNoble(Player*, int*);//ѡ����嵽��
	int ShowDiamonds();//��ʾ����ʣ�౦ʯ����������ӿ�
private:
	Card* CardHead[3];//δ�����Ŀ� /*��ע��1
	Card* OpenCard[3][4];//�����Ŀ� 
	Noble* Nobles[5];//ʹ�õĹ���
	int Diamonds[6];//�����ϵı�ʯʣ��
	Player* Players[4];//���
};

/*ע��1��ÿ����һ��Card����Noble�ʹ���һ��ָ�����ָ�룬��Table��Playerӵ��
Card��Nobleʱ������ָ�������е�ָ��ָ���Card����Noble����֤һ��Card����Noble
ͬʱֻ��һ��ָ��ָ����
ע��2��ʵ������ĸ��д���β�ȫСд

�Ȱ�ɶ�������
��Table������ĳ�Ա������Table.Init() Table.Start()
Ŀǰֱ�Ӵ��γ�ʼ����Ƭ�����壬���棬�ļ������ü��Ͳ�

*/







