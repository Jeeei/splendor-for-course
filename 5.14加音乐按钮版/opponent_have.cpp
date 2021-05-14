#include "opponent_have.h"
#include "ui_opponent_have.h"

opponent_have::opponent_have(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::opponent_have)
{
    ui->setupUi(this);
    setGeometry(0,40,183,151);

    ui->red_have->setFontPointSize(qreal(20));
    ui->red_have->setTextColor(QColor(255,255,255));
    ui->green_have->setFontPointSize(qreal(20));
    ui->green_have->setTextColor(QColor(255,255,255));
    ui->blue_have->setFontPointSize(qreal(20));
    ui->blue_have->setTextColor(QColor(255,255,255));
    ui->white_have->setFontPointSize(qreal(20));
    ui->white_have->setTextColor(QColor(255,255,255));
    ui->white_have->setFontPointSize(qreal(20));
    ui->black_have->setTextColor(QColor(255,255,255));
    ui->gold_have->setFontPointSize(qreal(20));
    ui->gold_have->setTextColor(QColor(255,255,255));

    ui->red_card->setFontPointSize(qreal(16));
    ui->red_card->setAlignment( Qt::AlignHCenter );
    ui->green_card->setFontPointSize(qreal(16));
    ui->green_card->setAlignment( Qt::AlignHCenter );
    ui->blue_card->setFontPointSize(qreal(16));
    ui->blue_card->setAlignment( Qt::AlignHCenter );
    ui->white_card->setFontPointSize(qreal(16));
    ui->white_card->setAlignment( Qt::AlignHCenter );
    ui->black_card->setFontPointSize(qreal(16));
    ui->black_card->setAlignment( Qt::AlignHCenter );

    hide();
}

opponent_have::~opponent_have()
{
    delete ui;
}

void opponent_have::showRed(int num)
{
    ui->red_have->setText(QString::number(num));
}

void opponent_have::showGreen(int num)
{
    ui->green_have->setText(QString::number(num));
}

void opponent_have::showBlue(int num)
{
    ui->blue_have->setText(QString::number(num));
}

void opponent_have::showWhite(int num)
{
    ui->white_have->setText(QString::number(num));
}

void opponent_have::showBlack(int num)
{
    ui->black_have->setText(QString::number(num));
}

void opponent_have::showGold(int num)
{
    ui->gold_have->setText(QString::number(num));
}

void opponent_have::showRedCard(int num)
{
    ui->red_card->setText(QString::number(num));
}

void opponent_have::showGreenCard(int num)
{
    ui->green_card->setText(QString::number(num));
}

void opponent_have::showBlueCard(int num)
{
    ui->blue_card->setText(QString::number(num));
}

void opponent_have::showWhiteCard(int num)
{
    ui->white_card->setText(QString::number(num));
}

void opponent_have::showBlackCard(int num)
{
    ui->black_card->setText(QString::number(num));
}

void opponent_have::on_closeButton_clicked()
{
    this->hide();
}
