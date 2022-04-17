#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyThread *thread = new MyThread(this);
    BubbleSort *bubble = new BubbleSort(this);
    QuickSort *quick = new QuickSort(this);

    connect(ui->pushButton, &QPushButton::clicked, this, [=]()
            {
                emit generalNum(10000);
                thread->start();
            });
    connect(this, &MainWindow::generalNum, thread, &MyThread::recvNum);
    connect(thread, &MyThread::resultNum, bubble, &BubbleSort::recvArray);
    connect(thread, &MyThread::resultNum, quick, &QuickSort::recvArray);

    connect(thread, &MyThread::resultNum, this, [=](QVector<int> list)
            {
                ui->listWidget->clear();
                for (auto i = 0; i < list.length(); i++)
                {
                    ui->listWidget->addItem(QString::number(list.at(i)));
                }
                bubble->start();
                quick->start();
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

