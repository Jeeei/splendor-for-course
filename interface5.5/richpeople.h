#ifndef RICHPEOPLE_H
#define RICHPEOPLE_H

#include <QFrame>

namespace Ui {
class richPeople;
}

class richPeople : public QFrame
{
    Q_OBJECT

public:
    explicit richPeople(QWidget *parent = 0);
    ~richPeople();

    void showRich();

private slots:
    void on_rich_clicked();

    void on_toolButton_clicked();

private:
    Ui::richPeople *ui;

signals:
    void richScoreSignal();
};

#endif // RICHPEOPLE_H
