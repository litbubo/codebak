#include "mydialog.h"
#include "ui_mydialog.h"

myDialog::myDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myDialog)
{
    ui->setupUi(this);
}

myDialog::~myDialog()
{
    delete ui;
}

void myDialog::on_accept_clicked()
{
    this->accept();
}




void myDialog::on_pushButton_2_clicked()
{
    this->reject();
}


void myDialog::on_pushButton_3_clicked()
{
    this->done(10);
}

