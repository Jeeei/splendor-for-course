#ifndef PICKCOIN_H
#define PICKCOIN_H

#include <QFrame>

namespace Ui {
class pickCoin;
}

class pickCoin : public QFrame
{
    Q_OBJECT

public:
    explicit pickCoin(QWidget *parent = 0);
    ~pickCoin();

    void showCoin1();

private slots:
    void on_coin1_clicked();

    void on_OK_clicked();

private:
    Ui::pickCoin *ui;
};

#endif // PICKCOIN_H
