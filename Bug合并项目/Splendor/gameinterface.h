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
    friend class Table;
public:
    explicit gameInterface(QWidget *parent = 0);
    ~gameInterface();


private slots:
    void on_card1_1_clicked();

    void on_white_num_textChanged();

    void on_black_num_textChanged();

    void on_red_num_textChanged();

    void on_blue_num_textChanged();

    void on_green_num_textChanged();

    void on_gold_num_textChanged();

    void on_people1_clicked(bool checked);

    void on_people2_clicked(bool checked);

    void on_require1_1_1_textChanged();

    void on_require1_1_3_textChanged();

    void on_card1_2_clicked(bool checked);

    void on_card1_3_clicked(bool checked);

    void on_card1_4_clicked();

    void on_card2_1_clicked(bool checked);

    void on_card2_2_clicked(bool checked);

    void on_card2_3_clicked(bool checked);

    void on_card2_4_clicked(bool checked);

    void on_card3_1_clicked(bool checked);

    void on_card3_2_clicked(bool checked);

    void on_card3_3_clicked(bool checked);

    void on_card3_4_clicked(bool checked);

    void on_card1_1_pressed();

    void on_card2_1_clicked();

    void on_selectBlack_clicked();

    void on_selectRed_clicked();

    void on_selectGreen_clicked();

    void on_toolButton_clicked();

private:
    /*这个是在gameinterface.h文件gameinterface类的定义里的private数据成员，我的想法是
     *在gameinterface类中定义一个Table成员,即游戏主类,然后在买卡片和选宝石的DialogPurchaseSlot()
     *和dialog2OKSlot()里加入对Table的操作以实现后端逻辑,但是出现了这个错误,一直不能解决
     *测试过,不是头文件没包括的问题,这tm就离谱
     *另外
     *就算把后端接上本来也实现不了太多功能,甚至只把界面生成的exe程序交上去就是结果*/
    Table *table;
    Ui::gameInterface *ui;
    Dialog *dialog;
    Dialog2 *dialog2;

protected slots:
   void DialogPurchaseSlot();
   void DialogCancelSlot();
   void dialog2OKSlot();
};

#endif // GAMEINTERFACE_H
