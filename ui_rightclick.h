/********************************************************************************
** Form generated from reading UI file 'rightclick.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RIGHTCLICK_H
#define UI_RIGHTCLICK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_RightClick
{
public:
    QLabel *menu;
    QToolButton *rule;
    QToolButton *resign;
    QToolButton *tryAgain;
    QToolButton *toolButton;

    void setupUi(QFrame *RightClick)
    {
        if (RightClick->objectName().isEmpty())
            RightClick->setObjectName(QStringLiteral("RightClick"));
        RightClick->resize(512, 691);
        RightClick->setStyleSheet(QLatin1String("#RightClick{\n"
"border-radius:25px;\n"
"border:3px solid rgb(249, 249, 0);\n"
"background-image: url(:/images/rule_background.png);\n"
"}"));
        RightClick->setFrameShape(QFrame::StyledPanel);
        RightClick->setFrameShadow(QFrame::Raised);
        menu = new QLabel(RightClick);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setGeometry(QRect(176, 30, 150, 91));
        menu->setStyleSheet(QLatin1String("font: 36pt \"Blackadder ITC\";\n"
"color:white;"));
        rule = new QToolButton(RightClick);
        rule->setObjectName(QStringLiteral("rule"));
        rule->setGeometry(QRect(165, 220, 171, 61));
        rule->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border:2px solid rgb(249, 249, 0);\n"
"background-color: rgba(255, 255, 254, 0);\n"
"font: italic 20pt \"Bodoni MT\";\n"
"color:white;"));
        resign = new QToolButton(RightClick);
        resign->setObjectName(QStringLiteral("resign"));
        resign->setGeometry(QRect(165, 340, 171, 61));
        resign->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border:2px solid rgb(249, 249, 0);\n"
"background-color: rgba(255, 255, 254, 0);\n"
"font: italic 20pt \"Bodoni MT\";\n"
"color:white;"));
        tryAgain = new QToolButton(RightClick);
        tryAgain->setObjectName(QStringLiteral("tryAgain"));
        tryAgain->setGeometry(QRect(165, 460, 171, 61));
        tryAgain->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border:2px solid rgb(249, 249, 0);\n"
"background-color: rgba(255, 255, 254, 0);\n"
"font: italic 20pt \"Bodoni MT\";\n"
"color:white;"));
        toolButton = new QToolButton(RightClick);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(20, 20, 81, 51));
        toolButton->setStyleSheet(QLatin1String("font: 48pt \"Algerian\";\n"
"color:white;\n"
"background-color: rgba(255, 255, 254, 20);\n"
"border-radius:25px;"));

        retranslateUi(RightClick);

        QMetaObject::connectSlotsByName(RightClick);
    } // setupUi

    void retranslateUi(QFrame *RightClick)
    {
        RightClick->setWindowTitle(QApplication::translate("RightClick", "Frame", Q_NULLPTR));
        menu->setText(QApplication::translate("RightClick", "Menu", Q_NULLPTR));
        rule->setText(QApplication::translate("RightClick", "Rule", Q_NULLPTR));
        resign->setText(QApplication::translate("RightClick", "Resign", Q_NULLPTR));
        tryAgain->setText(QApplication::translate("RightClick", "Try again", Q_NULLPTR));
        toolButton->setText(QApplication::translate("RightClick", "\342\206\220", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RightClick: public Ui_RightClick {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RIGHTCLICK_H
