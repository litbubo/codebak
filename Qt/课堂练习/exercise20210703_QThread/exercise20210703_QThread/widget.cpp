#include "widget.h"
#include "ui_widget.h"

#include <QThread>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    ui->lcdNumber->display(num);
    connect(timer, &QTimer::timeout,
            [=]()
            {
                num++;
                ui->lcdNumber->display(num);
            });

    myThread = new MyThread(this);

    connect(myThread, &MyThread::Done, this, &Widget::Dealdone);

    connect(this, &Widget::destroyed, this, &Widget::Stopthread);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{

    if(timer->isActive() == false)
    {
        timer->start(100);
    }
    else
    {
        qDebug() << "定时器已被打开";
        return;
    }
    //QThread::sleep(5);
    myThread->start();
}

void Widget::Dealdone()
{
    timer->stop();
}

void Widget::Stopthread()
{
    myThread->quit();
    myThread->wait();
    qDebug() << "stop";
}
