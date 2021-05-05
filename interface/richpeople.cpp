#include "richpeople.h"
#include "ui_richpeople.h"

richPeople::richPeople(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::richPeople)
{
    ui->setupUi(this);
}

richPeople::~richPeople()
{
    delete ui;
}

void richPeople::showRich()
{
    ui->rich->setStyleSheet("border-radius:65px;border-image:url(:/images/贵族/1.png)");
}

void richPeople::on_rich_clicked()
{
    this->close();
}

void richPeople::on_toolButton_clicked()
{
    emit richScoreSignal();
    this->close();
}
