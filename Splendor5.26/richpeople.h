#ifndef RICHPEOPLE_H
#define RICHPEOPLE_H

#include <QFrame>
#include <QCloseEvent>

namespace Ui {
class richPeople;
}

class richPeople : public QFrame
{
    Q_OBJECT

public:
    explicit richPeople(QWidget *parent = 0);
    ~richPeople();

    void showRich(QString s);
    void setnum(int);

private slots:
    void on_toolButton_clicked();

private:
    Ui::richPeople *ui;
    int num;

protected:
    void closeEvent(QCloseEvent *) override;
signals:
    void richScoreSignal(int);
};

#endif // RICHPEOPLE_H
