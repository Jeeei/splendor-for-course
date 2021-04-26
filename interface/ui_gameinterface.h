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
    QToolButton *toolButton;
    QToolButton *re;

    void setupUi(QWidget *gameInterface)
    {
        if (gameInterface->objectName().isEmpty())
            gameInterface->setObjectName(QStringLiteral("gameInterface"));
        gameInterface->resize(1311, 750);
        gameInterface->setMinimumSize(QSize(1311, 750));
        gameInterface->setMaximumSize(QSize(1311, 750));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/\346\211\223\345\274\200\347\225\214\351\235\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        gameInterface->setWindowIcon(icon);
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
"border-image: url(:/images/card/green-low/4.png);\n"
""));
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
        red_num->setGeometry(QRect(980, 280, 51, 41));
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
        background->setGeometry(QRect(0, 0, 1311, 750));
        background->setMinimumSize(QSize(1311, 750));
        background->setMaximumSize(QSize(1311, 750));
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
        toolButton = new QToolButton(gameInterface);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(1080, 90, 111, 41));
        re = new QToolButton(gameInterface);
        re->setObjectName(QStringLiteral("re"));
        re->setGeometry(QRect(1250, 0, 61, 81));
        re->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border:none;\n"
"border-radius:30px;"));
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
        toolButton->raise();
        re->raise();

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
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; color:#ffffff;\">5</span></p></body></html>", Q_NULLPTR));
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
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", Q_NULLPTR));
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
        toolButton->setText(QApplication::translate("gameInterface", "\346\210\221\350\246\201\346\213\277\345\270\201", Q_NULLPTR));
        re->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gameInterface: public Ui_gameInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEINTERFACE_H
