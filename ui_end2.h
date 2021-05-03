/********************************************************************************
** Form generated from reading UI file 'end2.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_END2_H
#define UI_END2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_END2
{
public:
    QLabel *no1;
    QLabel *no1_2;
    QLabel *no3;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *END2)
    {
        if (END2->objectName().isEmpty())
            END2->setObjectName(QStringLiteral("END2"));
        END2->resize(1400, 800);
        END2->setStyleSheet(QLatin1String("#END2{\n"
"border-image: url(:/images/rule_background.png);\n"
"}"));
        no1 = new QLabel(END2);
        no1->setObjectName(QStringLiteral("no1"));
        no1->setGeometry(QRect(590, 140, 220, 220));
        no1->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 254, 50);\n"
"border:2px solid rgb(247, 228, 16);\n"
"border-radius:45px;"));
        no1_2 = new QLabel(END2);
        no1_2->setObjectName(QStringLiteral("no1_2"));
        no1_2->setGeometry(QRect(400, 460, 220, 220));
        no1_2->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 254, 50);\n"
"border:2px solid rgb(247, 228, 16);\n"
"border-radius:45px;"));
        no3 = new QLabel(END2);
        no3->setObjectName(QStringLiteral("no3"));
        no3->setGeometry(QRect(780, 460, 220, 220));
        no3->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 254, 50);\n"
"border:2px solid rgb(247, 228, 16);\n"
"border-radius:45px;"));
        label_1 = new QLabel(END2);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(610, 60, 181, 51));
        label_1->setStyleSheet(QLatin1String("background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(147, 97, 117, 255), stop:1 rgba(82, 54, 65, 255));\n"
"border-radius:15px;\n"
"border:1px solid rgb(132, 132, 132);\n"
"font:75 italic 18pt \"Bodoni MT\" ;\n"
"color:rgb(247, 228, 16);"));
        label_1->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(END2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(420, 400, 181, 51));
        label_2->setStyleSheet(QLatin1String("background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(147, 97, 117, 255), stop:1 rgba(82, 54, 65, 255));\n"
"border-radius:15px;\n"
"border:1px solid rgb(132, 132, 132);\n"
"font:75 italic 18pt \"Bodoni MT\" ;\n"
"color:rgb(247, 228, 16);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(END2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(800, 400, 181, 51));
        label_3->setStyleSheet(QLatin1String("background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(147, 97, 117, 255), stop:1 rgba(82, 54, 65, 255));\n"
"border-radius:15px;\n"
"border:1px solid rgb(132, 132, 132);\n"
"font:75 italic 18pt \"Bodoni MT\" ;\n"
"color:rgb(247, 228, 16);"));
        label_3->setAlignment(Qt::AlignCenter);

        retranslateUi(END2);

        QMetaObject::connectSlotsByName(END2);
    } // setupUi

    void retranslateUi(QWidget *END2)
    {
        END2->setWindowTitle(QApplication::translate("END2", "Form", Q_NULLPTR));
        no1->setText(QString());
        no1_2->setText(QString());
        no3->setText(QString());
        label_1->setText(QApplication::translate("END2", "Winner", Q_NULLPTR));
        label_2->setText(QApplication::translate("END2", "NO.2", Q_NULLPTR));
        label_3->setText(QApplication::translate("END2", "NO.3", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class END2: public Ui_END2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_END2_H
