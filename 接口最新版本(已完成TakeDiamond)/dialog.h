#ifndef DIALOG_H
#define DIALOG_H

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
    void showImageChanged();//显示贴图

private:
    Ui::Dialog *ui;

signals:
   void DialogPurchase();//发送给主窗口的信号
   void DialogCancel();


protected slots:
   void ClickedPurchase()
   {
      // 触发子窗口的信号给父窗口接收
      emit DialogPurchase();
   }
   void ClickedCancel()
   {
       emit DialogCancel();
   }
};

#endif // DIALOG_H
