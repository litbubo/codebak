#include "mybutterfly.h"

#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QRandomGenerator>
#include <QApplication>
#include <QDesktopWidget>
#include <QTimerEvent>
#include <QPaintEvent>
#include <QEvent>

MyButterFly::MyButterFly(QWidget *parent) : QWidget(parent)
{
    m_pix.load(":/1");
    setFixedSize(m_pix.size());
    update();
    startTimer(100);
}

void MyButterFly::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(rect(), m_pix);
}

void MyButterFly::timerEvent(QTimerEvent *event)
{
    select ++;
    if (select > 2)
    {
        select = 1;
    }
    QString name = QString(":/%1").arg(select);
    m_pix.load(name);
    update();

    QRandomGenerator *desk = QRandomGenerator::global();
    int stepX = desk->bounded(0, 30);
    int stepY = desk->bounded(0, 30);

    int currX = this->geometry().topLeft().x() + stepX;
    int currY = this->geometry().topLeft().y() + stepY;

    auto ret = QApplication::desktop();
    if (currX >= ret->screenGeometry().right())
    {
        currX = ret->screenGeometry().left();
    }
    if (currY >= ret->screenGeometry().bottom())
    {
        currY = ret->screenGeometry().top();
    }
    move(currX, currY);
}

void MyButterFly::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug() << "move left";
    if((event->buttons() & Qt::LeftButton) == 1)
    {
        move(event->globalPos() - pox);
        //qDebug() << "move left";
    }
}

void MyButterFly::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        pox = event->globalPos() - this->geometry().topLeft();
        qDebug() << "left";
    }
}

void MyButterFly::enterEvent(QEvent *event)
{
    select ++;
    if (select > 2)
    {
        select = 1;
    }
    QString name = QString(":/%1").arg(select);
    m_pix.load(name);
    update();

    QRandomGenerator *desk = QRandomGenerator::global();
    int stepX = desk->bounded(-200, 200);
    int stepY = desk->bounded(-200, 200);

    int currX = this->geometry().topLeft().x() + stepX;
    int currY = this->geometry().topLeft().y() + stepY;

    auto ret = QApplication::desktop();
    if (currX >= ret->screenGeometry().right())
    {
        currX = ret->screenGeometry().left();
    }
    if (currY >= ret->screenGeometry().bottom())
    {
        currY = ret->screenGeometry().top();
    }
    move(currX, currY);
}
