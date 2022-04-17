#include "widget.h"
#include <QPainter>
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::blue);	   //设置蓝色画笔
    painter.setFont(QFont("Arial", 30));	//设置字体
    //在客户区中央输出文字
    painter.drawText(rect(), Qt::AlignCenter, "Qt");
    painter.drawEllipse(QRect(0, 0, width()-400, height()-400));
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{
}

