/********************************************************************************
** Form generated from reading UI file 'mainsurface.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSURFACE_H
#define UI_MAINSURFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainSurface
{
public:
    QLabel *label;
    QToolButton *start_button;
    QToolButton *rule_button;
    QTextBrowser *start_text;
    QTextBrowser *rule_text;

    void setupUi(QWidget *mainSurface)
    {
        if (mainSurface->objectName().isEmpty())
            mainSurface->setObjectName(QStringLiteral("mainSurface"));
        mainSurface->resize(1311, 750);
        mainSurface->setMinimumSize(QSize(1311, 750));
        mainSurface->setMaximumSize(QSize(1311, 750));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/\346\211\223\345\274\200\347\225\214\351\235\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        mainSurface->setWindowIcon(icon);
        mainSurface->setStyleSheet(QStringLiteral(""));
        label = new QLabel(mainSurface);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1311, 750));
        label->setMinimumSize(QSize(1311, 750));
        label->setMaximumSize(QSize(1311, 750));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/images/\346\211\223\345\274\200\347\225\214\351\235\242.png);"));
        start_button = new QToolButton(mainSurface);
        start_button->setObjectName(QStringLiteral("start_button"));
        start_button->setGeometry(QRect(90, 340, 231, 61));
        start_button->setStyleSheet(QLatin1String("background-color: rgba(0,0,0,0);\n"
"border:none;"));
        rule_button = new QToolButton(mainSurface);
        rule_button->setObjectName(QStringLiteral("rule_button"));
        rule_button->setGeometry(QRect(970, 340, 231, 61));
        rule_button->setStyleSheet(QLatin1String("background-color: rgba(0,0,0,0);\n"
"border:none;"));
        start_text = new QTextBrowser(mainSurface);
        start_text->setObjectName(QStringLiteral("start_text"));
        start_text->setGeometry(QRect(90, 340, 231, 61));
        start_text->setStyleSheet(QLatin1String("background-color: rgba(22, 36, 52,80);\n"
"border-radius: 20px;\n"
""));
        rule_text = new QTextBrowser(mainSurface);
        rule_text->setObjectName(QStringLiteral("rule_text"));
        rule_text->setGeometry(QRect(970, 340, 231, 61));
        rule_text->setStyleSheet(QLatin1String("background-color: rgba(22, 36, 52,80);\n"
"border-radius: 20px;\n"
""));
        label->raise();
        start_text->raise();
        rule_text->raise();
        start_button->raise();
        rule_button->raise();

        retranslateUi(mainSurface);

        QMetaObject::connectSlotsByName(mainSurface);
    } // setupUi

    void retranslateUi(QWidget *mainSurface)
    {
        mainSurface->setWindowTitle(QApplication::translate("mainSurface", "Form", Q_NULLPTR));
        label->setText(QString());
        start_button->setText(QString());
        rule_button->setText(QString());
        start_text->setHtml(QApplication::translate("mainSurface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:26pt; font-weight:600; color:#eac705;\">Start</span></p></body></html>", Q_NULLPTR));
        rule_text->setHtml(QApplication::translate("mainSurface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:26pt; font-weight:600; color:#edcd04;\">Rule</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mainSurface: public Ui_mainSurface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSURFACE_H
