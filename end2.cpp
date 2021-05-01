#include "end2.h"
#include "ui_end2.h"

END2::END2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::END2)
{
    ui->setupUi(this);
}

END2::~END2()
{
    delete ui;
}
