#ifndef PICKCARD_H
#define PICKCARD_H
#include <QCloseEvent>
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

    void showCard(QString s);//显示贴图
protected:
   void closeEvent(QCloseEvent *) override;
signals://发送给主窗口的信号
   void Purchase();
   void PickCardCancel();
private slots:
    void on_cardShow_clicked();
    void on_purchase_clicked()
    {
        // 触发子窗口的信号给父窗口接收
        emit Purchase();
        close();
    }

private:
    Ui::pickCard *ui;
};

#endif // PICKCARD_H
