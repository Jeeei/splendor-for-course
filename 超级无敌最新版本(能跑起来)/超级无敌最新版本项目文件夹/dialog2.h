#ifndef DIALOG2_H
#define DIALOG2_H
#include "Splendor.h"
#include <QDialog>
#include <QCloseEvent>
#include <QToolButton>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();
    void selectDiamond(color);//记录所选宝石的信息
    void clearDiamond();//清空临时变量
    bool getStatus()const{
        return status;
    }
    void OpenStatus(){
        status = 1;
    }
private:
    Ui::Dialog2 *ui;
    color selected[3]={Gold,Gold,Gold};//储存已选择宝石的颜色,Gold表示空
    bool status = 0;//记录窗口是否已打开,0为关闭,1为打开

    void showDiamond(QToolButton *,color);//显示颜色,内部调用

signals:
    void dialog2OK();
    void dialog2close();
    void Cancel_selected(color);

protected slots:
    void select1_clicked();
    void ClickedOK()
    {
        emit dialog2OK();
        close();
    }
protected:
    void closeEvent(QCloseEvent *) override;
private slots:
    void on_selected1_clicked();
    void on_selected2_clicked();
    void on_selected3_clicked();
};

#endif // DIALOG2_H
