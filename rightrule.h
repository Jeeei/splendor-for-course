#ifndef RIGHTRULE_H
#define RIGHTRULE_H

#include <QFrame>

namespace Ui {
class rightRule;
}

class rightRule : public QFrame
{
    Q_OBJECT

public:
    explicit rightRule(QWidget *parent = 0);
    ~rightRule();

private slots:
    void on_toolButton_clicked();

private:
    Ui::rightRule *ui;
};

#endif // RIGHTRULE_H
