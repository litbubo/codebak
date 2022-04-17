#include "widget.h"
#include <QTimer>
#include <QTimerEvent>
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    l = new QLabel(this);
    l->resize(100,50);
    l2 = new QLabel(this);
    l2->resize(50,50);
    l2->move(1000,0);

    id = startTimer(100);
    id2 = startTimer(500);

}

Widget::~Widget()
{
}

void Widget::timerEvent(QTimerEvent *e)
{

    if(e->timerId() == id)
    {
        l->setText(QString("给凯美瑞听说你%1").arg(sec++));
        update();

    }
    if(e->timerId() == id2)
    {
        l2->setText(QString("%1").arg(sec2++));
    }
    /*
    QString("66669");
    sec;  //10
    QString("66666%1").arg(sec);
    //QString("66666sec");
    */

}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawRect(x,0,50,50);
    x++;

}

