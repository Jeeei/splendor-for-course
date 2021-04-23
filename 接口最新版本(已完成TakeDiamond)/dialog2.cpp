#include "dialog2.h"
#include "ui_dialog2.h"
#include "Splendor.h"

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

void Dialog2::selectDiamond(color co)//选择宝石函数，包含显示功能
{
    for(int i=0;i<3;i++)
    {
        if(selected[0] == Gold)
        {
            showDiamond(ui->selected1,co);
            selected[0] = co;
            break;
        }
        if(selected[1] == Gold)
        {
            showDiamond(ui->selected2,co);
            selected[1] = co;
            break;
        }
        if(selected[2] == Gold)
        {
            showDiamond(ui->selected3,co);
            selected[2] = co;
            break;
        }
    }
}

void Dialog2::clearDiamond()//清空dialog里的宝石信息
{
    for(int i = 0; i < 3; i++)
        selected[i] = Gold;
}

void Dialog2::showDiamond(QToolButton * selectedButton,color co)
{
    switch(co)
    {
    case Red:
        selectedButton->setStyleSheet("border-image:url(:/images/red.PNG)");
        break;
    case Black:
        selectedButton->setStyleSheet("border-image:url(:/images/black.PNG)");
        break;
    case Blue:
        selectedButton->setStyleSheet("border-image:url(:/images/blue.PNG)");
        break;
    case Green:
        selectedButton->setStyleSheet("border-image:url(:/images/green.PNG)");
        break;
    case White:
        selectedButton->setStyleSheet("border-image:url(:/images/white.PNG)");
        break;
    default:
        break;
    }
}

void Dialog2::closeEvent(QCloseEvent *)
{
    status = 0;//窗口状态设为关闭
    clearDiamond();//清空dialog里的宝石信息
    emit dialog2close();
}


//unfinished
void Dialog2::on_selected1_clicked()
{
    if(selected[0] != Gold)
    {
        emit Cancel_selected(selected[0]);
        selected[0] = Gold;
        ui->selected1->setStyleSheet("QToolButton{border:none;background:rgb:(255,255,255);color:rgb:(0,0,0)}");
    }
}

void Dialog2::on_selected2_clicked()
{
    if(selected[1] != Gold)
    {
        emit Cancel_selected(selected[1]);
        selected[1] = Gold;
        ui->selected2->setStyleSheet("QToolButton{border:none;background:rgb:(255,255,255);color:rgb:(0,0,0)}");
    }
}

void Dialog2::on_selected3_clicked()
{
    if(selected[2] != Gold)
    {
        emit Cancel_selected(selected[2]);
        selected[2] = Gold;
        ui->selected3->setStyleSheet("QToolButton{border:none;background:rgb:(255,255,255);color:rgb:(0,0,0)}");
    }
}
