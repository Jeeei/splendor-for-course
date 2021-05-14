#ifndef RULE_H
#define RULE_H

#include <QFrame>

namespace Ui {
class Rule;
}

class Rule : public QFrame
{
    Q_OBJECT

public:
    explicit Rule(QWidget *parent = 0);
    ~Rule();

private slots:
    void on_back2_clicked();

    void on_back1_clicked();

private:
    Ui::Rule *ui;
};

#endif // RULE1_H
