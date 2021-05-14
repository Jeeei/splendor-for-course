#ifndef END1_H
#define END1_H

#include <QWidget>

namespace Ui {
class END1;
}

class END1 : public QWidget
{
    Q_OBJECT

public:
    explicit END1(QWidget *parent = 0);
    ~END1();

    void showNo1(QString);
    void showNo2(QString);
    void showScore1(int);
    void showScore2(int);

signals:
    void end();

private slots:
    void on_back_clicked();

private:
    Ui::END1 *ui;

};

#endif // END1_H
