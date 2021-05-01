#include "end1.h"
#include "ui_end1.h"

END1::END1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::END1)
{
    ui->setupUi(this);
}

END1::~END1()
{
    delete ui;
}
