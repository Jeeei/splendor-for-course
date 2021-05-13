#ifndef KOUCARD_H
#define KOUCARD_H

#include <QFrame>
#include <QCloseEvent>

namespace Ui {
class kouCard;
}

class kouCard : public QFrame
{
    Q_OBJECT

public:
    explicit kouCard(QWidget *parent = 0);
    ~kouCard();

    void showCard(QString);
    void showGold();
protected:
    void closeEvent(QCloseEvent *) override;
private slots:
    void on_toolButton_clicked();

    void on_ShowCard_clicked();

private:
    Ui::kouCard *ui;

signals:
    void Retain();//发送给gameInterface的信号

};

#endif // KOUCARD_H
