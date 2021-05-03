/********************************************************************************
** Form generated from reading UI file 'pickcard.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICKCARD_H
#define UI_PICKCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_pickCard
{
public:
    QToolButton *cardShow;
    QToolButton *purchase;

    void setupUi(QFrame *pickCard)
    {
        if (pickCard->objectName().isEmpty())
            pickCard->setObjectName(QStringLiteral("pickCard"));
        pickCard->resize(271, 351);
        pickCard->setStyleSheet(QLatin1String("#pickCard{\n"
"border-image: url(:/images/rule_background.png);\n"
"border-radius:75px;\n"
"}"));
        pickCard->setFrameShape(QFrame::StyledPanel);
        pickCard->setFrameShadow(QFrame::Raised);
        cardShow = new QToolButton(pickCard);
        cardShow->setObjectName(QStringLiteral("cardShow"));
        cardShow->setGeometry(QRect(40, 20, 191, 251));
        cardShow->setStyleSheet(QLatin1String("border-radius:15px;\n"
"background-color: rgba(255, 255, 254, 50);"));
        purchase = new QToolButton(pickCard);
        purchase->setObjectName(QStringLiteral("purchase"));
        purchase->setGeometry(QRect(40, 290, 171, 41));
        purchase->setStyleSheet(QLatin1String("border-radius:15px;\n"
"background-color: rgba(255, 255, 254, 50);\n"
"font: italic 16pt \"Elephant\";"));

        retranslateUi(pickCard);

        QMetaObject::connectSlotsByName(pickCard);
    } // setupUi

    void retranslateUi(QFrame *pickCard)
    {
        pickCard->setWindowTitle(QApplication::translate("pickCard", "Frame", Q_NULLPTR));
        cardShow->setText(QString());
        purchase->setText(QApplication::translate("pickCard", "Purchase", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pickCard: public Ui_pickCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICKCARD_H
