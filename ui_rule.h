/********************************************************************************
** Form generated from reading UI file 'rule.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULE_H
#define UI_RULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Rule
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QDialog *Rule)
    {
        if (Rule->objectName().isEmpty())
            Rule->setObjectName(QStringLiteral("Rule"));
        Rule->resize(660, 600);
        Rule->setMinimumSize(QSize(660, 600));
        Rule->setMaximumSize(QSize(660, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/\346\211\223\345\274\200\347\225\214\351\235\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        Rule->setWindowIcon(icon);
        Rule->setStyleSheet(QStringLiteral("border-image: url(:/images/rule_background.png);"));
        textBrowser = new QTextBrowser(Rule);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 640, 580));
        textBrowser->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 254, 70);\n"
"border-radius:30px;\n"
""));

        retranslateUi(Rule);

        QMetaObject::connectSlotsByName(Rule);
    } // setupUi

    void retranslateUi(QDialog *Rule)
    {
        Rule->setWindowTitle(QApplication::translate("Rule", "Dialog", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("Rule", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:36pt; font-weight:600; color:#ffffff;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:36pt; font-weight:600; color:#ffffff;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px"
                        "; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-weight:600; color:#ffffff;\">\345\220\264\351\233\250\346\232\204</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-weight:600; color:#ffffff;\">\346\230\257\345\244\247\347\214\252\345\244\264</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-weight:600; color:#ffffff;\">\350\203\241\347\216\211\345\251\267</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-weight:600; color:#ffffff;\">\344\271\237\346\230\257\345\244\247\347\214\252\345\244\264</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Rule: public Ui_Rule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULE_H
