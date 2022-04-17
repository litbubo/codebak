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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFrame *frame;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(510, 553);
        Widget->setStyleSheet(QString::fromUtf8("*{\n"
"font-size:14px;\n"
"color:black;\n"
"font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QLineEdit {\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}\n"
"QPushButton {\n"
"background:rgb(226,230,168);\n"
"color:black;	\n"
"border: 2px solid gray;\n"
"border-radius: 8px; \n"
"}\n"
"QFrame { \n"
"background: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #efefff, stop:1 #cfcfff);\n"
"border: 6px solid red;\n"
"border-radius: 28px;\n"
"}\n"
"QLabel{\n"
"border: 0px;\n"
"background:transparent;\n"
"}\n"
""));
        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(70, 130, 371, 221));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 4);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 4);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 2, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label_2->setText(QApplication::translate("Widget", "\345\247\223\345\220\215", nullptr));
        label->setText(QApplication::translate("Widget", "\345\255\246\345\217\267", nullptr));
        pushButton->setText(QApplication::translate("Widget", "  \347\231\273\345\275\225  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
