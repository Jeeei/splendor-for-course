#include "opponent_have.h"
#include "ui_opponent_have.h"

opponent_have::opponent_have(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::opponent_have)
{
    ui->setupUi(this);
}

opponent_have::~opponent_have()
{
    delete ui;
}

void opponent_have::on_white_have_textChanged()
{
    ui->card_have->setText("0");
    ui->card_have->setAlignment( Qt::AlignHCenter );
}

void opponent_have::on_closeButton_clicked()
{
    this->hide();
}
