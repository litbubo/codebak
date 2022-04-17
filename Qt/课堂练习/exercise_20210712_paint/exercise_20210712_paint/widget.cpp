#include "widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(rect(),QPixmap("../Image/c++study.jpg"));
}

