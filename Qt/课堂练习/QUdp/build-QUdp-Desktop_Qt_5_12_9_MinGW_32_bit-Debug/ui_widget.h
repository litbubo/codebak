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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditport;
    QLabel *label_2;
    QLineEdit *lineEditip;
    QTextEdit *textEdit;
    QPushButton *pushButtonsend;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonclose;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(355, 415);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditport = new QLineEdit(Widget);
        lineEditport->setObjectName(QString::fromUtf8("lineEditport"));

        gridLayout->addWidget(lineEditport, 0, 1, 1, 3);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditip = new QLineEdit(Widget);
        lineEditip->setObjectName(QString::fromUtf8("lineEditip"));

        gridLayout->addWidget(lineEditip, 1, 1, 1, 3);

        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 2, 0, 1, 4);

        pushButtonsend = new QPushButton(Widget);
        pushButtonsend->setObjectName(QString::fromUtf8("pushButtonsend"));

        gridLayout->addWidget(pushButtonsend, 3, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(130, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 2, 1, 1);

        pushButtonclose = new QPushButton(Widget);
        pushButtonclose->setObjectName(QString::fromUtf8("pushButtonclose"));

        gridLayout->addWidget(pushButtonclose, 3, 3, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "\347\253\257\345\217\243", nullptr));
        label_2->setText(QApplication::translate("Widget", "ip", nullptr));
        pushButtonsend->setText(QApplication::translate("Widget", "sned", nullptr));
        pushButtonclose->setText(QApplication::translate("Widget", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
