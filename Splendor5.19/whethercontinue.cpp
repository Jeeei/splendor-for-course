#include "whethercontinue.h"
#include "ui_whethercontinue.h"

whetherContinue::whetherContinue(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::whetherContinue)
{
    ui->setupUi(this);
    hide();
}

whetherContinue::~whetherContinue()
{
    delete ui;
}

void whetherContinue::on_continue_2_clicked()
{
    close();
    emit gameContinue();
}

void whetherContinue::on_new_2_clicked()
{
    close();
    emit gameNew();
}
