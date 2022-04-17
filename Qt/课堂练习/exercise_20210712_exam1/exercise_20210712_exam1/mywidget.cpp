#include "mywidget.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    m_value = 0;
}

myWidget::~myWidget()
{
}

void myWidget::setValue(int new_value)
{
    if (new_value == m_value)
        return;
    m_value = new_value;
    emit sendValue(m_value);
}

