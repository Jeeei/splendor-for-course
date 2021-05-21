#include "richpeople.h"
#include "ui_richpeople.h"

richPeople::richPeople(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::richPeople)
{
    ui->setupUi(this);
    num = -1;
    hide();
}

richPeople::~richPeople()
{
    delete ui;
}

void richPeople::showRich(QString nobleImg)
{
    ui->rich->setStyleSheet("border-radius:55px;"+nobleImg);
}

void richPeople::setnum(int n)
{
    num = n;
}

void richPeople::on_toolButton_clicked()
{
    emit richScoreSignal(num);
    this->close();
}

void richPeople::closeEvent(QCloseEvent *)
{
    setnum(-1);
}
