#ifndef WHETHERCONTINUE_H
#define WHETHERCONTINUE_H

#include <QFrame>

namespace Ui {
class whetherContinue;
}

class whetherContinue : public QFrame
{
    Q_OBJECT

public:
    explicit whetherContinue(QWidget *parent = 0);
    ~whetherContinue();

signals:
    void gameContinue();
    void gameNew();
private slots:
    void on_continue_2_clicked();

    void on_new_2_clicked();

private:
    Ui::whetherContinue *ui;
};

#endif // WHETHERCONTINUE_H
