#include "sunwidget.h"

sunWidget::sunWidget(QWidget *parent) : QWidget(parent)
{
    b.setText("qiehuan");
    b.setParent(this);
    connect(&b, &QPushButton::clicked, this, &sunWidget::sendSlot);
}

void sunWidget::sendSlot()
{
    emit mySignal();
    emit mySignal(250,"lalala");
}
