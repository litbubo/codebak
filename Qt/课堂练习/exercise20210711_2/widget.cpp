#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.setText("^_^");
    b1.move(100, 100);

    b2 = new QPushButton(this);
    b2->setText("abc");

    connect(&b1,&QPushButton::released, this, &Widget::close);
    connect(b2, &QPushButton::released, this, &Widget::mySlot);
    connect(b2, &QPushButton::released, &b1, &QPushButton::hide);

    this->setWindowTitle("laoda");

    b3.setParent(this);
    b3.setText("qiehuan");
    b3.move(50,50);

    connect(&b3, &QPushButton::released, this, &Widget::changeWin);

    void (sunWidget::*funslots)() = &sunWidget::mySignal;
    connect(&sunWin, funslots, this, &Widget::dealSub);

    QPushButton *b4 = new QPushButton(this);
    b4->setText("aaa");
    b4->move(150,150);

    connect(b4, &QPushButton::clicked,
            [=]()
            {
                qDebug() << 6666;
            });

}

void Widget::mySlot()
{
    b2->setText("123");
}

void Widget::changeWin()
{
    sunWin.show();
    this->hide();
}

void Widget::dealSub()
{
    sunWin.hide();
    this->show();
}

Widget::~Widget()
{
}

