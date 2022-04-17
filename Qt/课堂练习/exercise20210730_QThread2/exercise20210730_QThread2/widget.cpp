#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    myT = new MyThread();
    mythread = new QThread(this);
    myT->moveToThread(mythread);

    connect(myT, &MyThread::mySignal,this, &Widget::dealSignal);
    qDebug() << "main Thread" << QThread::currentThread();


    connect(this, &Widget::startThread, myT, &MyThread::myTimeout, Qt::QueuedConnection);
    connect(this, &Widget::destroyed,
            [=]()
            {
                if(thread()->isRunning() == true)
                {
                        myT->setFlag();
                        mythread->quit();
                        mythread->wait();
                }
                delete myT;
            });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    if(mythread->isRunning() == false)
    {
        myT->setFlag(false);
        mythread->start();
        // myT->myTimeout();
        emit startThread();
    }

}

void Widget::dealSignal()
{
    static int i = 0;
    ui->lcdNumber->display(i++);
}

void Widget::on_pushButton_2_clicked()
{
    if(mythread->isRunning() == true)
    {
        myT->setFlag();
        mythread->quit();
        mythread->wait();
    }
}
