#include "widget.h"
#include <QPushButton>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *bleft = new QPushButton("火速围观",this);
    QPushButton *bright = new QPushButton("残忍拒绝",this);
    QLabel *label1 = new QLabel("水的ph值",this);
    QLabel *label2 = new QLabel("水位等水情",this);
    QLabel *label3 = new QLabel("情况时影响农作",this);
    QLabel *label4 = new QLabel("物的生长因素",this);
    bleft->resize(180,50);
    bright->resize(180,50);
    bleft->move(50,600);
    bright->move(270,600);
    bleft->setStyleSheet("QPushButton::hover{background-color:GREEN;}"
                         "QPushButton{background-color:RED;}");
    bright->setStyleSheet("QPushButton::hover{background-color:blue;}"
                         "QPushButton{background-color:RED;}");

    label1->move(100,100);
    label2->move(100,230);
    label3->move(100,360);
    label4->move(100,500);
    label1->setStyleSheet("QLabel{font-family:\"黑体\";"
                          "font-style: oblique;"
                          "color: rgb(255,255,255);"
                          "font-size: 20px;}");
    label2->setStyleSheet("QLabel{font-family:\"楷体\";"
                          "font-weight: bold;"
                          "color: rgb(0,255,255);"
                          "font-size: 50px;}");
    label3->setStyleSheet("QLabel{font-family:\"宋体\";"
                          "font-style: italic;"
                          "font-weight: lighter;"
                          "color: rgb(255,0,255);"
                          "font-size: 40px;}");
    label4->setStyleSheet("QLabel{"
                          "font-size: 40px;}");
    this->setStyleSheet("background-color:#555555");
    resize(500,700);

}

Widget::~Widget()
{
}

