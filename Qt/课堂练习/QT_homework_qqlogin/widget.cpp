#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("用户名");
    ui->lineEdit_2->setPlaceholderText("密码");
    ui->lineEdit->setStyleSheet("background-color:white;");
    ui->lineEdit_2->setStyleSheet("background-color:white;");
    this->setStyleSheet("background-color:pink;");
    this->show();

}

Widget::~Widget()
{
    delete ui;
}


//void Widget::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
//{

//}
