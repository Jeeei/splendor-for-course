#ifndef KOUCARD_H
#define KOUCARD_H

#include <QFrame>

namespace Ui {
class kouCard;
}

class kouCard : public QFrame
{
    Q_OBJECT

public:
    explicit kouCard(QWidget *parent = 0);
    ~kouCard();

    void showKouCard();

private slots:
    void on_toolButton_clicked();

    void on_cardShow_clicked();

private:
    Ui::kouCard *ui;

signals:
    void IsKou();//发送给gameInterface的信号

};

#endif // KOUCARD_H
