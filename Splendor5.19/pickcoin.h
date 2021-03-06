#ifndef PICKCOIN_H
#define PICKCOIN_H
#include "Splendor.h"
#include <QFrame>
#include <QToolButton>
#include <QCloseEvent>


namespace Ui {
class pickCoin;
}

class pickCoin : public QFrame
{
    Q_OBJECT

public:
    explicit pickCoin(QWidget *parent = 0);
    ~pickCoin();
    void selectDiamond(color);//记录所选宝石的信息


signals:
    void Pick_OK();
    void Pick_Close();
    void Pick_UnTake(color);

private slots:
    void on_coin1_clicked();
    void on_coin2_clicked();
    void on_coin3_clicked();

    void on_OK_clicked();

protected:
    void closeEvent(QCloseEvent *) override;
private:
    Ui::pickCoin *ui;
    color selected[3];//储存已选择宝石的颜色,Gold表示空

    void showDiamond(QToolButton *,color);//显示颜色,内部调用
    void ifclose();//判断是否关闭窗口，内部调用
};

#endif // PICKCOIN_H
