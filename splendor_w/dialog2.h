#ifndef DIALOG2_H
#define DIALOG2_H
#include "Splendor.h"
#include <QDialog>
#include <QCloseEvent>

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
    void selectDiamond(int,color);//记录所选宝石的信息
    void clearDiamond();//清空临时变量
    bool getStatus()const{
        return status;
    }
    bool OpenStatus(){
        status = 1;
    }
private:
    Ui::Dialog2 *ui;
    int selected[3]={-1,-1,-1};//储存已选择宝石的颜色
    int numDiamond = 0;//已选择宝石数
    bool status = 0;//记录窗口是否已打开,0为关闭,1为打开
signals:
    void dialog2OK();
    void dialog2close();

protected slots:
    void ClickedOK()
    {
        emit dialog2OK();
    }
protected:
    void closeEvent(QCloseEvent *) override;
};

#endif // DIALOG2_H
