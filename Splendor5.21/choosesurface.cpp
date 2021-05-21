#include "choosesurface.h"
#include "ui_choosesurface.h"
#include <QDebug>

chooseSurface::chooseSurface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chooseSurface)
{
    ui->setupUi(this);
    ui->haveRead->hide();
    ui->explain->hide();

    ui->no1->hide();
    ui->no2->hide();
    ui->no3->hide();
    ui->no4->hide();

    ui->subtract->hide();

    ui->rule->setStyleSheet("border-radius:25px;border-image:url(:/images/rightRuleFor2.png)");

    hide();
}

chooseSurface::~chooseSurface()
{
    delete ui;
}

void chooseSurface::showImg1(QString img)
{
    ui->img1->setStyleSheet("border-radius:15px;"+img);
}

void chooseSurface::showImg2(QString img)
{
    ui->img2->setStyleSheet("border-radius:15px;"+img);
}

void chooseSurface::showImg3(QString img)
{
    ui->img3->setStyleSheet("border-radius:15px;"+img);
}

void chooseSurface::showImg4(QString img)
{
    ui->img4->setStyleSheet("border-radius:15px;"+img);
}

void chooseSurface::on_start_clicked()
{
    close();
    emit Start();//发送给gameinterface，游戏开始
}

void chooseSurface::on_add_clicked()
{
    //增加玩家人数
    emit add();
    ////////////////////////////////////////2
    if(nowNum==3)
    {
        nowNum=4;
        ui->add->hide();
        ui->rule->setStyleSheet("border-radius:25px;border-image:url(:/images/rightRuleFor4.png)");
        ui->img4->setStyleSheet("border-image:url(:/images/role/0.jfif);border-radius:15px");
    }
    if(nowNum==2)
    {
        ui->subtract->show();
        nowNum=3;
        ui->rule->setStyleSheet("border-radius:25px;border-image:url(:/images/rightRuleFor3.png)");
        ui->img3->setStyleSheet("border-image:url(:/images/role/2.jpg);border-radius:15px");
    }
}

void chooseSurface::on_subtract_clicked()
{
    //减少玩家人数
    emit subtract();
    /////////////////////////////////////////3
    if(nowNum==3)
    {
        nowNum=2;
        ui->subtract->hide();
        ui->rule->setStyleSheet("border-radius:25px;border-image:url(:/images/rightRuleFor2.png)");
        ui->img3->setStyleSheet("background-color: rgba(255, 255, 254, 50);border-radius:15px");
    }
    if(nowNum==4)
    {
        nowNum=3;
        ui->add->show();
        ui->rule->setStyleSheet("border-radius:25px;border-image:url(:/images/rightRuleFor3.png)");
        ui->img4->setStyleSheet("background-color: rgba(255, 255, 254, 50);border-radius:15px");
    }
}

void chooseSurface::on_img1_clicked()
{
    //点击第一个玩家头像，更改玩家头像
    emit image1();
}

void chooseSurface::on_img2_clicked()
{
    //点击第二个玩家头像，更改玩家头像
    emit image2();
}

void chooseSurface::on_img3_clicked()
{
    //点击第三个玩家头像，更改玩家头像
    emit image3();
    ui->img3->setStyleSheet("border-image:url(:/images/role/6.jpg);border-radius:15px");
}

void chooseSurface::on_img4_clicked()
{
    //点击第四个玩家头像，更改玩家头像
    emit image4();
    ui->img4->setStyleSheet("border-image:url(:/images/role/7.jpg);border-radius:15px");
}

void chooseSurface::on_help_clicked()
{
    ui->explain->show();
    ui->haveRead->show();
}

void chooseSurface::on_haveRead_clicked()
{
    ui->haveRead->hide();
    ui->explain->hide();
}

void chooseSurface::on_sequence_clicked()
{
    ifSequenceChange = 1;
    ui->no1->setText("1");
    ui->no2->setText("2");
    ui->no3->setText("3");
    ui->no4->setText("4");
    ui->no1->show();
    ui->no2->show();
    ui->no3->show();
    ui->no4->show();
    emit sequenceChange();
}

void chooseSurface::on_no1_clicked()
{
    if(ifSequenceChange)
    {
        emit no1_clicked();
    }
}

void chooseSurface::on_no2_clicked()
{
    if(ifSequenceChange)
    {
        emit no2_clicked();
    }
}

void chooseSurface::on_no3_clicked()
{
    if(ifSequenceChange)
    {
        emit no3_clicked();
    }
}

void chooseSurface::on_no4_clicked()
{
    if(ifSequenceChange)
    {
        emit no4_clicked();
    }
}

void chooseSurface::on_name1_editingFinished()
{
    emit name1(ui->name1->text());
}

void chooseSurface::on_name2_editingFinished()
{
    emit name2(ui->name2->text());
}

/*void chooseSurface::on_name3_editingFinished()
{
    emit name3(ui->name3->text());
}

void chooseSurface::on_name4_editingFinished()
{
    emit name4(ui->name4->text());
}
*/
