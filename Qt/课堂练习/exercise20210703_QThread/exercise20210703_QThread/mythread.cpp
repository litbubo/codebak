#include "mythread.h"
#include <QDebug>
MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run()
{

    sleep(50);
    qDebug() << "Done";
    emit Done();

}
