#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QCompleter>
#include <QStringList>
#include <QMovie>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->myButton->setText("123");

    QString str = ui->myButton->text();
    QString str2 = ui->mylineEdit->text();
    qDebug() << str << str2;

    ui->mylineEdit->setText("1111");
    ui->lcdNumber->display(123);

    ui->progressBar->setMaximum(100);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(90);
}

MainWindow::~MainWindow()
{
    delete ui;
}

