#ifndef DIALOG2_H
#define DIALOG2_H
#include "Splendor.h"
#include <QDialog>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();
    void showBlack();
    void showRed();
    void showGreen();
    void showBlue();
    void showWhite();
    void selectDiamond(int,color);
    void clearDiamond();
private:
    Ui::Dialog2 *ui;
    int selected[3]={-1,-1,-1};//已选择宝石数
    int numDiamond = 0;
signals:
    void dialog2OK();

protected slots:
    void ClickedOK()
    {
        emit dialog2OK();
    }
};

#endif // DIALOG2_H
