#include "widget.h"
#include <iostream>
#include <QtMath>
#define PI 3.1415926
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    startTimer(100);
}

Widget::~Widget()
{
}

void Widget::paintEvent(QPaintEvent *)
{

    QPainter painter1(this);
    QBrush brush1;
    brush1.setColor(Qt::green);
    brush1.setStyle(Qt::SolidPattern);
    painter1.setBrush(brush1);
    painter1.setPen(Qt::green);
    painter1.translate(300,200);   //以(50,100)为原点
    //painter.drawRect(0, 0, 100, 30);
    painter1.rotate(angel); 		//以原点为中心，顺时针旋转45度
    painter1.drawRect(-20, -20, 150, 40);

    QPainter painter2(this);
    QBrush brush2;
    brush2.setColor(Qt::gray);
    brush2.setStyle(Qt::SolidPattern);
    painter2.setBrush(brush2);
    painter2.setPen(Qt::gray);
    painter2.translate(300 + 120*cos(angel*((2*PI)/360)),200 + 120*sin(angel*((2*PI)/360)));   //以(50,100)为原点
    painter2.rotate(angel*2);
    painter2.drawRect(-15, -15, 120, 30);

    QPainter painter3(this);
    QBrush brush3;
    brush3.setColor(Qt::red);
    brush3.setStyle(Qt::SolidPattern);
    painter3.setBrush(brush3);
    painter3.setPen(Qt::red);
    painter3.translate(300 + 120*cos(angel*((2*PI)/360)) + 90*cos(2*angel*((2*PI)/360)),
                       200 + 120*sin(angel*((2*PI)/360)) + 90*sin(2*angel*((2*PI)/360)));   //以(50,100)为原点
    painter3.rotate(angel*3);
    painter3.drawRect(-10, -10, 80, 20);

    QPainter painter0(this);
    QBrush brush;   //画刷。填充几何图形的调色板，由颜色和填充风格组成
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    painter0.setBrush(brush);
    painter0.setPen(Qt::blue);
    painter0.drawEllipse(292,192,16,16);
    painter0.drawEllipse(300 + 120*cos(angel*((2*PI)/360)) - 5, 200 + 120*sin(angel*((2*PI)/360)) - 5,10,10);
    painter0.drawEllipse(300 + 120*cos(angel*((2*PI)/360)) + 90*cos(2*angel*((2*PI)/360)) - 3,
                         200 + 120*sin(angel*((2*PI)/360)) + 90*sin(2*angel*((2*PI)/360)) - 3,6,6);

}

void Widget::timerEvent(QTimerEvent *)
{
    //std::cout << 1 << std::endl;
    if (angel == 160)
        angel = 0;
    angel += 1;
    update();
}

