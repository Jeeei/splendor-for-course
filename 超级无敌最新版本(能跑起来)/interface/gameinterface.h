#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include "dialog.h"
#include "dialog2.h"
#include "Splendor.h"

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

    void on_people1_clicked();

    void on_people2_clicked();

    void on_require1_1_1_textChanged();

    void on_require1_1_3_textChanged();

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

    void on_toolButton_clicked();


    void on_toolButton_triggered(QAction *arg1);

    void on_changeMan_clicked();

private:
    Ui::gameInterface *ui;
    Dialog *dialog;
    Dialog2 *dialog2;
    Table* table;


    //点击宝石之后调用函数
    void AnyDiamondClicked(enum color);
    //点击卡片后调用显示函数
    void AnyCardClicked(int level,int num);

    //显示玩家拥有宝石
    void on_white_have_textChanged();
    void on_blue_have_textChanged();
    void on_green_have_textChanged();
    void on_red_have_textChanged();
    void on_black_have_textChanged();
    void on_gold_have_textChanged();
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

protected slots:
   void DialogPurchaseSlot();
   void DialogCancelSlot();
   void dialog2OKSlot();
   void dialog2CancelSlot();
   void dialog2CancelTake(enum color);
};

#endif // GAMEINTERFACE_H
