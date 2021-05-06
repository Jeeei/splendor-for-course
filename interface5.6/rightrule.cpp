#include "rightrule.h"
#include "ui_rightrule.h"

rightRule::rightRule(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::rightRule)
{
    ui->setupUi(this);
    setGeometry(0,0,570,660);
    hide();
}

rightRule::~rightRule()
{
    delete ui;
}

void rightRule::on_toolButton_clicked()
{
    this->hide();
}
