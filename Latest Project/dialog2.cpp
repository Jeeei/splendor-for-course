#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    connect(ui->OK,SIGNAL(clicked()),SLOT(ClickedOK()));
}

Dialog2::~Dialog2()
{
    delete ui;
}

//unfinished
void Dialog2::showBlack()//选择黑宝石
{
    ui->selected1->setStyleSheet("border-image:url(:/images/black.PNG)");
}
void Dialog2::showRed()//选择红宝石
{
    ui->selected2->setStyleSheet("border-image:url(:/images/red.PNG)");
}
void Dialog2::showGreen()//选择绿宝石
{
    ui->selected3->setStyleSheet("border-image:url(:/images/green.PNG)");
}
void Dialog2::showBlue()//选择蓝宝石
{
    ui->selected3->setStyleSheet("border-image:url(:/images/blue.PNG)");
}
void Dialog2::showWhite()//选择白宝石
{
    ui->selected3->setStyleSheet("border-image:url(:/images/white.PNG)");
}
