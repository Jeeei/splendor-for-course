#ifndef PICKCARD_H
#define PICKCARD_H

#include <QFrame>

namespace Ui {
class pickCard;
}

class pickCard : public QFrame
{
    Q_OBJECT

public:
    explicit pickCard(QWidget *parent = 0);
    ~pickCard();

    void showCard();
private slots:
    void on_cardShow_clicked();

    void on_purchase_clicked();

private:
    Ui::pickCard *ui;
};

#endif // PICKCARD_H
