/********************************************************************************
** Form generated from reading UI file 'pickcoin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICKCOIN_H
#define UI_PICKCOIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_pickCoin
{
public:
    QToolButton *coin1;
    QToolButton *coin2;
    QToolButton *coin3;
    QToolButton *OK;

    void setupUi(QFrame *pickCoin)
    {
        if (pickCoin->objectName().isEmpty())
            pickCoin->setObjectName(QStringLiteral("pickCoin"));
        pickCoin->resize(321, 101);
        pickCoin->setStyleSheet(QLatin1String("#pickCoin\n"
"{\n"
"border-image: url(:/images/rule_background.png);\n"
"border-radius:55px;\n"
"}"));
        pickCoin->setFrameShape(QFrame::StyledPanel);
        pickCoin->setFrameShadow(QFrame::Raised);
        coin1 = new QToolButton(pickCoin);
        coin1->setObjectName(QStringLiteral("coin1"));
        coin1->setGeometry(QRect(10, 10, 75, 75));
        coin1->setStyleSheet(QLatin1String("border-radius:25px;\n"
"background-color: rgba(255, 255, 254, 50);"));
        coin2 = new QToolButton(pickCoin);
        coin2->setObjectName(QStringLiteral("coin2"));
        coin2->setGeometry(QRect(100, 10, 75, 75));
        coin2->setStyleSheet(QStringLiteral("border-radius:25px;background-color: rgba(255, 255, 254, 50);"));
        coin3 = new QToolButton(pickCoin);
        coin3->setObjectName(QStringLiteral("coin3"));
        coin3->setGeometry(QRect(190, 10, 75, 75));
        coin3->setStyleSheet(QLatin1String("border-radius:25px;\n"
"background-color: rgba(255, 255, 254, 50);"));
        OK = new QToolButton(pickCoin);
        OK->setObjectName(QStringLiteral("OK"));
        OK->setGeometry(QRect(280, 30, 30, 30));
        OK->setStyleSheet(QStringLiteral("border-radius:8px;background-color: rgba(255, 255, 254, 50);font: 12pt \"Forte\";"));

        retranslateUi(pickCoin);

        QMetaObject::connectSlotsByName(pickCoin);
    } // setupUi

    void retranslateUi(QFrame *pickCoin)
    {
        pickCoin->setWindowTitle(QApplication::translate("pickCoin", "Frame", Q_NULLPTR));
        coin1->setText(QString());
        coin2->setText(QString());
        coin3->setText(QString());
        OK->setText(QApplication::translate("pickCoin", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pickCoin: public Ui_pickCoin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICKCOIN_H
