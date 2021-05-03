/********************************************************************************
** Form generated from reading UI file 'end1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_END1_H
#define UI_END1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_END1
{
public:
    QLabel *no1;
    QLabel *label_1;
    QLabel *no2;
    QLabel *label_2;

    void setupUi(QWidget *END1)
    {
        if (END1->objectName().isEmpty())
            END1->setObjectName(QStringLiteral("END1"));
        END1->resize(1400, 800);
        END1->setMinimumSize(QSize(1400, 800));
        END1->setMaximumSize(QSize(1400, 800));
        END1->setStyleSheet(QLatin1String("#END1{\n"
"border-image: url(:/images/rule_background.png);\n"
"}"));
        no1 = new QLabel(END1);
        no1->setObjectName(QStringLiteral("no1"));
        no1->setGeometry(QRect(590, 140, 220, 220));
        no1->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 254, 50);\n"
"border:2px solid rgb(247, 228, 16);\n"
"border-radius:45px;"));
        label_1 = new QLabel(END1);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(610, 80, 181, 51));
        label_1->setStyleSheet(QLatin1String("background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(147, 97, 117, 255), stop:1 rgba(82, 54, 65, 255));\n"
"border-radius:15px;\n"
"border:1px solid rgb(132, 132, 132);\n"
"font:75 italic 18pt \"Bodoni MT\" ;\n"
"color:rgb(247, 228, 16);"));
        label_1->setAlignment(Qt::AlignCenter);
        no2 = new QLabel(END1);
        no2->setObjectName(QStringLiteral("no2"));
        no2->setGeometry(QRect(590, 460, 220, 220));
        no2->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 254, 50);\n"
"border:2px solid rgb(247, 228, 16);\n"
"border-radius:45px;"));
        label_2 = new QLabel(END1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(610, 400, 181, 51));
        label_2->setStyleSheet(QLatin1String("background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(147, 97, 117, 255), stop:1 rgba(82, 54, 65, 255));\n"
"border-radius:15px;\n"
"border:1px solid rgb(132, 132, 132);\n"
"font:75 italic 18pt \"Bodoni MT\" ;\n"
"color:rgb(247, 228, 16);"));
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(END1);

        QMetaObject::connectSlotsByName(END1);
    } // setupUi

    void retranslateUi(QWidget *END1)
    {
        END1->setWindowTitle(QApplication::translate("END1", "Form", Q_NULLPTR));
        no1->setText(QString());
        label_1->setText(QApplication::translate("END1", "Winner", Q_NULLPTR));
        no2->setText(QString());
        label_2->setText(QApplication::translate("END1", "NO.2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class END1: public Ui_END1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_END1_H
