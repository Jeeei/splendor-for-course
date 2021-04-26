/********************************************************************************
** Form generated from reading UI file 'dialog2.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG2_H
#define UI_DIALOG2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog2
{
public:
    QToolButton *OK;
    QToolButton *selected1;
    QToolButton *selected2;
    QToolButton *selected3;

    void setupUi(QDialog *Dialog2)
    {
        if (Dialog2->objectName().isEmpty())
            Dialog2->setObjectName(QStringLiteral("Dialog2"));
        Dialog2->resize(562, 235);
        Dialog2->setMinimumSize(QSize(562, 235));
        Dialog2->setMaximumSize(QSize(562, 235));
        OK = new QToolButton(Dialog2);
        OK->setObjectName(QStringLiteral("OK"));
        OK->setGeometry(QRect(200, 180, 151, 41));
        selected1 = new QToolButton(Dialog2);
        selected1->setObjectName(QStringLiteral("selected1"));
        selected1->setGeometry(QRect(40, 20, 131, 131));
        selected1->setStyleSheet(QLatin1String("border-radius:45px;\n"
"background-color: rgb(255, 255, 255);"));
        selected2 = new QToolButton(Dialog2);
        selected2->setObjectName(QStringLiteral("selected2"));
        selected2->setGeometry(QRect(210, 20, 131, 131));
        selected2->setStyleSheet(QLatin1String("border-radius:45px;\n"
"background-color: rgb(255, 255, 255);"));
        selected3 = new QToolButton(Dialog2);
        selected3->setObjectName(QStringLiteral("selected3"));
        selected3->setGeometry(QRect(380, 20, 131, 131));
        selected3->setStyleSheet(QLatin1String("border-radius:45px;\n"
"background-color: rgb(255, 255, 255);"));

        retranslateUi(Dialog2);

        QMetaObject::connectSlotsByName(Dialog2);
    } // setupUi

    void retranslateUi(QDialog *Dialog2)
    {
        Dialog2->setWindowTitle(QApplication::translate("Dialog2", "Dialog", Q_NULLPTR));
        OK->setText(QApplication::translate("Dialog2", "OK", Q_NULLPTR));
        selected1->setText(QString());
        selected2->setText(QString());
        selected3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog2: public Ui_Dialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG2_H
