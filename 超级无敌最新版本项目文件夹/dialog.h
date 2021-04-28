#ifndef DIALOG_H
#define DIALOG_H
#include <QCloseEvent>
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void showImageChanged(QString s);//显示贴图

private:
    Ui::Dialog *ui;

signals:
   void DialogPurchase();//发送给主窗口的信号
   void DialogCancel();

protected:
   void closeEvent(QCloseEvent *) override;
protected slots:
   void ClickedPurchase()
   {
       // 触发子窗口的信号给父窗口接收
       emit DialogPurchase();
       close();
   }
   void ClickedCancel()
   {
       close();
   }
};

#endif // DIALOG_H
