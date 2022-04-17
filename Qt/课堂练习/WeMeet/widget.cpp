#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->move(550,100);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    //this->close();
    widgetlogin *p = new widgetlogin();
    p->show();
}

void Widget::on_pushButton_clicked()
{
    //this->close();
    widgetjion *p1 = new widgetjion;
    p1->show();
}
