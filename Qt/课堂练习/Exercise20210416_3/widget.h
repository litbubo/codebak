#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    float radius;       // 时钟半径
        //指针针尖坐标
    int x= 0,y=160;
        int xSecond, ySecond, xMinute, yMinute, xHour, yHour;
        int xCenter, yCenter;	//时钟中心坐标
        int second,minute,hour;	//时分秒的实际数字
        void CalcPosition();	//计算三种指针针尖坐标的函数
    protected:
        void paintEvent(QPaintEvent *);
        void timerEvent(QTimerEvent *event);

    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
