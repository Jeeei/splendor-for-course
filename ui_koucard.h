/********************************************************************************
** Form generated from reading UI file 'koucard.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KOUCARD_H
#define UI_KOUCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_kouCard
{
public:
    QToolButton *cardShow;
    QToolButton *toolButton;
    QGraphicsView *graphicsView;

    void setupUi(QFrame *kouCard)
    {
        if (kouCard->objectName().isEmpty())
            kouCard->setObjectName(QStringLiteral("kouCard"));
        kouCard->resize(271, 351);
        kouCard->setMinimumSize(QSize(271, 351));
        kouCard->setMaximumSize(QSize(271, 351));
        kouCard->setStyleSheet(QLatin1String("#kouCard{\n"
"border-image: url(:/images/rule_background.png);\n"
"border-radius:75px;\n"
"}"));
        kouCard->setFrameShape(QFrame::StyledPanel);
        kouCard->setFrameShadow(QFrame::Raised);
        cardShow = new QToolButton(kouCard);
        cardShow->setObjectName(QStringLiteral("cardShow"));
        cardShow->setGeometry(QRect(40, 20, 191, 251));
        cardShow->setStyleSheet(QLatin1String("border-radius:15px;\n"
"background-color: rgba(255, 255, 254, 50);"));
        toolButton = new QToolButton(kouCard);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(70, 290, 141, 41));
        toolButton->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border:1px solid rgb(181, 178, 76);\n"
"background-color: rgba(255, 255, 254, 0);\n"
"font: italic 20pt \"Bodoni MT\";\n"
"color:white;"));
        graphicsView = new QGraphicsView(kouCard);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(170, 190, 91, 91));
        graphicsView->setStyleSheet(QLatin1String("border-image: url(:/images/bbb.png);\n"
"border-radius:45px;"));

        retranslateUi(kouCard);

        QMetaObject::connectSlotsByName(kouCard);
    } // setupUi

    void retranslateUi(QFrame *kouCard)
    {
        kouCard->setWindowTitle(QApplication::translate("kouCard", "Frame", Q_NULLPTR));
        cardShow->setText(QString());
        toolButton->setText(QApplication::translate("kouCard", "End turn", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class kouCard: public Ui_kouCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KOUCARD_H
