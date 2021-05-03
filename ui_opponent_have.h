/********************************************************************************
** Form generated from reading UI file 'opponent_have.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPPONENT_HAVE_H
#define UI_OPPONENT_HAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_opponent_have
{
public:
    QFrame *white;
    QTextBrowser *card_have;
    QTextBrowser *white_have;
    QFrame *blue;
    QTextBrowser *card_have_2;
    QTextBrowser *white_have_2;
    QFrame *green;
    QTextBrowser *card_have_3;
    QTextBrowser *white_have_3;
    QFrame *red;
    QTextBrowser *card_have_4;
    QTextBrowser *white_have_4;
    QFrame *black;
    QTextBrowser *card_have_5;
    QTextBrowser *white_have_5;
    QToolButton *closeButton;
    QLabel *gold;
    QTextBrowser *gold_have;

    void setupUi(QFrame *opponent_have)
    {
        if (opponent_have->objectName().isEmpty())
            opponent_have->setObjectName(QStringLiteral("opponent_have"));
        opponent_have->resize(183, 151);
        opponent_have->setStyleSheet(QLatin1String("#opponent_have{\n"
"background-color: rgba(255, 255, 254, 60);\n"
"border-top-right-radius:65px;\n"
"border-bottom-right-radius:65px;\n"
"}"));
        opponent_have->setFrameShape(QFrame::StyledPanel);
        opponent_have->setFrameShadow(QFrame::Raised);
        white = new QFrame(opponent_have);
        white->setObjectName(QStringLiteral("white"));
        white->setGeometry(QRect(0, 0, 60, 75));
        white->setStyleSheet(QLatin1String("#white{\n"
"border-image: url(:/images/white_have.png);\n"
"border-radius:15px;\n"
"}"));
        white->setFrameShape(QFrame::StyledPanel);
        white->setFrameShadow(QFrame::Raised);
        card_have = new QTextBrowser(white);
        card_have->setObjectName(QStringLiteral("card_have"));
        card_have->setGeometry(QRect(1, 1, 42, 53));
        card_have->setStyleSheet(QLatin1String("background-color: rgb(240, 240, 240);\n"
"border-radius:15px;\n"
"border:1px solid black;"));
        white_have = new QTextBrowser(white);
        white_have->setObjectName(QStringLiteral("white_have"));
        white_have->setGeometry(QRect(20, 20, 61, 61));
        white_have->setStyleSheet(QLatin1String("background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"\n"
"font: 18pt \"Calibri\";"));
        blue = new QFrame(opponent_have);
        blue->setObjectName(QStringLiteral("blue"));
        blue->setGeometry(QRect(62, 0, 60, 75));
        blue->setStyleSheet(QLatin1String("#blue{\n"
"border-image: url(:/images/blue_have.png);\n"
"border-radius:15px;\n"
"}"));
        blue->setFrameShape(QFrame::StyledPanel);
        blue->setFrameShadow(QFrame::Raised);
        card_have_2 = new QTextBrowser(blue);
        card_have_2->setObjectName(QStringLiteral("card_have_2"));
        card_have_2->setGeometry(QRect(1, 1, 42, 53));
        card_have_2->setStyleSheet(QLatin1String("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(112, 198, 255, 255), stop:1 rgba(80, 141, 182, 255));\n"
"border:1px solid white;\n"
"border-radius:15px;\n"
""));
        white_have_2 = new QTextBrowser(blue);
        white_have_2->setObjectName(QStringLiteral("white_have_2"));
        white_have_2->setGeometry(QRect(18, 20, 61, 61));
        white_have_2->setStyleSheet(QLatin1String("background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"\n"
"font: 18pt \"Calibri\";"));
        green = new QFrame(opponent_have);
        green->setObjectName(QStringLiteral("green"));
        green->setGeometry(QRect(0, 76, 60, 75));
        green->setStyleSheet(QLatin1String("#green{\n"
"border-image: url(:/images/green_have.png);\n"
"border-radius:15px;\n"
"}"));
        green->setFrameShape(QFrame::StyledPanel);
        green->setFrameShadow(QFrame::Raised);
        card_have_3 = new QTextBrowser(green);
        card_have_3->setObjectName(QStringLiteral("card_have_3"));
        card_have_3->setGeometry(QRect(1, 1, 42, 53));
        card_have_3->setStyleSheet(QLatin1String("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(155, 255, 162, 255), stop:1 rgba(0, 213, 0, 255));\n"
"border-radius:15px;\n"
"border:1px solid white;"));
        white_have_3 = new QTextBrowser(green);
        white_have_3->setObjectName(QStringLiteral("white_have_3"));
        white_have_3->setGeometry(QRect(18, 20, 61, 61));
        white_have_3->setStyleSheet(QLatin1String("background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"\n"
"font: 18pt \"Calibri\";"));
        red = new QFrame(opponent_have);
        red->setObjectName(QStringLiteral("red"));
        red->setGeometry(QRect(62, 76, 60, 75));
        red->setStyleSheet(QLatin1String("#red{\n"
"border-image: url(:/images/red_have.png);\n"
"border-radius:15px;\n"
"}"));
        red->setFrameShape(QFrame::StyledPanel);
        red->setFrameShadow(QFrame::Raised);
        card_have_4 = new QTextBrowser(red);
        card_have_4->setObjectName(QStringLiteral("card_have_4"));
        card_have_4->setGeometry(QRect(1, 1, 42, 53));
        card_have_4->setStyleSheet(QLatin1String("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(234, 189, 189, 255), stop:1 rgba(247, 90, 90, 255));\n"
"border-radius:15px;\n"
"border:1px solid white;"));
        white_have_4 = new QTextBrowser(red);
        white_have_4->setObjectName(QStringLiteral("white_have_4"));
        white_have_4->setGeometry(QRect(18, 20, 61, 61));
        white_have_4->setStyleSheet(QLatin1String("background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"\n"
"font: 18pt \"Calibri\";"));
        black = new QFrame(opponent_have);
        black->setObjectName(QStringLiteral("black"));
        black->setGeometry(QRect(122, 30, 60, 75));
        black->setStyleSheet(QLatin1String("#black{\n"
"border-image: url(:/images/black_have.png);\n"
"border-radius:15px;\n"
"}"));
        black->setFrameShape(QFrame::StyledPanel);
        black->setFrameShadow(QFrame::Raised);
        card_have_5 = new QTextBrowser(black);
        card_have_5->setObjectName(QStringLiteral("card_have_5"));
        card_have_5->setGeometry(QRect(1, 1, 42, 53));
        card_have_5->setStyleSheet(QLatin1String("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(99, 99, 99, 255), stop:1 rgba(55, 55, 55, 255));\n"
"border-radius:15px;\n"
"border:1px solid white;"));
        white_have_5 = new QTextBrowser(black);
        white_have_5->setObjectName(QStringLiteral("white_have_5"));
        white_have_5->setGeometry(QRect(18, 20, 61, 61));
        white_have_5->setStyleSheet(QLatin1String("background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"\n"
"font: 18pt \"Calibri\";"));
        closeButton = new QToolButton(opponent_have);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(0, 0, 183, 151));
        closeButton->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 254, 0);\n"
"border-top-right-radius:65px;\n"
"border-bottom-right-radius:65px;"));
        gold = new QLabel(opponent_have);
        gold->setObjectName(QStringLiteral("gold"));
        gold->setGeometry(QRect(145, 115, 31, 31));
        gold->setStyleSheet(QLatin1String("border-image: url(:/images/bbb.png);\n"
"border-radius:10px;"));
        gold_have = new QTextBrowser(opponent_have);
        gold_have->setObjectName(QStringLiteral("gold_have"));
        gold_have->setGeometry(QRect(130, 90, 61, 61));
        gold_have->setStyleSheet(QLatin1String("background:transparent;\n"
"border-width:0;\n"
"border-style:outset;\n"
"\n"
"font: 18pt \"Calibri\";"));

        retranslateUi(opponent_have);

        QMetaObject::connectSlotsByName(opponent_have);
    } // setupUi

    void retranslateUi(QFrame *opponent_have)
    {
        opponent_have->setWindowTitle(QApplication::translate("opponent_have", "Frame", Q_NULLPTR));
        card_have->setHtml(QApplication::translate("opponent_have", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        white_have->setHtml(QApplication::translate("opponent_have", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Calibri'; font-size:18pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:22pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", Q_NULLPTR));
        white_have_2->setHtml(QApplication::translate("opponent_have", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Calibri'; font-size:18pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:22pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", Q_NULLPTR));
        white_have_3->setHtml(QApplication::translate("opponent_have", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Calibri'; font-size:18pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:22pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", Q_NULLPTR));
        white_have_4->setHtml(QApplication::translate("opponent_have", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Calibri'; font-size:18pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:22pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", Q_NULLPTR));
        white_have_5->setHtml(QApplication::translate("opponent_have", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Calibri'; font-size:18pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:22pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", Q_NULLPTR));
        closeButton->setText(QString());
        gold->setText(QString());
        gold_have->setHtml(QApplication::translate("opponent_have", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Calibri'; font-size:18pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:22pt; font-weight:600; color:#ffffff;\">0</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class opponent_have: public Ui_opponent_have {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPPONENT_HAVE_H
