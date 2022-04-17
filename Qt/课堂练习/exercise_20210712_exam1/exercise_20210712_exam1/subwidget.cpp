#include "subwidget.h"
#include <QDebug>

subWidget::subWidget(QWidget *parent) : QWidget(parent)
{

}

void subWidget::Function(int x)
{
    qDebug() << x ;
}
