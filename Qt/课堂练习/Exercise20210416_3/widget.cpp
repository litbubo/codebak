#include "widget.h"
#include <qmath.h>         // 数学库
#include <QPainter>
#define PI 3.14159265       // 圆周率
void Widget::CalcPosition()
{   float secondHandLen, minuteHandLen, hourHandLen;
    secondHandLen = radius*0.8;      //计算秒针长度
    minuteHandLen = radius*0.65;     //计算分针长度
    hourHandLen = radius*0.5;        //计算时针长度
    // 计算秒针针尖位置
    xSecond = xCenter+secondHandLen*cos(second*PI/30-PI/2);
    ySecond = yCenter+secondHandLen*sin(second*PI/30-PI/2);
    // 计算分针针尖位置
    xMinute = xCenter+minuteHandLen*cos(minute*PI/30-PI/2);
    yMinute = yCenter+minuteHandLen*sin(minute*PI/30-PI/2);
    // 计算时针针尖位置
    xHour=xCenter + hourHandLen*
                                           cos((hour+1.0*minute/60)*PI/6-PI/2);
    yHour = yCenter + hourHandLen*
                                           sin((hour+1.0*minute/60)*PI/6-PI/2);
}

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    radius = 100;
    xCenter = 120, yCenter=120;
    hour = 3, minute = 56, second = 55;       //初始时间 3:56:55
    CalcPosition();  //计算初始位置用于第一次显示
    startTimer(10); //启动定时器，为了便于观察，加速10倍
}
void Widget::timerEvent(QTimerEvent *e)
{
    CalcPosition();     // 计算位置
    second++;         // 秒增加
    x++;
    //if(x %2000== 0)
     //   y+=10;
    if(second==60)
    {
         second = 0;
         minute++;    // 分增加
    }
    if(minute==60) {
         minute = 0;
         hour++;      // 时增加
    }
    update();
}

void Widget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QPen pen;    // 画笔的使用请参考下一节
    painter.drawEllipse(QPointF(120.0,120.0),radius,radius);
    painter.drawLine(xCenter,yCenter, xSecond,ySecond);  //秒针
    painter.drawArc(200,200,210,y,500,x);
    //if(x>2000)
    painter.drawPie(300,300,210,y,500,x);
    pen.setWidth(2);     // 画笔设置宽度
    painter.setPen(pen);   //使用画笔
    painter.drawLine(xCenter,yCenter, xMinute,yMinute);   //分针
    pen.setWidth(4);
    painter.setPen(pen);
    painter.drawLine(xCenter,yCenter, xHour,yHour);    // 时针
}

Widget::~Widget()
{
}

