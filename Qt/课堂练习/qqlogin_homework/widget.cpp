#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //ui->pushButton->styleSheet("QPushButton{border-radius:50px;}");
    ui->lineEdit->setPlaceholderText("用户名");
    ui->lineEdit_2->setPlaceholderText("密码");
    //ui->lineEdit->setStyleSheet("background-color:white;");
    //ui->lineEdit_2->setStyleSheet("background-color:white;");
    ui->lineEdit->setStyleSheet("border-top:0px solid;border-bottom:1px solid");
    ui->lineEdit_2->setStyleSheet("border-top:0px solid;border-bottom:1px solid");
    //this->setStyleSheet("background-color:blue;");
    this->show();
}

Widget::~Widget()
{
    delete ui;
}

