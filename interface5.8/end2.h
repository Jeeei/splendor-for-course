#ifndef END2_H
#define END2_H

#include <QWidget>

namespace Ui {
class END2;
}

class END2 : public QWidget
{
    Q_OBJECT

public:
    explicit END2(QWidget *parent = 0);
    ~END2();

    void showNo1(QString);
    void showNo2(QString);
    void showNo3(QString);

private:
    Ui::END2 *ui;
};

#endif // END2_H
