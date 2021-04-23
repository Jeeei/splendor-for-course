/********************************************************************************
** Form generated from reading UI file 'gameinterface.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEINTERFACE_H
#define UI_GAMEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameInterface
{
public:
    QPushButton *card1_1;
    QPushButton *card1_2;
    QPushButton *card1_3;
    QPushButton *card1_4;
    QPushButton *card2_1;
    QPushButton *card2_2;
    QPushButton *card2_3;
    QPushButton *card2_4;
    QPushButton *card3_1;
    QPushButton *card3_2;
    QPushButton *card3_3;
    QPushButton *card3_4;
    QTextBrowser *gold_num;
    QTextBrowser *black_num;
    QTextBrowser *red_num;
    QTextBrowser *green_num;
    QTextBrowser *blue_num;
    QTextBrowser *white_num;
    QLabel *background;
    QLabel *money;
    QTextBrowser *white_have;
    QTextBrowser *blue_nave;
    QTextBrowser *green_have;
    QTextBrowser *red_have;
    QTextBrowser *black_have;
    QLabel *label;
    QTextBrowser *gold_have;
    QPushButton *selectBlack;
    QPushButton *selectRed;
    QPushButton *selectGreen;
    QPushButton *selectBlue;
    QPushButton *selectWhite;
    QTextBrowser *gradePeople2;
    QTextBrowser *gradePeople1;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QToolButton *toolButton;
    QTextBrowser *textBrowser_3;

    void setupUi(QWidget *gameInterface)
    {
        if (gameInterface->objectName().isEmpty())
            gameInterface->setObjectName(QStringLiteral("gameInterface"));
        gameInterface->resize(1311, 750);
        gameInterface->setMinimumSize(QSize(1311, 750));
        gameInterface->setMaximumSize(QSize(1311, 750));
        gameInterface->setStyleSheet(QStringLiteral(""));
        card1_1 = new QPushButton(gameInterface);
        card1_1->setObjectName(QStringLiteral("card1_1"));
        card1_1->setGeometry(QRect(310, 50, 141, 171));
        card1_1->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border-image: url(:/images/card/blue-high/1.png);\n"
"\n"
"\n"
""));
        card1_2 = new QPushButton(gameInterface);
        card1_2->setObjectName(QStringLiteral("card1_2"));
        card1_2->setGeometry(QRect(480, 50, 141, 171));
        card1_2->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border-image: url(:/images/card/blue-high/2.png);"));
        card1_3 = new QPushButton(gameInterface);
        card1_3->setObjectName(QStringLiteral("card1_3"));
        card1_3->setGeometry(QRect(650, 50, 141, 171));
        card1_3->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border-image: url(:/images/card/blue-high/3.png);"));
        card1_4 = new QPushButton(gameInterface);
        card1_4->setObjectName(QStringLiteral("card1_4"));
        card1_4->setGeometry(QRect(820, 50, 141, 171));
        card1_4->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border-image: url(:/images/card/blue-high/4.png);"));
        card2_1 = new QPushButton(gameInterface);
        card2_1->setObjectName(QStringLiteral("card2_1"));
        card2_1->setGeometry(QRect(310, 234, 141, 171));
        card2_1->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border-image: url(:/images/card/yellow-middle/1.png);"));
        card2_2 = new QPushButton(gameInterface);
        card2_2->setObjectName(QStringLiteral("card2_2"));
        card2_2->setGeometry(QRect(480, 234, 141, 171));
        card2_2->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border-image: url(:/images/card/yellow-middle/2.png);"));
        card2_3 = new QPushButton(gameInterface);
        card2_3->setObjectName(QStringLiteral("card2_3"));
        card2_3->setGeometry(QRect(650, 234, 141, 171));
        card2_3->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border-image: url(:/images/card/yellow-middle/3.png);"));
        card2_4 = new QPushButton(gameInterface);
        card2_4->setObjectName(QStringLiteral("card2_4"));
        card2_4->setGeometry(QRect(820, 234, 141, 171));
        card2_4->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border-image: url(:/images/card/yellow-middle/4.png);"));
        card3_1 = new QPushButton(gameInterface);
        card3_1->setObjectName(QStringLiteral("card3_1"));
        card3_1->setGeometry(QRect(310, 420, 141, 171));
        card3_1->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border-image: url(:/images/card/green-low/1.png);"));
        card3_2 = new QPushButton(gameInterface);
        card3_2->setObjectName(QStringLiteral("card3_2"));
        card3_2->setGeometry(QRect(480, 420, 141, 171));
        card3_2->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border-image: url(:/images/card/green-low/2.png);"));
        card3_3 = new QPushButton(gameInterface);
        card3_3->setObjectName(QStringLiteral("card3_3"));
        card3_3->setGeometry(QRect(650, 420, 141, 171));
        card3_3->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border-image: url(:/images/card/green-low/3.png);"));
        card3_4 = new QPushButton(gameInterface);
        card3_4->setObjectName(QStringLiteral("card3_4"));
        card3_4->setGeometry(QRect(820, 420, 141, 171));
        card3_4->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border-image: url(:/images/card/green-low/4.png);"));
        gold_num = new QTextBrowser(gameInterface);
        gold_num->setObjectName(QStringLiteral("gold_num"));
        gold_num->setGeometry(QRect(970, 110, 41, 41));
        gold_num->setStyleSheet(QLatin1String("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        black_num = new QTextBrowser(gameInterface);
        black_num->setObjectName(QStringLiteral("black_num"));
        black_num->setGeometry(QRect(970, 190, 51, 51));
        black_num->setStyleSheet(QLatin1String("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        red_num = new QTextBrowser(gameInterface);
        red_num->setObjectName(QStringLiteral("red_num"));
        red_num->setGeometry(QRect(990, 280, 51, 41));
        red_num->setStyleSheet(QLatin1String("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        green_num = new QTextBrowser(gameInterface);
        green_num->setObjectName(QStringLiteral("green_num"));
        green_num->setGeometry(QRect(980, 370, 51, 51));
        green_num->setStyleSheet(QLatin1String("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        blue_num = new QTextBrowser(gameInterface);
        blue_num->setObjectName(QStringLiteral("blue_num"));
        blue_num->setGeometry(QRect(990, 480, 41, 41));
        blue_num->setStyleSheet(QLatin1String("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        white_num = new QTextBrowser(gameInterface);
        white_num->setObjectName(QStringLiteral("white_num"));
        white_num->setGeometry(QRect(1000, 600, 41, 41));
        white_num->setStyleSheet(QLatin1String("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        background = new QLabel(gameInterface);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(1, 4, 1311, 751));
        background->setStyleSheet(QStringLiteral("border-image: url(:/images/background.png);"));
        money = new QLabel(gameInterface);
        money->setObjectName(QStringLiteral("money"));
        money->setGeometry(QRect(460, 670, 451, 91));
        money->setStyleSheet(QLatin1String("border-image: url(:/images/bb.png);\n"
"border-radius:8px;"));
        white_have = new QTextBrowser(gameInterface);
        white_have->setObjectName(QStringLiteral("white_have"));
        white_have->setGeometry(QRect(500, 690, 51, 61));
        white_have->setStyleSheet(QLatin1String("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        blue_nave = new QTextBrowser(gameInterface);
        blue_nave->setObjectName(QStringLiteral("blue_nave"));
        blue_nave->setGeometry(QRect(590, 690, 51, 61));
        blue_nave->setStyleSheet(QLatin1String("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        green_have = new QTextBrowser(gameInterface);
        green_have->setObjectName(QStringLiteral("green_have"));
        green_have->setGeometry(QRect(680, 690, 51, 61));
        green_have->setStyleSheet(QLatin1String("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        red_have = new QTextBrowser(gameInterface);
        red_have->setObjectName(QStringLiteral("red_have"));
        red_have->setGeometry(QRect(760, 690, 51, 61));
        red_have->setStyleSheet(QLatin1String("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        black_have = new QTextBrowser(gameInterface);
        black_have->setObjectName(QStringLiteral("black_have"));
        black_have->setGeometry(QRect(850, 690, 51, 61));
        black_have->setStyleSheet(QLatin1String("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        label = new QLabel(gameInterface);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(270, 650, 101, 91));
        label->setStyleSheet(QLatin1String("border-image: url(:/images/bbb.png);\n"
"border-radius:35px;"));
        gold_have = new QTextBrowser(gameInterface);
        gold_have->setObjectName(QStringLiteral("gold_have"));
        gold_have->setGeometry(QRect(240, 700, 51, 61));
        gold_have->setStyleSheet(QLatin1String("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));
        selectBlack = new QPushButton(gameInterface);
        selectBlack->setObjectName(QStringLiteral("selectBlack"));
        selectBlack->setGeometry(QRect(1000, 140, 71, 61));
        selectBlack->setStyleSheet(QLatin1String("border-radius:15px;\n"
"\n"
"\n"
""));
        selectRed = new QPushButton(gameInterface);
        selectRed->setObjectName(QStringLiteral("selectRed"));
        selectRed->setGeometry(QRect(1010, 230, 71, 61));
        selectRed->setStyleSheet(QLatin1String("border-radius:15px;\n"
"\n"
"\n"
""));
        selectGreen = new QPushButton(gameInterface);
        selectGreen->setObjectName(QStringLiteral("selectGreen"));
        selectGreen->setGeometry(QRect(1010, 330, 71, 61));
        selectGreen->setStyleSheet(QLatin1String("border-radius:15px;\n"
"\n"
"\n"
""));
        selectBlue = new QPushButton(gameInterface);
        selectBlue->setObjectName(QStringLiteral("selectBlue"));
        selectBlue->setGeometry(QRect(1030, 440, 71, 61));
        selectBlue->setStyleSheet(QLatin1String("border-radius:15px;\n"
"\n"
"\n"
""));
        selectWhite = new QPushButton(gameInterface);
        selectWhite->setObjectName(QStringLiteral("selectWhite"));
        selectWhite->setGeometry(QRect(1040, 540, 71, 61));
        selectWhite->setStyleSheet(QLatin1String("border-radius:15px;\n"
"\n"
"\n"
""));
        gradePeople2 = new QTextBrowser(gameInterface);
        gradePeople2->setObjectName(QStringLiteral("gradePeople2"));
        gradePeople2->setGeometry(QRect(110, 40, 41, 41));
        gradePeople2->setStyleSheet(QLatin1String("background-color:rgba(130, 87, 103,0.8);\n"
"border-radius:20px"));
        gradePeople1 = new QTextBrowser(gameInterface);
        gradePeople1->setObjectName(QStringLiteral("gradePeople1"));
        gradePeople1->setGeometry(QRect(120, 600, 41, 41));
        gradePeople1->setStyleSheet(QLatin1String("background-color:rgba(130, 87, 103,0.8);\n"
"border-radius:20px\n"
""));
        textBrowser = new QTextBrowser(gameInterface);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 310, 241, 151));
        textBrowser->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0.523, x2:1, y2:0.54, stop:0 rgba(101, 67, 80, 255), stop:1 rgba(133, 89, 105, 255));"));
        textBrowser_2 = new QTextBrowser(gameInterface);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(960, 620, 281, 131));
        textBrowser_2->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0.523, x2:1, y2:0.54, stop:0 rgba(101, 67, 80, 255), stop:1 rgba(133, 89, 105, 255));"));
        toolButton = new QToolButton(gameInterface);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(1080, 90, 111, 41));
        textBrowser_3 = new QTextBrowser(gameInterface);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(510, 290, 291, 41));
        textBrowser_3->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0.523, x2:1, y2:0.54, stop:0 rgba(101, 67, 80, 255), stop:1 rgba(133, 89, 105, 255));"));
        background->raise();
        card1_1->raise();
        card1_2->raise();
        card1_3->raise();
        card1_4->raise();
        card2_1->raise();
        card2_2->raise();
        card2_3->raise();
        card2_4->raise();
        card3_1->raise();
        card3_2->raise();
        card3_3->raise();
        card3_4->raise();
        gold_num->raise();
        black_num->raise();
        red_num->raise();
        green_num->raise();
        blue_num->raise();
        white_num->raise();
        money->raise();
        white_have->raise();
        blue_nave->raise();
        green_have->raise();
        red_have->raise();
        black_have->raise();
        label->raise();
        gold_have->raise();
        selectBlack->raise();
        selectRed->raise();
        selectGreen->raise();
        selectBlue->raise();
        selectWhite->raise();
        gradePeople2->raise();
        gradePeople1->raise();
        textBrowser->raise();
        textBrowser_2->raise();
        toolButton->raise();
        textBrowser_3->raise();

        retranslateUi(gameInterface);

        QMetaObject::connectSlotsByName(gameInterface);
    } // setupUi

    void retranslateUi(QWidget *gameInterface)
    {
        gameInterface->setWindowTitle(QApplication::translate("gameInterface", "gameInterface", Q_NULLPTR));
        card1_1->setText(QString());
        card1_2->setText(QString());
        card1_3->setText(QString());
        card1_4->setText(QString());
        card2_1->setText(QString());
        card2_2->setText(QString());
        card2_3->setText(QString());
        card2_4->setText(QString());
        card3_1->setText(QString());
        card3_2->setText(QString());
        card3_3->setText(QString());
        card3_4->setText(QString());
        gold_num->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#ffffff;\">5</span></p></body></html>", Q_NULLPTR));
        black_num->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#ffffff;\">5</span></p></body></html>", Q_NULLPTR));
        red_num->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", Q_NULLPTR));
        green_num->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#ffffff;\">5</span></p></body></html>", Q_NULLPTR));
        blue_num->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#ffffff;\">5</span></p></body></html>", Q_NULLPTR));
        white_num->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#ffffff;\">5</span></p></body></html>", Q_NULLPTR));
        background->setText(QString());
        money->setText(QString());
        white_have->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", Q_NULLPTR));
        blue_nave->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", Q_NULLPTR));
        green_have->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", Q_NULLPTR));
        red_have->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:600; color:#ffffff;\">7</span></p></body></html>", Q_NULLPTR));
        black_have->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", Q_NULLPTR));
        label->setText(QString());
        gold_have->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", Q_NULLPTR));
        selectBlack->setText(QString());
        selectRed->setText(QString());
        selectGreen->setText(QString());
        selectBlue->setText(QString());
        selectWhite->setText(QString());
        textBrowser->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#ffaa7f;\">\347\233\256\345\211\215\344\273\205\346\224\257\346\214\201\350\264\255\344\271\260</span><span style=\" font-size:12pt; font-weight:600; color:#ffffff;\">\345\267\246\344\270\212\350\247\222\347\254\254\344\270\200\345\274\240\347\211\214</span><span style=\" font-size:12pt; font-weight:600; color:#ffaa7f;\">\357\274\214\344\270\224</span><span style=\" font-size:12pt; font-weight:600; color:#ffffff;\">\344\273\205\345\217\257\350\264\255\344\271\260\344\270\200\346\254\241</span><span style=\" font"
                        "-size:12pt; font-weight:600; color:#ffaa7f;\">\357\274\214\346\233\264\345\244\232\347\262\276\345\275\251\345\206\205\345\256\271\357\274\214\346\225\254\350\257\267\346\234\237\345\276\205\357\274\201</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#ffaa7f;\">(\347\202\271\345\207\273\345\233\276\347\211\207\357\274\214\345\215\263\345\217\257\350\264\255\344\271\260\357\274\211</span></p></body></html>", Q_NULLPTR));
        textBrowser_2->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#ffaa7f;\">\347\233\256\345\211\215\344\273\205\346\224\257\346\214\201\346\213\277\345\217\226</span><span style=\" font-size:12pt; font-weight:600; color:#ffffff;\">\351\273\221\347\272\242\347\273\277</span><span style=\" font-size:12pt; font-weight:600; color:#ffaa7f;\">\344\270\211\344\270\252\345\270\201\357\274\214\350\257\267</span><span style=\" font-size:12pt; font-weight:600; color:#ffffff;\">\347\202\271\345\207\273\342\200\234\346\210\221\350\246\201\346\213\277\345\270\201\342\200\235</span><span s"
                        "tyle=\" font-size:12pt; font-weight:600; color:#ffaa7f;\">\345\220\216</span><span style=\" font-size:12pt; font-weight:600; color:#ffffff;\">\346\214\211\351\241\272\345\272\217</span><span style=\" font-size:12pt; font-weight:600; color:#ffaa7f;\">\346\213\277\345\217\226\357\274\214\346\233\264\345\244\232\347\262\276\345\275\251\345\206\205\345\256\271\357\274\214\346\225\254\350\257\267\346\234\237\345\276\205\357\274\201</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#ffaa7f;\">(\347\202\271\345\207\273\345\270\201\357\274\214\345\215\263\345\217\257\346\213\277\345\217\226\357\274\211</span></p></body></html>", Q_NULLPTR));
        toolButton->setText(QApplication::translate("gameInterface", "\346\210\221\350\246\201\346\213\277\345\270\201", Q_NULLPTR));
        textBrowser_3->setHtml(QApplication::translate("gameInterface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; color:#ffffff;\">\350\257\267\345\205\210\344\271\260\345\215\241\357\274\214\345\206\215\346\213\277\345\270\201\357\274\201</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gameInterface: public Ui_gameInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEINTERFACE_H
