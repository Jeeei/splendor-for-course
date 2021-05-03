/********************************************************************************
** Form generated from reading UI file 'richpeople.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RICHPEOPLE_H
#define UI_RICHPEOPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_richPeople
{
public:
    QToolButton *toolButton;
    QToolButton *rich;

    void setupUi(QFrame *richPeople)
    {
        if (richPeople->objectName().isEmpty())
            richPeople->setObjectName(QStringLiteral("richPeople"));
        richPeople->resize(315, 392);
        richPeople->setStyleSheet(QLatin1String("#richPeople{\n"
"background-image: url(:/images/rule_background.png);\n"
"border:3px solid rgb(216, 216, 107)\n"
"}"));
        richPeople->setFrameShape(QFrame::StyledPanel);
        richPeople->setFrameShadow(QFrame::Raised);
        toolButton = new QToolButton(richPeople);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(60, 320, 191, 41));
        toolButton->setStyleSheet(QLatin1String("border-radius:15px;\n"
"background-color: rgba(255, 255, 254, 50);\n"
"font: italic 16pt \"Elephant\";"));
        rich = new QToolButton(richPeople);
        rich->setObjectName(QStringLiteral("rich"));
        rich->setGeometry(QRect(10, 10, 291, 291));
        rich->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 254, 30);\n"
"border-radius:65px;\n"
"border:1px solid rgb(223, 223, 223)"));

        retranslateUi(richPeople);

        QMetaObject::connectSlotsByName(richPeople);
    } // setupUi

    void retranslateUi(QFrame *richPeople)
    {
        richPeople->setWindowTitle(QApplication::translate("richPeople", "Frame", Q_NULLPTR));
        toolButton->setText(QApplication::translate("richPeople", "Selected", Q_NULLPTR));
        rich->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class richPeople: public Ui_richPeople {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RICHPEOPLE_H
