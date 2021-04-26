/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QToolButton *purchase;
    QToolButton *cancel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(342, 383);
        Dialog->setMinimumSize(QSize(342, 383));
        Dialog->setMaximumSize(QSize(342, 383));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/\346\211\223\345\274\200\347\225\214\351\235\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setStyleSheet(QStringLiteral(""));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 10, 201, 281));
        purchase = new QToolButton(Dialog);
        purchase->setObjectName(QStringLiteral("purchase"));
        purchase->setGeometry(QRect(40, 320, 101, 51));
        purchase->setStyleSheet(QStringLiteral(""));
        cancel = new QToolButton(Dialog);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(190, 320, 111, 51));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label->setText(QString());
        purchase->setText(QApplication::translate("Dialog", "Purchase", Q_NULLPTR));
        cancel->setText(QApplication::translate("Dialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
