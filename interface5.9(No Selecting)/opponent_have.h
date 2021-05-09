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

    void showRed(int);
    void showGreen(int);
    void showBlue(int);
    void showWhite(int);
    void showBlack(int);
    void showGold(int);

    void showRedCard(int);
    void showGreenCard(int);
    void showBlueCard(int);
    void showWhiteCard(int);
    void showBlackCard(int);

private slots:
    void on_closeButton_clicked();


private:
    Ui::opponent_have *ui;
};

#endif // OPPONENT_HAVE_H
