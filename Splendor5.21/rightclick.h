#ifndef RIGHTCLICK_H
#define RIGHTCLICK_H

#include <QFrame>
#include "rightrule.h"

namespace Ui {
class RightClick;
}

class RightClick : public QFrame
{
    Q_OBJECT

public:
    explicit RightClick(QWidget *parent = 0);
    ~RightClick();

private slots:
    void on_rule_clicked();

    void on_resign_clicked();//回主界面

    void on_back_clicked();

    void on_save_clicked();

    void on_tryAgain_clicked();

signals:
    void resign();
    void save();
    void tryAgain();

private:
    Ui::RightClick *ui;
    rightRule *rrule1;

};

#endif // RIGHTCLICK_H
