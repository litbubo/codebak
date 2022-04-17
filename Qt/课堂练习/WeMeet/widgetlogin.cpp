#include "widgetlogin.h"
#include "ui_widgetlogin.h"

widgetlogin::widgetlogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgetlogin)
{
    ui->setupUi(this);
    this->move(550,100);
    this->setFixedSize(370,630);
    ui->lineEdit->setPlaceholderText("请输入密码");
    ui->lineEdit_2->setPlaceholderText("   请输入手机号码");
    ui->lineEdit_3->setPlaceholderText("  +86");
}

widgetlogin::~widgetlogin()
{
    delete ui;
}

void widgetlogin::on_pushButton_2_clicked()
{
    this->close();

}

void widgetlogin::on_pushButton_clicked()
{
    this->close();
    widgetmain *p2 = new widgetmain;
    p2->show();
}
