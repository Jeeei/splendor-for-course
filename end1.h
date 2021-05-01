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

private:
    Ui::END1 *ui;
};

#endif // END1_H
