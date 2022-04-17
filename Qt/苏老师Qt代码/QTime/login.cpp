#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setFixedSize(314, 340);;
}

Login::~Login()
{
    delete ui;
}
