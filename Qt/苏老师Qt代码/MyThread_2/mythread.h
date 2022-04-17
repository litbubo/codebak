#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QVector>
class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    void working(int num);
signals:
    void resultNum(QVector<int> list);

};

class BubbleSort : public QObject
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);
    void working(QVector<int> list);

signals:
    void finishArray(QVector<int> list);

};

class QuickSort : public QObject
{
    Q_OBJECT
public:
    explicit QuickSort(QObject *parent = nullptr);
    void working(QVector<int> list);
private:
    void quickSort(int left, int right, QVector<int>& list);
signals:
    void finishArray(QVector<int> list);

};

#endif // MYTHREAD_H
