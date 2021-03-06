#include "pickcoin.h"
#include "ui_pickcoin.h"

pickCoin::pickCoin(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::pickCoin)
{
    ui->setupUi(this);
    for(int i = 0; i < 3; i++)
    {
        selected[i] = Gold;
    }
    setGeometry(999,668,400,130);
    hide();
}

pickCoin::~pickCoin()
{
    delete ui;
}

void pickCoin::selectDiamond(color co)//选择宝石函数，包含显示功能
{
    for(int i = 0; i < 3; i++)
    {
        if(selected[0] == Gold)
        {
            showDiamond(ui->coin1,co);
            selected[0] = co;
            break;
        }
        if(selected[1] == Gold)
        {
            showDiamond(ui->coin2,co);
            selected[1] = co;
            break;
        }
        if(selected[2] == Gold)
        {
            showDiamond(ui->coin3,co);
            selected[2] = co;
            break;
        }
    }
}

void pickCoin::showDiamond(QToolButton * selectedButton,color co)
{
    switch(co)
    {
    case Red:
        selectedButton->setStyleSheet("border-image:url(:/images/red.PNG);border-radius:55px");
        break;
    case Black:
        selectedButton->setStyleSheet("border-image:url(:/images/black.PNG);border-radius:55px");
        break;
    case Blue:
        selectedButton->setStyleSheet("border-image:url(:/images/blue.PNG);border-radius:55px");
        break;
    case Green:
        selectedButton->setStyleSheet("border-image:url(:/images/green.PNG);border-radius:55px");
        break;
    case White:
        selectedButton->setStyleSheet("border-image:url(:/images/white.PNG);border-radius:55px");
        break;
    default:
        break;
    }
}

void pickCoin::ifclose()//判断是否需要关闭窗口
{
    int cl = 1;
    for(int i = 0;i < 3;i++)
    {
        if(selected[i] != Gold)
        {
            cl = 0;
            break;
        }
    }
    if(cl)
        close();
}

void pickCoin::closeEvent(QCloseEvent *)//关闭窗口函数
{
    emit Pick_Close();
    for(int i = 0; i < 3; i++)
    {
        selected[i] = Gold;
    }
    ui->coin1->setStyleSheet("border-radius:55px;background-color: rgba(255, 255, 254, 50);");
    ui->coin2->setStyleSheet("border-radius:55px;background-color: rgba(255, 255, 254, 50);");
    ui->coin3->setStyleSheet("border-radius:55px;background-color: rgba(255, 255, 254, 50);");
}

void pickCoin::on_coin1_clicked()
{
    if(selected[0] != Gold)
    {
        emit Pick_UnTake(selected[0]);
        selected[0] = Gold;
        ui->coin1->setStyleSheet("border-radius:55px;background-color: rgba(255, 255, 254, 50);");
    }
    ifclose();
}

void pickCoin::on_coin2_clicked()
{
    if(selected[1] != Gold)
    {
        emit Pick_UnTake(selected[1]);
        selected[1] = Gold;
        ui->coin2->setStyleSheet("border-radius:55px;background-color: rgba(255, 255, 254, 50);");
    }
    ifclose();
}

void pickCoin::on_coin3_clicked()
{
    if(selected[2] != Gold)
    {
        emit Pick_UnTake(selected[2]);
        selected[2] = Gold;
        ui->coin3->setStyleSheet("border-radius:55px;background-color: rgba(255, 255, 254, 50);");
    }
    ifclose();
}

void pickCoin::on_OK_clicked()
{
    {
        emit Pick_OK();
        close();
    }
}
