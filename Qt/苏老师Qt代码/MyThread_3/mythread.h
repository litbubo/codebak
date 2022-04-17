#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QVector>
#include <QRunnable>
class MyThread : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    void recvNum(int num);
    void run() override;
private:
    int num;
signals:
    void resultNum(QVector<int> list);

};

class BubbleSort : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);
    void recvArray(QVector<int> list);
    void run() override;
private:
    QVector<int> list;
signals:
    void finishArray(QVector<int> list);

};

class QuickSort : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit QuickSort(QObject *parent = nullptr);
    void recvArray(QVector<int> list);
    void run() override;
private:
    QVector<int> list;
    void quickSort(int left, int right, QVector<int>& list);
signals:
    void finishArray(QVector<int> list);

};

#endif // MYTHREAD_H
