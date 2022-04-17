#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    p = new myButton(this);

    connect(p,&myButton::clicked,p, &myButton::myclick);
    void (Widget::*fun)() = &Widget::mySlots;
    connect(p,&myButton::mySignal,this,fun);
/*
    connect(p,&QPushButton::clicked, this,&Widget::myclick);
    //void (Widget::*funmySlots)() = &Widget::mySlots;
    //connect(this,&Widget::mySignal, this, funmySlots);
    connect(this, SIGNAL(mySignal(int,  QString)), this, SLOT ( mySlots(int,  QString)));
    //connect(this, SIGNAL(mySign), this, SLOT ( mySlots(int,  QString) )  );
*/
}

void Widget::mySlots(int x, QString str)
{
    qDebug() << x << str;
}


void Widget::mySlots()
{
    qDebug() << 666666;
}

Widget::~Widget()
{
}

