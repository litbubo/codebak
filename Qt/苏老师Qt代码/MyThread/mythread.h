#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QVector>
class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    void recvNum(int num);
protected:
    void run() override;
private:
    int num;
signals:
    void resultNum(QVector<int> list);

};

class BubbleSort : public QThread
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);
    void recvArray(QVector<int> list);
protected:
    void run() override;
private:
    QVector<int> list;
signals:
    void finishArray(QVector<int> list);

};

class QuickSort : public QThread
{
    Q_OBJECT
public:
    explicit QuickSort(QObject *parent = nullptr);
    void recvArray(QVector<int> list);
protected:
    void run() override;
private:
    QVector<int> list;
    void quickSort(int left, int right, QVector<int>& list);
signals:
    void finishArray(QVector<int> list);

};

#endif // MYTHREAD_H
