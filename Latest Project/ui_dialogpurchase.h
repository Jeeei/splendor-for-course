/********************************************************************************
** Form generated from reading UI file 'dialogpurchase.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPURCHASE_H
#define UI_DIALOGPURCHASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DialogPurchase
{
public:
    QDialogButtonBox *Purchase;
    QLabel *label;

    void setupUi(QDialog *DialogPurchase)
    {
        if (DialogPurchase->objectName().isEmpty())
            DialogPurchase->setObjectName(QStringLiteral("DialogPurchase"));
        DialogPurchase->resize(239, 300);
        DialogPurchase->setStyleSheet(QStringLiteral("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.495, fy:0.5, stop:0 rgba(243, 224, 171, 255), stop:1 rgba(255, 173, 117, 255));"));
        Purchase = new QDialogButtonBox(DialogPurchase);
        Purchase->setObjectName(QStringLiteral("Purchase"));
        Purchase->setGeometry(QRect(-10, 230, 231, 51));
        Purchase->setOrientation(Qt::Horizontal);
        Purchase->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DialogPurchase);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 151, 191));

        retranslateUi(DialogPurchase);
        QObject::connect(Purchase, SIGNAL(accepted()), DialogPurchase, SLOT(accept()));
        QObject::connect(Purchase, SIGNAL(rejected()), DialogPurchase, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogPurchase);
    } // setupUi

    void retranslateUi(QDialog *DialogPurchase)
    {
        DialogPurchase->setWindowTitle(QApplication::translate("DialogPurchase", "Dialog", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        Purchase->setToolTip(QApplication::translate("DialogPurchase", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Purchase</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogPurchase: public Ui_DialogPurchase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPURCHASE_H
