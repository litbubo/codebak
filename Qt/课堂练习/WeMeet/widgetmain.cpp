#include "widgetmain.h"
#include "ui_widgetmain.h"

widgetmain::widgetmain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgetmain)
{
    ui->setupUi(this);
    this->move(550,100);
    this->setFixedSize(370,630);
}

widgetmain::~widgetmain()
{
    delete ui;
}

void widgetmain::on_pushButton_clicked()
{
    widgetjion *p3 = new widgetjion;
    p3->show();
}
