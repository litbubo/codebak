#include "mythread.h"
#include <QRandomGenerator>
#include <QDebug>
#include <QElapsedTimer>

MyThread::MyThread(QObject *parent) : QObject(parent), QRunnable()
{
    setAutoDelete(true);
}

void MyThread::recvNum(int num)
{
    this->num = num;
}

void MyThread::run()
{
    qDebug() << "生成线程地址" << QThread::currentThread();
    QVector<int> list;
    QElapsedTimer timer;
    timer.start();
    for(auto i = 0; i < num; i++)
    {
        list.push_back( QRandomGenerator::global()->bounded(0, 100000) );
        //qDebug() << list.at(i);
    }
    auto ret = timer.elapsed();
    qDebug() << "生成" << num << "个随机数用时 " << ret << "ms";
    emit resultNum(list);
}


BubbleSort::BubbleSort(QObject *parent): QObject(parent), QRunnable()
{
    setAutoDelete(true);
}

void BubbleSort::recvArray(QVector<int> list)
{
    this->list = list;
}

void BubbleSort::run()
{
    qDebug() << "冒泡线程地址" << QThread::currentThread();
    int temp;
    QElapsedTimer timer;
    timer.start();
    for (auto i = 0; i < list.length(); i++)
        for (auto j = 0; j < list.length() - 1 -i; j++)
            if(list.at(j) > list.at(j + 1))
            {
                temp = list.at(j);
                list[j] = list.at(j + 1);
                list[j + 1] = temp;
            }
    auto ret = timer.elapsed();
    qDebug() << "冒泡排序" << list.length() << "个随机数用时 " << ret << "ms";
    emit finishArray(list);
}



QuickSort::QuickSort(QObject *parent): QObject(parent), QRunnable()
{
    setAutoDelete(true);
}

void QuickSort::recvArray(QVector<int> list)
{
    this->list = list;
}

void QuickSort::run()
{
    qDebug() << "快速线程地址" << QThread::currentThread();
    //int temp;
    QElapsedTimer timer;
    timer.start();
    quickSort(0, list.length() - 1, list);
    auto ret = timer.elapsed();
    qDebug() << "快速排序" << list.length() << "个随机数用时 " << ret << "ms";
    emit finishArray(list);
}

void QuickSort::quickSort(int left, int right, QVector<int> &list)
{
    //快速排序（从小到大）
    if(left >= right)
        return;
    int i, j, base, temp;
    i = left, j = right;
    base = list[left];  //取最左边的数为基准数
    while (i < j)
    {
        while (list[j] >= base && i < j)
            j--;
        while (list[i] <= base && i < j)
            i++;
        if(i < j)
        {
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }
    //基准数归位
    list[left] = list[i];
    list[i] = base;
    quickSort(left, i - 1, list);//递归左边
    quickSort(i + 1, right, list);//递归右边
}
