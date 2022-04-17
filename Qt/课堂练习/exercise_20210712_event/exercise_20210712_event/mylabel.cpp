#include "mylabel.h"
#include <QDebug>

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    this->setMouseTracking(true);
}

void myLabel::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    this->setText(QString("<center><h1>MOVE:(%1,%2)</h1></center>").arg(x).arg(y));

}

void myLabel::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    this->setText(QString("<center><h1>PRESS:(%1,%2)</h1></center>").arg(x).arg(y));
    if(event->button() == Qt::LeftButton)
        qDebug() << "left";
}
