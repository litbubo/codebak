#include "mybutton.h"

#include <QMouseEvent>
#include <QPainter>
#include <QDebug>

MyButton::MyButton(QWidget *parent) : QWidget(parent)
{
    m_pix.load(":/image/cherish-ball.png");
}

void MyButton::mouseDoubleClickEvent(QMouseEvent *event)
{

}

void MyButton::mouseMoveEvent(QMouseEvent *event)
{

}

void MyButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        qDebug() << "left";
    }
    else if (event->button() == Qt::RightButton)
    {
        qDebug() << "right";
    }
}

void MyButton::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "press";
}

void MyButton::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(rect() ,m_pix);
}

void MyButton::enterEvent(QEvent *event)
{
    m_pix.load(":/image/great-ball.png");
    update();
}

void MyButton::leaveEvent(QEvent *event)
{
    m_pix.load(":/image/cherish-ball.png");
    update();
}
