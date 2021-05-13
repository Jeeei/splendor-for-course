#include "rule.h"
#include "ui_rule.h"

Rule::Rule(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Rule)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);     //隐藏窗体标题栏
}

Rule::~Rule()
{
    delete ui;
}

void Rule::on_back2_clicked()
{
    this->hide();
}

void Rule::on_back1_clicked()
{
    this->hide();
}
