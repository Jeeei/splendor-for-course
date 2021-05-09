#include "choosesurface.h"
#include "ui_choosesurface.h"

chooseSurface::chooseSurface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chooseSurface)
{
    ui->setupUi(this);
    hide();
}

chooseSurface::~chooseSurface()
{
    delete ui;
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
}

void chooseSurface::on_subtract_clicked()
{
    //减少玩家人数
    emit subtract();
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
}

void chooseSurface::on_img4_clicked()
{
    //点击第四个玩家头像，更改玩家头像
    emit image4();
}
