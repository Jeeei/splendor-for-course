#include "dialog.h"
#include "ui_dialog.h"
#include <QObject>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->purchase, SIGNAL(clicked()), SLOT(ClickedPurchase()));
    connect(ui->cancel,SIGNAL(clicked()),SLOT(ClickedCancel()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showImageChanged(QString s)//显示贴图
{
    ui->label->setStyleSheet(s);
}

void Dialog::closeEvent(QCloseEvent *)
{
    emit DialogCancel();
}
