/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *sendbutton;
    QSpacerItem *horizontalSpacer;
    QPushButton *closebutton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(348, 424);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 0, 0, 1, 3);

        textEdit_2 = new QTextEdit(Widget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        gridLayout->addWidget(textEdit_2, 1, 0, 1, 3);

        sendbutton = new QPushButton(Widget);
        sendbutton->setObjectName(QString::fromUtf8("sendbutton"));

        gridLayout->addWidget(sendbutton, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(123, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        closebutton = new QPushButton(Widget);
        closebutton->setObjectName(QString::fromUtf8("closebutton"));

        gridLayout->addWidget(closebutton, 2, 2, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        sendbutton->setText(QApplication::translate("Widget", "send", nullptr));
        closebutton->setText(QApplication::translate("Widget", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
