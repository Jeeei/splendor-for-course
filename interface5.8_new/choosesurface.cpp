#include "choosesurface.h"
#include "ui_choosesurface.h"

chooseSurface::chooseSurface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chooseSurface)
{
    ui->setupUi(this);
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
    //GetSetPlayerNum()//返回设置的玩家人数
    table->AlterPlayerNum(1);
    emit add();
}

void chooseSurface::on_subtract_clicked()
{
    //减少玩家人数
    //table->GetSetPlayerNum()//返回设置的玩家人数
    table->AlterPlayerNum(-1);
    emit subtract();
}

void chooseSurface::on_img1_clicked()
{
    //点击第一个玩家头像，更改玩家头像
    //table->GetPlayerPic(1);
    table->AlterPlayerPic(1);
    emit image1();
}

void chooseSurface::on_img2_clicked()
{
    //点击第二个玩家头像，更改玩家头像
    //table->GetPlayerPic(2);
    table->AlterPlayerPic(2);
    emit image2();

}

void chooseSurface::on_img3_clicked()
{
    //点击第三个玩家头像，更改玩家头像
    //table->GetPlayerPic(3);
    table->AlterPlayerPic(3);
    emit image3();
}

void chooseSurface::on_img4_clicked()
{
    //点击第四个玩家头像，更改玩家头像
    //table->GetPlayerPic(4);
    table->AlterPlayerPic(4);
    emit image4();
}

/*
 * //更改玩家姓名函数
 * {
 *  table->AlterPlayerName(int no, QString a);
 *  table->GetPlayerName(int no)
 * }
 *
 * //点击随机/固定顺序按钮
 * {
 *  table->AlterIfRandom();
 *  if(!table->GetIfRandom())
 *      {
 *          //展示顺序
 *      }
 * }
 *
 * //点击玩家No的次序将其设为先手
 * {
 *  table->AlterFirst(no);
 *  table->GetFirst();
 *  //第no个玩家的顺序sqe
 *      if(no>=GetFirst()) sqe=(no-GetFirst)+1;
 *      else sqe=(no-GetFirst)+1+sPlayerNum;
 * }
 *
*/
