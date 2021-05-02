#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include "pickcoin.h"
#include "pickcard.h"
#include "opponent_have.h"
#include "rightclick.h"

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

    void on_white_num_textChanged();

    void on_black_num_textChanged();

    void on_red_num_textChanged();

    void on_blue_num_textChanged();

    void on_green_num_textChanged();

    void on_gold_num_textChanged();

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

    void on_white_have_textChanged();

    void on_green_have_textChanged();

    void on_red_have_textChanged();

    void on_black_have_textChanged();

    void on_re_clicked();

    void on_oppo1_clicked();

private:
    Ui::gameInterface *ui;
    pickCoin *PickCoin;
    pickCard *PickCard;
    opponent_have * opp1;
    RightClick *rclick;

    int color;
    int action;//用来表示行为，0表示拿，1表示买

};

#endif // GAMEINTERFACE_H
