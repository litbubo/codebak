#include "mythread.h"
#include <QThread>
#include <QDebug>
#include <QMessageBox>
MyThread::MyThread(QObject *parent) : QObject(parent)
{
    flag = false;
}

void MyThread::myTimeout()
{

    while (flag == false)
    {
        //QMessageBox::aboutQt(NULL);
        QThread::sleep(1);
        emit mySignal();
        qDebug() << "child Thread" << QThread::currentThread();
        if (flag == true)
        {
            break;
        }
    }

}

void MyThread::setFlag(bool flag)
{
    this->flag = flag;
}
