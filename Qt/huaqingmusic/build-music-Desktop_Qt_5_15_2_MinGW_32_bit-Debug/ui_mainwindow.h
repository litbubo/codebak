/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLabel *label_name;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_pre;
    QPushButton *pushButton_play;
    QPushButton *pushButton_next;
    QSlider *horizontalSlider_progress;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(484, 153);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        label->setFont(font);

        horizontalLayout_4->addWidget(label);

        label_name = new QLabel(centralwidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        horizontalLayout_4->addWidget(label_name);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_pre = new QPushButton(centralwidget);
        pushButton_pre->setObjectName(QString::fromUtf8("pushButton_pre"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_pre->setIcon(icon);
        pushButton_pre->setIconSize(QSize(40, 40));
        pushButton_pre->setFlat(true);

        horizontalLayout->addWidget(pushButton_pre);

        pushButton_play = new QPushButton(centralwidget);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_play->setIcon(icon1);
        pushButton_play->setIconSize(QSize(50, 50));
        pushButton_play->setFlat(true);

        horizontalLayout->addWidget(pushButton_play);

        pushButton_next = new QPushButton(centralwidget);
        pushButton_next->setObjectName(QString::fromUtf8("pushButton_next"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_next->setIcon(icon2);
        pushButton_next->setIconSize(QSize(40, 40));
        pushButton_next->setFlat(true);

        horizontalLayout->addWidget(pushButton_next);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSlider_progress = new QSlider(centralwidget);
        horizontalSlider_progress->setObjectName(QString::fromUtf8("horizontalSlider_progress"));
        horizontalSlider_progress->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_progress);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216\346\211\223\345\274\200\346\210\221\347\232\204\346\222\255\346\224\276\345\231\250", nullptr));
        label_name->setText(QString());
        pushButton_pre->setText(QString());
        pushButton_play->setText(QString());
        pushButton_next->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
