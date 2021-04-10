#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include "dialog.h"

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

private:
    Ui::gameInterface *ui;
    Dialog *dialog;

protected slots:
   void DialogPurchaseSlot();
   void DialogCancelSlot();
};

#endif // GAMEINTERFACE_H
