/********************************************************************************
** Form generated from reading UI file 'rightrule.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RIGHTRULE_H
#define UI_RIGHTRULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_rightRule
{
public:
    QTextBrowser *score;
    QToolButton *toolButton;

    void setupUi(QFrame *rightRule)
    {
        if (rightRule->objectName().isEmpty())
            rightRule->setObjectName(QStringLiteral("rightRule"));
        rightRule->resize(512, 691);
        rightRule->setMinimumSize(QSize(512, 691));
        rightRule->setMaximumSize(QSize(512, 691));
        rightRule->setStyleSheet(QLatin1String("#rightRule{\n"
"border-radius:25px;\n"
"border:3px solid rgb(249, 249, 0);\n"
"border-image: url(:/images/rightRuleFor2.png);\n"
"}\n"
""));
        rightRule->setFrameShape(QFrame::StyledPanel);
        rightRule->setFrameShadow(QFrame::Raised);
        score = new QTextBrowser(rightRule);
        score->setObjectName(QStringLiteral("score"));
        score->setGeometry(QRect(165, 640, 161, 41));
        score->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 254, 10);\n"
"border:1px solid rgb(166, 145, 14);\n"
"border-radius:8px;"));
        toolButton = new QToolButton(rightRule);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(20, 10, 81, 51));
        toolButton->setStyleSheet(QLatin1String("font: 48pt \"Algerian\";\n"
"color:white;\n"
"background-color: rgba(255, 255, 254, 20);\n"
"border-radius:25px;"));

        retranslateUi(rightRule);

        QMetaObject::connectSlotsByName(rightRule);
    } // setupUi

    void retranslateUi(QFrame *rightRule)
    {
        rightRule->setWindowTitle(QApplication::translate("rightRule", "Frame", Q_NULLPTR));
        toolButton->setText(QApplication::translate("rightRule", "\342\206\220", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class rightRule: public Ui_rightRule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RIGHTRULE_H
