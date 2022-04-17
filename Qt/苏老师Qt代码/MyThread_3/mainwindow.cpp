#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
#include <QVector>
#include <QThreadPool>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyThread *thread = new MyThread;
    BubbleSort *bubble = new BubbleSort;
    QuickSort *quick = new QuickSort;

    connect(ui->pushButton, &QPushButton::clicked, this, [=]()
            {
                emit generalNum(10000);
                QThreadPool::globalInstance()->start(thread);
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
                QThreadPool::globalInstance()->start(bubble);
                QThreadPool::globalInstance()->start(quick);
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

