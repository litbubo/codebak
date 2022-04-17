#include "widgetjion.h"
#include "ui_widgetjion.h"

widgetjion::widgetjion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgetjion)
{
    ui->setupUi(this);
    this->move(550,100);
    this->setFixedSize(370,630);
    ui->lineEdit->setPlaceholderText("  请输入会议号");
    ui->lineEdit_2->setPlaceholderText("  请输入您的名称");
}

widgetjion::~widgetjion()
{
    delete ui;
}
