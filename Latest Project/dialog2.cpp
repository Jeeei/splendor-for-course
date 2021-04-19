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


void Dialog2::showBlack()//选择黑宝石
{
    switch(numDiamond)
    {
    case 1:
        ui->selected1->setStyleSheet("border-image:url(:/images/black.PNG)");
        break;
    case 2:
        ui->selected2->setStyleSheet("border-image:url(:/images/black.PNG)");
        break;
    case 3:
        ui->selected3->setStyleSheet("border-image:url(:/images/black.PNG)");
        break;
    default:
        break;
    }
}
void Dialog2::showRed()//选择红宝石
{
    switch(numDiamond)
    {
    case 1:
        ui->selected1->setStyleSheet("border-image:url(:/images/red.PNG)");
        break;
    case 2:
        ui->selected2->setStyleSheet("border-image:url(:/images/red.PNG)");
        break;
    case 3:
        ui->selected3->setStyleSheet("border-image:url(:/images/red.PNG)");
        break;
    default:
        break;
    }
}
void Dialog2::showGreen()//选择绿宝石
{
    switch(numDiamond)
    {
    case 1:
        ui->selected1->setStyleSheet("border-image:url(:/images/green.PNG)");
        break;
    case 2:
        ui->selected2->setStyleSheet("border-image:url(:/images/green.PNG)");
        break;
    case 3:
        ui->selected3->setStyleSheet("border-image:url(:/images/green.PNG)");
        break;
    default:
        break;
    }

}
void Dialog2::showBlue()//选择蓝宝石
{
    switch(numDiamond)
    {
    case 1:
        ui->selected1->setStyleSheet("border-image:url(:/images/blue.PNG)");
        break;
    case 2:
        ui->selected2->setStyleSheet("border-image:url(:/images/blue.PNG)");
        break;
    case 3:
        ui->selected3->setStyleSheet("border-image:url(:/images/blue.PNG)");
        break;
    default:
        break;
    }

}
void Dialog2::showWhite()//选择白宝石
{
    switch(numDiamond)
    {
    case 1:
        ui->selected1->setStyleSheet("border-image:url(:/images/white.PNG)");
        break;
    case 2:
        ui->selected2->setStyleSheet("border-image:url(:/images/white.PNG)");
        break;
    case 3:
        ui->selected3->setStyleSheet("border-image:url(:/images/white.PNG)");
        break;
    default:
        break;
    }
}

void Dialog2::selectDiamond(int takendiamond, color co)//takendiamond为拿了的宝石数
{
    numDiamond = takendiamond;
    selected[takendiamond - 1] = co;
}
void Dialog2::clearDiamond()
{
    numDiamond = 0;
    for(int i = 0; i < 3; i++)
    selected[i] = -1;
}
