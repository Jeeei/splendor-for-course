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

void Dialog2::showBlack()
{
    ui->selected1->setStyleSheet("border-image:url(:/images/black.PNG)");
}

void Dialog2::showRed()
{
    ui->selected2->setStyleSheet("border-image:url(:/images/red.PNG)");
}

void Dialog2::showGreen()
{
    ui->selected3->setStyleSheet("border-image:url(:/images/green.PNG)");
}
