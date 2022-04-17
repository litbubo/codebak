#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    void setFlag(bool flag = true);

    void myTimeout();
signals:
    void mySignal();
private:
    bool flag;
};

#endif // MYTHREAD_H
