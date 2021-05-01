#ifndef OPPONENT_HAVE_H
#define OPPONENT_HAVE_H

#include <QFrame>

namespace Ui {
class opponent_have;
}

class opponent_have : public QFrame
{
    Q_OBJECT

public:
    explicit opponent_have(QWidget *parent = 0);
    ~opponent_have();

private slots:
    void on_white_have_textChanged();

    void on_closeButton_clicked();

private:
    Ui::opponent_have *ui;
};

#endif // OPPONENT_HAVE_H
