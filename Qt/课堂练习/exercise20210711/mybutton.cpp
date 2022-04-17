#include "mybutton.h"
#include <QDebug>

myButton::myButton(QWidget *parent) : QPushButton(parent)
{
    this->setText("dianji");
}

void myButton::myclick()
{
    emit mySignal(5,"；是咖啡连锁");
    qDebug() << 44444;

}
