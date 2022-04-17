#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
#include <QVector>
#include <QThread>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QThread *t1 = new QThread;
    QThread *t2 = new QThread;
    QThread *t3 = new QThread;
    MyThread *thread = new MyThread;
    BubbleSort *bubble = new BubbleSort;
    QuickSort *quick = new QuickSort;

    thread->moveToThread(t1);
    bubble->moveToThread(t2);
    quick->moveToThread(t3);

    connect(ui->pushButton, &QPushButton::clicked, this, [=]()
            {
                emit generalNum(10000);
                t1->start();
            });
    connect(this, &MainWindow::generalNum, thread, &MyThread::working);
    connect(thread, &MyThread::resultNum, bubble, &BubbleSort::working);
    connect(thread, &MyThread::resultNum, quick, &QuickSort::working);

    connect(thread, &MyThread::resultNum, this, [=](QVector<int> list)
            {
                ui->listWidget->clear();
                for (auto i = 0; i < list.length(); i++)
                {
                    ui->listWidget->addItem(QString::number(list.at(i)));
                }
                t2->start();
                t3->start();
            });

    connect(bubble, &BubbleSort::finishArray, this, [=](QVector<int> list)
            {
                ui->listWidget_2->clear();
                for (auto i = 0; i < list.length(); i++)
                {
                    ui->listWidget_2->addItem(QString::number(list.at(i)));
                }

            });
    connect(quick, &QuickSort::finishArray, this, [=](QVector<int> list)
            {
                ui->listWidget_3->clear();
                for (auto i = 0; i < list.length(); i++)
                {
                    ui->listWidget_3->addItem(QString::number(list.at(i)));
                }

            });
    connect(this, &MainWindow::destroyed, this, [=]()
    {
        t1->quit();
        t1->wait();
        t1->deleteLater();
        t2->quit();
        t2->wait();
        t2->deleteLater();
        t3->quit();
        t3->wait();
        t3->deleteLater();

        thread->deleteLater();
        bubble->deleteLater();
        quick->deleteLater();
        qDebug() << "析构";
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

