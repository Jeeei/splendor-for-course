#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QSound>
#include <QTimer>
#include <windows.h>
#include <QPropertyAnimation>
#include "Splendor.h"
#include "pickcoin.h"
#include "pickcard.h"
#include "opponent_have.h"
#include "koucard.h"
#include "rightclick.h"
#include "richpeople.h"
#include "choosesurface.h"
#include "whethercontinue.h"
#include "end1.h"
#include "end2.h"

namespace Ui {
class gameInterface;
}

class gameInterface : public QWidget
{
    Q_OBJECT

public:
    explicit gameInterface(QWidget *parent = 0);
    ~gameInterface();

private slots:

    void on_card1_1_clicked();

    void on_card1_2_clicked();

    void on_card1_3_clicked();

    void on_card1_4_clicked();

    void on_card2_1_clicked();

    void on_card2_2_clicked();

    void on_card2_3_clicked();

    void on_card2_4_clicked();

    void on_card3_1_clicked();

    void on_card3_2_clicked();

    void on_card3_3_clicked();

    void on_card3_4_clicked();

    void on_selectBlack_clicked();
    void on_selectRed_clicked();
    void on_selectGreen_clicked();
    void on_selectBlue_clicked();
    void on_selectWhite_clicked();

    void on_changeMan_clicked();

    void on_oppo1_clicked();

    void on_reserved1_clicked();

    void on_reserved2_clicked();

    void on_reserved3_clicked();

    void on_re_clicked();

    void on_musicC_clicked();

private:
    Ui::gameInterface *ui;
    Table* table;
    pickCard *PickCard;
    pickCoin *PickCoin;
    opponent_have *opp1;
    kouCard *kcard;
    RightClick *rclick;
    chooseSurface *ChooseSurface;
    whetherContinue *WContinue;
    richPeople *rpeople[3];
    QSound *bsound;
    END1 *end1;
    END2 *end2;

    bool musicW = 1;//0表示不播放，1表示播放


    //点击宝石之后调用函数
    void AnyDiamondClicked(enum color);
    //点击卡片后调用显示函数
    void AnyCardClicked(int level,int num);

    //显示玩家拥有宝石
    void people1_textChanged();
    void people2_textChanged();

    //显示场上宝石
    void on_white_num_textChanged();
    void on_black_num_textChanged();
    void on_red_num_textChanged();
    void on_blue_num_textChanged();
    void on_green_num_textChanged();
    void on_gold_num_textChanged();
    //显示信息函数
    void textChanged();//刷新信息，每次操作结束后调用
    void textInit();//信息设置初始化，在构造函数中使用

    void Next();//切换下一个玩家
    void ChooseNoble();//选择noble

    //动画效果函数
    void NewCard(QAbstractButton*);
    void cardConsume(QAbstractButton*,color,bool ifnew = true);
    void cardConsume(QAbstractButton*,int);
    void CardUsed(int,int);
    void CardUsed(int,int,int);

signals:
    void gameInterfaceResign();
    void gameInterfaceEnd();

protected slots:
    //买卡片窗口槽
    void PickCard_PurchaseSlot();
    void PickCard_CancelSlot();
    //拿宝石窗口槽
    void PICK_OKSlot();
    void PICK_CancelSlot();
    void PICK_UnTake(enum color);
    //扣卡槽
    void RetainSlot();
    //选择贵族槽
    void ChooseNobleSlot(int);
    //菜单槽
    void SaveSlot();
    void gameInterfaceResignSlot();
    void TryAgainSlot();
    //继续游戏弹框槽
    void gameContinueSlot();
    void gameNewSlot();
    //选择界面槽
    void StartSlot();
    void AddSlot();
    void SubtractSlot();
    void Img1Change();
    void Img2Change();
    void Img3Change();
    void Img4Change();
    //结算界面槽
    void EndSlot();
    //显示名字
    void name1Slot(QString);
    void name2Slot(QString);
    //void name3Slot(QString);
    //void name4Slot(QString);

};

#endif // GAMEINTERFACE_H
